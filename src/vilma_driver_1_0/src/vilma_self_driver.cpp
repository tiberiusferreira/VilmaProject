#include "vilma_self_driver.h"

vilma_self_driver::vilma_self_driver(morse_receiver *morse_receiver_obj, morse_transmiter *morse_transmiter_obj)
{
    this->morse_receiver_obj=morse_receiver_obj;
    this->morse_transmiter_obj=morse_transmiter_obj;
    gasControler.initPid(150,0.9,150,500,-500,this->rosNode);
    running_threads=0;
}
int vilma_self_driver::reorientate_to_pose(float x, float y){ //reorientates wheels so model goes to given X Y position.
    //Step 1: Find out if the desired location if forward or backwards in respect to the car.
    //Solution: put all data in respect to car. Take car as origin, but keep axis orientation.
    float newx=x-morse_receiver_obj->getPosX();
    float newy=y-morse_receiver_obj->getPosY();
//    qDebug("Orientation: %f",morse_receiver_obj->getOrientationZAsEuler());
    if(sqrt(newy*newx+newy*newy)<0.3){
        return -1;
    }
//    if( (newy>=0 && (morse_receiver_obj->getOrientationZAsEuler()<=(-3.14/2) || morse_receiver_obj->getOrientationZAsEuler()>=(3.14/2)))
//            || (newy<0 && (morse_receiver_obj->getOrientationZAsEuler()<(3.14/2) || morse_receiver_obj->getOrientationZAsEuler()>(-3.14/2))))
//    { //if point is oposite to car direction, do nothing
//        /* The point given is oposite to car direction if the car is facing forward (between -pi/2 and pi/2 of rotation)
// and the point has a negative x value or if the car is facing backwards (between -pi/2 and -pi or between pi/2 and pi) and
//the point has a positive x value.*/
//        return -1;
//    }
    float ang=atan(newx/newy); //ang returned is from -pi/2 to pi/2
    float ang_car=morse_receiver_obj->getOrientationZAsEuler(); //get car z rotation, but it goes from 0 to -3.14 and 0 to 3.14 too
    //need to convert it so I can compare it with ang_car. It only needs to happen when the car is backwards
    if(newx>=0 && newy>=0){ //first quadrant
        ang=-ang;
    }else if(newx<0 && newy>0){ //second quadrant
        ang=-ang;
    }else if(newx<0 && newy<0){ //third quadrant
        ang=3.14-ang;
    }else if(newx>0 && newy<0){ //forth quadrant
        ang=-3.14-ang;
    }
    float value_to_turn=ang-ang_car;
//    if(value_to_turn>(3.14/2) || value_to_turn<(-3.14/2)){
//        return -1;
//    }
//    qDebug("Car Z is: %f\n",morse_receiver_obj->getOrientationZAsEuler());
    qDebug("Delta X is: %f",newx);
    qDebug("Detla Y is: %f",newy);
    qDebug("Time Delta = %f",(ros::Time::now().toNSec()-this->time)/1000000);
    this->time=ros::Time::now().toNSec();
//    qDebug("Atan newx/newy is:%f",ang);
//    qDebug("Wheel Ang %f\n",value_to_turn);
    if(abs(value_to_turn)>0.6){
        return -1;
    }
    morse_transmiter_obj->setSteering(value_to_turn);
    return 1;

}

std::deque<one_point> vilma_self_driver::generate_smooth_path(std::deque<one_point> given_points){
    std::deque <one_point> points,smoothed_points;
    unsigned int i;
    for(i=0;i<given_points.size();i++){
        one_point new_point(given_points.at(i).x,given_points.at(i).y);
        points.push_back(new_point);
        smoothed_points.push_back(new_point);
    }
    float weight_data=0.5, weight_smooth=0.1, tolerance=0.000001;
    float temp=0;
    float delta;
    delta=tolerance;
    while(tolerance<=delta){
        delta=0;
        for(i=1;i<given_points.size()-1;i++){ // for each point
            temp=(smoothed_points.at(i)).x;
            (smoothed_points.at(i)).x+=weight_data*(((points.at(i)).x) - (smoothed_points.at(i)).x) + weight_smooth * (((smoothed_points.at(i-1)).x) + ((smoothed_points.at(i+1)).x) - 2.0 * ((smoothed_points.at(i)).x));
            delta=+ fabs(temp-(smoothed_points.at(i)).x);
            temp=(smoothed_points.at(i)).y;
            (smoothed_points.at(i)).y+=weight_data*(((points.at(i)).y) - (smoothed_points.at(i)).y) + weight_smooth * (((smoothed_points.at(i-1)).y) + ((smoothed_points.at(i+1)).y) - 2.0 * ((smoothed_points.at(i)).y));
            delta=+ fabs(temp-(smoothed_points.at(i)).y);
        }
    }
    //    for(i=0;i<given_points.size();i++){
    //        printf("\n");
    //            printf("%f %f",((smoothed_points.at(i)).x),((smoothed_points.at(i)).y));
    //    }
    return smoothed_points;
}

std::deque<one_point> vilma_self_driver::generate_points(std::deque<one_point> given_points){
    std::deque <one_point> smoothed_points;
    unsigned int i;
    one_point new_point;
       for(i=0;i<given_points.size()-1;i++){ // for each point
            smoothed_points.push_back(given_points.at(i));
            new_point.x=(given_points.at(i+1).x-given_points.at(i).x)/2 + given_points.at(i).x;
            new_point.y=(given_points.at(i+1).y-given_points.at(i).y)/2 + given_points.at(i).y;
            smoothed_points.push_back(new_point);
        }
        smoothed_points.push_back(given_points.at(i));
    //    for(i=0;i<given_points.size();i++){
    //        printf("\n");
    //            printf("%f %f",((smoothed_points.at(i)).x),((smoothed_points.at(i)).y));
    //    }
    return smoothed_points;
}


vilma_self_driver::~vilma_self_driver(){
    this->SetMaintainSpeedOFF();
    if(running_threads!=0){
    printf("Deconstructor Waiting for thread to finish.\n");
    }
    while(running_threads!=0){
    }
    this->morse_transmiter_obj->~morse_transmiter(); //otherwise results in mutex
    //being killed before the maintainSpeedWorker has unlocked it
}

void vilma_self_driver::maintainSpeed(int desiredSpeed){
    this->SetMaintainSpeedOFF();
    if(running_threads!=0){
    printf("Waiting for thread to finish.\n");
    }
    while(running_threads!=0){
    }
    boost::thread t(&vilma_self_driver::maintainSpeedWorker,this,desiredSpeed);
    t.detach();
}
void vilma_self_driver::SetMaintainSpeedOFF(){
    this->maintainSpeedON=0;
}


void vilma_self_driver::maintainSpeedWorker(int desiredSpeed){
    running_threads++;
    this->maintainSpeedON=1;
    gasControler.reset();
    ros::Time previous_interation_time;
    previous_interation_time = ros::Time::now();
    float currentSpeed;
    double updated_value;
    double initialTime = ros::Time::now().toSec();
    FILE * pFile;
    pFile = fopen ("SpeedLog.txt","w");
    FILE * pFile2;
    pFile2 = fopen ("PositionLog.txt","w");

    fprintf (pFile,"Tempo desde o começo da simulação\tMódulo da velocidade do veículo\n");
    while(this->maintainSpeedON){
        ros::Duration dt = ros::Time::now()-previous_interation_time;
        previous_interation_time = ros::Time::now();
        currentSpeed=this->morse_receiver_obj->getLinearVelAVG();
        if(abs(desiredSpeed-currentSpeed)>2){
            gasControler.setGains(150,0,150,0,0);
            gasControler.reset();
        }else{
            gasControler.setGains(150,15,150,25*desiredSpeed,-25*desiredSpeed);
        }
        updated_value=this->gasControler.computeCommand(desiredSpeed-currentSpeed,dt);
        if(updated_value-this->morse_transmiter_obj->getPowerAmount()>10){
            updated_value=this->morse_transmiter_obj->getPowerAmount()+10;
        }
        if(updated_value-this->morse_transmiter_obj->getPowerAmount()<-10){
            updated_value=this->morse_transmiter_obj->getPowerAmount()-10;
        }
        if(updated_value>20*(desiredSpeed)){
            updated_value=20*(desiredSpeed);
        }
        if(updated_value<0){
            updated_value=-updated_value;
        }
//        fprintf (pFile,"%f\t%f\n",ros::Time::now().toSec()-initialTime,currentSpeed);
       fprintf (pFile2,"%f\t%f\n",this->morse_receiver_obj->getPosX(),morse_receiver_obj->getPosY());
//        printf ("%f\t%f\n",ros::Time::now().toSec()-initialTime,currentSpeed);
        boost::this_thread::sleep(boost::posix_time::milliseconds(250));
        this->morse_transmiter_obj->setPowerAmount(updated_value);
    }
    fclose (pFile);
    fclose (pFile2);
    running_threads--;
}

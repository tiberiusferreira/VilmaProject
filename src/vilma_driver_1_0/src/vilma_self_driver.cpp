#include "vilma_self_driver.h"

vilma_self_driver::vilma_self_driver(morse_receiver *morse_receiver_obj, morse_transmiter *morse_transmiter_obj)
{
    this->morse_receiver_obj=morse_receiver_obj;
    this->morse_transmiter_obj=morse_transmiter_obj;
    gasControler.initPid(150,0.9,150,500,-500,this->rosNode);
}
int vilma_self_driver::reorientate_to_pose(float x, float y){ //reorientates wheels so model goes to given X Y position.
    ros::spinOnce(); //update ros side values
    //Step 1: Find out if the desired location if forward or backwards in respect to the car.
    //Solution: put all data in respect to car. Take car as origin, but keep axis orientation.
    float newx=x-morse_receiver_obj->getPosX();
    float newy=y-morse_receiver_obj->getPosY();
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
    if(abs(value_to_turn)>0.6){
        return -1;
    }
    morse_transmiter_obj->setSteering(value_to_turn);
    return 1;
}

std::deque<one_point> vilma_self_driver::generate_smooth_path(std::deque<one_point> given_points){
    std::deque <one_point> points,smoothed_points;//udacity's autonomous vehicles course algorithm
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
            delta+= fabs(temp-(smoothed_points.at(i)).x);
            temp=(smoothed_points.at(i)).y;
            (smoothed_points.at(i)).y+=weight_data*(((points.at(i)).y) - (smoothed_points.at(i)).y) + weight_smooth * (((smoothed_points.at(i-1)).y) + ((smoothed_points.at(i+1)).y) - 2.0 * ((smoothed_points.at(i)).y));
            delta+= fabs(temp-(smoothed_points.at(i)).y);
        }
    }
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
    return smoothed_points;
}


vilma_self_driver::~vilma_self_driver(){
    this->maintainSpeedON=0;
    maintainSpeedThread.join();
    this->morse_transmiter_obj->~morse_transmiter(); //otherwise results in mutex
    //being killed before the maintainSpeedWorker has unlocked it -> segfault
}

void vilma_self_driver::maintainSpeed(int desiredSpeed){
    this->SetMaintainSpeedOFF();
    maintainSpeedThread = boost::thread(&vilma_self_driver::maintainSpeedWorker,this,desiredSpeed);
}
void vilma_self_driver::SetMaintainSpeedOFF(){
    this->maintainSpeedON=0;
    maintainSpeedThread.join();
    this->morse_transmiter_obj->setPowerAmount(0);
    this->morse_transmiter_obj->setManualControl();
}

void vilma_self_driver::speedLogger(){
    record_speed=0;
    SpeedLoggerThread.join();
    record_speed=1;
    SpeedLoggerThread = boost::thread(&vilma_self_driver::speedLogger_worker,this);
}
void vilma_self_driver::positionLogger(){
    record_pos=0;
    PositionLoggerThread.join();
    record_pos=1;
    PositionLoggerThread = boost::thread(&vilma_self_driver::positionLogger_worker,this);
}
void vilma_self_driver::speedLogger_worker(){
    FILE * SpeedLog;
    SpeedLog = fopen ("SpeedLog.txt","w");
    double initialTime = ros::Time::now().toSec();
    printf("ROS TIME NOW:%f\n",ros::Time::now().toSec());
    fprintf(SpeedLog,"Tempo desde o começo da simulação\tMódulo da velocidade do veículo\n");
    fprintf (SpeedLog,"%lf\t%f\n",ros::Time::now().toSec()-initialTime,this->morse_receiver_obj->getLinearVelAVG());
    boost::this_thread::sleep(boost::posix_time::milliseconds(250));
    while(this->record_speed==1){
        fprintf (SpeedLog,"%lf\t%f\n",ros::Time::now().toSec()-initialTime,this->morse_receiver_obj->getLinearVelAVG());
        boost::this_thread::sleep(boost::posix_time::milliseconds(250));
    }
    fclose (SpeedLog);
}

void vilma_self_driver::positionLogger_worker(){
    FILE * PositionLog;
    PositionLog = fopen ("PositionLog.txt","w");
    fprintf (PositionLog,"%f\t%f\n",this->morse_receiver_obj->getPosX(),morse_receiver_obj->getPosY());
    boost::this_thread::sleep(boost::posix_time::milliseconds(250));
    while(this->record_pos==1){
        fprintf (PositionLog,"%f\t%f\n",this->morse_receiver_obj->getPosX(),morse_receiver_obj->getPosY());
        boost::this_thread::sleep(boost::posix_time::milliseconds(250));
    }
    fclose (PositionLog);
}


void vilma_self_driver::maintainSpeedWorker(int desiredSpeed){
    this->maintainSpeedON=1;
    gasControler.reset();
    ros::Time previous_interation_time;
    previous_interation_time = ros::Time::now();
    float currentSpeed;
    double updated_value;
    while(this->maintainSpeedON){
        ros::Duration dt = ros::Time::now()-previous_interation_time;
        previous_interation_time = ros::Time::now();
        currentSpeed=this->morse_receiver_obj->getLinearVelAVG();
        if(abs(desiredSpeed-currentSpeed)>1){
            gasControler.setGains(200+abs(morse_transmiter_obj->getSteering()*350),0,0,0,0);
            gasControler.reset();
        }else{
            gasControler.setGains(200+abs(morse_transmiter_obj->getSteering()*350),50+abs(morse_transmiter_obj->getSteering()*800),0,25*desiredSpeed+abs(morse_transmiter_obj->getSteering()*500),-25*desiredSpeed-abs(morse_transmiter_obj->getSteering()*500));

        }
        updated_value=this->gasControler.computeCommand(desiredSpeed-currentSpeed,dt);
        if(updated_value-this->morse_transmiter_obj->getPowerAmount()>10){
            updated_value=this->morse_transmiter_obj->getPowerAmount()+10;
        }
        if(updated_value-this->morse_transmiter_obj->getPowerAmount()<-40){
            updated_value=this->morse_transmiter_obj->getPowerAmount()-40;
        }
        if(updated_value>50*(desiredSpeed)+abs(this->morse_transmiter_obj->getSteering()*800)){
            updated_value=50*(desiredSpeed)+abs(this->morse_transmiter_obj->getSteering()*800);
        }
        if(updated_value<0){
            updated_value=-updated_value;
        }
        gasControler.printValues();
        boost::this_thread::sleep(boost::posix_time::milliseconds(250));
        this->morse_transmiter_obj->setPowerAmount(updated_value);
    }
}

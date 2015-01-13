#include "vilma_self_driver.h"

vilma_self_driver::vilma_self_driver(morse_receiver *morse_receiver_obj, morse_transmiter *morse_transmiter_obj)
{
    this->morse_receiver_obj=morse_receiver_obj;
    this->morse_transmiter_obj=morse_transmiter_obj;

}
int vilma_self_driver::reorientate_to_pose(float x, float y){ //reorientates wheels so model goes to given X Y position.
    //Step 1: Find out if the desired location if forward or backwards in respect to the car.
    //Solution: put all data in respect to car. Take car as origin, but keep axis orientation.
    float newx=x-morse_receiver_obj->getPosX();
    float newy=y-morse_receiver_obj->getPosY();
    if( (newy>=0 && (morse_receiver_obj->getOrientationZAsEuler()<=(-3.14/2) || morse_receiver_obj->getOrientationZAsEuler()>=(3.14/2)))
            || (newy<0 && ((morse_receiver_obj->getOrientationZAsEuler()<(3.14/2)) && morse_receiver_obj->getOrientationZAsEuler()>(-3.14/2))))
    { //if point is oposite to car direction, do nothing
        /* The point given is oposite to car direction if the car is facing forward (between -pi/2 and pi/2 of rotation)
 and the point has a negative x value or if the car is facing backwards (between -pi/2 and -pi or between pi/2 and pi) and
the point has a positive x value.*/
        return -1;
    }
    float ang=atan(newx/newy); //ang returned is from -pi/2 to pi/2
    float ang_car=morse_receiver_obj->getOrientationZAsEuler(); //get car z rotation, but it goes from 0 to -3.14 and 0 to 3.14 too
    //need to convert it so I can compare it with ang_car. It only needs to happen when the car is backwards
    if(newx>0 && newy>0){ //first quadrant
        ang=-ang;
    }else if(newx<0 && newy>0){ //second quadrant
        ang=-ang;
    }else if(newx<0 && newy<0){ //third quadrant
        ang=3.14-ang;
    }else if(newx>0 && newy<0){ //forth quadrant
        ang=-3.14-ang;
    }
    float value_to_turn=ang-ang_car;
    qDebug("Car Z is: %f\n",morse_receiver_obj->getOrientationZAsEuler());
    qDebug("Delta X is: %f\n",newx);
    qDebug("Detla Y is: %f\n",newy);
    qDebug("Atan newx/newy is:%f\n",ang);
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

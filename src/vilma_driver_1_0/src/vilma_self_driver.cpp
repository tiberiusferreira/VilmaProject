#include "vilma_self_driver.h"

vilma_self_driver::vilma_self_driver(vilma_ros_talker *Vilmaobj)
{
    ros_talker=Vilmaobj;
}
int vilma_self_driver::reorientate_to_pose(float x, float y){ //reorientates wheels so model goes to given X Y position.
    //Step 1: Find out if the desired location if forward or backwards in respect to the car.
    //Solution: put all data in respect to car. Take car as origin, but keep axis orientation.
    float newx=x-ros_talker->modelstate.pose.position.x;
    float newy=y-ros_talker->modelstate.pose.position.y;
    if( (newx>=0 && (ros_talker->imudata_to_euler().GetYaw()<=(-3.14/2) || ros_talker->imudata_to_euler().GetYaw()>=(3.14/2)))
            || (newx<0 && ((ros_talker->imudata_to_euler().GetYaw()<(3.14/2)) && ros_talker->imudata_to_euler().GetYaw()>(-3.14/2))))
    { //if point is oposite to car direction, do nothing
        /* The point given is oposite to car direction if the car is facing forward (between -pi/2 and pi/2 of rotation)
 and the point has a negative x value or if the car is facing backwards (between -pi/2 and -pi or between pi/2 and pi) and
the point has a positive x value.*/
        return -1;
    }
    float ang=atan(newy/newx); //ang returned is from -pi/2 to pi/2
    float ang_car=ros_talker->imudata_to_euler().GetAsEuler().z; //get car z rotation, but it goes from 0 to -3.14 and 0 to 3.14 too
    //need to convert it so I can compare it with ang_car. It only needs to happen when the car is backwards
    if(ang_car>(3.14/2))
    {
        ang_car=(ang_car-(3.14));
    }else if(ang_car<(-3.14/2))
    {
        ang_car=((3.14)+(ang_car));
    }
    float value_to_turn=ang-ang_car;
    qDebug("The world ang to reorient is:%f\n",ang);
    qDebug("The car ang is:%f\n",ang_car);
    std_msgs::Float64 steering_value;
    steering_value.data=value_to_turn*(3.14/0.8727);//Sends to steeringwheel, so need to put ratio steering wheel and actual wheel
    ros_talker->set_steering(steering_value.data);
    return 1;

}
std::deque<one_point> vilma_self_driver::generate_smooth_path(std::deque<one_point> given_points){
    std::deque <one_point> points,smoothed_points;
    int i;
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
    for(i=0;i<given_points.size();i++){
        printf("\n");
            printf("%f %f",((smoothed_points.at(i)).x),((smoothed_points.at(i)).y));
    }
    return smoothed_points;
}

#ifndef WHEEL_SPEED_H
#define WHEEL_SPEED_H

#include <sensor_msgs/NavSatFix.h>
#include <ros/ros.h>
#include <stdio.h>
#include <std_msgs/Float64MultiArray.h>

class wheel_speed
{
private:
    std_msgs::Float64MultiArray wheel_speed_data;
    ros::Subscriber wheel_speed_sub;
    ros::NodeHandle rosNode;
    void receive_wheel_speed(std_msgs::Float64MultiArray new_wheel_speed);


public:
    wheel_speed();
    ~wheel_speed();
    double getFLspeed();
    double getFRspeed();
    double getRLspeed();
    double getRRspeed();

};
#endif // WHEEL_SPEED_H

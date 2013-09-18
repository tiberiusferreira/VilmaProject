#ifndef VILMACONTROLER_H
#define VILMACONTROLER_H
#include <ros/ros.h>
#include <stdio.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Int8.h>
#include <time.h>


class VilmaControler_ROS
{
public:
    std_msgs::Float64 gas_pedal_state, brake_pedal_state, hand_brake_state, hand_wheel_state, br_wheel_speed,bl_wheel_speed,fl_wheel_speed,fr_wheel_speed; //Ask if necessary all those public: instead of one.
    std_msgs::Int8 gears;
public:
    ros::Publisher gas_pedalpub, brake_pedalpub, hand_brakepub,hand_wheelpub, gears_pub;
public:
    ros::Subscriber gas_pedalsub, brake_pedalsub, hand_brakesub, hand_wheelsub, bl_wheel, br_wheel, fl_wheel, fr_wheel,gears_sub;
public:
    ros::NodeHandle rosNode;
    void receive_gas_pedal_data(const std_msgs::Float64::ConstPtr& msg);
    void receive_brake_pedal_data(const std_msgs::Float64::ConstPtr& msg);
    void receive_hand_brake_data(const std_msgs::Float64::ConstPtr& msg);
    void receive_hand_wheel_data(const std_msgs::Float64::ConstPtr& msg);
    void receive_back_left_wheel_speed(const std_msgs::Float64::ConstPtr& msg);
    void receive_back_right_wheel_speed(const std_msgs::Float64::ConstPtr& msg);
    void receive_front_left_wheel_speed(const std_msgs::Float64::ConstPtr& msg);
    void receive_front_right_wheel_speed(const std_msgs::Float64::ConstPtr& msg);
    void receive_gears_state(const std_msgs::Int8::ConstPtr& msg);
    void init();

    };





#endif // VILMACONTROLER_H

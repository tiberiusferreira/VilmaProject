#ifndef VILMACONTROLER_H
#define VILMACONTROLER_H
#include <ros/ros.h>
#include <stdio.h>
#include <std_msgs/Float64.h>
#include <time.h>

void receive_gas_pedal_data(const std_msgs::Float64::ConstPtr& msg);
void receive_brake_pedal_data(const std_msgs::Float64::ConstPtr& msg);
void receive_hand_brake_data(const std_msgs::Float64::ConstPtr& msg);
void receive_hand_wheel_data(const std_msgs::Float64::ConstPtr& msg);
class ControlVilmaKeyboard
{

public:
    ros::Publisher gas_pedalpub, brake_pedalpub, hand_brakepub,hand_wheelpub;
public:
    ros::Subscriber gas_pedalsub, brake_pedalsub, hand_brakesub, hand_wheelsub;
public:
    ros::NodeHandle rosNode;
public:
    void init()
    {
        ////////////////////////////////////GAS PEDAL //////////////////////////////////////
        gas_pedalpub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/gas_pedal/cmd", 1);

        gas_pedalsub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/gas_pedal/state",1,receive_gas_pedal_data);

        ////////////////////////////////////Brake Pedal //////////////////////////////////////

        brake_pedalpub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/brake_pedal/cmd", 1);

        brake_pedalsub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/brake_pedal/state",1, receive_brake_pedal_data);
        ////////////////////////////////////Hand Brake //////////////////////////////////////


        hand_brakepub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/hand_brake/cmd", 1);

        ////////////////////////////////////Hand Wheel //////////////////////////////////////

        hand_wheelpub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/hand_wheel/cmd", 1);



        hand_brakesub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/hand_brake/state",1,receive_hand_brake_data);

        hand_wheelsub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/hand_wheel/state",1,receive_hand_wheel_data);


    }

    };





#endif // VILMACONTROLER_H

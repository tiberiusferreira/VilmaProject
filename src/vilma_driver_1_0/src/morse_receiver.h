#ifndef MORSE_RECEIVER_H
#define MORSE_RECEIVER_H
#include <ros/ros.h>
#include <stdio.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>
#include <gazebo/math/Quaternion.hh>
class morse_receiver
{
private:
    ros::Subscriber morse_pose_sub;
    ros::Subscriber morse_vel_sub;
    ros::NodeHandle rosNode;
    void receive_pos(geometry_msgs::PoseStamped pose);
    void receive_vel(geometry_msgs::TwistStamped vel);
    geometry_msgs::PoseStamped received_pose;
    geometry_msgs::TwistStamped received_vel;

public:
    morse_receiver();
    ~morse_receiver();
    geometry_msgs::PoseStamped getAsPoseStamped();
    geometry_msgs::TwistStamped getAsTwistStamped();

    float getOrientationX();
    float getOrientationY();
    float getOrientationZ();
    float getOrientationW();

    float getPosX();
    float getPosY();
    float getPosZ();


    float getLinearVelX();
    float getLinearVelY();
    float getLinearVelZ();

    float getAngularVelX();
    float getAngularVelY();
    float getAngularVelZ();
    float getOrientationZAsEuler();


};

#endif // MORSE_RECEIVER_H

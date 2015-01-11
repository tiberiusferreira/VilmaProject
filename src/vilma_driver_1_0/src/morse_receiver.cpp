#include "morse_receiver.h"

morse_receiver::morse_receiver()
{
    morse_pose_sub = rosNode.subscribe<geometry_msgs::PoseStamped>("/pose",1,&morse_receiver::receive_pos,this);
    morse_vel_sub = rosNode.subscribe<geometry_msgs::TwistStamped>("/velocity",1,&morse_receiver::receive_vel,this);

}

morse_receiver::~morse_receiver()
{

}

void morse_receiver::receive_pos(geometry_msgs::PoseStamped pose){
    this->received_pose=pose;
}

void morse_receiver::receive_vel(geometry_msgs::TwistStamped vel){
    this->received_vel=vel;
}

geometry_msgs::PoseStamped morse_receiver::getAsPoseStamped(){
    return this->received_pose;
}

geometry_msgs::TwistStamped morse_receiver::getAsTwistStamped(){
    return this->received_vel;
}

float morse_receiver::getOrientationX(){
    return this->received_pose.pose.orientation.x;
}

float morse_receiver::getOrientationY(){
    return this->received_pose.pose.orientation.y;
}

float morse_receiver::getOrientationZ(){
    return this->received_pose.pose.orientation.z;
}

float morse_receiver::getOrientationW(){
    return this->received_pose.pose.orientation.w;
}

float morse_receiver::getPosX(){
    return this->received_pose.pose.position.x;
}

float morse_receiver::getPosY(){
    return this->received_pose.pose.position.y;
}

float morse_receiver::getPosZ(){
    return this->received_pose.pose.position.z;
}

float morse_receiver::getLinearVelX(){
    return this->received_vel.twist.linear.x;
}

float morse_receiver::getLinearVelY(){
    return this->received_vel.twist.linear.y;
}

float morse_receiver::getLinearVelZ(){
    return this->received_vel.twist.linear.z;
}

float morse_receiver::getAngularVelX(){
    return this->received_vel.twist.angular.x;
}

float morse_receiver::getAngularVelY(){
    return this->received_vel.twist.angular.y;
}

float morse_receiver::getAngularVelZ(){
    return this->received_vel.twist.angular.z;
}

float morse_receiver::getOrientationZAsEuler(){
    gazebo::math::Quaternion temp;
    temp.x=this->received_pose.pose.orientation.x;
    temp.y=this->received_pose.pose.orientation.y;
    temp.z=this->received_pose.pose.orientation.z;
    temp.w=this->received_pose.pose.orientation.w;
    return (float) temp.GetYaw();
}

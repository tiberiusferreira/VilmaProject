#ifndef MORSE_SUBSCRIBER_H
#define MORSE_SUBSCRIBER_H
#include "ros/ros.h"
#include <stdio.h>       //printf
#include <string.h>      //strlen
#include <sys/socket.h>  //socket
#include <arpa/inet.h>   //inet_addr
#include <ackermann_msgs/AckermannDrive.h>


class morse_subscriber
{
public:
    int sock;
    struct sockaddr_in server;
    ros::NodeHandle n;
    ackermann_msgs::AckermannDrive ack;
    void chatterCallback(const ackermann_msgs::AckermannDrive::ConstPtr& msg);
    ros::Subscriber sub;

    morse_subscriber();
    ~morse_subscriber();
};

#endif // MORSE_SUBSCRIBER_H

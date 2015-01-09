#ifndef MORSE_TRANSMITER_H
#define MORSE_TRANSMITER_H
#include <ros/ros.h>
#include <stdio.h>
#include <ackermann_msgs/AckermannDrive.h>
#include <string.h>      //strlen
#include <sys/socket.h>  //socket
#include <arpa/inet.h>   //inet_addr
class morse_transmiter
{
private:
    ackermann_msgs::AckermannDrive ackermann_msg; //Holds the steering, speed and acceleration desired
    ros::Publisher ackermann_pub;
    ros::NodeHandle rosNode;
    float steering;
    float velocity;
    float power;
    int sock;
    struct sockaddr_in server;

public:
    morse_transmiter();
    ~morse_transmiter();

    void setSteering(float rad);
    void setVelocity(float meter_per_sec);
    void setPowerAmount(float power_amount);

};

#endif // MORSE_TRANSMITER_H

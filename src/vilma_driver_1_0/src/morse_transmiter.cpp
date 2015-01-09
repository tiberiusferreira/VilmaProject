#include "morse_transmiter.h"

morse_transmiter::morse_transmiter()
{
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1){
        printf("Could not create socket");
        exit(1);
    }
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(4000);
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0){
        perror("connect failed. Error");
        exit(1);
    }

}

morse_transmiter::~morse_transmiter()
{

}

void morse_transmiter::setSteering(float rad){
    char message1[100];
    this->steering=rad;
    //robot carina2 is hardcoded
    sprintf(message1, "id carina2 steer [1,%lf]\n", rad);

    if( send(sock , message1 , strlen(message1) , 0) < 0){
        puts("send steer failed");
    }
}

void morse_transmiter::setVelocity(float meter_per_sec){
    char message1[100];
    this->velocity=meter_per_sec;
    //robot carina2 is hardcoded
    sprintf(message1, "id carina2 controlpower [1,%lf,%lf]\n", this->power,meter_per_sec);

    if( send(sock , message1 , strlen(message1) , 0) < 0){
        puts("send steer failed");
    }
}

void morse_transmiter::setPowerAmount(float power_amount){
    char message1[100];
    this->power=power_amount;
    //robot carina2 is hardcoded
    sprintf(message1, "id carina2 controlpower [1,%lf,%lf]\n", power_amount,this->velocity);

    if( send(sock , message1 , strlen(message1) , 0) < 0){
        puts("send steer failed");
    }
}

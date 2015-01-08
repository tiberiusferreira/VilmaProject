#include "morse_subscriber.h"

morse_subscriber::morse_subscriber()
{

    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1){
        printf("Could not create socket");
    }
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(4000);
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0){
        perror("connect failed. Error");
        //return 1;
    }
    sub = n.subscribe<ackermann_msgs::AckermannDrive>("ackermann_cmd", 1000, &morse_subscriber::chatterCallback,this);

    ros::spinOnce();

}
void morse_subscriber::chatterCallback(const ackermann_msgs::AckermannDrive::ConstPtr& msg)
{

  //ROS_INFO("I heard: [%f]", msg->acceleration);

    //printf("%lf\n", msg->speed);

    //Socket_AckermannDrive *sack = new Socket_AckermannDrive(*msg);
    //Socket_AckermannDrive sack(*msg);

    //printf("INICIO\n");
    char message1[100];
    //robot carina2 is hardcoded
    sprintf(message1, "id carina2 controlpower [1,%lf,%lf]\n", msg->acceleration, msg->speed);

    if( send(sock , message1 , strlen(message1) , 0) < 0){
        puts("send failed");
        //return 1;
    }

    char message2[100];
    //robot carina2 is hardcoded
    sprintf(message2, "id carina2 steer [1,%lf]\n", msg->steering_angle);

    if( send(sock , message2 , strlen(message2) , 0) < 0){
        puts("send failed");
        //return 1;
    }

    //printf("FIM\n");

}

morse_subscriber::~morse_subscriber()
{

}


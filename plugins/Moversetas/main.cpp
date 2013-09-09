#include <ros/ros.h>
#include <stdio.h>
#include <std_msgs/Float64.h>
#include <termios.h>
#include <signal.h>
#include <time.h>
#define KEYCODE_A 0x61
#define KEYCODE_D 0x64
#define KEYCODE_S 0x73
#define KEYCODE_W 0x77
#define KEYCODE_H 0x68
void receive_gas_pedal_data(const std_msgs::Float64::ConstPtr& msg);
void receive_brake_pedal_data(const std_msgs::Float64::ConstPtr& msg);
void receive_hand_brake_data(const std_msgs::Float64::ConstPtr& msg);
void receive_hand_wheel_data(const std_msgs::Float64::ConstPtr& msg);
void quit(int sig);
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
        std_msgs::Float64 gas_pedal, brake_pedal, hand_brake, handwheel;



        ////////////////////////////////////GAS PEDAL //////////////////////////////////////
        gas_pedalpub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/gas_pedal/cmd", 1);

        gas_pedalsub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/gas_pedal/state",1,receive_gas_pedal_data);

        ////////////////////////////////////Brake Pedal //////////////////////////////////////

        brake_pedalpub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/brake_pedal/cmd", 1);

        ////////////////////////////////////Hand Brake //////////////////////////////////////


        hand_brakepub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/hand_brake/cmd", 1);

        ////////////////////////////////////Hand Wheel //////////////////////////////////////

        hand_wheelpub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/hand_wheel/cmd", 1);



        hand_brakesub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/hand_brake/state",1,receive_hand_brake_data);

        hand_wheelsub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/hand_wheel/state",1,receive_hand_wheel_data);




    }

};
struct termios cooked, raw; // Declared globally so both main and quit can access the cooked state.
void quit(int sig) // Called by the function signal and resets the terminal
{
    // to the default, standart state, stored in "cooked".
    tcsetattr(0, TCSANOW, &cooked); // resets terminal
    exit(0); // Clean up and return control to host
} //(closes whole program instead of return(0), which would keep the for loop running).

std_msgs::Float64 gas_pedal_state, brake_pedal_state, hand_brake_state, hand_wheel_state;

void receive_gas_pedal_data(const std_msgs::Float64::ConstPtr& msg)
{
    gas_pedal_state.data=msg->data;
}
void receive_brake_pedal_data(const std_msgs::Float64::ConstPtr& msg)
{
    brake_pedal_state.data=msg->data;
}
void receive_hand_brake_data(const std_msgs::Float64::ConstPtr& msg)
{
    hand_brake_state.data=msg->data;
}
void receive_hand_wheel_data(const std_msgs::Float64::ConstPtr& msg)
{
    hand_wheel_state.data=msg->data;
}
int main(int argc, char** argv)
{
    char keyboardread;
    ros::init(argc, argv, "Vilma_drive_cmd_publisher");
    ControlVilmaKeyboard Teste;
    std_msgs::Float64 accelerate, brake, hand_brake, hand_wheel;
    accelerate.data=0;
    brake.data=0;
    hand_brake.data=1;
    hand_wheel.data=0;


    tcgetattr(0, &cooked); // get the console "default" state and store it as cooked state.
    memcpy(&raw, &cooked, sizeof(struct termios)); // copy cooked state to raw
    raw.c_lflag &=~ (ICANON | ECHO); //change raw state
    // Setting a new line, then end of file
    raw.c_cc[VEOL] = 1;
    raw.c_cc[VEOF] = 2;
    tcsetattr(0, TCSANOW, &raw); // change terminal state to raw (the modified one)


    puts("Reading from keyboard");
    puts("---------------------------");
    puts("Use 'WS' to forward/back");
    puts("Use 'AD' to left/right");
    puts("Use 'H' for activating or desabling the hand brake");


    Teste.init();
    signal(SIGINT,quit); // runs until receives SIGIN (control + C) and then calls function quit.
    for(;;) // loop, but signal keeps running and will end program when control + c is detected.
    {
        scanf("%c",&keyboardread);
        switch(keyboardread)
        {
            // Walking
        case KEYCODE_W:
            if(brake_pedal_state.data>0.1)
            {
                brake.data=brake.data-0.1;
                Teste.brake_pedalpub.publish(brake);
                ros::spinOnce();
                printf("Brake was pressed, releasing it. Current state : %f\n", brake_pedal_state.data);
                break;
            }
            else
            {
                accelerate.data=accelerate.data+0.01;
                Teste.gas_pedalpub.publish(accelerate);
                ros::spinOnce();
                printf("Gas pedal pushed. Currently at: %f \n",gas_pedal_state.data);
                break;
            }
        case KEYCODE_S:
            if(gas_pedal_state.data>0.09)
            {
                printf("Gas pedal released. Currently at: %f \n",gas_pedal_state.data);
                accelerate.data=accelerate.data-0.1;
                Teste.gas_pedalpub.publish(accelerate);
                ros::spinOnce();
            }

            if(gas_pedal_state.data<=0.09)
            {
                brake.data=brake.data+0.02;
                Teste.brake_pedalpub.publish(brake);
                ros::spinOnce();
                printf("Gas pedal to zero. Brake pushed, currently at: %f\n", brake_pedal_state.data);
            }
            break;
        case KEYCODE_H:
            if(hand_brake_state.data>0.1)
            {
                puts("Hand Brake was engaged, disabling it.");
                for(hand_brake.data=hand_brake_state.data-0.09; hand_brake_state.data>=0.1; hand_brake.data=hand_brake_state.data-0.1)
                {
                    Teste.hand_brakepub.publish(hand_brake);
                    ros::spinOnce();
                    printf("Hand brake current at: %f\n",hand_brake_state.data);
                }
                break;
            }
            if(hand_brake_state.data<=0.1)
            {
                puts("Hand Brake was disabled, engaging it.");
                for(hand_brake.data=hand_brake_state.data+0.1; hand_brake_state.data<=0.88; hand_brake.data=hand_brake_state.data+0.1)
                {
                    Teste.hand_brakepub.publish(hand_brake);
                    ros::spinOnce();
                    printf("Hand brake current at: %f\n",hand_brake_state.data);
                }

                break;

            }

        case KEYCODE_A:
            puts("Turning left!");
            hand_wheel.data=hand_wheel.data+2;
            Teste.hand_wheelpub.publish(hand_wheel);
            break;
        case KEYCODE_D:
            puts("Turning right!");
            hand_wheel.data=hand_wheel.data-2;
            Teste.hand_wheelpub.publish(hand_wheel);
            break;
        }

    }

    return(0);
}

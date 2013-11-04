/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the documentation of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
//![0]

#include "piechart.h"
#include <QtQuick/QQuickView>
#include <QGuiApplication>


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "Vilma_drive_cmd_publisher"); //Inializing ROS basic, needed for basically anything
    ControlVilmaKeyboard Controler; // For some unknown reason I need to declare it here and use it's init function
    Controler.init(); // lookup the VilmaControler header.
    ros::spinOnce(); // ensure values are up to date on data collection

    QGuiApplication app(argc, argv);

    qmlRegisterType<Vilma_controler>("Charts", 1, 0, "Vilma_controler");

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl::fromLocalFile("app.qml"));
    view.show();
    return app.exec();
}
std_msgs::Float64 gas_pedal_state, brake_pedal_state, hand_brake_state, hand_wheel_state;

void receive_gas_pedal_data(const std_msgs::Float64::ConstPtr& msg)
{
    if(msg->data!=gas_pedal_state.data)
    {
        gas_pedal_state.data=msg->data;
    }

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

void Vilma_controler::update_vilma_info()
{

    ros::spinOnce();
    Vilma_controler::setGas_joint(QString::number(gas_pedal_state.data));
    Vilma_controler::setBrake_joint(QString::number(brake_pedal_state.data));
    Vilma_controler::setHand_brake_joint(QString::number(hand_brake_state.data));
    Vilma_controler::setSteering_joint(QString::number(hand_wheel_state.data));

}

void Vilma_controler::accelerate()
{
    ControlVilmaKeyboard Controler; //need to create an object to initialize the controller stuff in VilmaControler header.

    Controler.init(); // lookup the VilmaControler header.
    std_msgs::Float64 accelerate;
    accelerate.data=gas_pedal_state.data+0.1;
    Controler.gas_pedalpub.publish(accelerate);
}
void Vilma_controler::deaccelerate()
{
    ControlVilmaKeyboard Controler; //need to create an object to initialize the controller stuff in VilmaControler header.

    Controler.init(); // lookup the VilmaControler header.
    std_msgs::Float64 deaccelerate;
    deaccelerate.data=gas_pedal_state.data-0.1;
    Controler.gas_pedalpub.publish(deaccelerate);
}
void Vilma_controler::use_brake_push()
{
    ControlVilmaKeyboard Controler; //need to create an object to initialize the controller stuff in VilmaControler header.

    Controler.init(); // lookup the VilmaControler header.
    std_msgs::Float64 use_brake;
    use_brake.data=brake_pedal_state.data+0.1;
    Controler.brake_pedalpub.publish(use_brake);
}
void Vilma_controler::use_brake_release()
{
    ControlVilmaKeyboard Controler; //need to create an object to initialize the controller stuff in VilmaControler header.

    Controler.init(); // lookup the VilmaControler header.
    std_msgs::Float64 use_brake;
    use_brake.data=brake_pedal_state.data-0.1;
    Controler.brake_pedalpub.publish(use_brake);
}
void Vilma_controler::use_hand_brake()
{
    ControlVilmaKeyboard Controler; //need to create an object to initialize the controller stuff in VilmaControler header.

    Controler.init(); // lookup the VilmaControler header.
    std_msgs::Float64 hand_brake;
    if(hand_brake_state.data>0.1)
    {
        for(hand_brake.data=hand_brake_state.data-0.09; hand_brake_state.data>=0.1; hand_brake.data=hand_brake_state.data-0.1)
        {
            Controler.hand_brakepub.publish(hand_brake);
            ros::spinOnce();
        }
    }
    else
        if(hand_brake_state.data<=0.1)
        {
            for(hand_brake.data=hand_brake_state.data+0.1; hand_brake_state.data<=0.88; hand_brake.data=hand_brake_state.data+0.1)
            {
                Controler.hand_brakepub.publish(hand_brake);
                ros::spinOnce();
            }
        }
}
void Vilma_controler::use_Steering(float value)
{


    ControlVilmaKeyboard Controler; //need to create an object to initialize the controller stuff in VilmaControler header.

    Controler.init(); // lookup the VilmaControler header.


    std_msgs::Float64 steering_value;
    steering_value.data=value;
    Controler.hand_wheelpub.publish(steering_value);

}

//![0]

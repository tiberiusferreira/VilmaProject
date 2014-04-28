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
#include "VilmaControler_QtSide.h"



VilmaControler_QtSide::VilmaControler_QtSide(QDeclarativeItem *parent): QDeclarativeItem(parent)
{
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(update_vilma_info()));
    timer->start(600);
    VilmaControler_ROS_Object.init();
}

QString VilmaControler_QtSide::gas_joint() const
{
    return gas_joint_value;
}

void VilmaControler_QtSide::setGas_joint(const QString &value)
{
    gas_joint_value = value; // variable used by the gui and qml
    emit gas_jointChanged();
}

QString VilmaControler_QtSide::brake_joint() const
{
    return brake_joint_value;
}

void VilmaControler_QtSide::setBrake_joint(const QString &value)
{
    brake_joint_value = value;
    emit brake_jointChanged();
}

QString VilmaControler_QtSide::hand_brake_joint() const
{
    return hand_brake_joint_value;
}

void VilmaControler_QtSide::setHand_brake_joint(const QString &value)
{
    hand_brake_joint_value = value;
    emit hand_brake_jointChanged();
}


QString VilmaControler_QtSide::steering_joint() const
{
    return steering_joint_value;
}

void VilmaControler_QtSide::setSteering_joint(const QString &value)
{
    steering_joint_value = value;
    emit steering_jointChanged();
}

QString VilmaControler_QtSide::bl_wheel_speed() const
{
    return bl_wheel_speed_value;
}
void VilmaControler_QtSide::setBl_wheel_speed(const QString &value)
{
    bl_wheel_speed_value = value;
    emit bl_wheel_speedChanged();
}

QString VilmaControler_QtSide::br_wheel_speed() const
{
    return br_wheel_speed_value;
}

void VilmaControler_QtSide::setBr_wheel_speed(const QString &value)
{
    br_wheel_speed_value = value;
    emit br_wheel_speedChanged();
}

QString VilmaControler_QtSide::fl_wheel_speed() const
{
    return fl_wheel_speed_value;
}

void VilmaControler_QtSide::setFl_wheel_speed(const QString &value)
{
    fl_wheel_speed_value = value;
    emit fl_wheel_speedChanged();
}

QString VilmaControler_QtSide::fr_wheel_speed() const
{
    return fr_wheel_speed_value;
}

void VilmaControler_QtSide::setFr_wheel_speed(const QString &value)
{
    fr_wheel_speed_value = value;
    emit fr_wheel_speedChanged();
}

QString VilmaControler_QtSide::gears() const
{
    return gears_value;
}

void VilmaControler_QtSide::setgears(const QString &value)
{
    gears_value=value;
    emit gearsChanged();
}

void VilmaControler_QtSide::change_gears()
{
    std_msgs::Int8 gears_value;
    if (VilmaControler_ROS_Object.gears.data<0.3&&VilmaControler_ROS_Object.gears.data>-0.3)
    {
        gears_value.data=1;
        VilmaControler_ROS_Object.gears_pub.publish(gears_value);
    }
    else if (VilmaControler_ROS_Object.gears.data<-0.5)
    {
        gears_value.data=0;
        VilmaControler_ROS_Object.gears_pub.publish(gears_value);
    }
    else if (VilmaControler_ROS_Object.gears.data>0.5)
    {
        gears_value.data=-1;
        VilmaControler_ROS_Object.gears_pub.publish(gears_value);
    }
    emit gearsChanged();
}
void VilmaControler_QtSide::setXposition(const QString &value)
{
    xposition_value = value;
    emit x_positionChanged();
}

QString VilmaControler_QtSide::xposition() const
{
    return xposition_value;
}

void VilmaControler_QtSide::setYposition(const QString &value)
{
    yposition_value = value;
    emit y_positionChanged();
}

QString VilmaControler_QtSide::yposition() const
{
    return yposition_value;
}
void VilmaControler_QtSide::setZposition(const QString &value)
{
    zposition_value = value;
    emit z_positionChanged();
}

QString VilmaControler_QtSide::zposition() const
{
    return zposition_value;
}

QString VilmaControler_QtSide::readXtwist() const
{
    return xtwist_value;
}

void VilmaControler_QtSide::setXtwist(const QString &value)
{
    xtwist_value = value;
    emit xtwistChanged();
}


QString VilmaControler_QtSide::readYtwist() const
{
    return ytwist_value;
}

void VilmaControler_QtSide::setYtwist(const QString &value)
{
    ytwist_value = value;
    emit ytwistChanged();
}


QString VilmaControler_QtSide::readZtwist() const
{
    return ztwist_value;
}

void VilmaControler_QtSide::setZtwist(const QString &value)
{
    ztwist_value = value;
    emit ztwistChanged();
}

QString VilmaControler_QtSide::readXorientation() const
{
    return xorientation_value;
}

void VilmaControler_QtSide::setXorientation(const QString &value)
{
    xorientation_value = value;
    emit xorientationChanged();
}

QString VilmaControler_QtSide::readYorientation() const
{
    return yorientation_value;
}

void VilmaControler_QtSide::setYorientation(const QString &value)
{
    yorientation_value = value;
    emit yorientationChanged();
}

QString VilmaControler_QtSide::readZorientation() const
{
    return yorientation_value;
}

void VilmaControler_QtSide::setZorientation(const QString &value)
{
    zorientation_value = value;
    emit zorientationChanged();
}

QString VilmaControler_QtSide::readWorientation() const
{
    return worientation_value;
}
void VilmaControler_QtSide::setWorientation(const QString &value)
{
    worientation_value = value;
    emit worientationChanged();
}

void VilmaControler_QtSide::maintain_speed()
{
 this->VilmaControler_ROS_Object.maintain_speed();
}

void VilmaControler_QtSide::update_vilma_info()
{

    ros::spinOnce();//make sure it gets updated values
    VilmaControler_QtSide::setGas_joint(QString::number(VilmaControler_ROS_Object.gas_pedal_state.data,'f',2));
    VilmaControler_QtSide::setBrake_joint(QString::number(VilmaControler_ROS_Object.brake_pedal_state.data,'f',2));
    VilmaControler_QtSide::setHand_brake_joint(QString::number(VilmaControler_ROS_Object.hand_brake_state.data,'f',2));
    VilmaControler_QtSide::setSteering_joint(QString::number(VilmaControler_ROS_Object.hand_wheel_state.data,'f',2));
    VilmaControler_QtSide::setBl_wheel_speed(QString::number(VilmaControler_ROS_Object.bl_wheel_speed.data,'f',2));
    VilmaControler_QtSide::setBr_wheel_speed(QString::number(VilmaControler_ROS_Object.br_wheel_speed.data,'f',2));
    VilmaControler_QtSide::setFl_wheel_speed(QString::number(VilmaControler_ROS_Object.fl_wheel_speed.data,'f',2));
    VilmaControler_QtSide::setFr_wheel_speed(QString::number(VilmaControler_ROS_Object.fr_wheel_speed.data,'f',2));
    VilmaControler_QtSide::setgears(QString::number(VilmaControler_ROS_Object.gears.data));
    //Necessary because unlike subscribed nodes it does not update.
    VilmaControler_ROS_Object.receive_model_physical_state(VilmaControler_ROS_Object.getmodelstate);
    VilmaControler_QtSide::setXposition(QString::number(VilmaControler_ROS_Object.modelstate.pose.position.x,'f',3));
    VilmaControler_QtSide::setYposition(QString::number(VilmaControler_ROS_Object.modelstate.pose.position.y,'f',3));
    VilmaControler_QtSide::setZposition(QString::number(VilmaControler_ROS_Object.modelstate.pose.position.z,'f',3));
    VilmaControler_QtSide::setXtwist(QString::number(VilmaControler_ROS_Object.modelstate.twist.angular.x,'f',3));
    VilmaControler_QtSide::setYtwist(QString::number(VilmaControler_ROS_Object.modelstate.twist.angular.y,'f',3));
    VilmaControler_QtSide::setZtwist(QString::number(VilmaControler_ROS_Object.modelstate.twist.angular.z,'f',3));
    VilmaControler_QtSide::setXorientation(QString::number(VilmaControler_ROS_Object.modelstate.pose.orientation.x,'f',3));
    VilmaControler_QtSide::setYorientation(QString::number(VilmaControler_ROS_Object.modelstate.pose.orientation.y,'f',3));
    VilmaControler_QtSide::setZorientation(QString::number(VilmaControler_ROS_Object.modelstate.pose.orientation.z,'f',3));
    VilmaControler_QtSide::setWorientation(QString::number(VilmaControler_ROS_Object.modelstate.pose.orientation.w,'f',3));


}

void VilmaControler_QtSide::accelerate()
{

    std_msgs::Float64 accelerate;
    accelerate.data=VilmaControler_ROS_Object.gas_pedal_state.data+0.01;
    VilmaControler_ROS_Object.gas_pedalpub.publish(accelerate);
}
void VilmaControler_QtSide::deaccelerate()
{

    std_msgs::Float64 deaccelerate;
    deaccelerate.data=VilmaControler_ROS_Object.gas_pedal_state.data-0.01;
    VilmaControler_ROS_Object.gas_pedalpub.publish(deaccelerate);
}
void VilmaControler_QtSide::use_brake_push()
{

    std_msgs::Float64 use_brake;
    use_brake.data=VilmaControler_ROS_Object.brake_pedal_state.data+0.01;
    VilmaControler_ROS_Object.brake_pedalpub.publish(use_brake);
}
void VilmaControler_QtSide::use_brake_release()
{

    std_msgs::Float64 use_brake;
    use_brake.data=VilmaControler_ROS_Object.brake_pedal_state.data-0.01;
    VilmaControler_ROS_Object.brake_pedalpub.publish(use_brake);
}
void VilmaControler_QtSide::use_hand_brake()
{

    std_msgs::Float64 hand_brake;
    if(VilmaControler_ROS_Object.hand_brake_state.data>0.05)//turn to OFF
    {
        for(hand_brake.data=VilmaControler_ROS_Object.hand_brake_state.data-0.09; VilmaControler_ROS_Object.hand_brake_state.data>=0.05; hand_brake.data=VilmaControler_ROS_Object.hand_brake_state.data-0.1)
        {
            VilmaControler_ROS_Object.hand_brakepub.publish(hand_brake);
            ros::spinOnce();
        }
    }
    else
        if(VilmaControler_ROS_Object.hand_brake_state.data<=0.1)// TURN TO ON
        {
            for(hand_brake.data=VilmaControler_ROS_Object.hand_brake_state.data+0.1; VilmaControler_ROS_Object.hand_brake_state.data<=0.88; hand_brake.data=VilmaControler_ROS_Object.hand_brake_state.data+0.1)
            {
                VilmaControler_ROS_Object.hand_brakepub.publish(hand_brake);
                ros::spinOnce();
            }
        }
}
void VilmaControler_QtSide::use_Steering(float value)
{
    std_msgs::Float64 steering_value;
    steering_value.data=value;
    VilmaControler_ROS_Object.hand_wheelpub.publish(steering_value);

}

void VilmaControler_QtSide::reset_state()
{
    ros::spinOnce();
    std_msgs::Float64 reset_gas;
    std_msgs::Float64 reset_brake;
    std_msgs::Float64 reset_hand_brake;
    std_msgs::Float64 reset_steering;
    std_msgs::Int8 reset_gears;
    reset_gas.data=0;
    reset_steering.data=0;
    reset_brake.data=0;
    reset_gears.data=1;
    VilmaControler_ROS_Object.gas_pedalpub.publish(reset_gas);
    VilmaControler_ROS_Object.hand_wheelpub.publish(reset_steering);
    VilmaControler_ROS_Object.brake_pedalpub.publish(reset_brake);
    VilmaControler_ROS_Object.gears_pub.publish(reset_gears);
    if(VilmaControler_ROS_Object.hand_brake_state.data<=0.1)
    {
        for(reset_hand_brake.data=VilmaControler_ROS_Object.hand_brake_state.data+0.1; VilmaControler_ROS_Object.hand_brake_state.data<=0.88; reset_hand_brake.data=VilmaControler_ROS_Object.hand_brake_state.data+0.1)
        {
            VilmaControler_ROS_Object.hand_brakepub.publish(reset_hand_brake);
            ros::spinOnce();
        }
    }
}


//![0]

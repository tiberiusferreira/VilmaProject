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
#ifndef VILMACONTROLER_QTSIDE
#define VILMACONTROLER_QTSIDE
#include "VilmaControler_RosSide.h"
#include <QtDeclarative/QDeclarativeItem>
#include <QColor>
#include <QTimer>
#include <QKeyEvent>
#include <QDateTime>


class VilmaControler_QtSide : public QDeclarativeItem
{
public:
    VilmaControler_QtSide(); //constructor used to initilise stuff
private:
    VilmaControler_ROS VilmaControler_ROS_Object; //Object of the class VilmaControler_ROS, which handles ROS-QT interface.
    Q_OBJECT
    Q_PROPERTY(QString gas_joint READ gas_joint) // Each one is a property exposed to the qml interface
    Q_PROPERTY(QString brake_joint READ brake_joint) //Each has a name, a fuction to return
    Q_PROPERTY(QString hand_brake_joint READ hand_brake_joint) //it's value and one to set it.
    Q_PROPERTY(QString steering_joint READ steering_joint)
    Q_PROPERTY(QString bl_wheel_speed READ bl_wheel_speed)
    Q_PROPERTY(QString br_wheel_speed READ br_wheel_speed)
    Q_PROPERTY(QString fl_wheel_speed READ fl_wheel_speed)
    Q_PROPERTY(QString fr_wheel_speed READ fr_wheel_speed)
    Q_PROPERTY(QString gears READ gears)
    Q_PROPERTY(QString xposition READ xposition)
    Q_PROPERTY(QString yposition READ yposition)
    Q_PROPERTY(QString zposition READ zposition)
    Q_PROPERTY(QString xlinear_vel READ readXlinear_vel)
    Q_PROPERTY(QString ylinear_vel READ readYlinear_vel)
    Q_PROPERTY(QString zlinear_vel READ readZlinear_vel)
    Q_PROPERTY(QString xangular_vel READ readXangular_vel)
    Q_PROPERTY(QString yangular_vel READ readYangular_vel)
    Q_PROPERTY(QString zangular_vel READ readZangular_vel)
    Q_PROPERTY(QString xorientation READ readXorientation)
    Q_PROPERTY(QString yorientation READ readYorientation)
    Q_PROPERTY(QString zorientation READ readZorientation)
    Q_PROPERTY(QString worientation READ readWorientation)
    Q_PROPERTY(QString latitude READ readLatitude)
    Q_PROPERTY(QString longitude READ readLongitude) // velocidade angular X Y Z. Aceleração Linear X Y Z. Orientação X Y Z W.
    Q_PROPERTY(QString imu_ang_vel_x READ read_imu_ang_vel_x)
    Q_PROPERTY(QString imu_ang_vel_y READ read_imu_ang_vel_y)
    Q_PROPERTY(QString imu_ang_vel_z READ read_imu_ang_vel_z)
    Q_PROPERTY(QString imu_lin_acel_x READ read_imu_lin_acel_x)
    Q_PROPERTY(QString imu_lin_acel_y READ read_imu_lin_acel_y)
    Q_PROPERTY(QString imu_lin_acel_z READ read_imu_lin_acel_z)
    Q_PROPERTY(QString imu_ori_x READ read_imu_ori_x)
    Q_PROPERTY(QString imu_ori_y READ read_imu_ori_y)
    Q_PROPERTY(QString imu_ori_z READ read_imu_ori_z)
    Q_PROPERTY(QString imu_ori_w READ read_imu_ori_w)
    Q_PROPERTY(QString imu_eul_x READ read_imu_eul_x)
    Q_PROPERTY(QString imu_eul_y READ read_imu_eul_y)
    Q_PROPERTY(QString imu_eul_z READ read_imu_eul_z)




public:
    QString readXlinear_vel() const;
    QString readYlinear_vel() const;
    QString readZlinear_vel() const;

    QString readXangular_vel() const;
    QString readYangular_vel() const;
    QString readZangular_vel() const;

    QString readXorientation() const;
    QString readYorientation() const;
    QString readZorientation() const;
    QString readWorientation() const;

    QString gas_joint() const;  // Functions to read the properties declared above.

    QString brake_joint() const;

    QString hand_brake_joint() const;

    QString steering_joint() const;

    QString bl_wheel_speed() const;
    QString br_wheel_speed() const;
    QString fl_wheel_speed() const;
    QString fr_wheel_speed() const;

    QString gears() const;

    QString xposition() const;
    QString yposition() const;
    QString zposition() const;

    QString readLatitude() const;
    QString readLongitude() const;

    QString read_imu_ang_vel_x() const;
    QString read_imu_ang_vel_y() const;
    QString read_imu_ang_vel_z() const;
    QString read_imu_lin_acel_x() const;
    QString read_imu_lin_acel_y() const;
    QString read_imu_lin_acel_z() const;
    QString read_imu_ori_x() const;
    QString read_imu_ori_y() const;
    QString read_imu_ori_z() const;
    QString read_imu_ori_w() const;

    QString read_imu_eul_x();
    QString read_imu_eul_y();
    QString read_imu_eul_z();


    Q_INVOKABLE void change_gears();
    Q_INVOKABLE void accelerate();
    Q_INVOKABLE void deaccelerate();
    Q_INVOKABLE void use_hand_brake();
    Q_INVOKABLE void use_Steering(float value); //using float instead of Qstring because of the slider, it outputs using float.
    Q_INVOKABLE void use_brake_push();
    Q_INVOKABLE void use_brake_release();
    Q_INVOKABLE void reset_state(); //Function to reset all properties and car to default state.
    Q_INVOKABLE void maintain_speed();
    Q_INVOKABLE void reorientate_to_angle(float z);
    Q_INVOKABLE void reorientate_to_pose(float x, float y);



public slots:
    void update_vilma_info(); //function to update the qml values using the ros values

signals:
    void gas_jointChanged();
    void brake_jointChanged();
    void hand_brake_jointChanged();
    void steering_jointChanged();
    void bl_wheel_speedChanged();
    void br_wheel_speedChanged();
    void fl_wheel_speedChanged();
    void fr_wheel_speedChanged();
    void gearsChanged();
    void updated_info();
    void timeout();
    void x_positionChanged();
    void y_positionChanged();
    void z_positionChanged();
    void xlinear_velChanged();
    void ylinear_velChanged();
    void zlinear_velChanged();
    void xangular_velChanged();
    void yangular_velChanged();
    void zangular_velChanged();
    void xorientationChanged();
    void yorientationChanged();
    void zorientationChanged();
    void worientationChanged();
    void latitudeChanged();
    void longitudeChanged();
    void imu_ori_xChanged();
    void imu_ori_yChanged();
    void imu_ori_zChanged();
    void imu_ori_wChanged();
    void imu_ang_vel_xChanged();
    void imu_ang_vel_yChanged();
    void imu_ang_vel_zChanged();
    void imu_lin_acel_xChanged();
    void imu_lin_acel_yChanged();
    void imu_lin_acel_zChanged();
};
#endif


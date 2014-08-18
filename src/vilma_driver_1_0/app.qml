/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
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
import QtQuick 1.1
import VilmaControlerQtSide 1.0

VilmaControlerQtSide {
    id: controler
    focus: true
    x: 0
    y: 0
    anchors.leftMargin: 0
    width: 600; height: 800

    anchors.verticalCenterOffset: 0
    anchors.horizontalCenterOffset: 0
    Component.onCompleted:
    {
        controler.reset_state();
        steering_slider.value=1;
    }
    Component.onDestruction:
    {
        if(controler.hand_brake_joint<0.5)
        {
            controler.use_hand_brake();
        }
    }


    Text {
        id:gasvalue
        x: 0
        y: 147
        width: 141
        height: 35
        anchors {
            bottom: parent.bottom; horizontalCenter: parent.horizontalCenter; bottomMargin: 618 }
        text: "Gas joint Value: 0.00" ;
        style: Text.Normal
        font.strikeout: false
        font.underline: true
        font.italic: false
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        horizontalAlignment: Text.AlignHCenter
        anchors.horizontalCenterOffset: -229

    }
    Text {
        id:brakevalue
        x: 0
        y: 601
        width: 141
        height: 35
        anchors { bottom: parent.bottom; horizontalCenter: parent.horizontalCenter; bottomMargin: 164 }
        text: "Brake Value: 0.00" ;
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: -200

    }
    Text {
        id:steeringvalue
        x: 0
        y: 534
        width: 195
        height: 35
        anchors { bottom: parent.bottom; horizontalCenter: parent.horizontalCenter; bottomMargin: 231 }
        text: "Steering joint Value: 0.00" ;
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        anchors.horizontalCenterOffset: 222
    }


    Text {
        id: br_wheel_speed
        x: 194
        y: 528
        text: qsTr("Back Right Wheel Speed: 00.00")
        font.bold: true
        font.pixelSize: 12
    }

    Text {
        id: bl_wheel_speed
        x: 21
        y: 562
        text: qsTr("Front Right Wheel Speed: 00.00")
        font.bold: true
        font.pixelSize: 12
    }

    Text {
        id: fr_wheel_speed
        x: 224
        y: 677
        text: ("Back Left Wheel Speed: 00.00")
        font.bold: true
        font.pixelSize: 12
    }

    Text {
        id: fl_wheel_speed
        x: 16
        y: 706
        text: ("Front Left Wheel Speed: 00.00")
        font.bold: true
        font.pixelSize: 14
    }
    Text {
        id: xposition
        x: 125
        y: 260
        text: "X : 00.000"
        font.pointSize: 14
        font.bold: true
    }
    Text {
        id: yposition
        x: 240
        y: 260
        text: "Y : 00.000"
        font.pointSize: 14
        font.bold: true
    }
    Text {
        id: zposition
        x: 354
        y: 260
        text: "Z : 00.000"
        font.pointSize: 14
        font.bold: true
    }
    Text {
        id: angular_velx
        x: 16
        y: 468
        text: ("X : 00.000")
        font.pointSize: 14
        font.bold: true
    }        Text {
        id: angular_vely
        x: 17
        y: 489
        text: ("Y : 00.000")
        font.pointSize: 14
        font.bold: true
    }
    Text {
        id: angular_velz
        x: 17
        y: 515
        text: ("Z : 00.000")
        font.pointSize: 14
        font.bold: true
    }
    Text {
        id: xorientation
        x: 16
        y: 393
        text: "X : 00.000"
        font.pointSize: 14
        font.bold: true
    }
    Text {
        id: yorientation
        x: 160
        y: 393
        text: "Y  00.000"
        font.pointSize: 14
        font.bold: true
    }
    Text {
        id: zorientation
        x: 319
        y: 393
        text: "Z : 00.000"
        font.pointSize: 14
        font.bold: true
    }
    Text {
        id: worientation
        x: 470
        y: 393
        text: "W : 00.000"
        font.pointSize: 14
        font.bold: true
    }

    Rectangle{
        property color onHoverColor: "gold"
        property color borderColor: "lightblue"
        color: "#6ff1d9"
        border.color: "#add9e6"
        visible: true
        width: 94; height: 35
        x: 143
        y: 142

        MouseArea {
            id: gearsbutton
            anchors.fill: parent

            Text{
                id:gearsbuttontext
                anchors.centerIn: parent
                text: "Direction"
                font.bold: true

            }
            onClicked:controler.change_gears();
            //onEntered: parent.border.color = parent.onHoverColor
            //onExited:  parent.border.color = parent.borderColor
            hoverEnabled: true


        }

    }



    onGas_jointChanged: gasvalue.text="Gas joint Value: "+controler.gas_joint;
    onBrake_jointChanged:brakevalue.text= "Brake joint Value: "+controler.brake_joint;
    onHand_brake_jointChanged:
    {
        if (controler.hand_brake_joint>0.05)
        {
            hand_brake_usebuttontext.text="Hand Brake ON "+controler.hand_brake_joint;

        }
        else
        {
            hand_brake_usebuttontext.text="Hand Brake OFF "+controler.hand_brake_joint;
        }

    }
    onX_positionChanged: xposition.text="X : "+controler.xposition;
    onY_positionChanged: yposition.text="Y : "+controler.yposition;
    onZ_positionChanged: zposition.text="Z : "+controler.zposition;
    onXlinear_velChanged: linear_velx.text="X : "+controler.xlinear_vel;
    onYlinear_velChanged: linear_vely.text="Y : "+controler.ylinear_vel;
    onZlinear_velChanged: linear_velz.text="Z : "+controler.zlinear_vel;
    onXangular_velChanged: angular_velx.text="X : "+controler.xangular_vel;
    onYangular_velChanged: angular_vely.text="Y : "+controler.yangular_vel;
    onZangular_velChanged: angular_velz.text="Z : "+controler.zangular_vel;
    onXorientationChanged: xorientation.text="X : "+controler.xorientation;
    onYorientationChanged: yorientation.text="Y : "+controler.yorientation;
    onZorientationChanged: zorientation.text="Z : "+controler.zorientation;
    onWorientationChanged: worientation.text="W : "+controler.worientation;
    onLatitudeChanged: latitude.text="Latitude : "+controler.latitude;
    onLongitudeChanged: longitude.text="Longitude : "+controler.longitude;


    onSteering_jointChanged: steeringvalue.text="Steering joint Value: "+controler.steering_joint;
    onBr_wheel_speedChanged: br_wheel_speed.text="Back Right Wheel Speed: "+controler.br_wheel_speed+"rad/s";
    onBl_wheel_speedChanged: bl_wheel_speed.text="Back Left Wheel Speed: "+controler.bl_wheel_speed+"rad/s";
    onFr_wheel_speedChanged: fr_wheel_speed.text="Front Right Wheel Speed: "+controler.fr_wheel_speed+"rad/s";
    onFl_wheel_speedChanged: fl_wheel_speed.text="Front Left Wheel Speed: "+controler.fl_wheel_speed+"rad/s";
    onGearsChanged:
    {
        if (controler.gears>0.5)
        {
            gearsbuttontext.text = "Forward"
        }
        else if(controler.gears<0.3&&controler.gears>-0.3)
        {
            gearsbuttontext.text = "Neutral"

        }
        else
        {
            gearsbuttontext.text = "Backwards"
        }
    }


    Rectangle{
        property color onHoverColor: "gold"
        property color borderColor: "lightblue"
        color: "#71f1da"
        border.color: borderColor
        visible: true
        width: 118; height: 35
        x: 1
        y: 69
        MouseArea {
            id: gas_increase
            enabled: true
            anchors.fill: parent
            onClicked:
            {
                controler.accelerate();
            }
            //onEntered: parent.border.color = parent.onHoverColor
            //onExited:  parent.border.color = parent.borderColor
            hoverEnabled: true

            Text{
                text: "increase Gas"
                font.bold: true
                anchors.centerIn: parent
            }
        }
    }
    Rectangle{
        property color onHoverColor: "gold"
        property color borderColor: "lightblue"
        color: "#6ff1d9"
        border.color: borderColor
        visible: true
        width: 118; height: 35
        x: 1
        y: 106
        MouseArea {
            id: gas_decrease
            anchors.fill: parent

            onClicked:
            {
                controler.deaccelerate();
            }
            //onEntered: parent.border.color = parent.onHoverColor
            //onExited:  parent.border.color = parent.borderColor
            hoverEnabled: true

            Text{
                color: "#000000"
                text: "Decrease Gas"
                font.bold: true
                anchors.centerIn: parent
            }
        }}
    Rectangle{
        property color onHoverColor: "gold"
        property color borderColor: "lightblue"
        anchors.left: parent.left
        anchors.leftMargin: 121
        anchors.top: parent.top
        anchors.topMargin: 69
        border.color: borderColor
        visible: true
        width: 116; height: 35
        color: "#6ff1d9"
        MouseArea {
            id: brake_increase

            anchors.fill: parent
            Text{
                text: "Increase Brake"
                font.bold: true
                anchors.centerIn: parent
            }
            onClicked:
            {
                controler.use_brake_push();
            }
            hoverEnabled: true
            //onEntered: parent.border.color = parent.onHoverColor
            //onExited:  parent.border.color = parent.borderColor

        }}

    Rectangle{
        property color onHoverColor: "gold"
        property color borderColor: "lightblue"
        color: "#6ff1d9"
        border.color: borderColor
        visible: true
        width: 116; height: 35
        x: 121
        y: 106
        MouseArea {
            id: brake_decrease
            anchors.rightMargin: -1
            anchors.bottomMargin: 0
            anchors.leftMargin: 1
            anchors.topMargin: 0

            anchors.fill: parent
            Text{
                text: "Decrease Brake"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                anchors.centerIn: parent

            }
            onClicked:
            {
                controler.use_brake_release();
            }
            hoverEnabled: true
            //onEntered: parent.border.color = parent.onHoverColor
            //onExited:  parent.border.color = parent.borderColor
        }}
    Rectangle{
        property color onHoverColor: "gold"
        property color borderColor: "lightblue"
        color: "#6ff1d9"
        border.color: borderColor
        visible: true
        width: 142; height: 35
        x: 0
        y: 142

        MouseArea {
            id: hand_brake_usebutton
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent
            Text{ id:hand_brake_usebuttontext
                text: "Hand Brake ON 000"
                font.bold: true
                anchors.centerIn: parent
            }
            onClicked:{
                controler.use_hand_brake();
            }
            hoverEnabled: true
            //onEntered: parent.border.color = parent.onHoverColor
            //onExited:  parent.border.color = parent.borderColor
        }

    }
    Rectangle{
        property color onHoverColor: "gold"
        property color borderColor: "lightblue"
        color: "#6ff1d9"
        border.color: borderColor
        visible: true
        width: 139; height: 35
        x: 234
        y: 69
        MouseArea {
            id: reset_state
            anchors.fill: parent
            Text{
                text: "RESET CAR STATE"
                font.bold: true
                anchors.centerIn: parent
            }

            onClicked:{
                controler.reset_state();
                steering_slider.value=1;

            }
            //onEntered: parent.border.color = parent.onHoverColor
            //onExited:  parent.border.color = parent.borderColor
            hoverEnabled: true

        }}
    Rectangle{
        property color onHoverColor: "gold"
        property color borderColor: "lightblue"
        color: "#6ff1d9"
        border.color: borderColor
        visible: true
        width: 166; height: 35
        x: 237
        y: 106
        MouseArea {
            id: maintain_speed
            anchors.fill: parent
            Text{
                text: "MAINTAIN CAR SPEED"
                font.bold: true
                anchors.centerIn: parent
            }

            onClicked:{
                controler.maintain_speed();

            }
            //onEntered: parent.border.color = parent.onHoverColor
            //onExited:  parent.border.color = parent.borderColor
            hoverEnabled: true

        }}

    Keys.onPressed: {
        if (event.key === Qt.Key_W)
        {
            if(controler.brake_joint>0.005)
            {
                controler.use_brake_release();
            }
            else
            {
                controler.accelerate();
            }
        }
        if (event.key === Qt.Key_S)
            if(controler.gas_joint>0.005)
            {
                controler.deaccelerate();
            }
            else
            {
                controler.use_brake_push();
            }
        if (event.key === Qt.Key_A)
        {
            if(steering_slider.value>0)
                steering_slider.value=steering_slider.value-0.1;
        }
        if (event.key === Qt.Key_D)
        {
            if(steering_slider.value<2)
                steering_slider.value=steering_slider.value+0.1;
        }
        if (event.key === Qt.Key_H)
        {
            controler.use_hand_brake();
        }
        if (event.key === Qt.Key_R)
        {
            controler.reset_state();
            steering_slider.value=1;
        }
        if (event.key === Qt.Key_G)
        {
            controler.change_gears();
        }
    }

    Item  { //Code from http://qt-project.org/doc/qt-4.7/demos-declarative-flickr-common-slider-qml.html
        id: steering_slider; width: 146
        height: 29

        x: 247
        y: 145

        // value is read/write.
        property real value: 1
        property real maximum: 2
        property real minimum: 0
        onValueChanged:
        {
            updatePos();
            if (value>1)
            {
                controler.use_Steering(-(value-1)*3.14)
                steering_joint_exported_value.text="Value being published to the steering: "+(-(value-1)*3.14)
            }
            else
            {
                steering_joint_exported_value.text="Value being published to the steering: "+(-(value-1)*(3.14))
                controler.use_Steering(-(value-1)*(3.14))
            }
        }

        property int xMax: width - handle.width - 4
        onXMaxChanged: updatePos();
        onMinimumChanged: updatePos();

        function updatePos()  {
            if (maximum > minimum)  {
                var pos = 2 + (value - minimum) * steering_slider.xMax / (maximum - minimum);
                pos = Math.min(pos, width - handle.width - 2);
                pos = Math.max(pos, 2);
                handle.x = pos;
            } else  {
                handle.x = 2;
            }
        }

        Rectangle  {
            color: "#3afc36"
            anchors.fill: parent
            border.color: "#de5b5b"; border.width: 0; radius: 8
        }

        Rectangle  {
            id: handle; smooth: true
            y: 2; width: 30; height: steering_slider.height-4; color: "#6ff1d9"; radius: 6

            MouseArea  {
                id: mouse
                anchors.fill: parent; drag.target: parent
                drag.axis: Drag.XAxis; drag.minimumX: 2; drag.maximumX: steering_slider.xMax+2
                onPositionChanged:  { steering_slider.value = (steering_slider.maximum - steering_slider.minimum) * (handle.x-2) / steering_slider.xMax + steering_slider.minimum; }
            }
        }

    }





    Text {

        id: steering_joint_exported_value
        x: 200
        y: 611
        text: ("Value being published to the steering: 00.00")
        font.bold: true
        font.pixelSize: 12
    }

    Rectangle {
        id: controls_rectangle
        x: 0
        y: 0
        width: 600
        height: 191
        color: "#ff6b6b"
        z: -1
    }

    Text {
        id: text1
        x: 224
        y: 19
        color: "#011fba"
        text: qsTr("Controls")
        font.family: "Tahoma"
        font.underline: true
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 24
        font.bold: true
    }

    Rectangle {
        id: rectangle2
        x: 2
        y: 188
        width: 600
        height: 590
        color: "#f6c2c2"
        z: -2
    }

    Text {
        id: text3
        x: 181
        y: 188
        color: "#011fbc"
        text: qsTr("Vehicle State")
        verticalAlignment: Text.AlignVCenter
        font.underline: true
        font.bold: true
        font.family: "Tahoma"
        font.pointSize: 24
        horizontalAlignment: Text.AlignHCenter
    }

    Rectangle {
        id: rectangle1
        x: 0
        y: 226
        width: 604
        height: 286
        color: "#db29a9"
        radius: 3
        border.width: 2
        border.color: "#e99797"
        z: -2
    }

    Rectangle {
        id: rectangle3
        x: 8
        y: 226
        width: 586
        height: 113
        color: "#db29a9"
        radius: 0
        border.width: 6
        border.color: "#fbe5e5"
        z: -1
    }

    Text {
        id: text4
        x: 233
        y: 226
        color: "#3811a6"
        text: qsTr("Cartesian")
        font.bold: true
        font.pointSize: 19
    }

    Rectangle {
        id: rectangle4
        x: 8
        y: 345
        width: 586
        height: 81
        color: "#db29a9"
        radius: 0
        border.width: 6
        border.color: "#fbe5e5"
        z: -1
    }

    Text {
        id: text5
        x: 234
        y: 354
        color: "#3811a6"
        text: qsTr("Quaternion")
        font.bold: true
        font.pointSize: 19
    }

    Rectangle {
        id: rectangle5
        x: 8
        y: 428
        width: 586
        height: 110
        color: "#db29a9"
        radius: 0
        border.width: 6
        border.color: "#fbe5e5"
        z: -1
    }

    Text {
        id: text6
        x: 256
        y: 432
        color: "#3811a6"
        text: qsTr("Speed")
        font.bold: true
        font.pointSize: 19
    }

    Text {
        id: text7
        x: 16
        y: 432
        color: "#3811a6"
        text: qsTr("Angular")
        font.bold: true
        font.pointSize: 19
    }

    Text {
        id: text8
        x: 434
        y: 432
        color: "#3811a6"
        text: qsTr("Linear")
        font.bold: true
        font.pointSize: 19
    }

    Text {
        id: text9
        x: 266
        y: 282
        color: "#3811a6"
        text: qsTr("GPS")
        font.bold: true
        font.pointSize: 19
    }

    Text {
        id: latitude
        x: 14
        y: 310
        text: "Latitude : 00.000000000"
        font.bold: true
        font.pointSize: 14
    }

    Text {
        id: longitude
        x: 301
        y: 310
        text: "Longitude : 00.000000000"
        font.bold: true
        font.pointSize: 14
    }

    Text {
        id: linear_velx
        x: 434
        y: 468
        text: ("X : 00.000")
        font.bold: true
        font.pointSize: 14
    }

    Text {
        id: linear_vely
        x: 435
        y: 489
        text: ("Y : 00.000")
        font.bold: true
        font.pointSize: 14
    }

    Text {
        id: linear_velz
        x: 435
        y: 515
        text: ("Z : 00.000")
        font.bold: true
        font.pointSize: 14
    }


}
//}
//![0]

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDockWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAccelerator;
    QAction *actionBrake;
    QWidget *MainWidget;
    QMenuBar *menuBar;
    QMenu *menuView;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;
    QDockWidget *CarStatusWidget;
    QWidget *CarStatusWidget_contents;
    QWidget *widget;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *Position_gazebo;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *gazebo_x;
    QLabel *gazebo_y;
    QLabel *gazebo_z;
    QVBoxLayout *Position_gps;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *latitude;
    QLabel *longitude;
    QVBoxLayout *Quaternion;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_7;
    QLabel *quaternion_gazebo_x;
    QLabel *quaternion_gazebo_y;
    QLabel *quaternion_gazebo_z;
    QLabel *quaternion_gazebo_w;
    QVBoxLayout *IMU_quat;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout_8;
    QLabel *quaternion_imu_x;
    QLabel *quaternion_imu_y;
    QLabel *quaternion_imu_z;
    QLabel *quaternion_imu_w;
    QVBoxLayout *IMU_ang_vel;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_9;
    QLabel *imu_ang_speed_x;
    QLabel *imu_ang_speed_y;
    QLabel *imu_ang_speed_z;
    QVBoxLayout *IMU_lin_acel;
    QLabel *label_26;
    QHBoxLayout *horizontalLayout_10;
    QLabel *imu_lin_acel_x;
    QLabel *imu_lin_acel_y;
    QLabel *imu_lin_acel_z;
    QVBoxLayout *Lin_vel_gazebo;
    QLabel *label_34;
    QHBoxLayout *horizontalLayout_12;
    QLabel *gazebo_lin_vel_x;
    QLabel *gazebo_lin_vel_y;
    QLabel *gazebo_lin_vel_z;
    QVBoxLayout *Ang_vel_gazebo;
    QLabel *label_38;
    QHBoxLayout *horizontalLayout_13;
    QLabel *gazebo_ang_vel_x;
    QLabel *gazebo_ang_vel_y;
    QLabel *gazebo_ang_vel_z;
    QVBoxLayout *imu_euler;
    QLabel *imu_euler_z_rotation_label;
    QLabel *imu_euler_z_rotation_value;
    QDockWidget *ManualControlsWidget;
    QWidget *ManualControlsWidget_contents;
    QDockWidget *BrakeDock;
    QWidget *dockWidgetContents_4;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *current_brake_label;
    QSlider *current_brake_slider;
    QDockWidget *AccelerationDock;
    QWidget *dockWidgetContents_3;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QLabel *current_acel_label;
    QSlider *current_acel_label_slider;
    QDockWidget *GearWidget;
    QWidget *dockWidgetContents_7;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *gears_forward_radio_button;
    QRadioButton *gears_neutral_radio_button;
    QRadioButton *gears_backwards_radio_button;
    QDockWidget *HandBrakeDock;
    QWidget *dockWidgetContents_5;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *handbrake_label;
    QPushButton *handbrake_button;
    QDockWidget *SteeringDock;
    QWidget *dockWidgetContents_9;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *steering_status_label;
    QSlider *steering_slider;
    QDockWidget *AutomationWidget;
    QWidget *dockWidgetContents;
    QPushButton *Set_wheel_direction_button;
    QLineEdit *Set_wheel_direction_x_input;
    QLineEdit *Set_wheel_direction_y_input;
    QTableWidget *Set_wheel_direction_table;
    QCheckBox *Set_wheel_direction_from_table;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *Constant_speed_button;
    QRadioButton *Maintain_current_speed;
    QRadioButton *Set_new_speed;
    QLineEdit *Enter_new_constant_speed;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1255, 771);
        actionAccelerator = new QAction(MainWindow);
        actionAccelerator->setObjectName(QString::fromUtf8("actionAccelerator"));
        actionAccelerator->setCheckable(true);
        actionAccelerator->setChecked(true);
        actionBrake = new QAction(MainWindow);
        actionBrake->setObjectName(QString::fromUtf8("actionBrake"));
        actionBrake->setCheckable(true);
        MainWidget = new QWidget(MainWindow);
        MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWindow->setCentralWidget(MainWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1255, 20));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        CarStatusWidget = new QDockWidget(MainWindow);
        CarStatusWidget->setObjectName(QString::fromUtf8("CarStatusWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CarStatusWidget->sizePolicy().hasHeightForWidth());
        CarStatusWidget->setSizePolicy(sizePolicy);
        CarStatusWidget->setMinimumSize(QSize(384, 600));
        CarStatusWidget->setMaximumSize(QSize(384, 600));
        CarStatusWidget_contents = new QWidget();
        CarStatusWidget_contents->setObjectName(QString::fromUtf8("CarStatusWidget_contents"));
        widget = new QWidget(CarStatusWidget_contents);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(12, 16, 356, 498));
        verticalLayout_6 = new QVBoxLayout(widget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        Position_gazebo = new QVBoxLayout();
        Position_gazebo->setSpacing(6);
        Position_gazebo->setObjectName(QString::fromUtf8("Position_gazebo"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        Position_gazebo->addWidget(label_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        gazebo_x = new QLabel(widget);
        gazebo_x->setObjectName(QString::fromUtf8("gazebo_x"));

        horizontalLayout_5->addWidget(gazebo_x);

        gazebo_y = new QLabel(widget);
        gazebo_y->setObjectName(QString::fromUtf8("gazebo_y"));

        horizontalLayout_5->addWidget(gazebo_y);

        gazebo_z = new QLabel(widget);
        gazebo_z->setObjectName(QString::fromUtf8("gazebo_z"));

        horizontalLayout_5->addWidget(gazebo_z);


        Position_gazebo->addLayout(horizontalLayout_5);


        verticalLayout_6->addLayout(Position_gazebo);

        Position_gps = new QVBoxLayout();
        Position_gps->setSpacing(6);
        Position_gps->setObjectName(QString::fromUtf8("Position_gps"));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        Position_gps->addWidget(label_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        latitude = new QLabel(widget);
        latitude->setObjectName(QString::fromUtf8("latitude"));

        horizontalLayout_6->addWidget(latitude);

        longitude = new QLabel(widget);
        longitude->setObjectName(QString::fromUtf8("longitude"));

        horizontalLayout_6->addWidget(longitude);


        Position_gps->addLayout(horizontalLayout_6);


        verticalLayout_6->addLayout(Position_gps);

        Quaternion = new QVBoxLayout();
        Quaternion->setSpacing(6);
        Quaternion->setObjectName(QString::fromUtf8("Quaternion"));
        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        Quaternion->addWidget(label_12);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        quaternion_gazebo_x = new QLabel(widget);
        quaternion_gazebo_x->setObjectName(QString::fromUtf8("quaternion_gazebo_x"));

        horizontalLayout_7->addWidget(quaternion_gazebo_x);

        quaternion_gazebo_y = new QLabel(widget);
        quaternion_gazebo_y->setObjectName(QString::fromUtf8("quaternion_gazebo_y"));

        horizontalLayout_7->addWidget(quaternion_gazebo_y);

        quaternion_gazebo_z = new QLabel(widget);
        quaternion_gazebo_z->setObjectName(QString::fromUtf8("quaternion_gazebo_z"));

        horizontalLayout_7->addWidget(quaternion_gazebo_z);

        quaternion_gazebo_w = new QLabel(widget);
        quaternion_gazebo_w->setObjectName(QString::fromUtf8("quaternion_gazebo_w"));

        horizontalLayout_7->addWidget(quaternion_gazebo_w);


        Quaternion->addLayout(horizontalLayout_7);


        verticalLayout_6->addLayout(Quaternion);

        IMU_quat = new QVBoxLayout();
        IMU_quat->setSpacing(6);
        IMU_quat->setObjectName(QString::fromUtf8("IMU_quat"));
        label_17 = new QLabel(widget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        IMU_quat->addWidget(label_17);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        quaternion_imu_x = new QLabel(widget);
        quaternion_imu_x->setObjectName(QString::fromUtf8("quaternion_imu_x"));

        horizontalLayout_8->addWidget(quaternion_imu_x);

        quaternion_imu_y = new QLabel(widget);
        quaternion_imu_y->setObjectName(QString::fromUtf8("quaternion_imu_y"));

        horizontalLayout_8->addWidget(quaternion_imu_y);

        quaternion_imu_z = new QLabel(widget);
        quaternion_imu_z->setObjectName(QString::fromUtf8("quaternion_imu_z"));

        horizontalLayout_8->addWidget(quaternion_imu_z);

        quaternion_imu_w = new QLabel(widget);
        quaternion_imu_w->setObjectName(QString::fromUtf8("quaternion_imu_w"));

        horizontalLayout_8->addWidget(quaternion_imu_w);


        IMU_quat->addLayout(horizontalLayout_8);


        verticalLayout_6->addLayout(IMU_quat);

        IMU_ang_vel = new QVBoxLayout();
        IMU_ang_vel->setSpacing(6);
        IMU_ang_vel->setObjectName(QString::fromUtf8("IMU_ang_vel"));
        label_22 = new QLabel(widget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setAlignment(Qt::AlignCenter);

        IMU_ang_vel->addWidget(label_22);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        imu_ang_speed_x = new QLabel(widget);
        imu_ang_speed_x->setObjectName(QString::fromUtf8("imu_ang_speed_x"));

        horizontalLayout_9->addWidget(imu_ang_speed_x);

        imu_ang_speed_y = new QLabel(widget);
        imu_ang_speed_y->setObjectName(QString::fromUtf8("imu_ang_speed_y"));

        horizontalLayout_9->addWidget(imu_ang_speed_y);

        imu_ang_speed_z = new QLabel(widget);
        imu_ang_speed_z->setObjectName(QString::fromUtf8("imu_ang_speed_z"));

        horizontalLayout_9->addWidget(imu_ang_speed_z);


        IMU_ang_vel->addLayout(horizontalLayout_9);


        verticalLayout_6->addLayout(IMU_ang_vel);

        IMU_lin_acel = new QVBoxLayout();
        IMU_lin_acel->setSpacing(6);
        IMU_lin_acel->setObjectName(QString::fromUtf8("IMU_lin_acel"));
        label_26 = new QLabel(widget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setAlignment(Qt::AlignCenter);

        IMU_lin_acel->addWidget(label_26);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        imu_lin_acel_x = new QLabel(widget);
        imu_lin_acel_x->setObjectName(QString::fromUtf8("imu_lin_acel_x"));

        horizontalLayout_10->addWidget(imu_lin_acel_x);

        imu_lin_acel_y = new QLabel(widget);
        imu_lin_acel_y->setObjectName(QString::fromUtf8("imu_lin_acel_y"));

        horizontalLayout_10->addWidget(imu_lin_acel_y);

        imu_lin_acel_z = new QLabel(widget);
        imu_lin_acel_z->setObjectName(QString::fromUtf8("imu_lin_acel_z"));

        horizontalLayout_10->addWidget(imu_lin_acel_z);


        IMU_lin_acel->addLayout(horizontalLayout_10);


        verticalLayout_6->addLayout(IMU_lin_acel);

        Lin_vel_gazebo = new QVBoxLayout();
        Lin_vel_gazebo->setSpacing(6);
        Lin_vel_gazebo->setObjectName(QString::fromUtf8("Lin_vel_gazebo"));
        label_34 = new QLabel(widget);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setAlignment(Qt::AlignCenter);

        Lin_vel_gazebo->addWidget(label_34);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        gazebo_lin_vel_x = new QLabel(widget);
        gazebo_lin_vel_x->setObjectName(QString::fromUtf8("gazebo_lin_vel_x"));

        horizontalLayout_12->addWidget(gazebo_lin_vel_x);

        gazebo_lin_vel_y = new QLabel(widget);
        gazebo_lin_vel_y->setObjectName(QString::fromUtf8("gazebo_lin_vel_y"));

        horizontalLayout_12->addWidget(gazebo_lin_vel_y);

        gazebo_lin_vel_z = new QLabel(widget);
        gazebo_lin_vel_z->setObjectName(QString::fromUtf8("gazebo_lin_vel_z"));

        horizontalLayout_12->addWidget(gazebo_lin_vel_z);


        Lin_vel_gazebo->addLayout(horizontalLayout_12);


        verticalLayout_6->addLayout(Lin_vel_gazebo);

        Ang_vel_gazebo = new QVBoxLayout();
        Ang_vel_gazebo->setSpacing(6);
        Ang_vel_gazebo->setObjectName(QString::fromUtf8("Ang_vel_gazebo"));
        label_38 = new QLabel(widget);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setAlignment(Qt::AlignCenter);

        Ang_vel_gazebo->addWidget(label_38);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        gazebo_ang_vel_x = new QLabel(widget);
        gazebo_ang_vel_x->setObjectName(QString::fromUtf8("gazebo_ang_vel_x"));

        horizontalLayout_13->addWidget(gazebo_ang_vel_x);

        gazebo_ang_vel_y = new QLabel(widget);
        gazebo_ang_vel_y->setObjectName(QString::fromUtf8("gazebo_ang_vel_y"));

        horizontalLayout_13->addWidget(gazebo_ang_vel_y);

        gazebo_ang_vel_z = new QLabel(widget);
        gazebo_ang_vel_z->setObjectName(QString::fromUtf8("gazebo_ang_vel_z"));

        horizontalLayout_13->addWidget(gazebo_ang_vel_z);


        Ang_vel_gazebo->addLayout(horizontalLayout_13);


        verticalLayout_6->addLayout(Ang_vel_gazebo);

        imu_euler = new QVBoxLayout();
        imu_euler->setSpacing(6);
        imu_euler->setObjectName(QString::fromUtf8("imu_euler"));
        imu_euler_z_rotation_label = new QLabel(widget);
        imu_euler_z_rotation_label->setObjectName(QString::fromUtf8("imu_euler_z_rotation_label"));
        imu_euler_z_rotation_label->setAlignment(Qt::AlignCenter);

        imu_euler->addWidget(imu_euler_z_rotation_label);

        imu_euler_z_rotation_value = new QLabel(widget);
        imu_euler_z_rotation_value->setObjectName(QString::fromUtf8("imu_euler_z_rotation_value"));
        imu_euler_z_rotation_value->setAlignment(Qt::AlignCenter);

        imu_euler->addWidget(imu_euler_z_rotation_value);


        verticalLayout_6->addLayout(imu_euler);

        CarStatusWidget->setWidget(CarStatusWidget_contents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), CarStatusWidget);
        ManualControlsWidget = new QDockWidget(MainWindow);
        ManualControlsWidget->setObjectName(QString::fromUtf8("ManualControlsWidget"));
        sizePolicy.setHeightForWidth(ManualControlsWidget->sizePolicy().hasHeightForWidth());
        ManualControlsWidget->setSizePolicy(sizePolicy);
        ManualControlsWidget->setMinimumSize(QSize(850, 300));
        ManualControlsWidget->setMaximumSize(QSize(850, 300));
        ManualControlsWidget->setAutoFillBackground(false);
        ManualControlsWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
        ManualControlsWidget_contents = new QWidget();
        ManualControlsWidget_contents->setObjectName(QString::fromUtf8("ManualControlsWidget_contents"));
        BrakeDock = new QDockWidget(ManualControlsWidget_contents);
        BrakeDock->setObjectName(QString::fromUtf8("BrakeDock"));
        BrakeDock->setGeometry(QRect(409, 11, 423, 80));
        sizePolicy.setHeightForWidth(BrakeDock->sizePolicy().hasHeightForWidth());
        BrakeDock->setSizePolicy(sizePolicy);
        BrakeDock->setMinimumSize(QSize(423, 80));
        BrakeDock->setFloating(false);
        BrakeDock->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        layoutWidget2 = new QWidget(dockWidgetContents_4);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 367, 50));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        current_brake_label = new QLabel(layoutWidget2);
        current_brake_label->setObjectName(QString::fromUtf8("current_brake_label"));
        current_brake_label->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(current_brake_label->sizePolicy().hasHeightForWidth());
        current_brake_label->setSizePolicy(sizePolicy1);
        current_brake_label->setFrameShape(QFrame::Box);
        current_brake_label->setTextFormat(Qt::AutoText);
        current_brake_label->setScaledContents(true);
        current_brake_label->setWordWrap(false);

        verticalLayout_3->addWidget(current_brake_label);

        current_brake_slider = new QSlider(layoutWidget2);
        current_brake_slider->setObjectName(QString::fromUtf8("current_brake_slider"));
        sizePolicy1.setHeightForWidth(current_brake_slider->sizePolicy().hasHeightForWidth());
        current_brake_slider->setSizePolicy(sizePolicy1);
        current_brake_slider->setMaximum(100);
        current_brake_slider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(current_brake_slider);

        BrakeDock->setWidget(dockWidgetContents_4);
        AccelerationDock = new QDockWidget(ManualControlsWidget_contents);
        AccelerationDock->setObjectName(QString::fromUtf8("AccelerationDock"));
        AccelerationDock->setGeometry(QRect(11, 11, 392, 80));
        sizePolicy.setHeightForWidth(AccelerationDock->sizePolicy().hasHeightForWidth());
        AccelerationDock->setSizePolicy(sizePolicy);
        AccelerationDock->setMinimumSize(QSize(392, 80));
        AccelerationDock->setFloating(false);
        AccelerationDock->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        layoutWidget3 = new QWidget(dockWidgetContents_3);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 0, 367, 55));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        current_acel_label = new QLabel(layoutWidget3);
        current_acel_label->setObjectName(QString::fromUtf8("current_acel_label"));
        current_acel_label->setEnabled(true);
        sizePolicy1.setHeightForWidth(current_acel_label->sizePolicy().hasHeightForWidth());
        current_acel_label->setSizePolicy(sizePolicy1);
        current_acel_label->setFrameShape(QFrame::Box);
        current_acel_label->setTextFormat(Qt::AutoText);
        current_acel_label->setScaledContents(true);
        current_acel_label->setWordWrap(false);

        verticalLayout->addWidget(current_acel_label);

        current_acel_label_slider = new QSlider(layoutWidget3);
        current_acel_label_slider->setObjectName(QString::fromUtf8("current_acel_label_slider"));
        sizePolicy1.setHeightForWidth(current_acel_label_slider->sizePolicy().hasHeightForWidth());
        current_acel_label_slider->setSizePolicy(sizePolicy1);
        current_acel_label_slider->setMaximum(100);
        current_acel_label_slider->setOrientation(Qt::Horizontal);
        current_acel_label_slider->setTickPosition(QSlider::NoTicks);

        verticalLayout->addWidget(current_acel_label_slider);

        AccelerationDock->setWidget(dockWidgetContents_3);
        GearWidget = new QDockWidget(ManualControlsWidget_contents);
        GearWidget->setObjectName(QString::fromUtf8("GearWidget"));
        GearWidget->setGeometry(QRect(409, 97, 423, 100));
        sizePolicy.setHeightForWidth(GearWidget->sizePolicy().hasHeightForWidth());
        GearWidget->setSizePolicy(sizePolicy);
        GearWidget->setMinimumSize(QSize(423, 100));
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName(QString::fromUtf8("dockWidgetContents_7"));
        horizontalLayout_4 = new QHBoxLayout(dockWidgetContents_7);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gears_forward_radio_button = new QRadioButton(dockWidgetContents_7);
        gears_forward_radio_button->setObjectName(QString::fromUtf8("gears_forward_radio_button"));
        gears_forward_radio_button->setChecked(true);

        horizontalLayout_3->addWidget(gears_forward_radio_button);

        gears_neutral_radio_button = new QRadioButton(dockWidgetContents_7);
        gears_neutral_radio_button->setObjectName(QString::fromUtf8("gears_neutral_radio_button"));

        horizontalLayout_3->addWidget(gears_neutral_radio_button);

        gears_backwards_radio_button = new QRadioButton(dockWidgetContents_7);
        gears_backwards_radio_button->setObjectName(QString::fromUtf8("gears_backwards_radio_button"));

        horizontalLayout_3->addWidget(gears_backwards_radio_button);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        GearWidget->setWidget(dockWidgetContents_7);
        HandBrakeDock = new QDockWidget(ManualControlsWidget_contents);
        HandBrakeDock->setObjectName(QString::fromUtf8("HandBrakeDock"));
        HandBrakeDock->setGeometry(QRect(11, 97, 392, 100));
        sizePolicy.setHeightForWidth(HandBrakeDock->sizePolicy().hasHeightForWidth());
        HandBrakeDock->setSizePolicy(sizePolicy);
        HandBrakeDock->setMinimumSize(QSize(392, 100));
        HandBrakeDock->setFloating(false);
        HandBrakeDock->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QString::fromUtf8("dockWidgetContents_5"));
        horizontalLayout_2 = new QHBoxLayout(dockWidgetContents_5);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        handbrake_label = new QLabel(dockWidgetContents_5);
        handbrake_label->setObjectName(QString::fromUtf8("handbrake_label"));
        handbrake_label->setEnabled(true);
        sizePolicy1.setHeightForWidth(handbrake_label->sizePolicy().hasHeightForWidth());
        handbrake_label->setSizePolicy(sizePolicy1);
        handbrake_label->setFrameShape(QFrame::Box);
        handbrake_label->setTextFormat(Qt::AutoText);
        handbrake_label->setScaledContents(true);
        handbrake_label->setWordWrap(false);

        horizontalLayout->addWidget(handbrake_label);

        handbrake_button = new QPushButton(dockWidgetContents_5);
        handbrake_button->setObjectName(QString::fromUtf8("handbrake_button"));
        sizePolicy1.setHeightForWidth(handbrake_button->sizePolicy().hasHeightForWidth());
        handbrake_button->setSizePolicy(sizePolicy1);
        handbrake_button->setCheckable(true);
        handbrake_button->setChecked(false);
        handbrake_button->setAutoDefault(false);
        handbrake_button->setDefault(false);
        handbrake_button->setFlat(false);

        horizontalLayout->addWidget(handbrake_button);


        horizontalLayout_2->addLayout(horizontalLayout);

        HandBrakeDock->setWidget(dockWidgetContents_5);
        SteeringDock = new QDockWidget(ManualControlsWidget_contents);
        SteeringDock->setObjectName(QString::fromUtf8("SteeringDock"));
        SteeringDock->setGeometry(QRect(10, 204, 821, 85));
        sizePolicy.setHeightForWidth(SteeringDock->sizePolicy().hasHeightForWidth());
        SteeringDock->setSizePolicy(sizePolicy);
        SteeringDock->setMinimumSize(QSize(821, 85));
        SteeringDock->setMaximumSize(QSize(821, 85));
        dockWidgetContents_9 = new QWidget();
        dockWidgetContents_9->setObjectName(QString::fromUtf8("dockWidgetContents_9"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents_9);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        steering_status_label = new QLabel(dockWidgetContents_9);
        steering_status_label->setObjectName(QString::fromUtf8("steering_status_label"));
        steering_status_label->setScaledContents(true);
        steering_status_label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(steering_status_label);

        steering_slider = new QSlider(dockWidgetContents_9);
        steering_slider->setObjectName(QString::fromUtf8("steering_slider"));
        steering_slider->setMinimum(-314);
        steering_slider->setMaximum(314);
        steering_slider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(steering_slider);


        verticalLayout_5->addLayout(verticalLayout_2);

        SteeringDock->setWidget(dockWidgetContents_9);
        ManualControlsWidget->setWidget(ManualControlsWidget_contents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), ManualControlsWidget);
        AutomationWidget = new QDockWidget(MainWindow);
        AutomationWidget->setObjectName(QString::fromUtf8("AutomationWidget"));
        AutomationWidget->setMinimumSize(QSize(850, 400));
        AutomationWidget->setMaximumSize(QSize(850, 400));
        AutomationWidget->setLayoutDirection(Qt::LeftToRight);
        AutomationWidget->setAutoFillBackground(true);
        AutomationWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        Set_wheel_direction_button = new QPushButton(dockWidgetContents);
        Set_wheel_direction_button->setObjectName(QString::fromUtf8("Set_wheel_direction_button"));
        Set_wheel_direction_button->setGeometry(QRect(20, 50, 171, 23));
        Set_wheel_direction_button->setCheckable(true);
        Set_wheel_direction_button->setAutoRepeat(true);
        Set_wheel_direction_button->setAutoDefault(false);
        Set_wheel_direction_x_input = new QLineEdit(dockWidgetContents);
        Set_wheel_direction_x_input->setObjectName(QString::fromUtf8("Set_wheel_direction_x_input"));
        Set_wheel_direction_x_input->setGeometry(QRect(200, 50, 113, 23));
        Set_wheel_direction_x_input->setCursorPosition(0);
        Set_wheel_direction_y_input = new QLineEdit(dockWidgetContents);
        Set_wheel_direction_y_input->setObjectName(QString::fromUtf8("Set_wheel_direction_y_input"));
        Set_wheel_direction_y_input->setGeometry(QRect(320, 50, 113, 23));
        Set_wheel_direction_table = new QTableWidget(dockWidgetContents);
        if (Set_wheel_direction_table->columnCount() < 3)
            Set_wheel_direction_table->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Set_wheel_direction_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Set_wheel_direction_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Set_wheel_direction_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (Set_wheel_direction_table->rowCount() < 100)
            Set_wheel_direction_table->setRowCount(100);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(6, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(7, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(8, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        Set_wheel_direction_table->setItem(0, 2, __qtablewidgetitem12);
        Set_wheel_direction_table->setObjectName(QString::fromUtf8("Set_wheel_direction_table"));
        Set_wheel_direction_table->setEnabled(false);
        Set_wheel_direction_table->setGeometry(QRect(100, 110, 581, 151));
        Set_wheel_direction_table->setRowCount(100);
        Set_wheel_direction_from_table = new QCheckBox(dockWidgetContents);
        Set_wheel_direction_from_table->setObjectName(QString::fromUtf8("Set_wheel_direction_from_table"));
        Set_wheel_direction_from_table->setGeometry(QRect(440, 50, 91, 21));
        layoutWidget4 = new QWidget(dockWidgetContents);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 10, 511, 31));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        Constant_speed_button = new QPushButton(layoutWidget4);
        Constant_speed_button->setObjectName(QString::fromUtf8("Constant_speed_button"));
        Constant_speed_button->setCheckable(true);

        horizontalLayout_11->addWidget(Constant_speed_button);

        Maintain_current_speed = new QRadioButton(layoutWidget4);
        Maintain_current_speed->setObjectName(QString::fromUtf8("Maintain_current_speed"));
        Maintain_current_speed->setEnabled(false);

        horizontalLayout_11->addWidget(Maintain_current_speed);

        Set_new_speed = new QRadioButton(layoutWidget4);
        Set_new_speed->setObjectName(QString::fromUtf8("Set_new_speed"));
        Set_new_speed->setEnabled(false);

        horizontalLayout_11->addWidget(Set_new_speed);

        Enter_new_constant_speed = new QLineEdit(layoutWidget4);
        Enter_new_constant_speed->setObjectName(QString::fromUtf8("Enter_new_constant_speed"));
        Enter_new_constant_speed->setEnabled(false);

        horizontalLayout_11->addWidget(Enter_new_constant_speed);

        AutomationWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), AutomationWidget);

        menuBar->addAction(menuView->menuAction());
        menuView->addAction(actionAccelerator);
        menuView->addAction(actionBrake);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Vilma Driver", 0, QApplication::UnicodeUTF8));
        actionAccelerator->setText(QApplication::translate("MainWindow", "Accelerator", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAccelerator->setToolTip(QApplication::translate("MainWindow", "Show Accelerator Widget", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionBrake->setText(QApplication::translate("MainWindow", "Brake", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        CarStatusWidget->setWindowTitle(QApplication::translate("MainWindow", "Car Status", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Position GAZEBO</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        gazebo_x->setText(QApplication::translate("MainWindow", "X : 0.000", 0, QApplication::UnicodeUTF8));
        gazebo_y->setText(QApplication::translate("MainWindow", "Y : 0.000", 0, QApplication::UnicodeUTF8));
        gazebo_z->setText(QApplication::translate("MainWindow", "Z : 0.000", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Position GPS</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        latitude->setText(QApplication::translate("MainWindow", "Latitude: 0.000000000", 0, QApplication::UnicodeUTF8));
        longitude->setText(QApplication::translate("MainWindow", "Longitude: 0.000000000", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Quaternion</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        quaternion_gazebo_x->setText(QApplication::translate("MainWindow", "X : 0.000", 0, QApplication::UnicodeUTF8));
        quaternion_gazebo_y->setText(QApplication::translate("MainWindow", "Y : 0.000", 0, QApplication::UnicodeUTF8));
        quaternion_gazebo_z->setText(QApplication::translate("MainWindow", "Z : 0.000", 0, QApplication::UnicodeUTF8));
        quaternion_gazebo_w->setText(QApplication::translate("MainWindow", "W : 0.000", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">IMU</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        quaternion_imu_x->setText(QApplication::translate("MainWindow", "X : 0.000", 0, QApplication::UnicodeUTF8));
        quaternion_imu_y->setText(QApplication::translate("MainWindow", "Y : 0.000", 0, QApplication::UnicodeUTF8));
        quaternion_imu_z->setText(QApplication::translate("MainWindow", "Z : 0.000", 0, QApplication::UnicodeUTF8));
        quaternion_imu_w->setText(QApplication::translate("MainWindow", "W : 0.000", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">IMU Angular Velocity</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        imu_ang_speed_x->setText(QApplication::translate("MainWindow", "X : 0.000", 0, QApplication::UnicodeUTF8));
        imu_ang_speed_y->setText(QApplication::translate("MainWindow", "Y : 0.000", 0, QApplication::UnicodeUTF8));
        imu_ang_speed_z->setText(QApplication::translate("MainWindow", "Z : 0.000", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">IMU Linear Acceleration</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        imu_lin_acel_x->setText(QApplication::translate("MainWindow", "X : 0.000", 0, QApplication::UnicodeUTF8));
        imu_lin_acel_y->setText(QApplication::translate("MainWindow", "Y : 0.000", 0, QApplication::UnicodeUTF8));
        imu_lin_acel_z->setText(QApplication::translate("MainWindow", "Z : 0.000", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Velocidade Linear (GAZEBO)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        gazebo_lin_vel_x->setText(QApplication::translate("MainWindow", "X : 0.000", 0, QApplication::UnicodeUTF8));
        gazebo_lin_vel_y->setText(QApplication::translate("MainWindow", "Y : 0.000", 0, QApplication::UnicodeUTF8));
        gazebo_lin_vel_z->setText(QApplication::translate("MainWindow", "Z : 0.000", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Velocidade Angular (GAZEBO)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        gazebo_ang_vel_x->setText(QApplication::translate("MainWindow", "X : 0.000", 0, QApplication::UnicodeUTF8));
        gazebo_ang_vel_y->setText(QApplication::translate("MainWindow", "Y : 0.000", 0, QApplication::UnicodeUTF8));
        gazebo_ang_vel_z->setText(QApplication::translate("MainWindow", "Z : 0.000", 0, QApplication::UnicodeUTF8));
        imu_euler_z_rotation_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Euler Rotation (IMU)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        imu_euler_z_rotation_value->setText(QApplication::translate("MainWindow", "Z : 0.000", 0, QApplication::UnicodeUTF8));
        ManualControlsWidget->setWindowTitle(QApplication::translate("MainWindow", "Manual Controls", 0, QApplication::UnicodeUTF8));
        BrakeDock->setWindowTitle(QApplication::translate("MainWindow", "BrakeDock", 0, QApplication::UnicodeUTF8));
        current_brake_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Current Brake: 0.000 %</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        AccelerationDock->setWindowTitle(QApplication::translate("MainWindow", "Acceleration", 0, QApplication::UnicodeUTF8));
        current_acel_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Current Acceleration: 0.000 %</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        GearWidget->setWindowTitle(QApplication::translate("MainWindow", "Gears", 0, QApplication::UnicodeUTF8));
        gears_forward_radio_button->setText(QApplication::translate("MainWindow", "Forward", 0, QApplication::UnicodeUTF8));
        gears_forward_radio_button->setShortcut(QApplication::translate("MainWindow", "F", 0, QApplication::UnicodeUTF8));
        gears_neutral_radio_button->setText(QApplication::translate("MainWindow", "Neutral", 0, QApplication::UnicodeUTF8));
        gears_neutral_radio_button->setShortcut(QApplication::translate("MainWindow", "N", 0, QApplication::UnicodeUTF8));
        gears_backwards_radio_button->setText(QApplication::translate("MainWindow", "Backwards", 0, QApplication::UnicodeUTF8));
        gears_backwards_radio_button->setShortcut(QApplication::translate("MainWindow", "B", 0, QApplication::UnicodeUTF8));
        HandBrakeDock->setWindowTitle(QApplication::translate("MainWindow", "HandBrake", 0, QApplication::UnicodeUTF8));
        handbrake_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Handbrake Status:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        handbrake_button->setText(QApplication::translate("MainWindow", "ON", 0, QApplication::UnicodeUTF8));
        handbrake_button->setShortcut(QApplication::translate("MainWindow", "H", 0, QApplication::UnicodeUTF8));
        SteeringDock->setWindowTitle(QApplication::translate("MainWindow", "Hand Wheel", 0, QApplication::UnicodeUTF8));
        steering_status_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Hand Wheel Status : 00.0 rad</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        AutomationWidget->setWindowTitle(QApplication::translate("MainWindow", "Automatic Driving", 0, QApplication::UnicodeUTF8));
        Set_wheel_direction_button->setText(QApplication::translate("MainWindow", "Set Wheel Direction to (X,Y)", 0, QApplication::UnicodeUTF8));
        Set_wheel_direction_x_input->setPlaceholderText(QApplication::translate("MainWindow", "Input X", 0, QApplication::UnicodeUTF8));
        Set_wheel_direction_y_input->setPlaceholderText(QApplication::translate("MainWindow", "Input Y", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = Set_wheel_direction_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = Set_wheel_direction_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = Set_wheel_direction_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Current Active Row", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = Set_wheel_direction_table->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = Set_wheel_direction_table->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = Set_wheel_direction_table->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = Set_wheel_direction_table->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = Set_wheel_direction_table->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = Set_wheel_direction_table->verticalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = Set_wheel_direction_table->verticalHeaderItem(6);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = Set_wheel_direction_table->verticalHeaderItem(7);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = Set_wheel_direction_table->verticalHeaderItem(8);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = Set_wheel_direction_table->isSortingEnabled();
        Set_wheel_direction_table->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem12 = Set_wheel_direction_table->item(0, 2);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        Set_wheel_direction_table->setSortingEnabled(__sortingEnabled);

        Set_wheel_direction_from_table->setText(QApplication::translate("MainWindow", "From Table", 0, QApplication::UnicodeUTF8));
        Constant_speed_button->setText(QApplication::translate("MainWindow", "Constant Car Speed", 0, QApplication::UnicodeUTF8));
        Maintain_current_speed->setText(QApplication::translate("MainWindow", "Current Speed", 0, QApplication::UnicodeUTF8));
        Set_new_speed->setText(QApplication::translate("MainWindow", "Set Speed", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

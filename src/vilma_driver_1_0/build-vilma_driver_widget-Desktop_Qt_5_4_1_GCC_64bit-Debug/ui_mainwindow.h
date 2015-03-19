/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *morse_x_text;
    QLabel *morse_y_text;
    QLabel *morse_z_text;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_12;
    QHBoxLayout *Morse_quaternion_layout;
    QLabel *morse_quaternion_x_text;
    QLabel *morse_quaternion_y_text;
    QLabel *morse_quaternion_z_text;
    QLabel *morse_quaternion_w_text;
    QVBoxLayout *verticalLayout;
    QLabel *label_34;
    QHBoxLayout *horizontalLayout;
    QLabel *morse_lin_vel_x_text;
    QLabel *morse_lin_vel_y_text;
    QLabel *morse_lin_vel_z_text;
    QLabel *morse_lin_vel_avg_text;
    QVBoxLayout *Ang_vel_morse;
    QLabel *label_38;
    QHBoxLayout *horizontalLayout_13;
    QLabel *morse_ang_vel_x_text;
    QLabel *morse_ang_vel_y_text;
    QLabel *morse_ang_vel_z_text;
    QVBoxLayout *Position_gps;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *latitude_text;
    QLabel *longitude_text;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout_7;
    QLabel *imu_quaternion_x_text;
    QLabel *imu_quaternion_y_text;
    QLabel *imu_quaternion_z_text;
    QLabel *imu_quaternion_w_text;
    QVBoxLayout *IMU_lin_acel;
    QLabel *label_26;
    QHBoxLayout *horizontalLayout_10;
    QLabel *imu_lin_acel_x_text;
    QLabel *imu_lin_acel_y_text;
    QLabel *imu_lin_acel_z_text;
    QVBoxLayout *IMU_ang_vel;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_9;
    QLabel *imu_ang_speed_x_text;
    QLabel *imu_ang_speed_y_text;
    QLabel *imu_ang_speed_z_text;
    QVBoxLayout *imu_euler;
    QLabel *imu_euler_z_rotation_label;
    QLabel *imu_euler_z_rotation_text;
    QDockWidget *ManualControlsWidget;
    QWidget *ManualControlsWidget_contents;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLabel *current_acel_text;
    QLabel *current_max_speed_text;
    QLabel *steering_status_label;
    QSlider *steering_slider;
    QDockWidget *AutomationWidget;
    QWidget *dockWidgetContents;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Maintain_current_speed;
    QPushButton *Set_new_speed;
    QLineEdit *Enter_new_constant_speed;
    QPushButton *PlotTrajectory;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Set_wheel_direction_button;
    QLineEdit *Set_wheel_direction_x_input;
    QLineEdit *Set_wheel_direction_y_input;
    QCheckBox *Set_wheel_direction_from_table;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *SmoothTrajectoryButton;
    QPushButton *GeneratePoints;
    QPushButton *InputFromFile;
    QTableWidget *Set_wheel_direction_table;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1018, 661);
        MainWindow->setMaximumSize(QSize(1309, 1000));
        actionAccelerator = new QAction(MainWindow);
        actionAccelerator->setObjectName(QStringLiteral("actionAccelerator"));
        actionAccelerator->setCheckable(true);
        actionAccelerator->setChecked(true);
        actionBrake = new QAction(MainWindow);
        actionBrake->setObjectName(QStringLiteral("actionBrake"));
        actionBrake->setCheckable(true);
        MainWidget = new QWidget(MainWindow);
        MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWindow->setCentralWidget(MainWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1018, 25));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        CarStatusWidget = new QDockWidget(MainWindow);
        CarStatusWidget->setObjectName(QStringLiteral("CarStatusWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CarStatusWidget->sizePolicy().hasHeightForWidth());
        CarStatusWidget->setSizePolicy(sizePolicy);
        CarStatusWidget->setMinimumSize(QSize(400, 600));
        CarStatusWidget->setMaximumSize(QSize(400, 500));
        CarStatusWidget_contents = new QWidget();
        CarStatusWidget_contents->setObjectName(QStringLiteral("CarStatusWidget_contents"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CarStatusWidget_contents->sizePolicy().hasHeightForWidth());
        CarStatusWidget_contents->setSizePolicy(sizePolicy1);
        widget = new QWidget(CarStatusWidget_contents);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 14, 330, 507));
        verticalLayout_7 = new QVBoxLayout(widget);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        morse_x_text = new QLabel(widget);
        morse_x_text->setObjectName(QStringLiteral("morse_x_text"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(morse_x_text->sizePolicy().hasHeightForWidth());
        morse_x_text->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(morse_x_text);

        morse_y_text = new QLabel(widget);
        morse_y_text->setObjectName(QStringLiteral("morse_y_text"));

        horizontalLayout_5->addWidget(morse_y_text);

        morse_z_text = new QLabel(widget);
        morse_z_text->setObjectName(QStringLiteral("morse_z_text"));
        sizePolicy1.setHeightForWidth(morse_z_text->sizePolicy().hasHeightForWidth());
        morse_z_text->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(morse_z_text);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_7->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_12 = new QLabel(widget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_12);

        Morse_quaternion_layout = new QHBoxLayout();
        Morse_quaternion_layout->setSpacing(6);
        Morse_quaternion_layout->setObjectName(QStringLiteral("Morse_quaternion_layout"));
        morse_quaternion_x_text = new QLabel(widget);
        morse_quaternion_x_text->setObjectName(QStringLiteral("morse_quaternion_x_text"));

        Morse_quaternion_layout->addWidget(morse_quaternion_x_text);

        morse_quaternion_y_text = new QLabel(widget);
        morse_quaternion_y_text->setObjectName(QStringLiteral("morse_quaternion_y_text"));

        Morse_quaternion_layout->addWidget(morse_quaternion_y_text);

        morse_quaternion_z_text = new QLabel(widget);
        morse_quaternion_z_text->setObjectName(QStringLiteral("morse_quaternion_z_text"));

        Morse_quaternion_layout->addWidget(morse_quaternion_z_text);

        morse_quaternion_w_text = new QLabel(widget);
        morse_quaternion_w_text->setObjectName(QStringLiteral("morse_quaternion_w_text"));

        Morse_quaternion_layout->addWidget(morse_quaternion_w_text);


        verticalLayout_3->addLayout(Morse_quaternion_layout);


        verticalLayout_7->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_34 = new QLabel(widget);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_34);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        morse_lin_vel_x_text = new QLabel(widget);
        morse_lin_vel_x_text->setObjectName(QStringLiteral("morse_lin_vel_x_text"));

        horizontalLayout->addWidget(morse_lin_vel_x_text);

        morse_lin_vel_y_text = new QLabel(widget);
        morse_lin_vel_y_text->setObjectName(QStringLiteral("morse_lin_vel_y_text"));

        horizontalLayout->addWidget(morse_lin_vel_y_text);

        morse_lin_vel_z_text = new QLabel(widget);
        morse_lin_vel_z_text->setObjectName(QStringLiteral("morse_lin_vel_z_text"));

        horizontalLayout->addWidget(morse_lin_vel_z_text);

        morse_lin_vel_avg_text = new QLabel(widget);
        morse_lin_vel_avg_text->setObjectName(QStringLiteral("morse_lin_vel_avg_text"));

        horizontalLayout->addWidget(morse_lin_vel_avg_text);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_7->addLayout(verticalLayout);

        Ang_vel_morse = new QVBoxLayout();
        Ang_vel_morse->setSpacing(6);
        Ang_vel_morse->setObjectName(QStringLiteral("Ang_vel_morse"));
        label_38 = new QLabel(widget);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setAlignment(Qt::AlignCenter);

        Ang_vel_morse->addWidget(label_38);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        morse_ang_vel_x_text = new QLabel(widget);
        morse_ang_vel_x_text->setObjectName(QStringLiteral("morse_ang_vel_x_text"));

        horizontalLayout_13->addWidget(morse_ang_vel_x_text);

        morse_ang_vel_y_text = new QLabel(widget);
        morse_ang_vel_y_text->setObjectName(QStringLiteral("morse_ang_vel_y_text"));

        horizontalLayout_13->addWidget(morse_ang_vel_y_text);

        morse_ang_vel_z_text = new QLabel(widget);
        morse_ang_vel_z_text->setObjectName(QStringLiteral("morse_ang_vel_z_text"));

        horizontalLayout_13->addWidget(morse_ang_vel_z_text);


        Ang_vel_morse->addLayout(horizontalLayout_13);


        verticalLayout_7->addLayout(Ang_vel_morse);

        Position_gps = new QVBoxLayout();
        Position_gps->setSpacing(6);
        Position_gps->setObjectName(QStringLiteral("Position_gps"));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy3);
        label_9->setAlignment(Qt::AlignCenter);

        Position_gps->addWidget(label_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        latitude_text = new QLabel(widget);
        latitude_text->setObjectName(QStringLiteral("latitude_text"));

        horizontalLayout_6->addWidget(latitude_text);

        longitude_text = new QLabel(widget);
        longitude_text->setObjectName(QStringLiteral("longitude_text"));

        horizontalLayout_6->addWidget(longitude_text);


        Position_gps->addLayout(horizontalLayout_6);


        verticalLayout_7->addLayout(Position_gps);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_17 = new QLabel(widget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_17);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        imu_quaternion_x_text = new QLabel(widget);
        imu_quaternion_x_text->setObjectName(QStringLiteral("imu_quaternion_x_text"));

        horizontalLayout_7->addWidget(imu_quaternion_x_text);

        imu_quaternion_y_text = new QLabel(widget);
        imu_quaternion_y_text->setObjectName(QStringLiteral("imu_quaternion_y_text"));

        horizontalLayout_7->addWidget(imu_quaternion_y_text);

        imu_quaternion_z_text = new QLabel(widget);
        imu_quaternion_z_text->setObjectName(QStringLiteral("imu_quaternion_z_text"));

        horizontalLayout_7->addWidget(imu_quaternion_z_text);

        imu_quaternion_w_text = new QLabel(widget);
        imu_quaternion_w_text->setObjectName(QStringLiteral("imu_quaternion_w_text"));

        horizontalLayout_7->addWidget(imu_quaternion_w_text);


        verticalLayout_6->addLayout(horizontalLayout_7);


        verticalLayout_7->addLayout(verticalLayout_6);

        IMU_lin_acel = new QVBoxLayout();
        IMU_lin_acel->setSpacing(6);
        IMU_lin_acel->setObjectName(QStringLiteral("IMU_lin_acel"));
        label_26 = new QLabel(widget);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setAlignment(Qt::AlignCenter);

        IMU_lin_acel->addWidget(label_26);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        imu_lin_acel_x_text = new QLabel(widget);
        imu_lin_acel_x_text->setObjectName(QStringLiteral("imu_lin_acel_x_text"));

        horizontalLayout_10->addWidget(imu_lin_acel_x_text);

        imu_lin_acel_y_text = new QLabel(widget);
        imu_lin_acel_y_text->setObjectName(QStringLiteral("imu_lin_acel_y_text"));

        horizontalLayout_10->addWidget(imu_lin_acel_y_text);

        imu_lin_acel_z_text = new QLabel(widget);
        imu_lin_acel_z_text->setObjectName(QStringLiteral("imu_lin_acel_z_text"));

        horizontalLayout_10->addWidget(imu_lin_acel_z_text);


        IMU_lin_acel->addLayout(horizontalLayout_10);


        verticalLayout_7->addLayout(IMU_lin_acel);

        IMU_ang_vel = new QVBoxLayout();
        IMU_ang_vel->setSpacing(6);
        IMU_ang_vel->setObjectName(QStringLiteral("IMU_ang_vel"));
        label_22 = new QLabel(widget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setAlignment(Qt::AlignCenter);

        IMU_ang_vel->addWidget(label_22);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        imu_ang_speed_x_text = new QLabel(widget);
        imu_ang_speed_x_text->setObjectName(QStringLiteral("imu_ang_speed_x_text"));

        horizontalLayout_9->addWidget(imu_ang_speed_x_text);

        imu_ang_speed_y_text = new QLabel(widget);
        imu_ang_speed_y_text->setObjectName(QStringLiteral("imu_ang_speed_y_text"));

        horizontalLayout_9->addWidget(imu_ang_speed_y_text);

        imu_ang_speed_z_text = new QLabel(widget);
        imu_ang_speed_z_text->setObjectName(QStringLiteral("imu_ang_speed_z_text"));

        horizontalLayout_9->addWidget(imu_ang_speed_z_text);


        IMU_ang_vel->addLayout(horizontalLayout_9);


        verticalLayout_7->addLayout(IMU_ang_vel);

        imu_euler = new QVBoxLayout();
        imu_euler->setSpacing(6);
        imu_euler->setObjectName(QStringLiteral("imu_euler"));
        imu_euler_z_rotation_label = new QLabel(widget);
        imu_euler_z_rotation_label->setObjectName(QStringLiteral("imu_euler_z_rotation_label"));
        imu_euler_z_rotation_label->setAlignment(Qt::AlignCenter);

        imu_euler->addWidget(imu_euler_z_rotation_label);

        imu_euler_z_rotation_text = new QLabel(widget);
        imu_euler_z_rotation_text->setObjectName(QStringLiteral("imu_euler_z_rotation_text"));
        imu_euler_z_rotation_text->setAlignment(Qt::AlignCenter);

        imu_euler->addWidget(imu_euler_z_rotation_text);


        verticalLayout_7->addLayout(imu_euler);

        CarStatusWidget->setWidget(CarStatusWidget_contents);
        label_12->raise();
        label_5->raise();
        label_17->raise();
        morse_lin_vel_avg_text->raise();
        label_34->raise();
        morse_lin_vel_avg_text->raise();
        morse_ang_vel_z_text->raise();
        imu_quaternion_x_text->raise();
        imu_quaternion_z_text->raise();
        imu_quaternion_w_text->raise();
        imu_quaternion_y_text->raise();
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), CarStatusWidget);
        ManualControlsWidget = new QDockWidget(MainWindow);
        ManualControlsWidget->setObjectName(QStringLiteral("ManualControlsWidget"));
        ManualControlsWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(ManualControlsWidget->sizePolicy().hasHeightForWidth());
        ManualControlsWidget->setSizePolicy(sizePolicy);
        ManualControlsWidget->setMinimumSize(QSize(600, 200));
        ManualControlsWidget->setMaximumSize(QSize(600, 200));
        ManualControlsWidget->setAutoFillBackground(false);
        ManualControlsWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
        ManualControlsWidget_contents = new QWidget();
        ManualControlsWidget_contents->setObjectName(QStringLiteral("ManualControlsWidget_contents"));
        widget1 = new QWidget(ManualControlsWidget_contents);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(11, 21, 461, 71));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        current_acel_text = new QLabel(widget1);
        current_acel_text->setObjectName(QStringLiteral("current_acel_text"));
        current_acel_text->setEnabled(true);
        sizePolicy2.setHeightForWidth(current_acel_text->sizePolicy().hasHeightForWidth());
        current_acel_text->setSizePolicy(sizePolicy2);
        current_acel_text->setMinimumSize(QSize(50, 0));
        current_acel_text->setFrameShape(QFrame::Box);
        current_acel_text->setTextFormat(Qt::AutoText);
        current_acel_text->setScaledContents(true);
        current_acel_text->setWordWrap(false);

        gridLayout->addWidget(current_acel_text, 0, 0, 1, 1);

        current_max_speed_text = new QLabel(widget1);
        current_max_speed_text->setObjectName(QStringLiteral("current_max_speed_text"));
        current_max_speed_text->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(current_max_speed_text->sizePolicy().hasHeightForWidth());
        current_max_speed_text->setSizePolicy(sizePolicy4);
        current_max_speed_text->setFrameShape(QFrame::Box);
        current_max_speed_text->setTextFormat(Qt::AutoText);
        current_max_speed_text->setScaledContents(true);
        current_max_speed_text->setWordWrap(false);

        gridLayout->addWidget(current_max_speed_text, 0, 1, 1, 1);

        steering_status_label = new QLabel(widget1);
        steering_status_label->setObjectName(QStringLiteral("steering_status_label"));
        steering_status_label->setScaledContents(true);
        steering_status_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(steering_status_label, 1, 0, 1, 1);

        steering_slider = new QSlider(widget1);
        steering_slider->setObjectName(QStringLiteral("steering_slider"));
        steering_slider->setMinimum(-314);
        steering_slider->setMaximum(314);
        steering_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(steering_slider, 1, 1, 1, 1);

        ManualControlsWidget->setWidget(ManualControlsWidget_contents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), ManualControlsWidget);
        AutomationWidget = new QDockWidget(MainWindow);
        AutomationWidget->setObjectName(QStringLiteral("AutomationWidget"));
        AutomationWidget->setMinimumSize(QSize(600, 400));
        AutomationWidget->setMaximumSize(QSize(60, 800));
        AutomationWidget->setLayoutDirection(Qt::LeftToRight);
        AutomationWidget->setAutoFillBackground(true);
        AutomationWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        widget2 = new QWidget(dockWidgetContents);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(11, 1, 559, 301));
        verticalLayout_5 = new QVBoxLayout(widget2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Maintain_current_speed = new QPushButton(widget2);
        Maintain_current_speed->setObjectName(QStringLiteral("Maintain_current_speed"));
        Maintain_current_speed->setEnabled(true);
        Maintain_current_speed->setCheckable(true);
        Maintain_current_speed->setFlat(false);

        horizontalLayout_3->addWidget(Maintain_current_speed);

        Set_new_speed = new QPushButton(widget2);
        Set_new_speed->setObjectName(QStringLiteral("Set_new_speed"));
        Set_new_speed->setEnabled(true);
        Set_new_speed->setCheckable(true);

        horizontalLayout_3->addWidget(Set_new_speed);

        Enter_new_constant_speed = new QLineEdit(widget2);
        Enter_new_constant_speed->setObjectName(QStringLiteral("Enter_new_constant_speed"));
        Enter_new_constant_speed->setEnabled(true);
        Enter_new_constant_speed->setMaximumSize(QSize(111, 51));

        horizontalLayout_3->addWidget(Enter_new_constant_speed);

        PlotTrajectory = new QPushButton(widget2);
        PlotTrajectory->setObjectName(QStringLiteral("PlotTrajectory"));

        horizontalLayout_3->addWidget(PlotTrajectory);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Set_wheel_direction_button = new QPushButton(widget2);
        Set_wheel_direction_button->setObjectName(QStringLiteral("Set_wheel_direction_button"));
        Set_wheel_direction_button->setCheckable(true);
        Set_wheel_direction_button->setAutoRepeat(true);
        Set_wheel_direction_button->setAutoDefault(false);

        horizontalLayout_2->addWidget(Set_wheel_direction_button);

        Set_wheel_direction_x_input = new QLineEdit(widget2);
        Set_wheel_direction_x_input->setObjectName(QStringLiteral("Set_wheel_direction_x_input"));
        sizePolicy.setHeightForWidth(Set_wheel_direction_x_input->sizePolicy().hasHeightForWidth());
        Set_wheel_direction_x_input->setSizePolicy(sizePolicy);
        Set_wheel_direction_x_input->setMaximumSize(QSize(111, 51));
        Set_wheel_direction_x_input->setCursorPosition(0);

        horizontalLayout_2->addWidget(Set_wheel_direction_x_input);

        Set_wheel_direction_y_input = new QLineEdit(widget2);
        Set_wheel_direction_y_input->setObjectName(QStringLiteral("Set_wheel_direction_y_input"));
        sizePolicy.setHeightForWidth(Set_wheel_direction_y_input->sizePolicy().hasHeightForWidth());
        Set_wheel_direction_y_input->setSizePolicy(sizePolicy);
        Set_wheel_direction_y_input->setMaximumSize(QSize(111, 51));

        horizontalLayout_2->addWidget(Set_wheel_direction_y_input);

        Set_wheel_direction_from_table = new QCheckBox(widget2);
        Set_wheel_direction_from_table->setObjectName(QStringLiteral("Set_wheel_direction_from_table"));

        horizontalLayout_2->addWidget(Set_wheel_direction_from_table);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        SmoothTrajectoryButton = new QPushButton(widget2);
        SmoothTrajectoryButton->setObjectName(QStringLiteral("SmoothTrajectoryButton"));

        horizontalLayout_4->addWidget(SmoothTrajectoryButton);

        GeneratePoints = new QPushButton(widget2);
        GeneratePoints->setObjectName(QStringLiteral("GeneratePoints"));

        horizontalLayout_4->addWidget(GeneratePoints);

        InputFromFile = new QPushButton(widget2);
        InputFromFile->setObjectName(QStringLiteral("InputFromFile"));

        horizontalLayout_4->addWidget(InputFromFile);


        verticalLayout_4->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(verticalLayout_4);

        Set_wheel_direction_table = new QTableWidget(widget2);
        if (Set_wheel_direction_table->columnCount() < 5)
            Set_wheel_direction_table->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Set_wheel_direction_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Set_wheel_direction_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Set_wheel_direction_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Set_wheel_direction_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QFont font;
        font.setPointSize(10);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        Set_wheel_direction_table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (Set_wheel_direction_table->rowCount() < 10000)
            Set_wheel_direction_table->setRowCount(10000);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(6, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(7, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        Set_wheel_direction_table->setVerticalHeaderItem(8, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        Set_wheel_direction_table->setItem(0, 4, __qtablewidgetitem14);
        Set_wheel_direction_table->setObjectName(QStringLiteral("Set_wheel_direction_table"));
        Set_wheel_direction_table->setEnabled(false);
        Set_wheel_direction_table->setGridStyle(Qt::SolidLine);
        Set_wheel_direction_table->setWordWrap(true);
        Set_wheel_direction_table->setRowCount(10000);
        Set_wheel_direction_table->horizontalHeader()->setCascadingSectionResizes(true);
        Set_wheel_direction_table->horizontalHeader()->setDefaultSectionSize(120);
        Set_wheel_direction_table->horizontalHeader()->setMinimumSectionSize(120);
        Set_wheel_direction_table->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        Set_wheel_direction_table->horizontalHeader()->setStretchLastSection(true);
        Set_wheel_direction_table->verticalHeader()->setVisible(false);
        Set_wheel_direction_table->verticalHeader()->setDefaultSectionSize(42);
        Set_wheel_direction_table->verticalHeader()->setMinimumSectionSize(42);
        Set_wheel_direction_table->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        Set_wheel_direction_table->verticalHeader()->setStretchLastSection(false);

        verticalLayout_5->addWidget(Set_wheel_direction_table);

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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Vilma Driver", 0));
        actionAccelerator->setText(QApplication::translate("MainWindow", "Accelerator", 0));
#ifndef QT_NO_TOOLTIP
        actionAccelerator->setToolTip(QApplication::translate("MainWindow", "Show Accelerator Widget", 0));
#endif // QT_NO_TOOLTIP
        actionBrake->setText(QApplication::translate("MainWindow", "Brake", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
        CarStatusWidget->setWindowTitle(QApplication::translate("MainWindow", "Car Status", 0));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Position (MORSE) </span></p></body></html>", 0));
        morse_x_text->setText(QApplication::translate("MainWindow", "X : 0.000", 0));
        morse_y_text->setText(QApplication::translate("MainWindow", "Y : 0.000", 0));
        morse_z_text->setText(QApplication::translate("MainWindow", "Z : 0.000", 0));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Orientation (MORSE )</span></p></body></html>", 0));
        morse_quaternion_x_text->setText(QApplication::translate("MainWindow", "X : 0.000", 0));
        morse_quaternion_y_text->setText(QApplication::translate("MainWindow", "Y : 0.000", 0));
        morse_quaternion_z_text->setText(QApplication::translate("MainWindow", "Z : 0.000", 0));
        morse_quaternion_w_text->setText(QApplication::translate("MainWindow", "W : 0.000", 0));
        label_34->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Linear Velocity (MORSE)</span></p></body></html>", 0));
        morse_lin_vel_x_text->setText(QApplication::translate("MainWindow", "X : 0.000", 0));
        morse_lin_vel_y_text->setText(QApplication::translate("MainWindow", "Y : 0.000", 0));
        morse_lin_vel_z_text->setText(QApplication::translate("MainWindow", "Z : 0.000", 0));
        morse_lin_vel_avg_text->setText(QApplication::translate("MainWindow", "AVG : 0.000", 0));
        label_38->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Angular Velocity (MORSE)</span></p></body></html>", 0));
        morse_ang_vel_x_text->setText(QApplication::translate("MainWindow", "X : 0.000", 0));
        morse_ang_vel_y_text->setText(QApplication::translate("MainWindow", "Y : 0.000", 0));
        morse_ang_vel_z_text->setText(QApplication::translate("MainWindow", "Z : 0.000", 0));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Position GPS</span></p></body></html>", 0));
        latitude_text->setText(QApplication::translate("MainWindow", "Latitude: 0.000000000", 0));
        longitude_text->setText(QApplication::translate("MainWindow", "Longitude: 0.000000000", 0));
        label_17->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">IMU Orientation </span></p></body></html>", 0));
        imu_quaternion_x_text->setText(QApplication::translate("MainWindow", "X : 0.000", 0));
        imu_quaternion_y_text->setText(QApplication::translate("MainWindow", "Y : 0.000", 0));
        imu_quaternion_z_text->setText(QApplication::translate("MainWindow", "Z : 0.000", 0));
        imu_quaternion_w_text->setText(QApplication::translate("MainWindow", "W : 0.000", 0));
        label_26->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">IMU Linear Acceleration</span></p></body></html>", 0));
        imu_lin_acel_x_text->setText(QApplication::translate("MainWindow", "X : 0.000", 0));
        imu_lin_acel_y_text->setText(QApplication::translate("MainWindow", "Y : 0.000", 0));
        imu_lin_acel_z_text->setText(QApplication::translate("MainWindow", "Z : 0.000", 0));
        label_22->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">IMU Angular Velocity</span></p></body></html>", 0));
        imu_ang_speed_x_text->setText(QApplication::translate("MainWindow", "X : 0.000", 0));
        imu_ang_speed_y_text->setText(QApplication::translate("MainWindow", "Y : 0.000", 0));
        imu_ang_speed_z_text->setText(QApplication::translate("MainWindow", "Z : 0.000", 0));
        imu_euler_z_rotation_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">IMU Euler Rotation</span></p></body></html>", 0));
        imu_euler_z_rotation_text->setText(QApplication::translate("MainWindow", "Z : 0.000", 0));
        ManualControlsWidget->setWindowTitle(QApplication::translate("MainWindow", "Manual Controls", 0));
        current_acel_text->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Current Power: 0.000</span></p></body></html>", 0));
        current_max_speed_text->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Max Speed 0.000 m/s</span></p></body></html>", 0));
        steering_status_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Hand Wheel:    </span></p></body></html>", 0));
        AutomationWidget->setWindowTitle(QApplication::translate("MainWindow", "Automatic Driving", 0));
        Maintain_current_speed->setText(QApplication::translate("MainWindow", "Current Speed", 0));
        Set_new_speed->setText(QApplication::translate("MainWindow", "Set Speed", 0));
        PlotTrajectory->setText(QApplication::translate("MainWindow", "Plot Trajectory", 0));
        Set_wheel_direction_button->setText(QApplication::translate("MainWindow", "Set Wheel Direction to (X,Y)", 0));
        Set_wheel_direction_x_input->setPlaceholderText(QApplication::translate("MainWindow", "Input X", 0));
        Set_wheel_direction_y_input->setPlaceholderText(QApplication::translate("MainWindow", "Input Y", 0));
        Set_wheel_direction_from_table->setText(QApplication::translate("MainWindow", "From Table", 0));
        SmoothTrajectoryButton->setText(QApplication::translate("MainWindow", "Smooth Trajectory", 0));
        GeneratePoints->setText(QApplication::translate("MainWindow", "Generate Points", 0));
        InputFromFile->setText(QApplication::translate("MainWindow", "Input From File", 0));
        QTableWidgetItem *___qtablewidgetitem = Set_wheel_direction_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "X", 0));
        QTableWidgetItem *___qtablewidgetitem1 = Set_wheel_direction_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Y", 0));
        QTableWidgetItem *___qtablewidgetitem2 = Set_wheel_direction_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Velocity", 0));
        QTableWidgetItem *___qtablewidgetitem3 = Set_wheel_direction_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Action", 0));
        QTableWidgetItem *___qtablewidgetitem4 = Set_wheel_direction_table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Current Active Row", 0));
        QTableWidgetItem *___qtablewidgetitem5 = Set_wheel_direction_table->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem6 = Set_wheel_direction_table->verticalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem7 = Set_wheel_direction_table->verticalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem8 = Set_wheel_direction_table->verticalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem9 = Set_wheel_direction_table->verticalHeaderItem(4);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "5", 0));
        QTableWidgetItem *___qtablewidgetitem10 = Set_wheel_direction_table->verticalHeaderItem(5);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "6", 0));
        QTableWidgetItem *___qtablewidgetitem11 = Set_wheel_direction_table->verticalHeaderItem(6);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "7", 0));
        QTableWidgetItem *___qtablewidgetitem12 = Set_wheel_direction_table->verticalHeaderItem(7);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "8", 0));
        QTableWidgetItem *___qtablewidgetitem13 = Set_wheel_direction_table->verticalHeaderItem(8);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "9", 0));

        const bool __sortingEnabled = Set_wheel_direction_table->isSortingEnabled();
        Set_wheel_direction_table->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem14 = Set_wheel_direction_table->item(0, 4);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "1", 0));
        Set_wheel_direction_table->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

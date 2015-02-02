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
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *IMU_quat;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout_8;
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
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *Quaternion_morse;
    QVBoxLayout *Position_morse;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *morse_x_text;
    QLabel *morse_y_text;
    QLabel *morse_z_text;
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
    QDockWidget *ManualControlsWidget;
    QWidget *ManualControlsWidget_contents;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *current_acel_text;
    QLabel *current_max_speed_text;
    QSlider *steering_slider;
    QLabel *steering_status_label;
    QPushButton *PlotTrajectory;
    QPushButton *InputFromFile;
    QPushButton *GeneratePoints;
    QDockWidget *AutomationWidget;
    QWidget *dockWidgetContents;
    QPushButton *Set_wheel_direction_button;
    QLineEdit *Set_wheel_direction_x_input;
    QLineEdit *Set_wheel_direction_y_input;
    QTableWidget *Set_wheel_direction_table;
    QCheckBox *Set_wheel_direction_from_table;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *Maintain_current_speed;
    QPushButton *Set_new_speed;
    QLineEdit *Enter_new_constant_speed;
    QPushButton *SmoothTrajectoryButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1709, 1159);
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
        menuBar->setGeometry(QRect(0, 0, 1709, 42));
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
        CarStatusWidget->setMinimumSize(QSize(800, 600));
        CarStatusWidget->setMaximumSize(QSize(800, 1200));
        CarStatusWidget_contents = new QWidget();
        CarStatusWidget_contents->setObjectName(QString::fromUtf8("CarStatusWidget_contents"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CarStatusWidget_contents->sizePolicy().hasHeightForWidth());
        CarStatusWidget_contents->setSizePolicy(sizePolicy1);
        layoutWidget = new QWidget(CarStatusWidget_contents);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 580, 495, 436));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        IMU_quat = new QVBoxLayout();
        IMU_quat->setSpacing(6);
        IMU_quat->setObjectName(QString::fromUtf8("IMU_quat"));
        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        IMU_quat->addWidget(label_17);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        imu_quaternion_x_text = new QLabel(layoutWidget);
        imu_quaternion_x_text->setObjectName(QString::fromUtf8("imu_quaternion_x_text"));

        horizontalLayout_8->addWidget(imu_quaternion_x_text);

        imu_quaternion_y_text = new QLabel(layoutWidget);
        imu_quaternion_y_text->setObjectName(QString::fromUtf8("imu_quaternion_y_text"));

        horizontalLayout_8->addWidget(imu_quaternion_y_text);

        imu_quaternion_z_text = new QLabel(layoutWidget);
        imu_quaternion_z_text->setObjectName(QString::fromUtf8("imu_quaternion_z_text"));

        horizontalLayout_8->addWidget(imu_quaternion_z_text);

        imu_quaternion_w_text = new QLabel(layoutWidget);
        imu_quaternion_w_text->setObjectName(QString::fromUtf8("imu_quaternion_w_text"));

        horizontalLayout_8->addWidget(imu_quaternion_w_text);


        IMU_quat->addLayout(horizontalLayout_8);


        verticalLayout_2->addLayout(IMU_quat);

        IMU_lin_acel = new QVBoxLayout();
        IMU_lin_acel->setSpacing(6);
        IMU_lin_acel->setObjectName(QString::fromUtf8("IMU_lin_acel"));
        label_26 = new QLabel(layoutWidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setAlignment(Qt::AlignCenter);

        IMU_lin_acel->addWidget(label_26);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        imu_lin_acel_x_text = new QLabel(layoutWidget);
        imu_lin_acel_x_text->setObjectName(QString::fromUtf8("imu_lin_acel_x_text"));

        horizontalLayout_10->addWidget(imu_lin_acel_x_text);

        imu_lin_acel_y_text = new QLabel(layoutWidget);
        imu_lin_acel_y_text->setObjectName(QString::fromUtf8("imu_lin_acel_y_text"));

        horizontalLayout_10->addWidget(imu_lin_acel_y_text);

        imu_lin_acel_z_text = new QLabel(layoutWidget);
        imu_lin_acel_z_text->setObjectName(QString::fromUtf8("imu_lin_acel_z_text"));

        horizontalLayout_10->addWidget(imu_lin_acel_z_text);


        IMU_lin_acel->addLayout(horizontalLayout_10);


        verticalLayout_2->addLayout(IMU_lin_acel);

        IMU_ang_vel = new QVBoxLayout();
        IMU_ang_vel->setSpacing(6);
        IMU_ang_vel->setObjectName(QString::fromUtf8("IMU_ang_vel"));
        label_22 = new QLabel(layoutWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setAlignment(Qt::AlignCenter);

        IMU_ang_vel->addWidget(label_22);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        imu_ang_speed_x_text = new QLabel(layoutWidget);
        imu_ang_speed_x_text->setObjectName(QString::fromUtf8("imu_ang_speed_x_text"));

        horizontalLayout_9->addWidget(imu_ang_speed_x_text);

        imu_ang_speed_y_text = new QLabel(layoutWidget);
        imu_ang_speed_y_text->setObjectName(QString::fromUtf8("imu_ang_speed_y_text"));

        horizontalLayout_9->addWidget(imu_ang_speed_y_text);

        imu_ang_speed_z_text = new QLabel(layoutWidget);
        imu_ang_speed_z_text->setObjectName(QString::fromUtf8("imu_ang_speed_z_text"));

        horizontalLayout_9->addWidget(imu_ang_speed_z_text);


        IMU_ang_vel->addLayout(horizontalLayout_9);


        verticalLayout_2->addLayout(IMU_ang_vel);

        imu_euler = new QVBoxLayout();
        imu_euler->setSpacing(6);
        imu_euler->setObjectName(QString::fromUtf8("imu_euler"));
        imu_euler_z_rotation_label = new QLabel(layoutWidget);
        imu_euler_z_rotation_label->setObjectName(QString::fromUtf8("imu_euler_z_rotation_label"));
        imu_euler_z_rotation_label->setAlignment(Qt::AlignCenter);

        imu_euler->addWidget(imu_euler_z_rotation_label);

        imu_euler_z_rotation_text = new QLabel(layoutWidget);
        imu_euler_z_rotation_text->setObjectName(QString::fromUtf8("imu_euler_z_rotation_text"));
        imu_euler_z_rotation_text->setAlignment(Qt::AlignCenter);

        imu_euler->addWidget(imu_euler_z_rotation_text);


        verticalLayout_2->addLayout(imu_euler);

        layoutWidget1 = new QWidget(CarStatusWidget_contents);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 11, 633, 550));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        Quaternion_morse = new QVBoxLayout();
        Quaternion_morse->setSpacing(6);
        Quaternion_morse->setObjectName(QString::fromUtf8("Quaternion_morse"));
        Position_morse = new QVBoxLayout();
        Position_morse->setSpacing(6);
        Position_morse->setObjectName(QString::fromUtf8("Position_morse"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setAlignment(Qt::AlignCenter);

        Position_morse->addWidget(label_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        morse_x_text = new QLabel(layoutWidget1);
        morse_x_text->setObjectName(QString::fromUtf8("morse_x_text"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(morse_x_text->sizePolicy().hasHeightForWidth());
        morse_x_text->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(morse_x_text);

        morse_y_text = new QLabel(layoutWidget1);
        morse_y_text->setObjectName(QString::fromUtf8("morse_y_text"));

        horizontalLayout_5->addWidget(morse_y_text);

        morse_z_text = new QLabel(layoutWidget1);
        morse_z_text->setObjectName(QString::fromUtf8("morse_z_text"));
        sizePolicy1.setHeightForWidth(morse_z_text->sizePolicy().hasHeightForWidth());
        morse_z_text->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(morse_z_text);


        Position_morse->addLayout(horizontalLayout_5);


        Quaternion_morse->addLayout(Position_morse);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        Quaternion_morse->addWidget(label_12);

        Morse_quaternion_layout = new QHBoxLayout();
        Morse_quaternion_layout->setSpacing(6);
        Morse_quaternion_layout->setObjectName(QString::fromUtf8("Morse_quaternion_layout"));
        morse_quaternion_x_text = new QLabel(layoutWidget1);
        morse_quaternion_x_text->setObjectName(QString::fromUtf8("morse_quaternion_x_text"));

        Morse_quaternion_layout->addWidget(morse_quaternion_x_text);

        morse_quaternion_y_text = new QLabel(layoutWidget1);
        morse_quaternion_y_text->setObjectName(QString::fromUtf8("morse_quaternion_y_text"));

        Morse_quaternion_layout->addWidget(morse_quaternion_y_text);

        morse_quaternion_z_text = new QLabel(layoutWidget1);
        morse_quaternion_z_text->setObjectName(QString::fromUtf8("morse_quaternion_z_text"));

        Morse_quaternion_layout->addWidget(morse_quaternion_z_text);

        morse_quaternion_w_text = new QLabel(layoutWidget1);
        morse_quaternion_w_text->setObjectName(QString::fromUtf8("morse_quaternion_w_text"));

        Morse_quaternion_layout->addWidget(morse_quaternion_w_text);


        Quaternion_morse->addLayout(Morse_quaternion_layout);


        verticalLayout_3->addLayout(Quaternion_morse);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_34 = new QLabel(layoutWidget1);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_34);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        morse_lin_vel_x_text = new QLabel(layoutWidget1);
        morse_lin_vel_x_text->setObjectName(QString::fromUtf8("morse_lin_vel_x_text"));

        horizontalLayout->addWidget(morse_lin_vel_x_text);

        morse_lin_vel_y_text = new QLabel(layoutWidget1);
        morse_lin_vel_y_text->setObjectName(QString::fromUtf8("morse_lin_vel_y_text"));

        horizontalLayout->addWidget(morse_lin_vel_y_text);

        morse_lin_vel_z_text = new QLabel(layoutWidget1);
        morse_lin_vel_z_text->setObjectName(QString::fromUtf8("morse_lin_vel_z_text"));

        horizontalLayout->addWidget(morse_lin_vel_z_text);

        morse_lin_vel_avg_text = new QLabel(layoutWidget1);
        morse_lin_vel_avg_text->setObjectName(QString::fromUtf8("morse_lin_vel_avg_text"));

        horizontalLayout->addWidget(morse_lin_vel_avg_text);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        Ang_vel_morse = new QVBoxLayout();
        Ang_vel_morse->setSpacing(6);
        Ang_vel_morse->setObjectName(QString::fromUtf8("Ang_vel_morse"));
        label_38 = new QLabel(layoutWidget1);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setAlignment(Qt::AlignCenter);

        Ang_vel_morse->addWidget(label_38);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        morse_ang_vel_x_text = new QLabel(layoutWidget1);
        morse_ang_vel_x_text->setObjectName(QString::fromUtf8("morse_ang_vel_x_text"));

        horizontalLayout_13->addWidget(morse_ang_vel_x_text);

        morse_ang_vel_y_text = new QLabel(layoutWidget1);
        morse_ang_vel_y_text->setObjectName(QString::fromUtf8("morse_ang_vel_y_text"));

        horizontalLayout_13->addWidget(morse_ang_vel_y_text);

        morse_ang_vel_z_text = new QLabel(layoutWidget1);
        morse_ang_vel_z_text->setObjectName(QString::fromUtf8("morse_ang_vel_z_text"));

        horizontalLayout_13->addWidget(morse_ang_vel_z_text);


        Ang_vel_morse->addLayout(horizontalLayout_13);


        verticalLayout_3->addLayout(Ang_vel_morse);

        Position_gps = new QVBoxLayout();
        Position_gps->setSpacing(6);
        Position_gps->setObjectName(QString::fromUtf8("Position_gps"));
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy3);
        label_9->setAlignment(Qt::AlignCenter);

        Position_gps->addWidget(label_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        latitude_text = new QLabel(layoutWidget1);
        latitude_text->setObjectName(QString::fromUtf8("latitude_text"));

        horizontalLayout_6->addWidget(latitude_text);

        longitude_text = new QLabel(layoutWidget1);
        longitude_text->setObjectName(QString::fromUtf8("longitude_text"));

        horizontalLayout_6->addWidget(longitude_text);


        Position_gps->addLayout(horizontalLayout_6);


        verticalLayout_3->addLayout(Position_gps);

        CarStatusWidget->setWidget(CarStatusWidget_contents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), CarStatusWidget);
        ManualControlsWidget = new QDockWidget(MainWindow);
        ManualControlsWidget->setObjectName(QString::fromUtf8("ManualControlsWidget"));
        ManualControlsWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(ManualControlsWidget->sizePolicy().hasHeightForWidth());
        ManualControlsWidget->setSizePolicy(sizePolicy);
        ManualControlsWidget->setMinimumSize(QSize(891, 400));
        ManualControlsWidget->setMaximumSize(QSize(1000, 1000));
        ManualControlsWidget->setAutoFillBackground(false);
        ManualControlsWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
        ManualControlsWidget_contents = new QWidget();
        ManualControlsWidget_contents->setObjectName(QString::fromUtf8("ManualControlsWidget_contents"));
        gridLayoutWidget = new QWidget(ManualControlsWidget_contents);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 861, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        current_acel_text = new QLabel(gridLayoutWidget);
        current_acel_text->setObjectName(QString::fromUtf8("current_acel_text"));
        current_acel_text->setEnabled(true);
        sizePolicy2.setHeightForWidth(current_acel_text->sizePolicy().hasHeightForWidth());
        current_acel_text->setSizePolicy(sizePolicy2);
        current_acel_text->setMinimumSize(QSize(50, 0));
        current_acel_text->setFrameShape(QFrame::Box);
        current_acel_text->setTextFormat(Qt::AutoText);
        current_acel_text->setScaledContents(true);
        current_acel_text->setWordWrap(false);

        gridLayout->addWidget(current_acel_text, 0, 0, 1, 1);

        current_max_speed_text = new QLabel(gridLayoutWidget);
        current_max_speed_text->setObjectName(QString::fromUtf8("current_max_speed_text"));
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

        steering_slider = new QSlider(gridLayoutWidget);
        steering_slider->setObjectName(QString::fromUtf8("steering_slider"));
        steering_slider->setMinimum(-314);
        steering_slider->setMaximum(314);
        steering_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(steering_slider, 1, 1, 1, 1);

        steering_status_label = new QLabel(gridLayoutWidget);
        steering_status_label->setObjectName(QString::fromUtf8("steering_status_label"));
        steering_status_label->setScaledContents(true);
        steering_status_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(steering_status_label, 1, 0, 1, 1);

        PlotTrajectory = new QPushButton(ManualControlsWidget_contents);
        PlotTrajectory->setObjectName(QString::fromUtf8("PlotTrajectory"));
        PlotTrajectory->setGeometry(QRect(90, 170, 231, 44));
        InputFromFile = new QPushButton(ManualControlsWidget_contents);
        InputFromFile->setObjectName(QString::fromUtf8("InputFromFile"));
        InputFromFile->setGeometry(QRect(90, 230, 241, 44));
        GeneratePoints = new QPushButton(ManualControlsWidget_contents);
        GeneratePoints->setObjectName(QString::fromUtf8("GeneratePoints"));
        GeneratePoints->setGeometry(QRect(370, 170, 231, 44));
        ManualControlsWidget->setWidget(ManualControlsWidget_contents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), ManualControlsWidget);
        AutomationWidget = new QDockWidget(MainWindow);
        AutomationWidget->setObjectName(QString::fromUtf8("AutomationWidget"));
        AutomationWidget->setMinimumSize(QSize(850, 400));
        AutomationWidget->setMaximumSize(QSize(850, 800));
        AutomationWidget->setLayoutDirection(Qt::LeftToRight);
        AutomationWidget->setAutoFillBackground(true);
        AutomationWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        Set_wheel_direction_button = new QPushButton(dockWidgetContents);
        Set_wheel_direction_button->setObjectName(QString::fromUtf8("Set_wheel_direction_button"));
        Set_wheel_direction_button->setGeometry(QRect(20, 60, 391, 41));
        Set_wheel_direction_button->setCheckable(true);
        Set_wheel_direction_button->setAutoRepeat(true);
        Set_wheel_direction_button->setAutoDefault(false);
        Set_wheel_direction_x_input = new QLineEdit(dockWidgetContents);
        Set_wheel_direction_x_input->setObjectName(QString::fromUtf8("Set_wheel_direction_x_input"));
        Set_wheel_direction_x_input->setGeometry(QRect(420, 60, 111, 51));
        Set_wheel_direction_x_input->setCursorPosition(0);
        Set_wheel_direction_y_input = new QLineEdit(dockWidgetContents);
        Set_wheel_direction_y_input->setObjectName(QString::fromUtf8("Set_wheel_direction_y_input"));
        Set_wheel_direction_y_input->setGeometry(QRect(530, 60, 111, 51));
        Set_wheel_direction_table = new QTableWidget(dockWidgetContents);
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
        if (Set_wheel_direction_table->rowCount() < 100)
            Set_wheel_direction_table->setRowCount(100);
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
        Set_wheel_direction_table->setObjectName(QString::fromUtf8("Set_wheel_direction_table"));
        Set_wheel_direction_table->setEnabled(false);
        Set_wheel_direction_table->setGeometry(QRect(0, 160, 841, 471));
        Set_wheel_direction_table->setGridStyle(Qt::SolidLine);
        Set_wheel_direction_table->setWordWrap(true);
        Set_wheel_direction_table->setRowCount(100);
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
        Set_wheel_direction_from_table = new QCheckBox(dockWidgetContents);
        Set_wheel_direction_from_table->setObjectName(QString::fromUtf8("Set_wheel_direction_from_table"));
        Set_wheel_direction_from_table->setGeometry(QRect(650, 70, 191, 41));
        layoutWidget4 = new QWidget(dockWidgetContents);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 10, 817, 46));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        Maintain_current_speed = new QPushButton(layoutWidget4);
        Maintain_current_speed->setObjectName(QString::fromUtf8("Maintain_current_speed"));
        Maintain_current_speed->setEnabled(true);
        Maintain_current_speed->setCheckable(true);
        Maintain_current_speed->setFlat(false);

        horizontalLayout_11->addWidget(Maintain_current_speed);

        Set_new_speed = new QPushButton(layoutWidget4);
        Set_new_speed->setObjectName(QString::fromUtf8("Set_new_speed"));
        Set_new_speed->setEnabled(true);
        Set_new_speed->setCheckable(true);

        horizontalLayout_11->addWidget(Set_new_speed);

        Enter_new_constant_speed = new QLineEdit(layoutWidget4);
        Enter_new_constant_speed->setObjectName(QString::fromUtf8("Enter_new_constant_speed"));
        Enter_new_constant_speed->setEnabled(true);

        horizontalLayout_11->addWidget(Enter_new_constant_speed);

        SmoothTrajectoryButton = new QPushButton(dockWidgetContents);
        SmoothTrajectoryButton->setObjectName(QString::fromUtf8("SmoothTrajectoryButton"));
        SmoothTrajectoryButton->setGeometry(QRect(20, 100, 271, 51));
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
        label_17->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">IMU Orientation </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        imu_quaternion_x_text->setText(QApplication::translate("MainWindow", "X : 0.000", 0, QApplication::UnicodeUTF8));
        imu_quaternion_y_text->setText(QApplication::translate("MainWindow", "Y : 0.000", 0, QApplication::UnicodeUTF8));
        imu_quaternion_z_text->setText(QApplication::translate("MainWindow", "Z : 0.000", 0, QApplication::UnicodeUTF8));
        imu_quaternion_w_text->setText(QApplication::translate("MainWindow", "W : 0.000", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">IMU Linear Acceleration</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        imu_lin_acel_x_text->setText(QApplication::translate("MainWindow", "X : 0.000", 0, QApplication::UnicodeUTF8));
        imu_lin_acel_y_text->setText(QApplication::translate("MainWindow", "Y : 0.000", 0, QApplication::UnicodeUTF8));
        imu_lin_acel_z_text->setText(QApplication::translate("MainWindow", "Z : 0.000", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">IMU Angular Velocity</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        imu_ang_speed_x_text->setText(QApplication::translate("MainWindow", "X : 0.000", 0, QApplication::UnicodeUTF8));
        imu_ang_speed_y_text->setText(QApplication::translate("MainWindow", "Y : 0.000", 0, QApplication::UnicodeUTF8));
        imu_ang_speed_z_text->setText(QApplication::translate("MainWindow", "Z : 0.000", 0, QApplication::UnicodeUTF8));
        imu_euler_z_rotation_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">IMU Euler Rotation</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        imu_euler_z_rotation_text->setText(QApplication::translate("MainWindow", "Z : 0.000", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Position (MORSE) </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        morse_x_text->setText(QApplication::translate("MainWindow", "X : 0.000", 0, QApplication::UnicodeUTF8));
        morse_y_text->setText(QApplication::translate("MainWindow", "Y : 0.000", 0, QApplication::UnicodeUTF8));
        morse_z_text->setText(QApplication::translate("MainWindow", "Z : 0.000", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Orientation (MORSE )</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        morse_quaternion_x_text->setText(QApplication::translate("MainWindow", "X : 0.000", 0, QApplication::UnicodeUTF8));
        morse_quaternion_y_text->setText(QApplication::translate("MainWindow", "Y : 0.000", 0, QApplication::UnicodeUTF8));
        morse_quaternion_z_text->setText(QApplication::translate("MainWindow", "Z : 0.000", 0, QApplication::UnicodeUTF8));
        morse_quaternion_w_text->setText(QApplication::translate("MainWindow", "W : 0.000", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Linear Velocity (MORSE)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        morse_lin_vel_x_text->setText(QApplication::translate("MainWindow", "X : 0.000", 0, QApplication::UnicodeUTF8));
        morse_lin_vel_y_text->setText(QApplication::translate("MainWindow", "Y : 0.000", 0, QApplication::UnicodeUTF8));
        morse_lin_vel_z_text->setText(QApplication::translate("MainWindow", "Z : 0.000", 0, QApplication::UnicodeUTF8));
        morse_lin_vel_avg_text->setText(QApplication::translate("MainWindow", "AVG : 0.000", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Angular Velocity (MORSE)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        morse_ang_vel_x_text->setText(QApplication::translate("MainWindow", "X : 0.000", 0, QApplication::UnicodeUTF8));
        morse_ang_vel_y_text->setText(QApplication::translate("MainWindow", "Y : 0.000", 0, QApplication::UnicodeUTF8));
        morse_ang_vel_z_text->setText(QApplication::translate("MainWindow", "Z : 0.000", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Position GPS</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        latitude_text->setText(QApplication::translate("MainWindow", "Latitude: 0.000000000", 0, QApplication::UnicodeUTF8));
        longitude_text->setText(QApplication::translate("MainWindow", "Longitude: 0.000000000", 0, QApplication::UnicodeUTF8));
        ManualControlsWidget->setWindowTitle(QApplication::translate("MainWindow", "Manual Controls", 0, QApplication::UnicodeUTF8));
        current_acel_text->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Current Power: 0.000</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        current_max_speed_text->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Max Speed 0.000 m/s</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        steering_status_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Hand Wheel:    </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        PlotTrajectory->setText(QApplication::translate("MainWindow", "Plot Trajectory", 0, QApplication::UnicodeUTF8));
        InputFromFile->setText(QApplication::translate("MainWindow", "Input From File", 0, QApplication::UnicodeUTF8));
        GeneratePoints->setText(QApplication::translate("MainWindow", "Generate Points", 0, QApplication::UnicodeUTF8));
        AutomationWidget->setWindowTitle(QApplication::translate("MainWindow", "Automatic Driving", 0, QApplication::UnicodeUTF8));
        Set_wheel_direction_button->setText(QApplication::translate("MainWindow", "Set Wheel Direction to (X,Y)", 0, QApplication::UnicodeUTF8));
        Set_wheel_direction_x_input->setPlaceholderText(QApplication::translate("MainWindow", "Input X", 0, QApplication::UnicodeUTF8));
        Set_wheel_direction_y_input->setPlaceholderText(QApplication::translate("MainWindow", "Input Y", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = Set_wheel_direction_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = Set_wheel_direction_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = Set_wheel_direction_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Velocity", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = Set_wheel_direction_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Action", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = Set_wheel_direction_table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Current Active Row", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = Set_wheel_direction_table->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = Set_wheel_direction_table->verticalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = Set_wheel_direction_table->verticalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = Set_wheel_direction_table->verticalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = Set_wheel_direction_table->verticalHeaderItem(4);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = Set_wheel_direction_table->verticalHeaderItem(5);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = Set_wheel_direction_table->verticalHeaderItem(6);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = Set_wheel_direction_table->verticalHeaderItem(7);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = Set_wheel_direction_table->verticalHeaderItem(8);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = Set_wheel_direction_table->isSortingEnabled();
        Set_wheel_direction_table->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem14 = Set_wheel_direction_table->item(0, 4);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        Set_wheel_direction_table->setSortingEnabled(__sortingEnabled);

        Set_wheel_direction_from_table->setText(QApplication::translate("MainWindow", "From Table", 0, QApplication::UnicodeUTF8));
        Maintain_current_speed->setText(QApplication::translate("MainWindow", "Current Speed", 0, QApplication::UnicodeUTF8));
        Set_new_speed->setText(QApplication::translate("MainWindow", "Set Speed", 0, QApplication::UnicodeUTF8));
        SmoothTrajectoryButton->setText(QApplication::translate("MainWindow", "Smooth Trajectory", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    ros::init(argc, argv, "Vilma_drive_cmd_publisher"); //Inializing ROS basic, needed for basically anything
    application.setStyle("cleanlooks");
    MainWindow w;
    w.show();
    return application.exec();
}

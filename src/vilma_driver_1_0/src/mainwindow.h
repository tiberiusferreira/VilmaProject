#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include "VilmaControler_RosSide.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void update();

//    void on_verticalSlider_valueChanged(int value);

//    void on_actionAccelerator_toggled(bool arg1);

    void keyPressEvent(QKeyEvent *key);

    void on_Set_new_speed_toggled(bool checked);

    void on_Constant_speed_button_toggled(bool checked);

    void on_Set_wheel_direction_from_table_toggled(bool checked);

    void on_current_acel_label_slider_sliderMoved(int position);

    void on_current_brake_slider_sliderMoved(int position);

    void on_steering_slider_sliderMoved(int position);

    void on_handbrake_button_toggled(bool checked);

    void on_gears_forward_radio_button_toggled(bool checked);

    void on_gears_neutral_radio_button_toggled(bool checked);

    void on_gears_backwards_radio_button_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    VilmaControler_ROS VilmaControler_object;
    QTimer *timer;

};

#endif // MAINWINDOW_H

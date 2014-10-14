#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include "vilma_ros_talker.h"
#include "vilma_self_driver.h"
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

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    vilma_ros_talker vilma_talker_obj;
    vilma_self_driver vilma_self_driver_obj{&vilma_talker_obj};
    QTimer *timer;

};

#endif // MAINWINDOW_H

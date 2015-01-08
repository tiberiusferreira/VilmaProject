#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include "morse_receiver.h"
#include "morse_transmiter.h"
#include "vilma_self_driver.h"
#include "morse_subscriber.h"
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

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    morse_subscriber morse_subscriber_obj;
    morse_receiver morse_receiver_obj;
    morse_transmiter morse_transmiter_obj;
    //vilma_self_driver vilma_self_driver_obj{&vilma_talker_obj};
    QTimer *timer;

};

#endif // MAINWINDOW_H

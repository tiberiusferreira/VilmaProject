#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT( update()));
    timer->start(250);
    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT( reset_state()));

//    ui->Set_wheel_direction_x_input->setValidator(new QDoubleValidator(this));
//    ui->Set_wheel_direction_y_input->setValidator(new QDoubleValidator(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset_state(){
    timer2->stop();
    morse_transmiter_obj.setSteering(0);

}

void MainWindow::keyReleaseEvent(QKeyEvent *key){
    if(key->key()== Qt::Key_A || key->key()== Qt::Key_D)
    {
        this->timer2->start(100);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *key){

    if(key->key()== Qt::Key_W)
    {
            morse_transmiter_obj.setVelocity(30);
            morse_transmiter_obj.setPowerAmount(500);

    }
    if(key->key()== Qt::Key_S)
    {
        morse_transmiter_obj.setPowerAmount(0);
        morse_transmiter_obj.setVelocity(0);

    }
    if(key->key()== Qt::Key_A)
    {
            morse_transmiter_obj.setSteering(0.3);
    }
    if(key->key()== Qt::Key_D)
    {
            morse_transmiter_obj.setSteering(-0.3);

    }
}


void MainWindow::update()
{

    ros::spinOnce(); //update ros side values
    //vilma_talker_obj.receive_model_physical_state(); //update ros side values dependable on service calls
//    ui->current_acel_label_slider->setSliderPosition((vilma_talker_obj.gas_pedal_state.data)*100); //acel slider pose update
//    ui->current_brake_slider->setSliderPosition((vilma_talker_obj.brake_pedal_state.data)*100); //brake slider pose update

      ui->steering_slider->setSliderPosition((float) -morse_transmiter_obj.getSteering()*523.23); //steering slider pose update
      QString acel_text = QString("Current Power: %1").arg(QString::number(morse_transmiter_obj.getPowerAmount(),'f',3));
      QString max_speed_text = QString("Max Speed %1 m/s").arg(QString::number(morse_transmiter_obj.getVelocity(),'f',3));
//    QString steering_text = QString("Hand Wheel Status : %1 rad").arg(QString::number(vilma_talker_obj.hand_wheel_state.data,'f',3));
//    QString gazebo_x_text = QString("X : %1").arg(QString::number(vilma_talker_obj.modelstate.pose.position.x,'f',3));
//    QString gazebo_y_text = QString("Y : %1").arg(QString::number(vilma_talker_obj.modelstate.pose.position.y,'f',3));
//    QString gazebo_z_text = QString("Z : %1").arg(QString::number(vilma_talker_obj.modelstate.pose.position.z,'f',3));
//    QString latitude_text = QString("Z : %1").arg(QString::number(vilma_talker_obj.car_gps_state.latitude,'f',9));
//    QString longitude_text = QString("Z : %1").arg(QString::number(vilma_talker_obj.car_gps_state.longitude,'f',9));
//    QString quaternion_gazebo_x_text = QString("X : %1").arg(QString::number(vilma_talker_obj.modelstate.pose.orientation.x,'f',3));
//    QString quaternion_gazebo_y_text = QString("Y : %1").arg(QString::number(vilma_talker_obj.modelstate.pose.orientation.y,'f',3));
//    QString quaternion_gazebo_z_text = QString("Z : %1").arg(QString::number(vilma_talker_obj.modelstate.pose.orientation.z,'f',3));
//    QString quaternion_gazebo_w_text = QString("W : %1").arg(QString::number(vilma_talker_obj.modelstate.pose.orientation.w,'f',3));
//    QString quaternion_imu_x_text = QString("X : %1").arg(QString::number(vilma_talker_obj.imu_data.orientation.x,'f',3));
//    QString quaternion_imu_y_text = QString("Y : %1").arg(QString::number(vilma_talker_obj.imu_data.orientation.y,'f',3));
//    QString quaternion_imu_z_text = QString("Z : %1").arg(QString::number(vilma_talker_obj.imu_data.orientation.z,'f',3));
//    QString quaternion_imu_w_text = QString("Z : %1").arg(QString::number(vilma_talker_obj.imu_data.orientation.w,'f',3));
//    QString imu_ang_speed_x_text = QString("X : %1").arg(QString::number(vilma_talker_obj.imu_data.angular_velocity.x,'f',3));
//    QString imu_ang_speed_y_text = QString("Y : %1").arg(QString::number(vilma_talker_obj.imu_data.angular_velocity.y,'f',3));
//    QString imu_ang_speed_z_text = QString("Z : %1").arg(QString::number(vilma_talker_obj.imu_data.angular_velocity.z,'f',3));
//    QString imu_lin_acel_x_text = QString("X : %1").arg(QString::number(vilma_talker_obj.imu_data.linear_acceleration.x,'f',3));
//    QString imu_lin_acel_y_text = QString("Y : %1").arg(QString::number(vilma_talker_obj.imu_data.linear_acceleration.y,'f',3));
//    QString imu_lin_acel_z_text = QString("Z : %1").arg(QString::number(vilma_talker_obj.imu_data.linear_acceleration.z,'f',3));
//    QString gazebo_lin_vel_x_text = QString("X : %1").arg(QString::number(vilma_talker_obj.modelstate.twist.linear.x,'f',3));
//    QString gazebo_lin_vel_y_text = QString("Y : %1").arg(QString::number(vilma_talker_obj.modelstate.twist.linear.y,'f',3));
//    QString gazebo_lin_vel_z_text = QString("Z : %1").arg(QString::number(vilma_talker_obj.modelstate.twist.linear.z,'f',3));
//    QString gazebo_ang_vel_x_text = QString("X : %1").arg(QString::number(vilma_talker_obj.modelstate.twist.angular.x,'f',3));
//    QString gazebo_ang_vel_y_text = QString("Y : %1").arg(QString::number(vilma_talker_obj.modelstate.twist.angular.y,'f',3));
//    QString gazebo_ang_vel_z_text = QString("Z : %1").arg(QString::number(vilma_talker_obj.modelstate.twist.angular.z,'f',3));
//    QString imu_euler_rot_z = QString("Z : %1").arg(QString::number(vilma_talker_obj.imudata_to_euler().GetYaw(),'f',3));
      ui->current_acel_label->setText(acel_text);
      ui->current_max_speed_label->setText(max_speed_text);
//    ui->current_brake_label->setText(brake_text);
//    ui->steering_status_label->setText(steering_text);
//    ui->gazebo_x->setText(gazebo_x_text);
//    ui->gazebo_y->setText(gazebo_y_text);
//    ui->gazebo_z->setText(gazebo_z_text);
//    ui->latitude->setText(latitude_text);
//    ui->longitude->setText(longitude_text);
//    ui->quaternion_gazebo_x->setText(quaternion_gazebo_x_text);
//    ui->quaternion_gazebo_y->setText(quaternion_gazebo_y_text);
//    ui->quaternion_gazebo_z->setText(quaternion_gazebo_z_text);
//    ui->quaternion_gazebo_w->setText(quaternion_gazebo_w_text);
//    ui->quaternion_imu_x->setText(quaternion_imu_x_text);
//    ui->quaternion_imu_y->setText(quaternion_imu_y_text);
//    ui->quaternion_imu_z->setText(quaternion_imu_z_text);
//    ui->quaternion_imu_w->setText(quaternion_imu_w_text);
//    ui->imu_ang_speed_x->setText(imu_ang_speed_x_text);
//    ui->imu_ang_speed_y->setText(imu_ang_speed_y_text);
//    ui->imu_ang_speed_z->setText(imu_ang_speed_z_text);
//    ui->imu_lin_acel_x->setText(imu_lin_acel_x_text);
//    ui->imu_lin_acel_y->setText(imu_lin_acel_y_text);
//    ui->imu_lin_acel_z->setText(imu_lin_acel_z_text);
//    ui->gazebo_lin_vel_x->setText(gazebo_lin_vel_x_text);
//    ui->gazebo_lin_vel_y->setText(gazebo_lin_vel_y_text);
//    ui->gazebo_lin_vel_z->setText(gazebo_lin_vel_z_text);
//    ui->gazebo_ang_vel_x->setText(gazebo_ang_vel_x_text);
//    ui->gazebo_ang_vel_y->setText(gazebo_ang_vel_y_text);
//    ui->gazebo_ang_vel_z->setText(gazebo_ang_vel_z_text);
//    ui->imu_euler_z_rotation_value->setText(imu_euler_rot_z);
//    if(vilma_talker_obj.hand_brake_state.data>0.05) //set hand brake button status based on car info
//    {
//        ui->handbrake_button->setChecked(1);
//    }
//    else
//    {
//        ui->handbrake_button->setChecked(0);
//    }

//    if(vilma_talker_obj.gears.data==1){ //set correct gear checked box based on car info
//        ui->gears_forward_radio_button->setChecked(1);
//    }
//    if(vilma_talker_obj.gears.data==0){
//        ui->gears_neutral_radio_button->setChecked(1);
//    }
//    if(vilma_talker_obj.gears.data==-1){
//        ui->gears_backwards_radio_button->setChecked(1);
//    }

//    if(ui->Set_wheel_direction_button->isChecked()){
//        if(!ui->Set_wheel_direction_from_table->isChecked() && ui->Set_wheel_direction_x_input->text()!=""
//                && ui->Set_wheel_direction_y_input->text()!=""){
//            vilma_self_driver_obj.reorientate_to_pose(ui->Set_wheel_direction_x_input->text().toDouble(),ui->Set_wheel_direction_y_input->text().toDouble());
//        }
//        if(ui->Set_wheel_direction_from_table->isChecked())
//        {
//            double current_row;
//            int ok;
//            QTableWidgetItem *current_item = ui->Set_wheel_direction_table->item(0,4);
//            if(current_item!=0){
//                current_row= current_item->text().toDouble();
//            }
//            QTableWidgetItem *X_item = ui->Set_wheel_direction_table->item(current_row-1,0);
//            QTableWidgetItem *Y_item = ui->Set_wheel_direction_table->item(current_row-1,1);
//            if(X_item==0 || Y_item==0){ //reached end of X Y list
//                vilma_talker_obj.set_steering(0);
//                vilma_talker_obj.set_gas_pedal(0);
//                vilma_talker_obj.set_brake_pedal(1);
//                return;
//            }
//            ok=vilma_self_driver_obj.reorientate_to_pose(X_item->text().toDouble(),Y_item->text().toDouble());
//            if(ok==-1){ //check if the X Y is behind the car already
//                current_item->setText(QString ("%1").arg(current_item->text().toDouble()+1));
//            }

//        }
//    }
}
void MainWindow::on_Set_new_speed_toggled(bool checked)
{
//    if(checked)
//        ui->Enter_new_constant_speed->setEnabled(1);
//    else
//        ui->Enter_new_constant_speed->setEnabled(0);

}

void MainWindow::on_Constant_speed_button_toggled(bool checked)
{
//    if(checked)
//    {
//        ui->Maintain_current_speed->setEnabled(1);
//        ui->Set_new_speed->setEnabled(1);
//    }else
//    {
//        ui->Maintain_current_speed->setEnabled(0);
//        ui->Set_new_speed->setEnabled(0);
//    }
}

void MainWindow::on_Set_wheel_direction_from_table_toggled(bool checked)
{
//    if(checked)
//    {
//        ui->Set_wheel_direction_table->setEnabled(1);
//    }else
//    {
//        ui->Set_wheel_direction_table->setEnabled(0);
//    }
}

void MainWindow::on_current_acel_label_slider_sliderMoved(int position)
{
    //vilma_talker_obj.set_gas_pedal((float) position/100);
}

void MainWindow::on_current_brake_slider_sliderMoved(int position)
{
//    vilma_talker_obj.set_brake_pedal((float) position/100);
}

void MainWindow::on_steering_slider_sliderMoved(int position)
{
    morse_transmiter_obj.setSteering(((float) -position/100)*0.191); //*0.191 so it stays as +-0.6 rad
    //and not +-3.14 rad
}

void MainWindow::on_pushButton_clicked()
{
//    std::deque<one_point> points_from_table;
//    std::deque<one_point> points_to_table;
//    QTableWidgetItem *X_item;
//    QTableWidgetItem *Y_item;
//    double current_row=0;
//    int ok=0;
//    while(ok==0){
//    X_item = ui->Set_wheel_direction_table->item(current_row,0);
//    Y_item = ui->Set_wheel_direction_table->item(current_row,1);
//    if(X_item==0 || Y_item==0){ //reached end of X Y list
//        ok =-1;
//        break;
//    }
//    points_from_table.push_back(one_point (X_item->text().toFloat(),Y_item->text().toFloat()));
//    current_row++;
//    }
//    points_to_table=vilma_self_driver_obj.generate_smooth_path(points_from_table);
//    current_row=0;
//    for(current_row=0;current_row<points_to_table.size();current_row++){
//        X_item = ui->Set_wheel_direction_table->item(current_row,0);
//        Y_item = ui->Set_wheel_direction_table->item(current_row,1);
//        X_item->setText(QString ("%5").arg(points_to_table.at(current_row).x));
//        Y_item->setText(QString ("%5").arg(points_to_table.at(current_row).y));
//    }
}

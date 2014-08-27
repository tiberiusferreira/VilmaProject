#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    VilmaControler_object.init();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT( update()));
    timer->start(100);
    ui->Set_wheel_direction_x_input->setValidator(new QDoubleValidator(this));
    ui->Set_wheel_direction_y_input->setValidator(new QDoubleValidator(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *key){
    if(key->key()== Qt::Key_W)
    {
        VilmaControler_object.accelerate(0.1);
    }
    if(key->key()== Qt::Key_S)
    {
        if(VilmaControler_object.gas_pedal_state.data>=0.02)
            VilmaControler_object.set_gas_pedal(0);
        else
        {
            VilmaControler_object.set_brake_pedal(VilmaControler_object.brake_pedal_state.data+0.1);
        }
    }
    if(key->key()== Qt::Key_D)
    {
        if(VilmaControler_object.hand_wheel_state.data<-2.5)
        {
            VilmaControler_object.use_Steering(VilmaControler_object.hand_wheel_state.data-0.4);
        }else
        {
            VilmaControler_object.use_Steering(VilmaControler_object.hand_wheel_state.data-0.4);
        }
    }
    if(key->key()== Qt::Key_A)
    {
        if(VilmaControler_object.hand_wheel_state.data>2.5)
        {
            VilmaControler_object.use_Steering(3.14);
        }else
        {
            VilmaControler_object.use_Steering(VilmaControler_object.hand_wheel_state.data+0.4);
        }
    }
}


void MainWindow::update()
{

    ros::spinOnce(); //update ros side values
    VilmaControler_object.receive_model_physical_state();
    ui->current_acel_label_slider->setSliderPosition((VilmaControler_object.gas_pedal_state.data)*100);
    ui->current_brake_slider->setSliderPosition((VilmaControler_object.brake_pedal_state.data)*100);
    ui->steering_slider->setSliderPosition((-VilmaControler_object.hand_wheel_state.data)*100);
    QString acel_text = QString("Current Acceleration: %1").arg(QString::number(VilmaControler_object.gas_pedal_state.data,'f',3));
    QString brake_text = QString("Current Brake: %1").arg(QString::number(VilmaControler_object.brake_pedal_state.data,'f',3));
    QString steering_text = QString("Hand Wheel Status : %1 rad").arg(QString::number(VilmaControler_object.hand_wheel_state.data,'f',3));
    QString gazebo_x_text = QString("X : %1").arg(QString::number(VilmaControler_object.modelstate.pose.position.x,'f',3));
    QString gazebo_y_text = QString("Y : %1").arg(QString::number(VilmaControler_object.modelstate.pose.position.y,'f',3));
    QString gazebo_z_text = QString("Z : %1").arg(QString::number(VilmaControler_object.modelstate.pose.position.z,'f',3));
    QString latitude_text = QString("Z : %1").arg(QString::number(VilmaControler_object.car_gps_state.latitude,'f',9));
    QString longitude_text = QString("Z : %1").arg(QString::number(VilmaControler_object.car_gps_state.longitude,'f',9));
    QString quaternion_gazebo_x_text = QString("X : %1").arg(QString::number(VilmaControler_object.modelstate.pose.orientation.x,'f',3));
    QString quaternion_gazebo_y_text = QString("Y : %1").arg(QString::number(VilmaControler_object.modelstate.pose.orientation.y,'f',3));
    QString quaternion_gazebo_z_text = QString("Z : %1").arg(QString::number(VilmaControler_object.modelstate.pose.orientation.z,'f',3));
    QString quaternion_gazebo_w_text = QString("W : %1").arg(QString::number(VilmaControler_object.modelstate.pose.orientation.w,'f',3));
    QString quaternion_imu_x_text = QString("X : %1").arg(QString::number(VilmaControler_object.imu_data.orientation.x,'f',3));
    QString quaternion_imu_y_text = QString("Y : %1").arg(QString::number(VilmaControler_object.imu_data.orientation.y,'f',3));
    QString quaternion_imu_z_text = QString("Z : %1").arg(QString::number(VilmaControler_object.imu_data.orientation.z,'f',3));
    QString quaternion_imu_w_text = QString("Z : %1").arg(QString::number(VilmaControler_object.imu_data.orientation.w,'f',3));
    QString imu_ang_speed_x_text = QString("X : %1").arg(QString::number(VilmaControler_object.imu_data.angular_velocity.x,'f',3));
    QString imu_ang_speed_y_text = QString("Y : %1").arg(QString::number(VilmaControler_object.imu_data.angular_velocity.y,'f',3));
    QString imu_ang_speed_z_text = QString("Z : %1").arg(QString::number(VilmaControler_object.imu_data.angular_velocity.z,'f',3));
    QString imu_lin_acel_x_text = QString("X : %1").arg(QString::number(VilmaControler_object.imu_data.linear_acceleration.x,'f',3));
    QString imu_lin_acel_y_text = QString("Y : %1").arg(QString::number(VilmaControler_object.imu_data.linear_acceleration.y,'f',3));
    QString imu_lin_acel_z_text = QString("Z : %1").arg(QString::number(VilmaControler_object.imu_data.linear_acceleration.z,'f',3));
    QString gazebo_lin_vel_x_text = QString("X : %1").arg(QString::number(VilmaControler_object.modelstate.twist.linear.x,'f',3));
    QString gazebo_lin_vel_y_text = QString("Y : %1").arg(QString::number(VilmaControler_object.modelstate.twist.linear.y,'f',3));
    QString gazebo_lin_vel_z_text = QString("Z : %1").arg(QString::number(VilmaControler_object.modelstate.twist.linear.z,'f',3));
    QString gazebo_ang_vel_x_text = QString("X : %1").arg(QString::number(VilmaControler_object.modelstate.twist.angular.x,'f',3));
    QString gazebo_ang_vel_y_text = QString("Y : %1").arg(QString::number(VilmaControler_object.modelstate.twist.angular.y,'f',3));
    QString gazebo_ang_vel_z_text = QString("Z : %1").arg(QString::number(VilmaControler_object.modelstate.twist.angular.z,'f',3));


    ui->current_acel_label->setText(acel_text);
    ui->current_brake_label->setText(brake_text);
    ui->steering_status_label->setText(steering_text);
    ui->gazebo_x->setText(gazebo_x_text);
    ui->gazebo_y->setText(gazebo_y_text);
    ui->gazebo_z->setText(gazebo_z_text);
    ui->latitude->setText(latitude_text);
    ui->longitude->setText(longitude_text);
    ui->quaternion_gazebo_x->setText(quaternion_gazebo_x_text);
    ui->quaternion_gazebo_y->setText(quaternion_gazebo_y_text);
    ui->quaternion_gazebo_z->setText(quaternion_gazebo_z_text);
    ui->quaternion_gazebo_w->setText(quaternion_gazebo_w_text);
    ui->quaternion_imu_x->setText(quaternion_imu_x_text);
    ui->quaternion_imu_y->setText(quaternion_imu_y_text);
    ui->quaternion_imu_z->setText(quaternion_imu_z_text);
    ui->quaternion_imu_w->setText(quaternion_imu_w_text);
    ui->imu_ang_speed_x->setText(imu_ang_speed_x_text);
    ui->imu_ang_speed_y->setText(imu_ang_speed_y_text);
    ui->imu_ang_speed_z->setText(imu_ang_speed_z_text);
    ui->imu_lin_acel_x->setText(imu_lin_acel_x_text);
    ui->imu_lin_acel_y->setText(imu_lin_acel_y_text);
    ui->imu_lin_acel_z->setText(imu_lin_acel_z_text);
    ui->gazebo_lin_vel_x->setText(gazebo_lin_vel_x_text);
    ui->gazebo_lin_vel_y->setText(gazebo_lin_vel_y_text);
    ui->gazebo_lin_vel_z->setText(gazebo_lin_vel_z_text);
    ui->gazebo_ang_vel_x->setText(gazebo_ang_vel_x_text);
    ui->gazebo_ang_vel_y->setText(gazebo_ang_vel_y_text);
    ui->gazebo_ang_vel_z->setText(gazebo_ang_vel_z_text);



    if(VilmaControler_object.hand_brake_state.data>0.05)
    {
        ui->handbrake_button->setChecked(1);
    }
    else
    {
        ui->handbrake_button->setChecked(0);
    }
    if(VilmaControler_object.gears.data==1){
        ui->gears_forward_radio_button->setChecked(1);
    }
    if(VilmaControler_object.gears.data==0){
        ui->gears_neutral_radio_button->setChecked(1);
    }
    if(VilmaControler_object.gears.data==-1){
        ui->gears_backwards_radio_button->setChecked(1);
    }
    if(ui->Set_wheel_direction_button->isChecked()){
        if(!ui->Set_wheel_direction_from_table->isChecked()){
            VilmaControler_object.reorientate_to_pose(ui->Set_wheel_direction_x_input->text().toDouble(),ui->Set_wheel_direction_y_input->text().toDouble());
        }
        if(ui->Set_wheel_direction_from_table->isChecked())
        {
            double row_max = ui->Set_wheel_direction_table->rowCount();
            double column_max = ui->Set_wheel_direction_table->columnCount();
            double current_row;
            int ok;
            QTableWidgetItem *current_item = ui->Set_wheel_direction_table->item(0,2);
            if(current_item!=0){
                current_row= current_item->text().toDouble();
            }
            QTableWidgetItem *X_item = ui->Set_wheel_direction_table->item(current_row-1,0);
            QTableWidgetItem *Y_item = ui->Set_wheel_direction_table->item(current_row-1,1);
            if(X_item==0 || Y_item==0){ //reached end of X Y list
                VilmaControler_object.use_Steering(0);
                VilmaControler_object.set_gas_pedal(0);
                VilmaControler_object.set_brake_pedal(1);
                return;
            }
            ok=VilmaControler_object.reorientate_to_pose(X_item->text().toDouble(),Y_item->text().toDouble());
            if(ok==-1){
                current_item->setText(QString ("%1").arg(current_item->text().toDouble()+1));
            }

        }
    }
}

void MainWindow::on_Set_new_speed_toggled(bool checked)
{
    if(checked)
        ui->Enter_new_constant_speed->setEnabled(1);
    else
        ui->Enter_new_constant_speed->setEnabled(0);

}

void MainWindow::on_Constant_speed_button_toggled(bool checked)
{
    if(checked)
    {
        ui->Maintain_current_speed->setEnabled(1);
        ui->Set_new_speed->setEnabled(1);
    }else
    {
        ui->Maintain_current_speed->setEnabled(0);
        ui->Set_new_speed->setEnabled(0);
    }
}

void MainWindow::on_Set_wheel_direction_from_table_toggled(bool checked)
{
    if(checked)
    {
        ui->Set_wheel_direction_table->setEnabled(1);
    }else
    {
        ui->Set_wheel_direction_table->setEnabled(0);
    }
}

void MainWindow::on_current_acel_label_slider_sliderMoved(int position)
{
    VilmaControler_object.set_gas_pedal((float) position/100);
}

void MainWindow::on_current_brake_slider_sliderMoved(int position)
{
    VilmaControler_object.set_brake_pedal((float) position/100);
}

void MainWindow::on_steering_slider_sliderMoved(int position)
{
    VilmaControler_object.use_Steering((float) -position/100);
}

void MainWindow::on_handbrake_button_toggled(bool checked)
{
    if(checked)
    {
        if(VilmaControler_object.hand_brake_state.data<0.2)
        {
            VilmaControler_object.use_hand_brake();
        }
    }else
    {
        if(VilmaControler_object.hand_brake_state.data>0.05)
        {
            VilmaControler_object.use_hand_brake();
        }
    }
}

void MainWindow::on_gears_forward_radio_button_toggled(bool checked)
{
    if(checked)
    {
        VilmaControler_object.set_gears(1);
    }
}

void MainWindow::on_gears_neutral_radio_button_toggled(bool checked)
{
    if(checked)
    {
        VilmaControler_object.set_gears(0);
    }
}

void MainWindow::on_gears_backwards_radio_button_toggled(bool checked)
{
    if(checked)
    {
        VilmaControler_object.set_gears(-1);
    }
}



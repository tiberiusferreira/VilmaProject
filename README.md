VilmaProject
============
 Project of a car simulator using gazebo and ros. To install it run the install script in the tutorials folder and then go 
 to the buildall folder in the plugins directory and in a terminal type sudo make and then sudo make install. After that
 the gazebo-ros car plugins and models should be installed in the folders and typing "gazebo -s libgazebo_ros_api_plugin.so my_world.world"
 should open the simulator with the models. 
 
 There also are 2 control tools. One if located in the folder plugins->moversetas and is a console based keyboard controler
 for the vehicle. If the already compiled version doesn't work, making it with the included makefile in the folder should 
 be pretty straight forward, just type make in the terminal. 
 
 The GUI alternative which is a more complete one is in the VILMA_QT folder in the plugins directory. The project should be 
 imported in the QT and compiled if launching it with the vilma_controler_opened doesn't work. 

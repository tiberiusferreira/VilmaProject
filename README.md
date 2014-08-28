VilmaProject
============
 Code used by UNICAMP's autonomous car simulator. Consists so far of:
 1-Fiat Punto model.
 2-Gazebo plugin to make the car behave like a real car would and not be just a static model (vilma-plugin).
 3-//Deprecated// Qt based controller for the vehicle so it can be controlled beyond the command line and the car state can be 
 checked (vilma_controller). 
 4-A self driving Qt based controller which controls the car, shows car info and is able change the wheels orientation so the
 car orients itself to go to a specified position.
 
 Installation:
 
 1-Create a catkin directory.
 2-Copy the folders src to your catkin src folder.
 3-Do catkin_make as usual from catkin base dir.
 4-Do catkin_make install.
 5-Copy the necessary libraries from the install folder (the one from github) to your install folder.
 
 Usage:
 Open gazebo with the ros_gazebo plugin (rosrun gazebo_ros gazebo) in a terminal where the mentioned setup.bash has
 been sourced.
 Place the Vilma_vehicle model. 
 Control it using the plugins (rosrun vilma_*).

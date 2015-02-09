VilmaProject
============
 Code used by UNICAMP's autonomous car simulator. Consists so far of:
 1-Fiat Punto model which is used in conjuction with MORSE Simulator and ROS.
 2-A self driving Qt based controller which controls the car, shows car info, is able change the wheels orientation so the
 car orients itself to go to a specified position, controls the car speed, plots graphs about car position and desired trajectory and much more. 
 
 Installation:
 
 1-Install ROS.
 2-Install MORSE (http://www.openrobots.org/morse/doc/1.2/user/installation.html) using -DPYMORSE_SUPPORT=ON -DCMAKE_BUILD_TYPE=Release -DBUILD_ROS_SUPPORT=ON .
 3-Clone the repository.
 4-Optional Install QT creator (easier to edit the QT based interface).
 5-Install ROS (http://www.ros.org).
 6-Create a catkin repository.
 7-Put the src folder inside catkin repository.
 8-Execute catkin_make (or just run the binary inside the vilma_driver build folder if in a 64bit Ubuntu 14.04 distro).
 
 Usage:
 Go to the cloned repository folder and execute morse run run.py.
 Open the vilma_driver binary via terminal.


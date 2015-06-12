# VilmaProject
This is the repository for the VILMA simulator (veículo inteligente do Laboratório de Mobilidade Autônoma, UNICAMP).
The project has been restructured and now utilizes the MORSE simulator (https://www.openrobots.org/wiki/morse/)
and ROS (http://ros.org).

# Automated INSTALL. (Supported on Ubuntu 14.04)

Install ROS Indigo by "two line install":

wget https://raw.githubusercontent.com/oroca/oroca-ros-pkg/master/ros_indigo_install.sh

sh ros_indigo_install.sh

Download put all the content of the install_stable folder in the HOME directory.

Execute the setup_scriptReliable.sh script at HOME directory.

Close terminal and open a new one.

Execute startvilma.sh at home directory.



# Manual Install:

To compile Morse it is recommended to install python-dev, in special python3.4-dev .

MORSE must be installed with the following cmake parameters for it's utilization:

cmake -DPYMORSE_SUPPORT=ON -DCMAKE_BUILD_TYPE=Release -DBUILD_ROS_SUPPORT=ON 

-DPYTHON_EXECUTABLE=$(which python3.4) can also be usefull to indicate the python location, in this case python3.4.

In addition the following components must be installed

1-
git clone git://github.com/ros-infrastructure/catkin_pkg.git -b 0.1.9

cd catkin_pkg

sudo python3 setup.py install

git clone git://github.com/ros/catkin.git

cd catkin

sudo python3 setup.py install


2-
sudo apt-get install python3-dev

Install PyYAML with Python3 support (package python3-yaml on Debian/Ubuntu, or you can get the sources from http://pyyaml.org ) and build it using python3:

wget http://pyyaml.org/download/pyyaml/PyYAML-3.10.tar.gz

tar xvf PyYAML-3.10.tar.gz

cd PyYAML-3.10

sudo python3 setup.py install

3-
Get Setuptools:

sudo apt-get install python3-setuptools

Install rospkg using Python3:

git clone git://github.com/ros/rospkg.git

cd rospkg

sudo python3 setup.py install

Import the Vilma morse environment (go to VilmaProject/src and type morse import Vilma) 

Done (to use it start roscore and type morse run Vilma at VilmaProject/src)

To open the GUI for car controlling utilize the executable in the vilma_driver build folder (64 bits Ubuntu 14.04 tested) or compile it utilizing the catkin system. To compile using the catkin system it is necessary to copy the src folder of the VilmaDriver to the catkin workspace.

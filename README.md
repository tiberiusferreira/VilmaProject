# VilmaProject
This is the repository for the VILMA simulator (veículo inteligente do Laboratório de Mobilidade Autônoma, UNICAMP).
The project has been restructured and now utilizes the MORSE simulator (https://www.openrobots.org/wiki/morse/)
and ROS (http://ros.org).

MORSE must be installed with the following cmake parameters for it's utilization:
cmake -DPYMORSE_SUPPORT=ON -DCMAKE_BUILD_TYPE=Release -DBUILD_ROS_SUPPORT=ON -DPYTHON_EXECUTABLE=`which python3.3` ..

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
Install rospkg using Python3:
wget http://python-distribute.org/distribute_setup.py
sudo python3 distribute_setup.py

git clone git://github.com/ros/rospkg.git
cd rospkg
sudo python3 setup.py install

To open the simulation go to the folder containing run2.py and execute the following command:
morse run run2.py

To open the GUI for car controlling utilize the executable in the vilma_driver build folder (64 bits Ubuntu 14.04 tested) or compile it utilizing the catkin system.

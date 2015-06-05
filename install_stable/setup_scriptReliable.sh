#!/bin/bash
#apt-get update ;
#sudo apt-get upgrade ;
#sudo apt-get install python3.4-dev ;
echo This script should be executed at the HOME directory.
cd
chmod +x startvilma.sh
while true; do
    read -p "It is necessary to upgrade/install python3.4-dev \n
    or instalation will fail. Should I install it?\n y=yes n=no?" yn
    case $yn in
        [Yy]* ) sudo apt-get update;
        sudo apt-get upgrade;
        sudo apt-get -y install python3.4-dev ;
        break;;
        [Nn]* ) break;;
        * ) echo "Please answer yes (y) or no (n).";;
    esac
done
 mkbuild=1

echo Cleaning up possible previous files

if [ -f blender-2.71-linux-glibc211-x86_64.tar.bz2 ]; then
echo Extracting Blender Version 2.71 into blender-2.71-linux-glibc211-x86_64
tar xjf blender-2.71-linux-glibc211-x86_64.tar.bz2
else
  echo Missing blender-2.71-linux-glibc211-x86_64.tar.bz2, exiting
  exit 1
fi

if [ -d morse ]; then
  echo Found morse folder ok!
else
  echo There is no morse folder with morse install files of version 1.2_Stable, exiting
  exit 1
fi



echo Entering Morse Directory
cd morse
if [ $? -eq 0 ]; then
    echo Sucess, entered morse directory
else
    echo Failed to enter morse directory, exiting
    exit 1
fi


echo Making a build Morse directory
rm -rf build
mkdir build
if [ $? -eq 0 ]; then
    echo Successfully created the build directory.
else
    echo Failed to create the build directory, exiting
    exit 1
fi

echo Entering Morse build Directory
cd build
if [ $? -eq 0 ]; then
    echo Sucess, entered build directory inside morse folder
else
    echo Failed to enter build directory inside morse folder, exiting
    exit 1
fi


echo Building Morse
cmake -DPYMORSE_SUPPORT=ON -DCMAKE_BUILD_TYPE=Release -DBUILD_ROS_SUPPORT=ON -DPYTHON_EXECUTABLE=$(which python3.4) ..
if [ $? -eq 0 ]; then
    echo Successfully executed cmake.
else
    echo Failed to execute cmake, exiting
    exit 1
fi


echo Installing Morse
make clean
make
sudo make -s install
if [ $? -eq 0 ]; then
    echo Successfully installed.
else
    echo Failed to install, exiting
    exit 1
fi

echo Checking Morse
echo 'export MORSE_BLENDER=~/blender-2.71-linux-glibc211-x86_64/blender' >> ~/.bashrc
export MORSE_BLENDER=~/blender-2.71-linux-glibc211-x86_64/blender
cd
echo Entering catkin_pkg directory
cd catkin_pkg
if [ $? -eq 0 ]; then
    echo Successfully entered.
else
    echo Failed to enter, exiting
    exit 1
fi
echo Installing catkin_pkg
sudo python3 setup.py install
if [ $? -eq 0 ]; then
    echo Successfully installed.
else
    echo Failed to install, exiting
    exit 1
fi
cd
echo Entering catkin dir.
cd catkin
if [ $? -eq 0 ]; then
    echo Successfully entered.
else
    echo Failed to enter, exiting
    exit 1
fi
echo Intalling catkin.
sudo python3 setup.py install
if [ $? -eq 0 ]; then
    echo Successfully installed.
else
    echo Failed to install, exiting
    exit 1
fi
cd
echo Extracting PyYAML-3
tar xf PyYAML-3.10.tar.gz
if [ $? -eq 0 ]; then
    echo Successfully extracted.
else
    echo Failed to extract, exiting
    exit 1
fi
echo Entering PyYAML-3.10 dir.
cd PyYAML-3.10
if [ $? -eq 0 ]; then
    echo Successfully entered.
else
    echo Failed to enter, exiting
    exit 1
fi
echo Installing PyYAML-3
sudo python3 setup.py install
if [ $? -eq 0 ]; then
    echo Successfully installed.
else
    echo Failed to install, exiting
    exit 1
fi
echo Installing python3-setuptools
sudo apt-get install python3-setuptools
if [ $? -eq 0 ]; then
    echo Successfully installed.
else
    echo Failed to install, exiting
    exit 1
fi
echo Installing ros-indigo-control-toolbox
sudo apt-get install ros-indigo-control-toolbox
if [ $? -eq 0 ]; then
    echo Successfully installed.
else
    echo Failed to install, exiting
    exit 1
fi
cd
echo Entering rospkg dir
cd rospkg
if [ $? -eq 0 ]; then
    echo Successfully entered.
else
    echo Failed to enter, exiting
    exit 1
fi
echo Installing rospkg
sudo python setup.py install
if [ $? -eq 0 ]; then
    echo Successfully installed.
else
    echo Failed to install, exiting
    exit 1
fi
sudo python3 setup.py install
if [ $? -eq 0 ]; then
    echo Successfully installed.
else
    echo Failed to install, exiting
    exit 1
fi

morse check

cd

morse import Vilma

echo ALL DONE! Please, close this terminal and open a new one
echo so the MORSE_BLENDER variable can take effect.
export MORSE_BLENDER=~/blender-2.71-linux-glibc211-x86_64/blender

#!/bin/bash
#apt-get update ;
#sudo apt-get upgrade ;
#sudo apt-get install python3.4-dev ;
while true; do
    read -p "It is recommended to upgrade/install python3.4-dev\n y=yes n=no?" yn
    case $yn in
        [Yy]* ) sudo apt-get update;
        sudo apt-get upgrade;
        sudo apt-get -y install python3.4-dev ;
        break;;
        [Nn]* ) break;;
        * ) echo "Please answer yes (y) or no (n).";;
    esac
done


echo Cleaning up possible previous files
mkbuild=1;
getmorse=1;
extractblender=1;
getblender=1;
cd
if [ -d "morse" ]; then
echo -e "\e[1;31mFound FOLDER morse. \e[0m"
  while true; do
      read -p "Do you want to erase it?  y=yes n=no?" yn
      case $yn in
          [Yy]* ) rm -rf morse; break;;
          [Nn]* ) getmorse=0; break;;
          * ) echo "Please answer yes (y) or no (n).";;
      esac
  done
fi


if [ -d "morse/build" ]; then
echo -e "\e[1;31mFound folder morse/build. \e[0m"
  while true; do
      read -p "Do you want to erase it?" yn
      case $yn in
          [Yy]* ) rm -rf morse/build; break;;
          [Nn]* ) mkbuild=0; break;;
          * ) echo "Please answer yes (y) or no (n).";;
      esac
  done
fi


if [ -d "blender-2.71-linux-glibc211-x86_64" ]; then
echo -e "\e[1;31mFound folder blender-2.71-linux-glibc211-x86_64. \e[0m"
  while true; do
      read -p "Do you want to erase it?" yn
      case $yn in
          [Yy]* ) rm -rf blender-2.71-linux-glibc211-x86_64; break;;
          [Nn]* ) extractblender=0; break;;
          * ) echo "Please answer yes (y) or no (n).";;
      esac
  done
fi

if [ -f "blender-2.71-linux-glibc211-x86_64.tar.bz2" ]; then
echo -e "\e[1;31mFound file blender-2.71-linux-glibc211-x86_64. \e[0m"
  while true; do
      read -p "Do you want to erase it?" yn
      case $yn in
          [Yy]* ) rm blender-2.71-linux-glibc211-x86_64; break;;
          [Nn]* ) getblender=0; break;;
          * ) echo "Please answer yes (y) or no (n).";;
      esac
  done
fi


if [ $getmorse -ne 0 ]; then
  echo Cloning Morse Directory
  git clone --progress -b 1.2_STABLE https://github.com/morse-simulator/morse.git
  if [ $? -eq 0 ]; then
      echo Sucess, cloned Morse source
  else
      echo Failed to clone, exiting
      exit 1
  fi
fi

if [ $getblender -ne 0 ]; then
  echo Cloning Blender Version 2.71 Directory
  wget  http://download.blender.org/release/Blender2.71/blender-2.71-linux-glibc211-x86_64.tar.bz2
  if [ $? -eq 0 ]; then
      echo Successfully downloaded Blender.
  else
      echo Failed to downloaded Blender, exiting.
      exit 1
  fi
fi

if [ $extractblender -ne 0 ]; then
echo Extracting Blender Version 2.71 into blender-2.71-linux-glibc211-x86_64
tar xjf blender-2.71-linux-glibc211-x86_64.tar.bz2
fi


echo Entering Morse Directory
cd morse
if [ $? -eq 0 ]; then
    echo Sucess, entered morse directory
else
    echo Failed to enter morse directory, exiting
    exit 1
fi


if [ $mkbuild -ne 0 ]; then
  echo Making a build Morse directory
  mkdir build
  if [ $? -eq 0 ]; then
      echo Successfully created the build directory.
  else
      echo Failed to create the build directory, exiting
      exit 1
  fi
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
echo Cloning catkin_pkg.
git clone git://github.com/ros-infrastructure/catkin_pkg.git -b 0.1.9
if [ $? -eq 0 ]; then
    echo Successfully cloned.
else
    echo Failed to clone, exiting
    exit 1
fi
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
echo Cloning catkin
git clone git://github.com/ros/catkin.git
if [ $? -eq 0 ]; then
    echo Successfully cloned.
else
    echo Failed to clone, exiting
    exit 1
fi
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
echo Getting Pyyaml.
wget http://pyyaml.org/download/pyyaml/PyYAML-3.10.tar.gz
if [ $? -eq 0 ]; then
    echo Successfully got.
else
    echo Failed to get, exiting
    exit 1
fi
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
echo Cloning rospkg
git clone git://github.com/ros/rospkg.git
if [ $? -eq 0 ]; then
    echo Successfully cloned.
else
    echo Failed to clone, exiting
    exit 1
fi
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

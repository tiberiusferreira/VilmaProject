#!/bin/bash
echo Execute me at at HOME folder, where the project was installed!
echo Resuming in 3 seconds...
sleep 3
cd
roscore &
sleep 4
morse run Vilma &
chmod +x ./vilma_driver_1_0/binary/vilma_driver_widget_qtBuilt
cd vilma_driver_1_0/binary/
sleep 1
echo NOT Using HIGH DPI Configuration.
echo If ARE using a HIDPI screen edit this script from
echo 'export QT_DEVICE_PIXEL_RATIO=1' to 'export QT_DEVICE_PIXEL_RATIO=2'
sleep 3
export QT_DEVICE_PIXEL_RATIO=1
./vilma_driver_widget_qtBuilt

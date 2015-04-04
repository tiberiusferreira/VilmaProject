#!/bin/bash
rosrun topic_tools relay /left/image /left/image_raw &
rosrun topic_tools relay /right/image /right/image_raw &

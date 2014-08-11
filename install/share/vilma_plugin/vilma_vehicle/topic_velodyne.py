#!/usr/bin/env python

import rospy
from sensor_msgs.msg import PointCloud

horizontal_samples = 64
vertical_samples = 48

def callback(data):
    x = open('velodyne_x.txt','w')
    y = open('velodyne_y.txt','w')
    z = open('velodyne_z.txt','w')

    for j in range(vertical_samples):
        for i in range(horizontal_samples-1,-1,-1):
            x.write("%g " % (data.points[(j*horizontal_samples)+i].x))
            y.write("%g " % (-data.points[(j*horizontal_samples)+i].y))
            z.write("%g " % (-data.points[(j*horizontal_samples)+i].z))

        x.write("\n")
        y.write("\n")
        z.write("\n")

    x.close()
    y.close()
    z.close()

    rospy.signal_shutdown('End of process!')

def getVelodyne():
    rospy.init_node('getVelodyne', anonymous=True)
    rospy.Subscriber("scan", PointCloud, callback)
    rospy.spin()

if __name__ == '__main__':
    getVelodyne()
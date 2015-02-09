import sys
sys.path.append("../teste8")

from Carina2Class import *
from sensor import *
from morse.builder import *


class Carina2Builder(Robot):
    def __init__(self):
        Robot.__init__(self, "carina2.blend")           
        self.properties(classpath="Carina2Class.Carina2Class")
        #add odometry
        odometry = Odometry()
        #odometry.translate(0,0,0)
        self.append(odometry)
        odometry.add_stream('ros', topic='/odom')


        pose = Pose()
        pose.translate(0,1.3,0.2)
        self.append(pose)               
        #pose.add_stream("ros", method="morse.middleware.ros.pose.TFPublisher", topic="/base_link")
        pose.add_stream("ros", topic="/pose")

        # add sick sensor
        sick = Sick()
        sick.translate(0,2.6,0.2)
        sick.rotate(0,0,1.570796327)
        self.append(sick)
        sick.add_stream("ros", topic='/sick')

        #add gps
        gps = GPS()
        gps.translate(0,1.3,0.2)
        self.append(gps)
        gps.add_stream("ros", topic='/gps')

        #add imu
        imu = IMU()
        imu.translate(0,1.3,0.2)
        self.append(imu)
        imu.add_stream("ros", topic='/imu')

        #velocity
        velocity = Velocity()
        velocity.translate(0,1.3,0.2)
        self.append(velocity)
        velocity.add_stream("ros", topic='/velocity')           




        # A pan-tilt unit to be able to orient the cameras
        Platine = PTU()
        Platine.translate(x=0.2000, z=0.9000)
        self.append(Platine)

        # The STEREO UNIT, where the two cameras will be fixed
        Stereo = StereoUnit()
        Stereo.translate(z=0.0400)
        Platine.append(Stereo)

        # Left camera
        CameraL = VideoCamera()
        CameraL.translate(x=0.1000, y=0.2000, z=0.0700)
        Stereo.append(CameraL)
        CameraL.properties(capturing = True)
        CameraL.properties(cam_width = 320)
        CameraL.properties(cam_height = 240)
        CameraL.properties(cam_focal = 25.0000)
        CameraL.add_stream("ros",topic='cameraL')

        # Right camera
        CameraR = VideoCamera()
        CameraR.translate(x=0.1000, y=-0.2000, z=0.0700)
        Stereo.append(CameraR)
        CameraR.properties(capturing = True)
        CameraR.properties(cam_width = 320)
        CameraR.properties(cam_height = 240)
        CameraR.properties(cam_focal = 25.0000)
        CameraR.add_stream("ros",topic='cameraR')








        print("bge alive")


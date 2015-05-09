import sys
import logging; logger = logging.getLogger("morse.builder." + __name__)
import math
from morse.builder.creator import SensorCreator, bpymorse
from morse.builder.blenderobjects import *
from std_msgs.msg import Float64MultiArray, MultiArrayDimension
from morse.middleware.ros import ROSPublisher, mathutils


class wheelspeedPub(ROSPublisher):
    """ Publish the wheel speed of the car. """
    ros_class = Float64MultiArray
    

    def default(self, ci='unused'):
        arrayList = []
        arrayList.append(self.data['w_fl'])
        arrayList.append(self.data['w_fr'])
        arrayList.append(self.data['w_rl'])
        arrayList.append(self.data['w_rr'])
        dim_fl = MultiArrayDimension()
        dim_fl.size = sys.getsizeof(self.data['w_fl'])
        dim_fl.label = 'FrontLeftWheelSpeed'
        dim_fl.stride = sys.getsizeof(self.data['w_fl'])

        dim_fr = MultiArrayDimension()
        dim_fr.size = sys.getsizeof(self.data['w_fr'])
        dim_fr.label = 'FrontRightWheelSpeed'
        dim_fr.stride = sys.getsizeof(self.data['w_fr'])

        dim_rl = MultiArrayDimension()
        dim_rl.size = sys.getsizeof(self.data['w_rl'])
        dim_rl.label = 'RearLeftWheelSpeed'
        dim_rl.stride = sys.getsizeof(self.data['w_rl'])

        dim_rr = MultiArrayDimension()
        dim_rr.size = sys.getsizeof(self.data['w_rr'])
        dim_rr.label = 'RearRightWheelSpeed'
        dim_rr.stride = sys.getsizeof(self.data['w_rr'])
 

        wheelspeed = Float64MultiArray()
        wheelspeed.data = arrayList
        wheelspeed.layout.dim.append(dim_fl)
        wheelspeed.layout.dim.append(dim_fr)
        wheelspeed.layout.dim.append(dim_rl)
        wheelspeed.layout.dim.append(dim_rr)
        wheelspeed.layout.data_offset = 0
        self.publish(wheelspeed)

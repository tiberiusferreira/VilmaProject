import logging; logger = logging.getLogger("morse." + __name__)
from morse.core import blenderapi
import morse.core.sensor
from morse.helpers.components import add_data
from rosgraph_msgs.msg import Clock
from morse.middleware.ros import ROSPublisher
class Carsensor(morse.core.sensor.Sensor):
    """ 
    This sensor returns the speed of the wheel 
    """
    _name = "Carsensor"

    add_data('w_fl', 0.0, "float",
             'x coordinate of the sensor, in world coordinate, in meter')
    add_data('w_fr', 0.0, "float",
             'y coordinate of the sensor, in world coordinate, in meter')
    add_data('w_rf', 0.0, "float",
             'z coordinate of the sensor, in world coordinate, in meter')
    add_data('w_rr', 0.0, "float",
             'rotation around the Z axis of the sensor, in radian')

    def __init__(self, obj, parent=None):
        """ Constructor method.

        Receives the reference to the Blender object.
        The second parameter should be the name of the object's parent.
        """
        logger.info('%s initialization' % obj.name)
        # Call the constructor of the parent class
        morse.core.sensor.Sensor.__init__(self, obj, parent)

        logger.info('Component initialized, runs at %.2f Hz', self.frequency)
        

    def default_action(self):
        """ Get the wheel speed of the blender object. """
        #self.local_data['w_lr'] = self.position_3d.y
        #self.local_data['w_rf'] = self.position_3d.z
        #self.local_data['w_rr'] = self.position_3d.yaw
        #self.local_data['pitch'] = self.position_3d.pitch
        #self.local_data['roll'] = self.position_3d.roll
        scene = blenderapi.scene()
        for objects in scene.objects:
                if 'wheel1' in objects.name:
                    logger.info('1 %s' % objects.getAngularVelocity(1) )
                    self.local_data['w_fl'] = objects.getAngularVelocity(1)[0]		
                if 'wheel2' in objects.name:
                    logger.info('2 %s' % objects.getAngularVelocity(1) )
                    self.local_data['w_fr'] = objects.getAngularVelocity(1)[0]	
                if 'wheel3' in objects.name:
                    logger.info('3 %s' % objects.getAngularVelocity(1) )
                    self.local_data['w_rf'] = objects.getAngularVelocity(1)[0]	
                if 'wheel4' in objects.name:
                    logger.info('4 %s' % objects.getAngularVelocity(1) )
                    self.local_data['w_rr'] = objects.getAngularVelocity(1)[0]	




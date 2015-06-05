import logging; logger = logging.getLogger("morse." + __name__)

import morse.core.sensor
from morse.core import blenderapi
from morse.core.services import service, async_service
from morse.core import status
from morse.helpers.components import add_data, add_property

class Wheelspeed(morse.core.sensor.Sensor):
    """Write here the general documentation of your sensor.
    It will appear in the generated online documentation.
    """
    _name = "Wheelspeed"
    _short_desc = "Provides the velocity of each of the four car wheels."

    # define here the data fields exported by your sensor
    # format is: field name, default initial value, type, description
    add_data('w_fl', 0.0, "float",
             'x coordinate of the sensor, in world coordinate, in meter')
    add_data('w_fr', 0.0, "float",
             'y coordinate of the sensor, in world coordinate, in meter')
    add_data('w_rl', 0.0, "float",
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

        scene = blenderapi.scene()
        for objects in scene.objects:
                if 'wheel1' in objects.name:
                    self.local_data['w_fl'] = objects.getAngularVelocity(1)[0]	 #(1) means get velocity relative to local frame [0] means get in x axis only
                    #logger.info('Front Left = %s' % objects.getAngularVelocity(1) )
                if 'wheel2' in objects.name:
                    self.local_data['w_fr'] = objects.getAngularVelocity(1)[0]  
                    #logger.info('Front Left = %s' % objects.getAngularVelocity(1)[0] )
                if 'wheel3' in objects.name:
                    self.local_data['w_rr'] = objects.getAngularVelocity(1)[0]  
                    #logger.info('Front Left = %s' % objects.getAngularVelocity(1)[0] )
                if 'wheel4' in objects.name:
                    self.local_data['w_rl'] = objects.getAngularVelocity(1)[0]  
                    #logger.info('Front Left = %s' % objects.getAngularVelocity(1)[0] )            




from morse.builder.creator import SensorCreator

class Wheelspeed(SensorCreator):
    def __init__(self, name=None):
        SensorCreator.__init__(self, name, \
                               "Vilma.sensors.wheelspeed.Wheelspeed",\
                               "wheelspeed")


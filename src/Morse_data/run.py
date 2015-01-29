import sys
sys.path.append("../Morse_data")

from Carina2Builder import *
from morse.builder import *

		
carina2 = Carina2Builder()

carina2.add_service('socket')


#keyboard = Keyboard()
#robot.append(keyboard)

env = Environment("../Morse_data/city7.blend")

import sys
sys.path.append("../Morse_data")

from Carina2Builder import *
from morse.builder import *

bpymorse.set_speed(30, 1, 1)

carina2 = Carina2Builder()

carina2.add_service('socket')


#keyboard = Keyboard()
#robot.append(keyboard)

env = Environment("../Morse_data/empty.blend", fastmode=True)
env.set_log_level('morse.middleware.socket_request_manager', 'warning')
env.set_log_level('morse.core.request_manager', 'warning')
#env = Environment("../Morse_data/empty.blend")

#!/usr/bin/env python

#Esta eh a parte logica do robo, ela tem que herdar de morse.core.robot Robot
#nao confundir esta heranca com o Robot do builder
import logging; logger = logging.getLogger("morse." + __name__)
import morse.middleware.ros.abstract_ros
import morse.core.robot
import morse.builder.bpymorse
from morse.core.services import service
from morse.builder import *


from morse.middleware.ros_request_manager import *
from morse.middleware.ros.abstract_ros import *

class VilmaClass(morse.core.robot.Robot):
			
	
	def __init__(self, obj, parent=None):
		logger.info('%s initialization' % obj.name)
		super(self.__class__,self).__init__(obj, parent)
		logger.info('Component initialized')
		print("############################## SOME TESTS ##############################")			
		#obj['keyboard'] = 1
		#print(obj['keyboard'])
		#obj['keyboard'] = 0
		#print(obj['keyboard'])
		#self.bge_object.getNumWheels()

 		#add imu
		#pub=ROSPublisher()




		scene = self.bge_object.scene
		for objects in scene.objects:
			if 'wheel1' in objects.name:
				logger.info('%s' % objects.getAngularVelocity(1)[0] )

				
		
		print("############################## END  TESTS ##############################")		
		
	
	#======================================================="
	#services examples
	#test example id carina2 changeProperty [1]	
	@service
	def addAB(self, a,b):
		c = a+b
		return c	
	
	@service
	def changeProperty(self, a):
		robot = self.bge_object
		robot['keyboard'] = a
		
		#return c	
	
	@service
	def printProperty(self):
		robot = self.bge_object
		a = robot['keyboard']
		#a = "hello"
		#return a
		return a
	
	#end services examples	
	#======================================================="
	
	
	#car services
	#=======================================================
		
	#set autonomous
	# param autonomous (on/off)
	@service
	def autonomous(self, autonomous):
		robot = self.bge_object
		robot['autonomous'] = autonomous	
	
	#set Brake 
	# param Brake(on/off brake autonomous)
	# param brakeAmount (float of amount brake)	
	@service
	def brake(self, Brake, brakeAmount):
		robot = self.bge_object
		robot['Brake'] = brakeState
		robot['brakeAmount'] = brakeAmount
		
		
	#set Power (acceleration)
	# param Power (on/off power autonomous)
	# param powerAmount (float of amount power, simula o pedal do acelerador)
	# param velocityAmount (float of amount power, velocidade final)	
	@service
	def power(self, Power, powerAmount, velocityAmount):
		robot = self.bge_object
		robot['Power'] = Power
		robot['powerAmount'] = powerAmount		
		robot['velocityAmount'] = velocityAmount
	
	
	#set Steering (angulo da roda)
	# param Steering (on/off autonomous)
	# param steeringAmount (float (angulo))
	@service
	def steer(self, Steering, steeringAmount):
		robot = self.bge_object
		robot['Steering'] = Steering
		robot['steeringAmount'] = steeringAmount
	
	#@service
	#def brake(self,autonomous, brakeState, brakeAmount):
	#	robot = self.bge_object
	#	robot['autonomous'] = autonomous
	#	robot['brakeState'] = brakeState
	#	robot['brakeAmount'] = brakeAmount
	
	@service
	def controlpower(self, controlPower, powerAmount ,velocityAmount):
		robot = self.bge_object
		robot['controlPower'] = controlPower
		robot['powerAmount'] = powerAmount		
		robot['velocityAmount'] = velocityAmount
	
	@service
	def status(self):
		robot = self.bge_object
		#return (robot['velocity'], robot['Brake'])
		return (robot['velocity'])
			
	#car services
	#=======================================================

	'''
	def MyROSAction(self):
		return "OK"
	
	#ros_service teste
	#=======================================================
	@ros_service
	def teste(self, type=MyROSAction, component=None, name='teste2'):
		return "OK ros service"
	
	#=======================================================		
	'''		


	def default_action(self):

		pass

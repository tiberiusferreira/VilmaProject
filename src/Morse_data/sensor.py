import sys
sys.path.append("/home/tiago/Documents/MORSE/teste8")
from laserscanner import *

import logging; logger = logging.getLogger("morse.builder." + __name__)
import math
from morse.builder.creator import SensorCreator, bpymorse
from morse.builder.blenderobjects import *


class VideoCamera(SensorCreator):
    def __init__(self, name=None, \
                 classpath="morse.sensors.video_camera.VideoCamera", \
                 filename="video_camera"):
        SensorCreator.__init__(self, name, classpath, filename)
        self.camera = Camera("CameraRobot")
        self.camera.name = "CameraRobot"
        self.append(self.camera)
        self.properties(cam_width = 256, cam_height = 256, cam_focal = 35.0, \
                        capturing = True, Vertical_Flip = True)
        # set the frequency to 3 (20ips for ticrate = 60Hz)
        self.frequency(3)
        # add toggle capture action (`Space` key)
        bpymorse.add_sensor(type="KEYBOARD")
        obj = bpymorse.get_context_object()
        sensor = obj.game.sensors[-1]
        sensor.key = 'SPACE'
        bpymorse.add_controller(type='LOGIC_AND')
        controller = obj.game.controllers[-1]
        bpymorse.add_actuator(type='PROPERTY')
        actuator = obj.game.actuators[-1]
        actuator.mode = 'TOGGLE'
        actuator.property = 'capturing'
        controller.link(sensor = sensor, actuator = actuator)
        # looking in +X
        SensorCreator.rotate(self, x=math.pi/2, z=math.pi/2)
        # append CameraMesh with its textures
        self.append_meshes(['CameraMesh'], "camera")
    def rotate(self, x=0, y=0, z=0):
        SensorCreator.rotate(self, x=y, y=z, z=x)

class DepthCamera(VideoCamera):
    def __init__(self, name=None):
        VideoCamera.__init__(self, name, \
                             "morse.sensors.depth_camera.DepthCamera",\
                             "depth_camera")
        self.properties(cam_width = 128, cam_height = 64, \
                        cam_near=1.0, cam_far=20.0, retrieve_depth=True,
                        Vertical_Flip=False)
        self.camera.rotate(z=math.pi)

class VelodyneZB1(DepthCamera):
    def __init__(self, name=None):
        DepthCamera.__init__(self, name)
        # Always (MORSE_LOGIC) - And - Motion (rotation z: 0.017453)
        morselogic = [sensor for sensor in self._bpy_object.game.sensors \
                      if sensor.name.startswith('MORSE_LOGIC')]
        sensor = morselogic[0]
        bpymorse.add_controller(type='LOGIC_AND')
        controller = self._bpy_object.game.controllers[-1]
        # Motion (rotation z: 0.017453)
        bpymorse.add_actuator(type='MOTION', name='MORSE_ROTATE')
        actuator = self._bpy_object.game.actuators[-1]
        actuator.offset_rotation.y = self.camera._bpy_object.data.angle # FOV
        controller.link(sensor = sensor, actuator = actuator)
    def set_rotation(self, rotation):
        """set rotation per tic (in radian, relative to component frequency)"""
        actuator = self._bpy_object.game.actuators['MORSE_ROTATE']
        actuator.offset_rotation.y = rotation


# abstract class
class LaserSensorWithArc(SensorCreator):
    def get_ray_material(self):
        if 'RayMat' in bpymorse.get_materials():
            return bpymorse.get_material('RayMat')

        ray_material = bpymorse.create_new_material()
        ray_material.diffuse_color = (.9, .05, .2)
        ray_material.use_shadeless = True
        ray_material.use_raytrace = False # ? is it needed ?
        ray_material.use_cast_buffer_shadows = False # ? is it needed ?
        ray_material.use_cast_approximate = False # ? is it needed ?
        ray_material.use_transparency = True
        ray_material.transparency_method = 'Z_TRANSPARENCY'
        ray_material.alpha = 0.3
        ray_material.name = 'RayMat'
        # link material to object as: Arc_XXX.active_material = ray_material
        return ray_material

    def create_laser_arc(self):
        """ Create an arc for use with the laserscanner sensor

        The arc is created using the parameters in the laserscanner Empty.
        'resolution and 'scan_window' are used to determine how many points
        will be added to the arc.
        """
        scene = bpymorse.get_context_scene()
        laserscanner_obj = self._bpy_object

        # Delete previously created arc
        for child in laserscanner_obj.children:
            if child.name.startswith("Arc_"):
                scene.objects.unlink( child )

        # Read the parameters to create the arc
        properties = laserscanner_obj.game.properties
        resolution = properties['resolution'].value
        window = properties['scan_window'].value
        # Parameters for multi layer sensors
        try:
            layers = properties['layers'].value
            layer_separation = properties['layer_separation'].value
            layer_offset = properties['layer_offset'].value
        except KeyError as detail:
            layers = 1
            layer_separation = 0.0
            layer_offset = 0.0
        logger.debug ("Creating %d arc(s) of %.2f degrees, resolution %.2f" % \
                      (layers, window, resolution))
        mesh = bpymorse.new_mesh( "ArcMesh" )
        # Add the center vertex to the list of vertices
        verts = [ [0.0, 0.0, 0.0] ]
        faces = []
        vertex_index = 0

        # Set the vertical angle, in case of multiple layers
        if layers > 1:
            v_angle = layer_separation * (layers-1) / 2.0
        else:
            v_angle = 0.0

        # Initialise the parameters for every layer
        for layer_index in range(layers):
            start_angle = -window / 2.0
            end_angle = window / 2.0
            # Offset the consecutive layers
            if (layer_index % 2) == 0:
                start_angle += layer_offset
                end_angle += layer_offset
            logger.debug ("Arc from %.2f to %.2f" % (start_angle, end_angle))
            logger.debug ("Vertical angle: %.2f" % v_angle)
            arc_angle = start_angle

            # Create all the vertices and faces in a layer
            while arc_angle <= end_angle:
                # Compute the coordinates of the new vertex
                new_vertex = [ math.cos(math.radians(arc_angle)), \
                               math.sin(math.radians(arc_angle)), \
                               math.sin(math.radians(v_angle)) ]
                verts.append(new_vertex)
                vertex_index = vertex_index + 1
                # Add the faces after inserting the 2nd vertex
                if arc_angle > start_angle:
                    faces.append([0, vertex_index-1, vertex_index])
                # Increment the angle by the resolution
                arc_angle = arc_angle + resolution

            v_angle -= layer_separation

        mesh.from_pydata( verts, [], faces )
        mesh.update()
        # Compose the name of the arc
        arc_name = "Arc_%d" % window
        arc = bpymorse.new_object( arc_name, mesh )
        arc.data = mesh
        # Remove collision detection for the object
        arc.game.physics_type = 'NO_COLLISION'
        # Link the new object in the scene
        scene.objects.link( arc )
        # Set the parent to be the laserscanner Empty
        arc.parent = laserscanner_obj
        # Set the material of the arc
        arc.active_material = self.get_ray_material()
        return arc

    def after_renaming(self):
        arc = [child for child in self._bpy_object.children
               if child.name.startswith("Arc_")]
        if not arc:
            self.create_laser_arc()

            
class Velodyne_antigo(LaserSensorWithArc):
    def __init__(self, name=None):
        LaserSensorWithArc.__init__(self, name, \
                "laserscanner.LaserScannerRotationZ", "/home/tiago/Documents/MORSE/teste8/velodyne.blend")
        # set components-specific properties
        self.properties(Visible_arc = True, laser_range = 50.0, \
                        scan_window = 31.500, resolution = 0.5)
        # append velodyne mesh, from MORSE_COMPONENTS/sensors/velodyne.blend
        self.frequency(10)
        arc = self.create_laser_arc()
        # Select only arc (active)
        bpymorse.select_only(arc)
        # Rotate Arc to scan vertically
        arc.rotation_euler = (math.radians(90), math.radians(12), 0)
        bpymorse.apply_transform(rotation=True)
        #self.append_meshes(['VelodyneMesh'])

class Velodyne1(LaserSensorWithArc):
    def __init__(self, name=None):
        LaserSensorWithArc.__init__(self, name, \
                "laserscanner.LaserScannerRotationZ", "/home/tiago/Documents/MORSE/teste8/velodyne.blend")
        # set components-specific properties
        #self.properties(Visible_arc = False, laser_range = 50.0, \
        #                scan_window = 31.500, resolution = 0.5)
        self.frequency(0)
        self.properties(Visible_arc = False, laser_range = 50.0, \
                        scan_window = 32.0, resolution = 0.5)
        # append velodyne mesh, from MORSE_COMPONENTS/sensors/velodyne.blend
        arc = self.create_laser_arc()
        # Select only arc (active)
        bpymorse.select_only(arc)
        # Rotate Arc to scan vertically
        arc.rotation_euler = (math.radians(90), math.radians(12), 0)
        bpymorse.apply_transform(rotation=True)
        self.append_meshes(['VelodyneMesh'])        

class Velodyne2(LaserSensorWithArc):
	def __init__(self, name=None):
		LaserSensorWithArc.__init__(self, name, \
			"laserscanner.LaserScannerRotationZ", "/home/tiago/Documents/MORSE/teste8/velodyne.blend")
		# set components-specific properties
		#self.properties(Visible_arc = False, laser_range = 50.0, \
		#                scan_window = 31.500, resolution = 0.5)
		#self.frequency(1000.0)
		self.properties(Visible_arc = True, laser_range = 50.0, \
		scan_window = 32.0, resolution = 1)
		
		#self.layers()
		
		# append velodyne mesh, from MORSE_COMPONENTS/sensors/velodyne.blend
		arc = self.create_laser_arc()
		# Select only arc (active)
		bpymorse.select_only(arc)
		# Rotate Arc to scan vertically
		arc.rotation_euler = (math.radians(90), math.radians(12),  math.radians(0))

		bpymorse.apply_transform(rotation=True)              	
		self.append_meshes(['VelodyneMesh'])    

class Velodyne3(LaserSensorWithArc):
    def __init__(self, name=None):
        LaserSensorWithArc.__init__(self, name, \
                "laserscanner.LaserScannerRotationZ", "velodyne")
        # set components-specific properties
        self.properties(Visible_arc = True, laser_range = 50.0, \
                        scan_window = 31.500, resolution = 0.5)
        # append velodyne mesh, from MORSE_COMPONENTS/sensors/velodyne.blend
        arc = self.create_laser_arc()
        # Select only arc (active)
        bpymorse.select_only(arc)
        # Rotate Arc to scan vertically
        arc.rotation_euler = (math.radians(90), math.radians(12), 0)
        bpymorse.apply_transform(rotation=True)
        self.append_meshes(['VelodyneMesh'])
        
        

#class VelodyneTest(Velodyne2):
#    def __init__(self, name=None):
#        for 
#            Velodyne2.__init__(self, name, angle)       


class Hokuyo(LaserSensorWithArc):
    def __init__(self, name=None):
        LaserSensorWithArc.__init__(self, name, \
                                    "morse.sensors.laserscanner.LaserScanner",\
                                    "hokuyo")
        mesh = Cylinder("HokuyoCylinder")
        mesh.scale = (.04, .04, .08)
        mesh.color(0, 0, 0)
        self.append(mesh)
        # set components-specific properties
        self.properties(Visible_arc = False, laser_range = 30.0,
                scan_window = 270.0, resolution = 0.25)
        # set the frequency to 10 (6 scan/s for ticrate = 60Hz)
        self.frequency(10)

class Sick1(LaserSensorWithArc):
    def __init__(self, name=None):
        LaserSensorWithArc.__init__(self, name, \
                                    "morse.sensors.laserscanner.LaserScanner",\
                                    "sick")
        # set components-specific properties
        self.properties(Visible_arc = False, laser_range = 30.0,
                scan_window = 180.0, resolution = 1.0)
        # set the frequency to 10 (6 scan/s for ticrate = 60Hz)
        self.frequency(10)
        # append sick mesh, from MORSE_COMPONENTS/sensors/sick.blend
        self.append_meshes(['SickMesh'])

class SickLDMRS(LaserSensorWithArc):
    def __init__(self, name=None):
        LaserSensorWithArc.__init__(self, name, \
                                    "morse.sensors.laserscanner.LaserScanner",\
                                    "sick-ld-mrs")
        # set components-specific properties
        self.properties(Visible_arc = False, laser_range = 30.0,
                scan_window = 100.0, resolution = 0.25, layers = 4,
                layer_separation = 0.8, layer_offset = 0.125)
        mesh = Cube("SickMesh")
        mesh.scale = (.05, .0825, .044)
        mesh.color(1., 1., .9)
        self.append(mesh)
        # set the frequency to 10 (6 scan/s for ticrate = 60Hz)
        self.frequency(4)          

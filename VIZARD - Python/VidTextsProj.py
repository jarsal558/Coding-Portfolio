import viz
import vizact
import vizcam
#import vizinput

viz.setMultiSample(4)
viz.fov(60)

# Start Vizard
viz.go()

MOVE_SPEED = 5
TURN_SPEED = 60

car = viz.addChild('mini.osg')

player = viz.MainView


def updatecar():
	if viz.key.isDown(viz.KEY_UP):
		player.move([0,0,MOVE_SPEED*viz.elapsed()],viz.BODY_ORI)
	elif viz.key.isDown(viz.KEY_DOWN):
		player.move([0,0,-MOVE_SPEED*viz.elapsed()],viz.BODY_ORI)
	elif viz.key.isDown(viz.KEY_RIGHT):
		player.setEuler([TURN_SPEED*viz.elapsed(),0,0],viz.BODY_ORI,viz.REL_PARENT)
	elif viz.key.isDown(viz.KEY_LEFT):
		player.setEuler([-TURN_SPEED*viz.elapsed(),0,0],viz.BODY_ORI,viz.REL_PARENT)

	car.setPosition(player.getPosition())
	car.setEuler(player.getEuler(viz.BODY_ORI))
	car.setPosition([0.35,-1.2,0.2],viz.REL_LOCAL)
vizact.ontimer(0,updatecar)

# Add an object to scene.
duck = viz.add('duck.wrl', viz.WORLD, 1)
duck.setPosition(1,7,5)

# Warehouse environment
ware = viz.add('pit.osgb')

# Create render texture for camera video feed
video = viz.addRenderTexture()

# Create render node for camera
cam = viz.addRenderNode(size=(1280,720))

# Render to video feed texture
cam.setRenderTexture(video)

# Only render once per frame, in case stereo is enabled
cam.setRenderLimit(viz.RENDER_LIMIT_FRAME)

# Get handle to screen object and apply video feed to it
screen = ware.getChild('screen')
screen.texture(video)

# Create attachment point for following avatar
car_camera = viz.link(car,viz.NullLinkable)
car_camera.preTrans([0,2,-2])
car_camera.preEuler([0,10,0])

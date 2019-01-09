""" 
This script demonstrates how to use render nodes to create a virtual video camera. 
Press spacebar to toggle the camera between panning and following the avatar. 
Use the mouse and keyboard to navigate around the room. 
""" 

# http://forum.worldviz.com/showthread.php?t=4866

import viz
import vizact
import vizcam

viz.fov(60)
viz.go()

import vizinfo
vizinfo.InfoPanel()

# Use keyboard/mouse camera
cam = vizcam.WalkNavigate()
viz.cam.setHandler(cam)

# Add environment
model = viz.add('pit.osgb')

# Create render texture for camera video feed
video = viz.addRenderTexture()

# Create render node for camera
cam = viz.addRenderNode(size=(1280,720))

# Do not inherit view/projection settings from main window
cam.setInheritView(False)

# Set FOV for video camera
cam.setFov(60.0,1280/720.0,0.1,1000.0)

# Render to video feed texture
cam.setRenderTexture(video)

# Only render once per frame, in case stereo is enabled
cam.setRenderLimit(viz.RENDER_LIMIT_FRAME)

# Get handle to screen object and apply video feed to it
screen = model.getChild('screen')
screen.texture(video)

# Don't render to texture if screen isn't visible (optimization)
cam.renderOnlyIfNodeVisible([screen])

# Add avatar walking around in circles
avatar = viz.addAvatar('vcc_male2.cfg')
WalkSequence = vizact.sequence(
    vizact.walkTo((0,0,5))
    ,vizact.walkTo((5,0,0))
    ,vizact.walkTo((0,0,-5))
    ,vizact.walkTo((-5,0,0))
    ,viz.FOREVER
)
avatar.runAction(WalkSequence)

# Create attachment point for panning camera
pan_camera = viz.addGroup()
PanEulers = (100,45,0), (170,45,0)
pan_camera.setPosition([-10.94835, 11.09378, 13.61334])
pan_camera.setEuler(PanEulers[0])
PanAction = vizact.sequence(
    vizact.spinTo(euler=PanEulers[1],speed=5)
    ,vizact.spinTo(euler=PanEulers[0],speed=5)
    ,viz.FOREVER
)
pan_camera.runAction(PanAction)

# Create attachment point for following avatar
avatar_camera = viz.link(avatar,viz.NullLinkable)
avatar_camera.preTrans([0,2,-2])
avatar_camera.preEuler([0,10,0])

# Toggle between attachment points with spacebar
camera_link = viz.link(pan_camera,cam)
vizact.onkeydown(' ',camera_link.setSrc,vizact.choice([avatar_camera,pan_camera]))

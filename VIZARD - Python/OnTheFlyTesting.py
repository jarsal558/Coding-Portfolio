import viz
import vizcam
import oculus
import vizfx
import math
import random
import vizact

viz.go()

viz.clearcolor(viz.BLACK)

#Set the main viewpoint's position and orientation.
viz.MainView.setPosition([0,1,-5])
#viz.MainView.setEuler(10,10,10)

viz.startLayer(viz.QUADS)

# Axis Movement Key
# X-Axis:Left(-)/Right(+); Y-Axis:Up(+)/Down(-); Z-Axis:Forward(-)/Backward(+)

# Front Side
viz.normal([0,0,-1])
viz.vertexColor(1,0,0) # Red
viz.texCoord(0,0)
viz.vertex(-.5,-.5,-.5)
viz.texCoord(1,0)
viz.vertex(.5,-.5,-.5)
viz.texCoord(1,1)
viz.vertex(.5,.5,-.5)
viz.texCoord(0,1)
viz.vertex(-.5,.5,-.5)

# Back Side
viz.normal([0,0,1])
viz.vertexColor(0,1,0) # Green
viz.texCoord(0,0)
viz.vertex(-.5,-.5,.5)
viz.texCoord(1,0)
viz.vertex(.5,-.5,.5)
viz.texCoord(1,1)
viz.vertex(.5,.5,.5)
viz.texCoord(0,1)
viz.vertex(-.5,.5,.5)

#Top Side
viz.normal([0,1,0])
viz.vertexColor(0,0,1) #Blue
viz.texCoord(0,0)
viz.vertex(-.5,.5,-.5)
viz.texCoord(1,0)
viz.vertex(.5,.5,-.5)
viz.texCoord(1,1)
viz.vertex(.5,.5,.5)
viz.texCoord(0,1)
viz.vertex(-.5,.5,.5)

#Bottom Side
viz.normal([0,-1,0])
viz.vertexColor(1,1,0) #Yellow
viz.texCoord(0,0)
viz.vertex(-.5,-.5,-.5)
viz.texCoord(1,0)
viz.vertex(.5,-.5,-.5)
viz.texCoord(1,1)
viz.vertex(.5,-.5,.5)
viz.texCoord(0,1)
viz.vertex(-.5,-.5,.5)

#Left Side
viz.normal([-1,0,0,])
viz.vertexColor(1,0,1) #Purple
viz.texCoord(0,0)
viz.vertex(-.5,-.5,-.5)
viz.texCoord(1,0)
viz.vertex(-.5,.5,-.5)
viz.texCoord(1,1)
viz.vertex(-.5,.5,.5)
viz.texCoord(0,1)
viz.vertex(-.5,-.5,.5)

#Right Side
viz.normal([1,0,0])
viz.vertexColor(0,1,1) #Blue-Green
viz.texCoord(0,0)
viz.vertex(.5,-.5,-.5)
viz.texCoord(1,0)
viz.vertex(.5,.5,-.5)
viz.texCoord(1,1)
viz.vertex(.5,.5,.5)
viz.texCoord(0,1)
viz.vertex(.5,-.5,.5)

cube1 = viz.endLayer()

tex1 = viz.addTexture('stewart copeland.jpg')
cube1.texture( tex1 )

cube2 = cube1.copy()
cube2.setParent(cube1) # Sets cube1 as cube2 parent
cube2.setPosition([0,-1,0]) #Shift Cube Down
cube2.setAxisAngle( [1,0,0,45] ) # Rotate 45 Degrees Around X-Axis

cube3 = cube1.copy()
cube3.setParent(cube2)# Sets cube2 as cube3 parent
cube3.setPosition([0,2,0]) #Shift Cube Up
cube3.setAxisAngle( [1,0,0,45] ) # Rotate 45 Degrees Around X-Axis

# Directional Light
redLight = viz.addLight()
redLight.setEuler(45,0,0)
redLight.color(viz.RED)

# Point Light
greenLight = viz.addLight()
greenLight.position(1,0,0)
greenLight.spread(180)
greenLight.color(viz.GREEN)

#Spin the light node which will in turn spin the light
greenLight.addAction(vizact.spin(0,1,0,90))

# Spotlight
blueLight = viz.addLight()
blueLight.direction(-1,0,0)
blueLight.spread(90)
blueLight.color(viz.BLUE)

#Add a white object to reflect the light. 
ball = viz.add('white_ball.wrl')
ball.setPosition(1,1,0)
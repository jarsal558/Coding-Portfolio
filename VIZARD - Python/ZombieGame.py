import viz
import math
import vizact
import vizinput
import vizproximity

viz.setMultiSample(4)
viz.fov(60)

# Start Dialog Box
viz.go()

import vizinfo
vizinfo.add('The Headlines for Today: Zombie Apocalypse!. Well, if this isnt a dream come true...')

# Initial Message
speed = viz.get(viz.INITMESG)

# Username Input
name = vizinput.input('Enter I.D.')

# Begin or Quit?
quitNow = vizinput.ask('Those Zombies will not go back to their graves all by themselves.\n\n Wanna Help Them Out?')

# Closes Game
if quitNow == 0:
	viz.quit()

# Starts Game
if quitNow == 1:
     viz.scene( 1 )

# Scene 1
wheelbarrow = viz.add('wheelbarrow.ive',viz.WORLD, 1)
court = viz.add('court.ive', viz.WORLD,1) 
player = viz.addChild('FullBody_ClassTemplate_Final.OSGB', viz.WORLD,1)
playerView = viz.MainView

# Scene 2
wheelbarrowCopy = wheelbarrow.copy(scene = 2)
temple = viz.add('FunkyTemple.OSGB', viz.WORLD,2)

# Add pedestrian
pers = viz.addChild('vcc_female.cfg', viz.WORLD,2)
viz.MainView.move([0,0,-7])

# Animation Path
path = viz.addAnimationPath()
positions = [ [0,0,2], [2,0,0], [0,0,-2], [-2,0,0] ]

for x,pos in enumerate(positions):
    # Add a person at each control point and make it
    # semi-transparent, so the user can see where the
    # control points are
    b = viz.addChild('vcc_female.cfg', viz.WORLD,2,cache=viz.CACHE_CLONE)
    b.setPosition(pos)
    b.alpha(0.2)
    # Add the control point to the animation path
    # at the new time
    path.addControlPoint(x+1,pos=pos)

# Circular loop mode
path.setLoopMode(viz.CIRCULAR)

# Compute Tangents for Cubic Bezier Translations
path.computeTangents()

path.setAutoRotate(viz.ON)

# Link person to path
viz.link(path, pers)
# Play animation path
path.play()

# Scene 3
wheelbarrow.addParent(viz.WORLD,3)

# Scene 4 - Wheelbarrow Clone
wheelbarrowClone = wheelbarrow.clone(scene = 4)
# Modify Wheelbarrow
wheelbarrow.color( viz.PURPLE )
# Apply a transform to the original.
wheelbarrow.addAction( vizact.spin( 1,0,0,-180,viz.FOREVER ) )

for i in range(0,6):
     vizact.onkeydown( str(i), viz.scene, i )
     viz.clearcolor(viz.RED)

# Scene 5
duck = viz.add('duck.wrl', viz.WORLD,5) 
duck.setPosition([1,2,3]) 
duck.addAction(vizact.spin( 0,0,1,-270,viz.FOREVER))
ground = viz.addChild('ground.osgb', viz.WORLD,5)

# Controls
MOVE_SPEED = 7.5
TURN_SPEED = 75

def updateplayer():
     if viz.key.isDown(viz.KEY_UP):
          playerView.move([0,0,MOVE_SPEED*viz.elapsed()],viz.BODY_ORI)
     elif viz.key.isDown(viz.KEY_DOWN):
          playerView.move([0,0,-MOVE_SPEED*viz.elapsed()],viz.BODY_ORI)
     elif viz.key.isDown(viz.KEY_RIGHT):
          playerView.setEuler([TURN_SPEED*viz.elapsed(),0,0],viz.BODY_ORI,viz.REL_PARENT)
     elif viz.key.isDown(viz.KEY_LEFT):
          playerView.setEuler([-TURN_SPEED*viz.elapsed(),0,0],viz.BODY_ORI,viz.REL_PARENT)

     player.setPosition(playerView.getPosition())
     player.setEuler(playerView.getEuler(viz.BODY_ORI))
     player.setPosition([0.35,-1.2,0.2],viz.REL_LOCAL)
vizact.ontimer(0,updateplayer)
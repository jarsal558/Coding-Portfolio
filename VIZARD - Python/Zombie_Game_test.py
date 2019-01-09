import viz
import math
import vizact
import vizinput
import vizproximity

viz.setMultiSample(4)
viz.fov(60)

# Start Vizard with a prompt dialog box
viz.go()

import vizinfo
vizinfo.add('The zombie story goes here.')

#Retrieve text from the prompt
speed = viz.get(viz.INITMESG)

#Ask user for name
name = vizinput.input('What is your name?')

#Ask user if they want to play
quitNow = vizinput.ask('The Zombie story goes here.\n\n Would you like to play?')

#Closes game when chooses 'No'
if quitNow == 0:
	viz.quit()

#Goes to first level when chooses 'Yes'
if quitNow == 1:
     viz.scene( 1 )
    # viz.setScene( 1 )

# Try to convert the text into a number.
# If the text is invalid, then set the rotation speed to 90.
try:
     rotateSpeed = float(speed)
except:
     rotateSpeed = 90

#health class
'''
#Add labels
label = viz.addText('Score:',parent=viz.SCREEN,pos=[0.005,0.957,0],scale=[0.5,0.5,1])
label.setBackdrop(viz.BACKDROP_OUTLINE)
scoreLabel = viz.addText('0',parent=viz.SCREEN,pos=[0.128,0.957,0],scale=[0.5,0.5,1])
scoreLabel.setBackdrop(viz.BACKDROP_OUTLINE)

#Initialize health
hitPoints.health = 100
               
class playerHealth( viz.EventClass ):
     def __init__(self,health):
          viz.EventClass.__init__(self)

          #Increment health
          hitPoints.health -= 1
          hitPoints.message(str(hitPoints.health))
               
          self.callback(viz.BUTTON_EVENT,onButton)

playerHealth()

'''


# Add the ball and move it in front of the viewer
ball = viz.add('beachball.osgb')
ball.setPosition([0,1.5,3])
ball.addAction(vizact.spin(0,1,0,rotateSpeed))
     
#Add a model to scene 1. 
soccerball = viz.add('soccerball.ive',viz.WORLD, 1)
#Add a copy to scene 2.
soccerballCopy = soccerball.copy(scene = 2)
#Add a duplicate to scene 3.
soccerball.addParent(viz.WORLD,3)
#Add a clone to scene 4.
soccerballClone = soccerball.clone(scene = 4)
#Change the appearance of the original.
soccerball.color( viz.RED )
#Apply a transform to the original.
soccerball.addAction( vizact.spin( 0,1,0,90,viz.FOREVER ) )

for i in range(0,6):
     vizact.onkeydown( str(i), viz.scene, i )
     viz.clearcolor(viz.SKYBLUE)
     
#Add an object somewhere in the world. 
thing = viz.add('wheelbarrow.ive', viz.WORLD,5) 
thing.setPosition([1,2,3]) 
court = viz.add('court.ive', viz.WORLD,5) 

MOVE_SPEED = 5
TURN_SPEED = 60

player = viz.addChild('FullBody_ClassTemplate_Final.OSGB', viz.WORLD,5)
ground = viz.addChild('ground.osgb', viz.WORLD,5)

playerView = viz.MainView

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
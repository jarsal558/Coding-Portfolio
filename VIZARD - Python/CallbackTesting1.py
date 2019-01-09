import viz
import vizcam
import oculus
import vizfx
import math
import random
import vizact

viz.go()
viz.mouse(viz.OFF) # Disables Moving Around Viewpoint with Mouse
viz.MainView.setPosition(-7.5,10,-65)

viz.clearcolor(viz.BLACK)

# Add Objects
wacker = viz.add('C:\Users\Owner\Documents\VIZARD Projects\Franzwa_Weed_Wacker.OSGB')
toilet = viz.add('C:\Users\Owner\Documents\VIZARD Projects\Shen_Toilet.OSGB')
urinal = viz.add('C:\Users\Owner\Documents\VIZARD Projects\Shen_Urinal.OSGB')
projector = viz.add('C:\Users\Owner\Documents\VIZARD Projects\Salvatore_Projector.OSGB')

# Position Objects 
wacker.setPosition(-45,5,45)
toilet.setPosition(-15,0,-10)
urinal.setPosition(0,-10,0)
projector.setPosition(30,0,0)

arrow = viz.addChild('arrow.wrl')
arrow.setScale([0.1,0.1,0.1])
arrow.visible(viz.OFF)

class InputAdapter(viz.EventClass): 
    def __init__(self): 
        #Initialize Base Class 
        viz.EventClass.__init__(self) 
         
        #Register Callback with Event Class 
        self.callback(viz.KEYDOWN_EVENT,self.onKeyDown) 
        self.callback(viz.MOUSEUP_EVENT,self.onMouseUp)

	def onMouseUp(button):
		if button == viz.MOUSEBUTTON_LEFT:
			model = viz.intersect([-5,-1,-25],[-5,-3,-25])
			if model.valid:
				model.object.id
			#	pos = model.getPosition()
			#	pos[1] += .2
				#arrow.setPosition(pos)
				#arrow.visible(viz.ON)
				#arrow.disable(viz.PICKING)
			info = viz.intersect([0,0,0],[2.7,5,-5])
			if info.valid:
				print 'Intersected with object id:', info.object.id 
				print 'Intersected at location: ', info.point
	viz.callback(viz.MOUSEUP_EVENT,onMouseUp)
	
	def onKeyDown(self,key):
		if key == 'q':#play sound
			#deselect
			sound = viz.addAudio('Sean.wav')
		elif key == 'w':#move forward
			#deselect
			moveForward = vizact.moveTo(0,0,2,4)
			object.add(moveForward)
		elif key =='e':#spin 180
			#deselect
			turn = vizact.spin([0,1,0], 180,FOREVER)
			object.add(turn)
		elif key =='r':#scale up
			#deselect
			#Scale the object to half its size in all dimensions. 
			object.setScale( .5, .5, .5 ) 
		elif key =='c':#random color
			#deselect
			object.color( random.choice( [viz.RED,viz.GREEN,viz.SKYBLUE,viz.YELLOW,viz.ORANGE,viz.PURPLE] ) )
	viz.callback(viz.KEYDOWN_EVENT,onKeyDown)
	
		 




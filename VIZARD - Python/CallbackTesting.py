import viz
import vizact

viz.setMultiSample(4)
viz.fov(60)
viz.go()

viz.MainView.setPosition(-15,15,-50)
viz.mouse(viz.OFF)

viz.clearcolor(viz.BLACK)
urinal = viz.addChild('Shen_Urinal.OSGB')
toilet = viz.addChild('Shen_Toilet.OSGB')
wacker = viz.addChild('Franzwa_Weed_Wacker.OSGB')
projector = viz.addChild('Salvatore_Projector.OSGB')

urinal.setPosition([-25,2,1.5])
toilet.setPosition([20,2,1.5])
wacker.setPosition([-50,4,40])
projector.setPosition([1.0,2,1.5])


arrow = viz.addChild('arrow.wrl')
arrow.setScale([1,1,1])
arrow.visible(viz.OFF)

def pickObject():
     object = viz.pick()
     if object.valid():
          print 'Clicked on an object'

          pos = object.getPosition()
          pos[1] += 15
          arrow.setPosition(pos)
          arrow.visible(viz.ON)

     # Avoids Picking the Arrow
     if object.valid() and object != arrow:
          arrow.disable(viz.PICKING)

vizact.onmousedown(viz.MOUSEBUTTON_LEFT, pickObject)


def onKeyDown(key):
	if key == 'q':# Play Sound
		sound = viz.playSound('Sean.wav')

	elif key == 'w':# Move Object Forward
		moveForward = viz.move(0,0,15)
		object.add(moveForward)

	elif key =='e':# Spin 180 Degrees
		turn = vizact.spin(0,1,0, 180,250)
		viz.add(turn)

	elif key =='r':# Scale Object Up 1.5 Its Size
		object.setScale(1.5,1.5,1.5) 

	elif key =='c':#random color
		object.color(random.choice([viz.RED,viz.ORANGE,viz.YELLOW,viz.GREEN,viz.SKYBLUE,viz.PURPLE]))

viz.callback(viz.KEYDOWN_EVENT,onKeyDown)

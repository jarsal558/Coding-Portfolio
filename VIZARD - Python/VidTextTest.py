import viz
import vizact

viz.setMultiSample(4)
viz.fov(60)
viz.go()

import vizinfo
vizinfo.add('This script demonstrates how to use video textures.\nThis example displays an mpeg video file on the faces of a box.')

# Add a box object and spin it
import vizshape
box = vizshape.addBox()
box.setPosition([0,1.5,5])
box.addAction(vizact.spin(0,1,0,90))

# Add, start, and loop the videow
video = viz.addVideo('mona.mpg')
video.play()
video.loop()

# Apply the video to the object
box.texture(video)

# Add a ground surface
ground = viz.addChild('ground.osgb')

# Change the background clear color to a shade of blue
viz.clearcolor(viz.SKYBLUE)
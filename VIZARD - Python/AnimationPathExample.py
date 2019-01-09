import viz
import vizinfo
import vizact

viz.setMultiSample(4)
viz.fov(60)
viz.go()

court = viz.add('vcc_female.cfg', viz.WORLD,1) 
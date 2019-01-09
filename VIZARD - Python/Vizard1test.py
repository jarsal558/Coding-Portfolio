import viz
import math
import random
viz.go()

class Vehicle (viz.EventClass):
	
	def __init__(self):
		
		viz.EventClass._init_(self)
		
		self.model = viz.add('Wheelbarrow.IVE')
		
		self.callback(viz.MOUSEDOWN_EVENT, self.onMouseDown)
		
	def onMouseDown(self, button):
		
		if button == viz.MOUSEBUTTON_MIDDLE:
			self.model.setPosition(0,0,0.1,viz.REL_LOCAL)
		
vehicle = Vehicle()
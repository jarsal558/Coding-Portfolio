import viz
import math

viz.go

vertex_source = '''

uniform mat4 osg_ViewMatrix;

uniform vec3 light_pos;

varying float dotted [Compatibility Issues]
out float dotted

void main(void)
{

	//vec4 world_vector = gl_ModelViewMatrix * gl_Vertex;
	//gl_Position = gl_ModelViewProjection*...;
	//gl_TexCoord[0] = gl_TexureMatrix*gl_MultiTexCoord0();
	//
	//vec3 world_Normal = gl_NormalMatrix*gl_Normal;
	//
	//float dotted = dot(world_Normal,world_light_Position);
	//dotted = max(0.0,dotted);
	//
}

'''

test = viz.addShader()


light_pos = viz.addUniformFloat('light_pos', [0,0,0])
test.attach(light_pos)

currDegree = 0




def onTimer(id):
	light_pos.set( 5.0*math.cos(),0.0, 5.0*math.sin())
	global currDegree
	currDegree += 0


viz.callback(viz.TIMER_EVENT,onTimer)

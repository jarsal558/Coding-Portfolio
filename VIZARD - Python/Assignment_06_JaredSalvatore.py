vert_shader = '''
uniform mat4 osg_ViewMatrix;
varying vec3 normal;
varying vec4 temp;
uniform vec4 position; //In-World Coordinates

varying vec3 lightPos;

void main(void)

{
	// Transform Normal So Vertices are in Eye Space
	normal = normalize(gl_NormalMatrix*gl_Normal);

	// Transform Vertices to be in Projection Space / Pass to Frag. Shader
	gl_Position = gl_ModelViewProjectionMatrix*gl_Vertex;

	// Multiply Light Vector Pos. by ViewMatrix to put in ModelView Coords
	temp = position*gl_ModelViewMatrix;
	lightPos = normalize(gl_Position - temp);

	// Transform TexCoords / Send to Frag. Shader
	gl_TexCoord[0] = gl_TextureMatrix[0]*gl_MultiTexCoord0;

	// Compute Diffuse (Light's Position Dotted with Normal Orientation
	float diffuse = dot( lightPos, normal );
	diffuse = max(0.0,diffuse);
	gl_FrontColor = gl_Color*diffuse;
}

'''

frag_shader = '''

uniform sampler2D texture1;
varying vec4 texel;
//varying vec3 gl_Color;
void main(void)

{
	// Take in Vertex Shader Outputs
	// Receive Texel from Texture
	vec4 texel = texture2D(texture1,gl_TexCoord[0].xy);

	// Compute Final Color by Multiplying Texel and Vertex Color
	gl_FragColor = texel*gl_Color;
}
'''

import viz
import vizcam
import oculus
import vizfx
import math
import random
import vizact

viz.go()

# Set the main viewpoint's position and orientation.
viz.MainView.setPosition([-30,20,-250])

sphere = viz.add('sphere.OSGB')

# Create Shader Object Linked to *.vs and *.fs Files
# vert_shader = viz.addShader(vert=vert_shader)
# frag_shader = viz.addShader(frag=frag_shader)
sphereShader = viz.addShader(vert=vert_shader,frag=frag_shader)

# Create, Attach Necessary Uniforms to Bind Shader Uniforms to Vizard Application
# pos = [25,0,0]
# lightPos = viz.addUniformFloat('lightPos',pos);
color = viz.addUniformFloat('gl_FragColor',[20,20,20]);

# Apply Shader to Sphere
sphere.apply(sphereShader)

# Create Timer Event that Updates Uniform Light Position in Circle Around Sphere Object
t = 0.0
def onTimer(id):
	global t
	t = t + 5.0
	color.set([5.0*math.cos(t),0.0,5.0*math.sin(t)])


viz.callback(viz.TIMER_EVENT, onTimer)
viz.starttimer(0,0.1,viz.FOREVER)
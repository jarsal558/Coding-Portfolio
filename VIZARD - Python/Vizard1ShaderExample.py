vert_shader = '''

void main (void)
{
	gl_TexCoord[0] = gl_TextureMatrix[0]*gl_MultiTexCoord0;
	gl_FrontColor = gl_Color;
	gl_Position = gl_Vertex;
}
'''

import viz

viz.go()
viz.clearcolor(1,1,1)
my_shader = viz.addShader(vert = vert_shader)

viz.startLayer(viz.TRIANGLES)

viz.vertexColor(1,0,0); viz.texCoord(0,0)
viz.vertex(-0.5,-0.5,0)
viz.vertexColor(0,1,0); viz.texCoord(1,0)
viz.vertex(0.5,-0.5,0)
viz.vertexColor(0,0,1); viz.texCoord(0.5,1.0)
viz.vertex(0.0,0.5,0)

my_triangle = viz.endLayer()

my_triangle.apply(my_shader)

my_triangle.disable(viz.CULLING)

my_texture = viz.addTexture('lake3.jpg')
my_triangle.texture(my_texture)

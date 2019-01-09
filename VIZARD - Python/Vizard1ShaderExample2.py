vert_shader = '''

uniform float my_float;



'''



viz.vertex(0.0,0.5,0.1)

my_triangle = viz.endLayer()
my_float = viz.addUniformFloat('my_float',0.5)


my_triangle.apply(my_shader)


my_triangle.disable(viz.CULLING)

my_texture = viz.addTexture('lake3.jpg')
my_triangle.texture(my_texture)


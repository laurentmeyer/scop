#include "scop.h"
#include "alloc.h"

char const	*passthrough_vertex_shader[6] = 
{"#version 330 core\n",
"layout(location=0) in vec3 in_Position;\n",
"void main(void)\n",
"{\n",
"  gl_Position = vec4(in_Position, 1.0);\n",
"}\n"};

char const	*constant_fragment_shader[6] = 
{"#version 330 core\n",
"layout(location=0) out vec4 out_FragmentColor;\n",
"void main(void)\n",
"{\n",
"  out_FragmentColor = vec4(0.49, 0.87, 0.59, 1.0);\n",
"}\n"};

int main(void)
{
	t_ram	ram;

	init_ram(&ram);
	while (!glfwWindowShouldClose(ram.display.window))
	{
		glfwSwapBuffers(ram.display.window);
		glfwPollEvents();
	}
	return (EXIT_SUCCESS);
}
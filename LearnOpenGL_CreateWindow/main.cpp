// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
#include <stdio.h>

const GLuint WIDTH = 800, HEIGHT = 600;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		printf("Failed to create an GLFW window.\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		printf("Failed to initialize GLEW\n");
		glfwTerminate();
		return -1;
	}

	glViewport(0, 0, WIDTH, HEIGHT);
	glfwSetKeyCallback(window, key_callback);

	GLfloat redValue = 0.0f;
	GLboolean goingUp = true;

	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		if (goingUp)
		{
			redValue += 0.05f;

			if (redValue >= 1.0f)
			{
				goingUp = GL_FALSE;
			}
		}
		else
		{
			redValue -= 0.05f;

			if (redValue <= 0.0f)
			{
				goingUp = GL_TRUE;
			}
		}

		// Check and call events.
		glfwPollEvents();

		// Rending commands here
		glClearColor(0.0f, 0.0f, redValue, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap the buffers.
		glfwSwapBuffers(window);
	}

	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// When a user presses the escape key, we set the WindowShouldClose property to true, 
	// closing the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}
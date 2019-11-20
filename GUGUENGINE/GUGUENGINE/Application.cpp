#include <iostream>
#include "glew.h"		
#include "external/glfw/include/GLFW/glfw3.h"
#include "Mesh.h"
#include "Shader.h"
#include "Application.h"

int framebufferWidth, framebufferHeight;

//Shader mShader;
#define WIDTH 800
#define HEIGHT 600
int moveCheck = 0;
glm::vec3 curser = { 0, 0, 0 };
Mesh mMesh;
std::vector<glm::vec3> mMeshVec = MESH::create_circle(0.7f, { 255, 255, 255 }, 6, { 400, 300, 0 }, 0);
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);

	framebufferWidth = width;
	framebufferHeight = height;
}

void errorCallback(int errorCode, const char* errorDescription)
{
	std::cerr << "Error: " << errorDescription << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	static float time = 0;
	double xpos, ypos;
	//getting cursor position
	glfwGetCursorPos(window, &xpos, &ypos);
	std::cout << "Cursor Position at (" << xpos << " : " << ypos << std::endl;
	//if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	//	glfwSetWindowShouldClose(window, GLFW_TRUE);

	//if (key == GLFW_KEY_D)
	//{
	//	//glClearColor(0.7f, 0.7f, 0.7f, 1);
	//	time += 0.3f;
	//	std::cout << "TIME:" << time << std::endl;
	//	mMeshVec = MESH::create_circle(0.7f, { 255, 255, 255 }, 6, { 0, 0, 0 }, time);
	//}
}

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	std::cout << "Cursor Position (" << xpos << " : " << ypos << std::endl;

	curser = { xpos, ypos , 1 };
	std::cout << "x: " << curser.x << "y: " << curser.y << std::endl;
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		std::cout << "Left mouse button pressed" << std::endl;
	}
}

void Application::Init()
{
	std::cout << "Initialize" << std::endl;
	//mShader.BuildShader();
	//mMesh.setShaderID(mShader.GetShaderID());
}

void Application::Update()
{
	/*while (!glfwWindowShouldClose(Mywindow)) {*/

		double lastTime = glfwGetTime();
		int numOfFrames = 0;
		int count = 0;

		double currentTime = glfwGetTime();
		numOfFrames++;
		if (currentTime - lastTime >= 1.0) {

			printf("%f ms/frame  %d fps \n", 1000.0 / double(numOfFrames), numOfFrames);
			numOfFrames = 0;
			lastTime = currentTime;
		}
		
		/*mMesh.Initialize();

		mMesh.Update();*/

		/*glfwSwapInterval(1);

		glClearColor(0.4f, 0.3f, 0.3f, 1);
		glClear(GL_COLOR_BUFFER_BIT);*/

		//glUseProgram(mShader.GetShaderID());

		//glDrawArrays(GL_TRIANGLE_FAN/*mMesh.GetPointListPattern()*/, 0, /*mMesh.GetPointCount()*/24*sizeof(float));

		/*if (moveCheck % 2 == 1)
		{
			mMeshVec = MESH::create_circle(0.7f, { 255, 255, 255 }, 6, { curser.x, curser.y ,1 }, 0);
		}*/

		/*count++;*/

		glfwSwapBuffers(Mywindow);
		glfwPollEvents();
	
}

Application::Application()
{
	if (!glfwInit()) {

		std::cerr << "Error: GLFW 초기화 실패" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	Mywindow = glfwCreateWindow(
		WIDTH,
		HEIGHT,
		"OpenGL Example",
		NULL, NULL);
	if (!Mywindow) {

		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(Mywindow);

	glfwSetKeyCallback(Mywindow, keyCallback);
	glfwSetFramebufferSizeCallback(Mywindow, framebufferSizeCallback);
	glfwSetCursorPosCallback(Mywindow, cursorPositionCallback);
	glfwSetMouseButtonCallback(Mywindow, mouseButtonCallback);

	glewExperimental = GL_TRUE;
	GLenum errorCode = glewInit();
	if (GLEW_OK != errorCode) {

		std::cerr << "Error: GLEW 초기화 실패 - " << glewGetErrorString(errorCode) << std::endl;

		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}

	if (!GLEW_VERSION_3_3) {

		std::cerr << "Error: OpenGL 3.3 API is not available." << std::endl;

		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}

	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

}

Application::~Application()
{
	glUseProgram(0);
	glBindVertexArray(0);

	//mShader.Delete();
	//mMesh.Delete();

	glfwTerminate();

	std::exit(EXIT_SUCCESS);
}




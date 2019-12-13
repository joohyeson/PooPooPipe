#include <iostream>
#include "glew.h"		
#include "../GLFW/glfw3.h"
#include "Mesh.h"
//#include "Shader.h"
#include "Application.h"

int framebufferWidth, framebufferHeight;
Application* APPLICATION = nullptr;
//Shader mShader;
#define WIDTH 800
#define HEIGHT 800
//int moveCheck = 0;
//Vector3<float> curser = { 0, 0, 0 };
Mesh mMesh;
//std::vector<Vector3<float>> mMeshVec = MESH::create_circle(0.7f, { 255, 255, 255 }, 6, { 400, 300, 0 }, 0);

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);

	framebufferWidth = width;
	framebufferHeight = height;
}

void Application::Init()
{
	std::cout << "Initialize" << std::endl;
	APPLICATION = this;
}

void Application::Update()
{
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

	/*if (moveCheck % 2 == 1)
	{
		mMeshVec = MESH::create_circle(0.7f, { 255, 255, 255 }, 6, { curser.x, curser.y ,1 }, 0);
	}*/

	//glfwSwapBuffers(Mywindow);
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
	//const GLFWvidmode* screenMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	//GLFWmonitor* screenMonitor = glfwGetPrimaryMonitor();//fullscreen code
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

	//glfwSetKeyCallback(Mywindow, keyCallback);
	//glfwSetFramebufferSizeCallback(Mywindow, framebufferSizeCallback);
	//glfwSetCursorPosCallback(Mywindow, cursorPositionCallback);
	//glfwSetMouseButtonCallback(Mywindow, mouseButtonCallback);

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

	glfwTerminate();

	std::exit(EXIT_SUCCESS);
}

void Application::PollKeyboardEvent(SDL_Event& currentEvent)
{
	if (currentEvent.type == SDL_KEYDOWN || currentEvent.type == SDL_KEYUP)
	{
		Input::realInupt().SetKeyPressed(currentEvent.key.keysym.scancode, (SDL_EventType)currentEvent.type);
	}
}

void Application::PollMouseEvent(SDL_Event& currentEvent)
{
	if (currentEvent.type == SDL_MOUSEBUTTONDOWN || currentEvent.type == SDL_MOUSEBUTTONUP)
	{
		Input::realInupt().SetMousePressed(currentEvent.button.button, (SDL_EventType)currentEvent.type);
	}
}

void Application::setMyWindow(GLFWwindow& m)
{
	Mywindow = &m;

}
GLFWwindow* Application::getMyWindow()
{
	return Mywindow;
}
/*
 *juhye.son
 *9.17.2019
 *juhye.son990902@gmail.com
 *Application.cpp
 *make window 
 */
#include <iostream>
#include "glew.h"		
#include "../GLFW/glfw3.h"
#include "Mesh.h"
#include "Application.h"
#include "external/stb/include/stb_image.h"

int framebufferWidth, framebufferHeight;
Application* APPLICATION = nullptr;

#define WIDTH 1440
#define HEIGHT 810

Mesh mMesh;


void framebufferSizeCallback(GLFWwindow* /*window*/, int width, int height)
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

	double currentTime = glfwGetTime();
	numOfFrames++;
	if (currentTime - lastTime >= 1.0) {

		printf("%f ms/frame  %d fps \n", 1000.0 / double(numOfFrames), numOfFrames);
		numOfFrames = 0;
		lastTime = currentTime;
	}

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
	glfwWindowHint(GLFW_SAMPLES, 4);

	const GLFWvidmode* screenMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	GLFWmonitor* screenMonitor = glfwGetPrimaryMonitor();//fullscreen code

	
	//APPLICATION->setFullScreen(true);
	//glViewport(0, 0, screenMode->width, screenMode->height);

	Mywindow = glfwCreateWindow(
		screenMode->width,
		screenMode->height,
		"PooPooPipe",
		glfwGetPrimaryMonitor(), NULL);

	if (!Mywindow) {

		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}
	glfwSetWindowMonitor(Mywindow, screenMonitor, 0, 0, screenMode->width, screenMode->height, 0);

	glViewport(0, 0, screenMode->width, screenMode->height);

	Application::width = screenMode->width;
	Application::height = screenMode->height;
	glfwMakeContextCurrent(Mywindow);
	GLFWimage icons[1];

	icons[0].pixels = stbi_load("assets/character.png", &icons[0].width, &icons[0].height, 0, 0);


	glfwSetWindowIcon(Mywindow, 1, icons);
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
	glfwSetFramebufferSizeCallback(Mywindow, framebufferSizeCallback);
	//framebufferSizeCallback(Mywindow, screenMode->width, screenMode->height);
	
}

Application::~Application()
{
	glUseProgram(0);
	glBindVertexArray(0);

	glfwTerminate();

	//std::exit(EXIT_SUCCESS);
}

void Application::setMyWindow(GLFWwindow& m)
{
	Mywindow = &m;

}
GLFWwindow* Application::getMyWindow()
{
	return Mywindow;
}
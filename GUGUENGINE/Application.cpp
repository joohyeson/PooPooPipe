#include <iostream>
#include "glew.h"		
#include "external/glfw/include/GLFW/glfw3.h"
#include "Mesh.h"
#include "Shader.h"

int framebufferWidth, framebufferHeight;
GLuint mVertexArrayObject;
GLuint mPositionVertexBufferObjectID, mColorVertexBufferObjectID;
Shader mShader;

int check = 0;
double xpos = 0;
double ypos = 0;

//Mesh mMesh = MESH::create_rectangle();
//Mesh mMesh = MESH::create_box();

//Mesh mMesh = MESH::create_triangle({ -0.5f, -0.5f, 1.0f }, { 0.5f, -0.5f, 1.0f }, { 0.0f, 0.5f, 1.0f });
Mesh mMesh = MESH::create_circle(0.7f, { 255, 255, 255 }, 6, { 0, 0, 0 }, 0);

bool defineVertexArrayObject() {

	float color[] = {
		1.0f, 0.0f, 0.0f, //vertex 1 : RED (1,0,0)
		0.0f, 1.0f, 0.0f, //vertex 2 : GREEN (0,1,0) 
		0.0f, 0.0f, 1.0f,  //vertex 3 : BLUE (0,0,1)
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
	};


	//#2
	//Vertex Buffer Object(VBO)를 생성하여 vertex 데이터를 복사한다.
	glGenBuffers(1, &mPositionVertexBufferObjectID);
	glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID);
	glBufferData(GL_ARRAY_BUFFER, mMesh.GetPointCount() * sizeof(float) * 3, &mMesh.GetPoint()[0], GL_STATIC_DRAW);

	glGenBuffers(1, &mColorVertexBufferObjectID);
	glBindBuffer(GL_ARRAY_BUFFER, mColorVertexBufferObjectID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);

	//#6
	glGenVertexArrays(1, &mVertexArrayObject);
	glBindVertexArray(mVertexArrayObject);

	GLint positionAttribute = glGetAttribLocation(mShader.GetShaderID(), "positionAttribute");
	if (positionAttribute == -1) {
		std::cerr << "position 속성 설정 실패" << std::endl;
		return false;
	}
	glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID);
	glVertexAttribPointer(positionAttribute, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(positionAttribute);

	GLint colorAttribute = glGetAttribLocation(mShader.GetShaderID(), "colorAttribute");
	if (colorAttribute == -1) {
		std::cerr << "color 속성 설정 실패" << std::endl;
		return false;
	}
	glBindBuffer(GL_ARRAY_BUFFER, mColorVertexBufferObjectID);
	glVertexAttribPointer(colorAttribute, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(colorAttribute);


	glBindVertexArray(0);


	return true;
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	//처음 2개의 파라미터는 viewport rectangle의 왼쪽 아래 좌표
	//다음 2개의 파라미터는 viewport의 너비와 높이이다.
	//framebuffer의 width와 height를 가져와 glViewport에서 사용한다.
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
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);

	if ( key == GLFW_KEY_D)
	{
		time += 0.3f;
		std::cout << "TIME:"<<time << std::endl;
		mMesh = MESH::create_circle(0.7f, { 255, 255, 255 }, 6, { 0, 0, 0 }, time);
	}


}

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	std::cout << "Cursor Position (" << xpos << " : " << ypos << std::endl;
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		std::cout << "Left mouse button pressed" << std::endl;
		check = 1;
		time += 0.9f;
		std::cout << "TIME:" << time << std::endl;
		mMesh = MESH::create_circle(0.7f, { 255, 255, 255 }, 6, { 0, 0, 0 }, time);
	}
}


int main()
{

	//glfwSetErrorCallback(errorCallback);

	//Shader mShader();
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


	GLFWwindow* window = glfwCreateWindow(
		800,
		600,
		"OpenGL Example",
		NULL, NULL);
	if (!window) {

		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}


	glfwMakeContextCurrent(window);


	glfwSetKeyCallback(window, keyCallback);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
	glfwSetCursorPosCallback(window, cursorPositionCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);



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

	if (!mShader.LoadFromSource()) {

		std::cerr << "Error: Shader Program 생성 실패" << std::endl;

		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}






	while (!glfwWindowShouldClose(window)) {

		if (!defineVertexArrayObject()) {

			std::cerr << "Error: Shader Program 생성 실패" << std::endl;

			glfwTerminate();
			std::exit(EXIT_FAILURE);
		}

		glfwSwapInterval(1);


		double lastTime = glfwGetTime();
		int numOfFrames = 0;
		int count = 0;


		glUseProgram(mShader.GetShaderID());
		glBindVertexArray(mVertexArrayObject);

		double currentTime = glfwGetTime();
		numOfFrames++;
		if (currentTime - lastTime >= 1.0) {

			printf("%f ms/frame  %d fps \n", 1000.0 / double(numOfFrames), numOfFrames);
			numOfFrames = 0;
			lastTime = currentTime;
		}



		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);


		glDrawArrays(mMesh.GetPointListPattern(), 0, 8);

		//while (check == 1)
		//{
		//	mMesh.SetPoint(xpos, ypos, 0);
		//}
		count++;

		glfwSwapBuffers(window);
		glfwPollEvents();

	}


	glUseProgram(0);
	glBindVertexArray(0);


	glDeleteProgram(mShader.GetShaderID());
	glDeleteBuffers(1, &mPositionVertexBufferObjectID);
	glDeleteBuffers(1, &mColorVertexBufferObjectID);
	glDeleteVertexArrays(1, &mVertexArrayObject);
	glfwTerminate();

	std::exit(EXIT_SUCCESS);
}

#include <iostream>
#include "glew.h"		
#include "external/glfw/include/GLFW/glfw3.h"
#include "Mesh.h"
#include "Shader.h"
#include "FreeImage.h"

int framebufferWidth, framebufferHeight;
GLuint mVertexArrayObject;
GLuint mPositionVertexBufferObjectID, mColorVertexBufferObjectID;
GLuint triangleTextureCoordinateBufferObjectID;
Shader mShader;

GLuint mVertexArrayObject2;
GLuint mPositionVertexBufferObjectID2, mColorVertexBufferObjectID2;
GLuint triangleTextureCoordinateBufferObjectID2;
Shader mShader2;

GLuint mVertexArrayObject3;
GLuint mPositionVertexBufferObjectID3, mColorVertexBufferObjectID3;
GLuint triangleTextureCoordinateBufferObjectID3;
Shader mShader3;

#define WIDTH 800
#define HEIGHT 800

int cheche = 0;
int moveCheck = 0;
float time = 0;
int rotationCheck = 0;

glm::vec3 curser = { 0, 0, 0 };
glm::vec3 getOrigin = { 0, 0, 0 };
glm::vec3 getOrigin2 = { 0, 0, 0 };

float r = 0.f;

Mesh mMesh = MESH::create_circle(0.3f, { 255, 255, 255 }, 6, { 0.1, 0.7, 1 }, glm::radians(0.f));
Mesh mMesh2 = MESH::create_box(0.4f, { 255, 255, 255 });
Mesh mMesh3 = MESH::create_circle(0, { 255, 255, 255 }, 6, { 0.1, 0.7, 1 }, glm::radians(0.f));


float textureCoordinate[] = { 0.5f, 0.5f,
						0.5f, 0.0f,
						1.0f, 0.25f ,
						1.0f, 0.75f,
						0.5f, 1.0f,
						0.0f, 0.75f,
						0.0f, 0.25f,
						0.5f, 0.0f };


GLuint CreateTexture(char const* filename, int i)
{
	FREE_IMAGE_FORMAT format = FreeImage_GetFileType(filename, 0);

	if (format == -1)
	{
		std::cout << "Could not find image: " << filename << " - Aborting." << std::endl;
		exit(-1);
	}

	if (format == FIF_UNKNOWN)
	{
		std::cout << "Couldn't determine file format - attempting to get from file extension..." << std::endl;
		format = FreeImage_GetFIFFromFilename(filename);
		if (!FreeImage_FIFSupportsReading(format))
		{
			std::cout << "Detected image format cannot be read!" << std::endl;
			exit(-1);
		}
	}
	FIBITMAP* bitmap = FreeImage_Load(format, filename);
	int bitsPerPixel = FreeImage_GetBPP(bitmap);

	FIBITMAP* bitmap32;
	if (bitsPerPixel == 32)
	{
		bitmap32 = bitmap;
	}
	else
	{
		std::cout << "Source image has " << bitsPerPixel << " bits per pixel. Converting to 32-bit colour." << std::endl;
		bitmap32 = FreeImage_ConvertTo32Bits(bitmap);
	}

	int imageWidth = FreeImage_GetWidth(bitmap32);
	int imageHeight = FreeImage_GetHeight(bitmap32);

	GLubyte* textureData = FreeImage_GetBits(bitmap32);

	GLuint tempTextureID;
	glGenTextures(1, &tempTextureID);
	glBindTexture(GL_TEXTURE_2D, tempTextureID);

	glTexImage2D(GL_TEXTURE_2D,
		0,
		GL_RGBA,
		imageWidth,
		imageHeight,
		0,
		GL_BGRA,
		GL_UNSIGNED_BYTE,
		textureData);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);


	glBindTexture(GL_TEXTURE_2D, i);

	GLenum glError = glGetError();
	if (glError)
	{
		std::cout << "There was an error loading the texture: " << filename << std::endl;

		switch (glError)
		{
		case GL_INVALID_ENUM:
			std::cout << "Invalid enum." << std::endl;
			break;

		case GL_INVALID_VALUE:
			std::cout << "Invalid value." << std::endl;
			break;

		case GL_INVALID_OPERATION:
			std::cout << "Invalid operation." << std::endl;

		default:
			std::cout << "Unrecognised GLenum." << std::endl;
			break;
		}

		std::cout << "See https://www.opengl.org/sdk/docs/man/html/glTexImage2D.xhtml for further details." << std::endl;
	}

	FreeImage_Unload(bitmap32);
	if (bitsPerPixel != 32)
	{
		FreeImage_Unload(bitmap);
	}

	return tempTextureID;
}


bool defineVertexArrayObject() {

	glGenBuffers(1, &mPositionVertexBufferObjectID);
	glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID);
	glBufferData(GL_ARRAY_BUFFER, mMesh.GetPointCount() * sizeof(float) * 3, &mMesh.GetPoint()[0], GL_STATIC_DRAW);

	glGenBuffers(1, &triangleTextureCoordinateBufferObjectID);
	glBindBuffer(GL_ARRAY_BUFFER, triangleTextureCoordinateBufferObjectID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(textureCoordinate), textureCoordinate, GL_STATIC_DRAW);

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

	GLint textureCoordinateAttribute = glGetAttribLocation(mShader.GetShaderID(), "textureCoordinateAttribute");
	if (textureCoordinateAttribute == -1) {
		std::cerr << "Texture Coordinate 속성 설정 실패" << std::endl;
		return false;
	}
	glBindBuffer(GL_ARRAY_BUFFER, triangleTextureCoordinateBufferObjectID);
	glVertexAttribPointer(textureCoordinateAttribute, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(textureCoordinateAttribute);

	glBindVertexArray(0);


	return true;
}

bool defineVertexArrayObject2() {
	glGenBuffers(1, &mPositionVertexBufferObjectID2);
	glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID2);
	glBufferData(GL_ARRAY_BUFFER, mMesh2.GetPointCount() * sizeof(float) * 3, &mMesh2.GetPoint()[0], GL_STATIC_DRAW);

	glGenBuffers(1, &triangleTextureCoordinateBufferObjectID2);
	glBindBuffer(GL_ARRAY_BUFFER, triangleTextureCoordinateBufferObjectID2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(textureCoordinate), textureCoordinate, GL_STATIC_DRAW);

	glGenVertexArrays(1, &mVertexArrayObject2);
	glBindVertexArray(mVertexArrayObject2);


	GLint positionAttribute2 = glGetAttribLocation(mShader2.GetShaderID(), "positionAttribute");
	if (positionAttribute2 == -1) {
		std::cerr << "position 속성 설정 실패" << std::endl;
		return false;
	}
	glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID2);
	glVertexAttribPointer(positionAttribute2, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(positionAttribute2);

	GLint textureCoordinateAttribute2 = glGetAttribLocation(mShader2.GetShaderID(), "textureCoordinateAttribute");
	if (textureCoordinateAttribute2 == -1) {
		std::cerr << "Texture Coordinate 속성 설정 실패" << std::endl;
		return false;
	}
	glBindBuffer(GL_ARRAY_BUFFER, triangleTextureCoordinateBufferObjectID2);
	glVertexAttribPointer(textureCoordinateAttribute2, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(textureCoordinateAttribute2);

	glBindVertexArray(0);


	return true;
}

bool defineVertexArrayObject3() {
	glGenBuffers(1, &mPositionVertexBufferObjectID3);
	glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID3);
	glBufferData(GL_ARRAY_BUFFER, mMesh3.GetPointCount() * sizeof(float) * 3, &mMesh3.GetPoint()[0], GL_STATIC_DRAW);

	glGenBuffers(1, &triangleTextureCoordinateBufferObjectID3);
	glBindBuffer(GL_ARRAY_BUFFER, triangleTextureCoordinateBufferObjectID3);
	glBufferData(GL_ARRAY_BUFFER, sizeof(textureCoordinate), textureCoordinate, GL_STATIC_DRAW);

	//#6
	glGenVertexArrays(1, &mVertexArrayObject3);
	glBindVertexArray(mVertexArrayObject3);


	GLint positionAttribute3 = glGetAttribLocation(mShader3.GetShaderID(), "positionAttribute");
	if (positionAttribute3 == -1) {
		std::cerr << "position 속성 설정 실패" << std::endl;
		return false;
	}
	glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID3);
	glVertexAttribPointer(positionAttribute3, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(positionAttribute3);

	GLint textureCoordinateAttribute3 = glGetAttribLocation(mShader3.GetShaderID(), "textureCoordinateAttribute");
	if (textureCoordinateAttribute3 == -1) {
		std::cerr << "Texture Coordinate 속성 설정 실패" << std::endl;
		return false;
	}
	glBindBuffer(GL_ARRAY_BUFFER, triangleTextureCoordinateBufferObjectID3);
	glVertexAttribPointer(textureCoordinateAttribute3, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(textureCoordinateAttribute3);

	glBindVertexArray(0);

	return true;
}

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
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	std::cout << "Cursor Position at (" << xpos << " : " << ypos << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);

	/*if (key == GLFW_KEY_D)
	{
		time += 0.3f;
		std::cout << "TIME:" << time << std::endl;
	}*/

	if (key == GLFW_KEY_SPACE)
	{
		//mMesh = MESH::create_circle(0.3f, { 255, 255, 255 }, 6, { 0.1, 0.7, 1 }, 0);
		if (cheche < 2)
		{
			mMesh2 = MESH::create_circle(0.3f, { 255, 255, 255 }, 6, { 0, 0, 1 }, 0);
		}

		if (cheche >= 2)
		{
			mMesh2 = MESH::create_circle(0.3f, { 255, 255, 255 }, 6, { -0.3, 0.3, 1 }, 0);
		}

		if (cheche > 3)
		{
			mMesh3 = MESH::create_circle(0.3f, { 255, 255, 255 }, 6, { 0.22f, 0.3, 1 }, 0);
		}

		cheche++;
	}

}

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	std::cout << "Cursor Position (" << xpos << " : " << ypos << std::endl;

	curser = { (xpos - WIDTH / 2) / (WIDTH / 2), -1 * ((ypos)-HEIGHT / 2) / (HEIGHT / 2), 1 };
	std::cout << "x: " << curser.x << "y: " << curser.y << std::endl;
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (cheche >= 1)
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
		{
			moveCheck += 1;
			std::cout << "Left mouse button pressed" << std::endl;
			time += 0.9f;
			std::cout << "TIME:" << time << std::endl;
		}
		if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
		{
			time += glm::radians(60.f);
			rotationCheck = 1;
		}
	}
}


void gameLoop()
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


	GLFWwindow* window = glfwCreateWindow(
		WIDTH,
		HEIGHT,
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



	if (!GLEW_VERSION_3_3)
	{
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

	if (!mShader2.LoadFromSource()) {

		std::cerr << "Error: Shader Program 생성 실패" << std::endl;

		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}

	if (!mShader3.LoadFromSource()) {

		std::cerr << "Error: Shader Program 생성 실패" << std::endl;

		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}

	while (!glfwWindowShouldClose(window)) {

		if (!defineVertexArrayObject2()) {

			std::cerr << "Error: Shader Program 생성 실패" << std::endl;

			glfwTerminate();
			std::exit(EXIT_FAILURE);
		}

		glBindVertexArray(mVertexArrayObject2);

		if (cheche == 0)
		{
			GLint texLoc2 = glGetUniformLocation(mShader2.GetShaderID(), "tex");
			glUniform1i(texLoc2, 0);
			glDrawArrays(mMesh.GetPointListPattern(), 0, 8);
		}
		else if (cheche == 1)
		{
			GLuint texureId2 = CreateTexture("assets\\image0.png", 0);
			GLint texLoc2 = glGetUniformLocation(mShader2.GetShaderID(), "tex");
			glUniform1i(texLoc2, 0);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texureId2);
			glDrawArrays(mMesh.GetPointListPattern(), 0, 8);
		}
		else if (cheche > 2)
		{
			GLuint texureId2 = CreateTexture("assets\\image1.png", 0);
			GLint texLoc2 = glGetUniformLocation(mShader2.GetShaderID(), "tex");
			glUniform1i(texLoc2, 0);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texureId2);
			glDrawArrays(mMesh2.GetPointListPattern(), 0, 8);
		}

		glDrawArrays(mMesh2.GetPointListPattern(), 0, 8);

		if (!defineVertexArrayObject()) {

			std::cerr << "Error: Shader Program 생성 실패" << std::endl;

			glfwTerminate();
			std::exit(EXIT_FAILURE);
		}

		glUseProgram(mShader.GetShaderID());
		glBindVertexArray(mVertexArrayObject);

		if (cheche == 0)
		{
			GLint texLoc = glGetUniformLocation(mShader.GetShaderID(), "tex");
			glUniform1i(texLoc, 0);
			glDrawArrays(mMesh.GetPointListPattern(), 0, 8);
		}
		else
		{
			GLuint texureId = CreateTexture("assets\\image0.png", 0);
			GLint texLoc = glGetUniformLocation(mShader.GetShaderID(), "tex");
			glUniform1i(texLoc, 0);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texureId);
			glDrawArrays(mMesh.GetPointListPattern(), 0, 8);
		}

		if (!defineVertexArrayObject3()) {

			std::cerr << "Error: Shader Program 3" << std::endl;

			glfwTerminate();
			std::exit(EXIT_FAILURE);
		}

		glUseProgram(mShader3.GetShaderID());
		glBindVertexArray(mVertexArrayObject3);

		if (cheche > 3)
		{
			GLuint texureId3 = CreateTexture("assets\\image2.png", 0);
			GLint texLoc3 = glGetUniformLocation(mShader3.GetShaderID(), "tex");
			glUniform1i(texLoc3, 0);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texureId3);
			glDrawArrays(mMesh3.GetPointListPattern(), 0, 8);
		}

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
		glfwSwapBuffers(window);

		glClearColor(255, 255, 255, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		if (cheche > 1)
		{
			getOrigin.x = mMesh.origin.x;
			getOrigin.y = mMesh.origin.y;

			getOrigin2.x = mMesh2.origin.x;
			getOrigin2.y = mMesh2.origin.y;

			r = mMesh.radius_r;


			if (curser.x <= (getOrigin.x + r / 2) &&
				curser.x >= (getOrigin.x - r / 2) &&
				curser.y <= (getOrigin.y + r) &&
				curser.y >= (getOrigin.y - r))
			{
				if (moveCheck % 2 == 1)
				{
					mMesh = MESH::create_circle(0.3f, { 255, 255, 255 }, 6, { curser.x, curser.y ,0 }, 0);
				}
			}
			else
			{
				moveCheck = 0;
			}

			if (getOrigin.x <= (getOrigin2.x + r / 2) &&
				getOrigin.x >= (getOrigin2.x - r / 2) &&
				getOrigin.y <= (getOrigin2.y + r) &&
				getOrigin.y >= (getOrigin2.y - r))
			{
				if (moveCheck % 2 == 0)
				{
					mMesh = mMesh2;
					if (rotationCheck == 1)
					{
						mMesh = MESH::create_circle(0.3f, { 255, 255, 255 }, 6, { -0.3, 0.3, 1 }, time);
						std::cout << time;
						mMesh2 = MESH::create_circle(0.3f, { 255, 255, 255 }, 6, { -0.3, 0.3, 1 }, time);
						rotationCheck = 0;
					}
				}
			}
		}
		count++;
		glfwPollEvents();
	}

	glUseProgram(0);
	glBindVertexArray(0);

	glDeleteProgram(mShader.GetShaderID());
	glDeleteBuffers(1, &mPositionVertexBufferObjectID);
	glDeleteBuffers(1, &mColorVertexBufferObjectID);
	glDeleteVertexArrays(1, &mVertexArrayObject);
	glDeleteVertexArrays(1, &mVertexArrayObject2);
	glfwTerminate();

	std::exit(EXIT_SUCCESS);
}

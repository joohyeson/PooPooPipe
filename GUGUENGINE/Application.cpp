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

#define WIDTH 800
#define HEIGHT 600
int moveCheck = 0;
glm::vec3 curser = { 0, 0, 0 };
glm::vec3 getOrigin = { 0, 0, 0 };
float r = 0.f;
//Mesh mMesh = MESH::create_rectangle();
//Mesh mMesh = MESH::create_box();
//Mesh mMesh = MESH::create_triangle({ -0.5f, -0.5f, 1.0f }, { 0.5f, -0.5f, 1.0f }, { 0.0f, 0.5f, 1.0f });

Mesh mMesh = MESH::create_circle(0.7f, { 255, 255, 255 }, 6, { 0, 0, 1 }, 0);
Mesh mMesh2 = MESH::create_circle(0.3f, { 255, 255, 255 }, 6, { 0.4,0.3,1}, 0);

GLuint CreateTexture(char const* filename, int i)
{
	// Determine the format of the image.
	// Note: The second paramter ('size') is currently unused, and we should use 0 for it.
	FREE_IMAGE_FORMAT format = FreeImage_GetFileType(filename, 0);

	// Image not found? Abort! Without this section we get a 0 by 0 image with 0 bits-per-pixel but we don't abort, which
	// you might find preferable to dumping the user back to the desktop.
	if (format == -1)
	{
		std::cout << "Could not find image: " << filename << " - Aborting." << std::endl;
		exit(-1);
	}

	// Found image, but couldn't determine the file format? Try again...
	if (format == FIF_UNKNOWN)
	{
		std::cout << "Couldn't determine file format - attempting to get from file extension..." << std::endl;

		// ...by getting the filetype from the filename extension (i.e. .PNG, .GIF etc.)
		// Note: This is slower and more error-prone that getting it from the file itself,
		// also, we can't use the 'U' (unicode) variant of this method as that's Windows only.
		format = FreeImage_GetFIFFromFilename(filename);

		// Check that the plugin has reading capabilities for this format (if it's FIF_UNKNOWN,
		// for example, then it won't have) - if we can't read the file, then we bail out =(
		if (!FreeImage_FIFSupportsReading(format))
		{
			std::cout << "Detected image format cannot be read!" << std::endl;
			exit(-1);
		}
	}

	// If we're here we have a known image format, so load the image into a bitap
	FIBITMAP* bitmap = FreeImage_Load(format, filename);

	// How many bits-per-pixel is the source image?
	int bitsPerPixel = FreeImage_GetBPP(bitmap);

	FIBITMAP* bitmap32;
	if (bitsPerPixel == 32)
	{
		//std::cout << "Source image has " << bitsPerPixel << " bits per pixel. Skipping conversion." << std::endl;
		bitmap32 = bitmap;
	}
	else
	{
		std::cout << "Source image has " << bitsPerPixel << " bits per pixel. Converting to 32-bit colour." << std::endl;
		bitmap32 = FreeImage_ConvertTo32Bits(bitmap);
	}

	// Some basic image info - strip it out if you don't care
	int imageWidth = FreeImage_GetWidth(bitmap32);
	int imageHeight = FreeImage_GetHeight(bitmap32);
	//std::cout << "Image: " << filename << " is size: " << imageWidth << "x" << imageHeight << "." << std::endl;

	GLubyte* textureData = FreeImage_GetBits(bitmap32);

	// Generate a texture ID and bind to it
	GLuint tempTextureID;
	glGenTextures(1, &tempTextureID);
	glBindTexture(GL_TEXTURE_2D, tempTextureID);

	glTexImage2D(GL_TEXTURE_2D,    // Type of texture
		0,                // Mipmap level (0 being the top level i.e. full size)
		GL_RGBA,          // Internal format
		imageWidth,       // Width of the texture
		imageHeight,      // Height of the texture,
		0,                // Border in pixels
		GL_BGRA,          // Data format
		GL_UNSIGNED_BYTE, // Type of texture data
		textureData);     // The image data to use for this texture

						  // Specify our minification and magnification filters

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);


	glBindTexture(GL_TEXTURE_2D, i);


	// Check for OpenGL texture creation errors
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

	// Unload the 32-bit colour bitmap
	FreeImage_Unload(bitmap32);

	// If we had to do a conversion to 32-bit colour, then unload the original
	// non-32-bit-colour version of the image data too. Otherwise, bitmap32 and
	// bitmap point at the same data, and that data's already been free'd, so
	// don't attempt to free it again! (or we'll crash).
	if (bitsPerPixel != 32)
	{
		FreeImage_Unload(bitmap);
	}

	// Finally, return the texture ID
	return tempTextureID;
}


bool defineVertexArrayObject() {

	float textureCoordinate[] = { 0.5f, 0.5f,
							0.5f, 0.0f,
							1.0f, 0.25f ,
							1.0f, 0.75f,
							0.5f, 1.0f,
							0.0f, 0.75f,
							0.0f, 0.25f,
							0.5f, 0.0f };

	//#2
	//Vertex Buffer Object(VBO)를 생성하여 vertex 데이터를 복사한다.
	glGenBuffers(1, &mPositionVertexBufferObjectID);
	glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID);
	glBufferData(GL_ARRAY_BUFFER, mMesh.GetPointCount() * sizeof(float) * 3, &mMesh.GetPoint()[0], GL_STATIC_DRAW);

	glGenBuffers(1, &triangleTextureCoordinateBufferObjectID);
	glBindBuffer(GL_ARRAY_BUFFER, triangleTextureCoordinateBufferObjectID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(textureCoordinate), textureCoordinate, GL_STATIC_DRAW);

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

	float textureCoordinate[] = { 0.5f, 0.5f,
							0.5f, 0.0f,
							1.0f, 0.25f ,
							1.0f, 0.75f,
							0.5f, 1.0f,
							0.0f, 0.75f,
							0.0f, 0.25f,
							0.5f, 0.0f };

	//#2
	//Vertex Buffer Object(VBO)를 생성하여 vertex 데이터를 복사한다.
	glGenBuffers(1, &mPositionVertexBufferObjectID2);
	glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID2);
	glBufferData(GL_ARRAY_BUFFER, mMesh2.GetPointCount() * sizeof(float) * 3, &mMesh2.GetPoint()[0], GL_STATIC_DRAW);

	glGenBuffers(1, &triangleTextureCoordinateBufferObjectID2);
	glBindBuffer(GL_ARRAY_BUFFER, triangleTextureCoordinateBufferObjectID2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(textureCoordinate), textureCoordinate, GL_STATIC_DRAW);

	//#6
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

	if (key == GLFW_KEY_D)
	{
		time += 0.3f;
		std::cout << "TIME:" << time << std::endl;
		mMesh = MESH::create_circle(0.7f, { 255, 255, 255 }, 6, { curser.x, curser.y, 0 }, time);
	}


}

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	std::cout << "Cursor Position (" << xpos << " : " << ypos << std::endl;

	curser = { (xpos - 400) / 400, -1 * ((ypos)-300) / 300, 1 };
	std::cout << "x: " << curser.x << "y: " << curser.y << std::endl;
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		moveCheck += 1;
		std::cout << "Left mouse button pressed" << std::endl;
		time += 0.9f;
		std::cout << "TIME:" << time << std::endl;
		//mMesh = MESH::create_circle(0.7f, { 255, 255, 255 }, 6, { 400, 300, 0 }, time);
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

	if (!mShader2.LoadFromSource()) {

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

		glUseProgram(mShader.GetShaderID());
		glBindVertexArray(mVertexArrayObject);

		GLuint texureId = CreateTexture("assets\\image0.png", 0);

		GLint texLoc = glGetUniformLocation(mShader.GetShaderID(), "tex");
		glUniform1i(texLoc, 0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texureId);
		glDrawArrays(mMesh.GetPointListPattern(), 0, 8);



	
		if (!defineVertexArrayObject2()) {

			std::cerr << "Error: Shader Program 생성 실패" << std::endl;

			glfwTerminate();
			std::exit(EXIT_FAILURE);
		}

		
		glBindVertexArray(mVertexArrayObject2);
		GLuint texureId2 = CreateTexture("assets\\numBoard.jpg", 1);
		GLint tex2Loc = glGetUniformLocation(mShader2.GetShaderID(), "tex");
		glUniform1i(tex2Loc, 1);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texureId2);
		glDrawArrays(mMesh2.GetPointListPattern(), 0, 8);
		

	



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

		//glfwSwapInterval(1);
		glfwSwapBuffers(window);

		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

	

		
		getOrigin.x = mMesh.origin.x;
		getOrigin.y = mMesh.origin.y;

		r = mMesh.radius_r;


		if (curser.x <= (getOrigin.x + r / 2) &&
			curser.x >= (getOrigin.x - r / 2) &&
			curser.y <= (getOrigin.y + r) &&
			curser.y >= (getOrigin.y - r))
		{
			if (moveCheck % 2 == 1)
			{
				mMesh = MESH::create_circle(0.7f, { 255, 255, 255 }, 6, { curser.x, curser.y ,1 }, 0);
			}
		}
		else
		{
			moveCheck = 0;
		}

		count++;

		//glfwSwapBuffers(window);
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

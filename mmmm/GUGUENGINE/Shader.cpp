/* 1.your name            joohye Son
2.the assignment number   3
3.the course name         CS230
4.the term                Spring 2019 */


#include <cassert>
#include <iostream>
#include "glew.h"
#include "external/glfw/include/GLFW/glfw3.h"
#include "Color.h"
#include "Shader.h"
#include "glCheck.h"
#include "Mesh.h"


#pragma comment(lib, "glew32.lib")

Shader::Shader() { mShaderProgramID = 0; mColorVertexBufferObjectID = 0; mPositionVertexBufferObjectID = 0; mVertexArrayObject = 0; }
bool Shader::LoadFromSource()
{

	const GLchar* vertex_shader_source =
		"#version 330 core\n"
		"in vec3 positionAttribute;"
		"in vec3 colorAttribute;"

		"out vec3 passColorAttribute;"

		"void main()"
		"{"
		"gl_Position = vec4(positionAttribute, 1.0);"
		"passColorAttribute = colorAttribute;"
		"}";

	const GLchar* fragment_shader_source =
		"#version 330 core\n"
		"in vec3 passColorAttribute;"
		"out vec4 fragmentColor;"
		"void main()"
		"{"
		"fragmentColor = vec4(passColorAttribute, 1.0);"
		"}";

	GLuint vshader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vshader, 1, &vertex_shader_source, NULL);

	// vertex_shader_source is a GLchar* containing glsl shader source code
	glCheck(glCompileShader(vshader));

	GLint vertex_compiled;
	glCheck(glGetShaderiv(vshader, GL_COMPILE_STATUS, &vertex_compiled));
	if (vertex_compiled != GL_TRUE)
	{
		GLsizei log_length = 0;
		GLchar message[1024];
		glCheck(glGetShaderInfoLog(vshader, 1024, &log_length, message));
		return false;
		// Write the error to a log
	}


	GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);

	glCheck(glShaderSource(fshader, 1, &fragment_shader_source, NULL));// fragment_shader_source is a GLchar* containing glsl shader source code
	glCheck(glCompileShader(fshader));

	GLint fragment_compiled;
	glCheck(glGetShaderiv(fshader, GL_COMPILE_STATUS, &fragment_compiled));
	if (fragment_compiled != GL_TRUE)
	{
		GLsizei log_length = 0;
		GLchar message[1024];
		glCheck(glGetShaderInfoLog(fshader, 1024, &log_length, message));
		return false;
		// Write the error to a log
	}


	mShaderProgramID = glCreateProgram();

	glCheck(glAttachShader(mShaderProgramID, vshader));
	glCheck(glAttachShader(mShaderProgramID, fshader));
	glCheck(glLinkProgram(mShaderProgramID));
	glCheck(glUseProgram(mShaderProgramID));
	handleToShader = mShaderProgramID;

	glDeleteShader(vshader);
	glDeleteShader(fshader);

	return true;
}
//void Shader::SendUniformVariable(const std::string& variable_name, const matrix3& affine_matrix) noexcept
//{
//	GLfloat matrix[9] = { affine_matrix.elements[0][0],affine_matrix.elements[0][1],affine_matrix.elements[0][2],
//	affine_matrix.elements[1][0] ,affine_matrix.elements[1][1] ,affine_matrix.elements[1][2] ,
//	affine_matrix.elements[2][0] ,affine_matrix.elements[2][1] ,affine_matrix.elements[2][2] };

//	glCheck(glUniformMatrix3fv(GetUniformLocation(variable_name), 1, GL_FALSE, matrix));
//}

void Shader::SendUniformVariable(const std::string& variable_name, float number) noexcept
{
	glCheck(glUniform1f(GetUniformLocation(variable_name), number));
}
void Shader::SendUniformVariable(const std::string& variable_name, int number) noexcept
{
	glCheck(glUniform1i(GetUniformLocation(variable_name), number));
}
void Shader::SendUniformVariable(const std::string& variable_name, Color4f color) noexcept
{
	glCheck(glUniform4f(GetUniformLocation(variable_name), color.red, color.green, color.blue, color.alpha));
}


void Shader::Select(const Shader& shader) noexcept
{
	glCheck(glUseProgram(shader.handleToShader));
}
void Shader::SelectNothing() noexcept
{
	glCheck(glUseProgram(0));
}

int Shader::GetUniformLocation(const std::string& name) noexcept
{
	const GLchar* uniformLocation = name.c_str();
	GLint a = glGetUniformLocation(handleToShader, uniformLocation);
	return a;
}

void Shader::Delete() noexcept
{
	glCheck(glDeleteProgram(handleToShader));
}

GLuint Shader::GetShaderID(void) noexcept
{
	GLuint mShader = mShaderProgramID;
	return mShader;
}

GLuint Shader::GetVertexArrayObject(void) noexcept
{
	GLuint vertexArrayObject = mVertexArrayObject;
	return vertexArrayObject;
}
GLuint* Shader::GetVertexArrayObjectPointer(void) noexcept
{
	GLuint* vertexArrayObject = &mVertexArrayObject;
	return vertexArrayObject;
}
GLuint* Shader::GetPositionVertexBufferObjectID(void) noexcept
{
	GLuint* positionVertexBufferObjectID = &mPositionVertexBufferObjectID;
	return positionVertexBufferObjectID;
}
GLuint* Shader::GetColorVertexBufferObjectID(void) noexcept
{
	GLuint* ColorVertexBufferObjectID = &mColorVertexBufferObjectID;
	return ColorVertexBufferObjectID;
}
bool Shader::defineVertexArrayObject(Mesh mMesh)
{

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

	GLint positionAttribute = glGetAttribLocation(GetShaderID(), "positionAttribute");
	if (positionAttribute == -1) {
		std::cerr << "position " << std::endl;
		return false;
	}
	glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID);
	glVertexAttribPointer(positionAttribute, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(positionAttribute);

	GLint colorAttribute = glGetAttribLocation(GetShaderID(), "colorAttribute");
	if (colorAttribute == -1) {
		std::cerr << "color " << std::endl;
		return false;
	}
	glBindBuffer(GL_ARRAY_BUFFER, mColorVertexBufferObjectID);
	glVertexAttribPointer(colorAttribute, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(colorAttribute);

	//glBindVertexArray(0);

	return true;
}
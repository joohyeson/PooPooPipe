/* 1.your name            joohye Son
2.the assignment number   3
3.the course name         CS230
4.the term                Spring 2019 */


#include <cassert>
#include <iostream>
#include "glew.h"
#include "Shader.h"


const GLchar* vertex_shader_source =
"#version 330 core\n"
"layout (location = 0) in vec3 positionAttribute;"
"layout (location = 1) in vec3 colorAttribute;"
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

Shader::Shader()
{
	mShaderProgramID = 0;
	mVertexShaderProgramID = 0;
	mFragmentShaderProgramID = 0;

}

void Shader::BuildShader()
{
	mShaderProgramID = glCreateProgram();

	VertexShaderCompile();
	FragmentShaderCompile();
	LinkShader();
}

void Shader::VertexShaderCompile()
{
	mVertexShaderProgramID = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(mVertexShaderProgramID, 1, &vertex_shader_source, NULL);

	// vertex_shader_source is a GLchar* containing glsl shader source code
	glCompileShader(mVertexShaderProgramID);

	GLint vertex_compiled;
	glGetShaderiv(mVertexShaderProgramID, GL_COMPILE_STATUS, &vertex_compiled);
	if (vertex_compiled != GL_TRUE)
	{
		GLsizei log_length = 0;
		GLchar message[1024];
		glGetShaderInfoLog(mVertexShaderProgramID, 1024, &log_length, message);
		glDeleteShader(mVertexShaderProgramID);

		printf("%s\n", &(message[0]));
		printf("Vertex Shader_Error: fail to compile!\n");

	}
}

void Shader::FragmentShaderCompile()
{
	mFragmentShaderProgramID = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(mFragmentShaderProgramID, 1, &fragment_shader_source, NULL);// fragment_shader_source is a GLchar* containing glsl shader source code
	glCompileShader(mFragmentShaderProgramID);

	GLint fragment_compiled;
	glGetShaderiv(mFragmentShaderProgramID, GL_COMPILE_STATUS, &fragment_compiled);
	if (fragment_compiled != GL_TRUE)
	{
		GLsizei log_length = 0;
		GLchar message[1024];
		glGetShaderInfoLog(mFragmentShaderProgramID, 1024, &log_length, message);
		glDeleteShader(mFragmentShaderProgramID);

		printf("%s\n", &(message[0]));
		printf("Fragment Shader_Error: fail to compile!\n");
	}
}

void Shader::LinkShader()
{
	glAttachShader(mShaderProgramID, mVertexShaderProgramID);
	glAttachShader(mShaderProgramID, mFragmentShaderProgramID);

	glLinkProgram(mShaderProgramID);
	glUseProgram(mShaderProgramID);

	handleToShader = mShaderProgramID;

	glDeleteShader(mVertexShaderProgramID);
	glDeleteShader(mFragmentShaderProgramID);

}
void Shader::Delete() noexcept
{
	glDeleteProgram(handleToShader);
}
GLuint Shader::GetShaderID(void) noexcept
{
	GLuint mShader = mShaderProgramID;
	return mShader;
}

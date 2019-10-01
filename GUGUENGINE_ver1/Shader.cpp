/* 1.your name            joohye Son
2.the assignment number   3
3.the course name         CS230
4.the term                Spring 2019 */

#include "Color.h"
#include "Shader.h"
#include "glCheck.h"
#include "glew.h"
#include <cassert>
#include <iostream>

#pragma comment(lib, "glew32.lib")

	Shader::Shader(const std::string& vertex_shader_source_code, const std::string& fragment_shader_source_code)
	{

		LoadFromSource(vertex_shader_source_code, fragment_shader_source_code);

	}
	bool Shader::LoadFromSource(const std::string& vertex_shader_source_code, const std::string& fragment_shader_source_code)
	{
		const char* vertex_shader_source = vertex_shader_source_code.c_str();
		GLuint vshader = glCreateShader(GL_VERTEX_SHADER);

		glCheck(glShaderSource(vshader, 1, &vertex_shader_source, NULL));

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

		const char* fragment_shader_source = fragment_shader_source_code.c_str();
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


		GLuint program = glCreateProgram();

		glCheck(glAttachShader(program, vshader));
		glCheck(glAttachShader(program, fshader));
		glCheck(glLinkProgram(program));
		glCheck(glUseProgram(program));
		handleToShader = program;


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


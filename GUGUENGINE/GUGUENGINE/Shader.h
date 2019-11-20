/*
 * Rudy Castan
 * Graphics Library
 * CS230
 */
#pragma once
#include <map>
#include <string>
#include "external/glew/include/GL/glew.h"	
#include "external/glfw/include/GLFW/glfw3.h"


class Color4f;
//struct matrix3;
//struct vector3;

class Mesh;

class [[nodiscard]] Shader
{
public:
	Shader();

	~Shader() noexcept = default;

	void BuildShader();
	void VertexShaderCompile();
	void FragmentShaderCompile();
	void LinkShader();

	GLuint GetShaderID(void) noexcept;

	constexpr unsigned GetShaderHandler() const noexcept { return handleToShader; }

	void Delete() noexcept;


	Shader(const Shader & other) = delete;
	Shader(Shader && other) noexcept = delete;
	Shader& operator=(const Shader & other) = delete;
	Shader& operator=(Shader && other) noexcept = delete;

private:
	//int GetUniformLocation(const std::string& name) noexcept;
	GLuint mShaderProgramID = 0;
	GLuint mVertexShaderProgramID = 0;
	GLuint mFragmentShaderProgramID = 0;

	unsigned int                   handleToShader = 0;
	std::map<std::string, int> uniformNameToLocation{};

};



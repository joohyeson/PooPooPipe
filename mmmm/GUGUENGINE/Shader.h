/*
 * Rudy Castan
 * Graphics Library
 * CS230
 */
#pragma once
#include <map>
#include <string>
#include "glew.h"		
#include "external/glfw/include/GLFW/glfw3.h"


	//class Color4f;
	//struct matrix3;
	//struct vector3;

class Mesh;

	class[[nodiscard]] Shader
	{
	public:
		Shader();
	
		~Shader() noexcept = default;

		bool LoadFromSource();

		//void SendUniformVariable(const std::string& variable_name, const matrix3& affine_matrix) noexcept;
		void SendUniformVariable(const std::string& variable_name, float number) noexcept;
		void SendUniformVariable(const std::string& variable_name, int number) noexcept;
		void SendUniformVariable(const std::string& variable_name, Color4f color) noexcept;
		//GLuint setShaderID(GLuint m);
		GLuint GetShaderID(void) noexcept;
		GLuint GetVertexArrayObject(void) noexcept;
		GLuint* GetPositionVertexBufferObjectID(void) noexcept;
		GLuint* GetColorVertexBufferObjectID(void) noexcept;
		GLuint* GetVertexArrayObjectPointer(void) noexcept;
		bool defineVertexArrayObject(Mesh mMesh);

		//bool initShaderProgram();

		constexpr unsigned GetShaderHandler() const noexcept { return handleToShader; }

		void Delete() noexcept;

		static void Select(const Shader& shader) noexcept;
		static void SelectNothing() noexcept;


		Shader(const Shader& other) = delete;
		Shader(Shader&& other) noexcept = delete;
		Shader& operator=(const Shader& other) = delete;
		Shader& operator=(Shader&& other) noexcept = delete;
		

	private:
		int GetUniformLocation(const std::string& name) noexcept;
		GLuint mShaderProgramID=0;
	
		unsigned int                   handleToShader = 0;
		std::map<std::string, int> uniformNameToLocation{};
		GLuint mVertexArrayObject=0;
		GLuint mPositionVertexBufferObjectID, mColorVertexBufferObjectID=0;
	};



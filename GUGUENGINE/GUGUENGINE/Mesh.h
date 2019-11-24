/*
 * Rudy Castan
 * Graphics Library
 * CS230
 */
#pragma once

#include "Color.h"
#include "glm/glm.hpp"
#include "glew.h"
 //#include <CS230/math/vector2.hpp>
#include <cstddef>
#include <vector>
#include "Component.h"
#include "Shader.h"
#include "Transform.h"


class Shader;

enum class [[nodiscard]] PointListPattern
{
	Lines, LineStrip, LineLoop, Triangles, TriangleStrip, TriangleFan
	//change to GL_TRIANGLE_FAN and so on
	//GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP, GL_TRIANGLES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN
};

class [[nodiscard]] Mesh :public Component
{
public:

	Mesh();
	~Mesh() override;

	void Initialize(void) ;
	void Update();


	/*Mesh(const Mesh& rhs)
	{
		this->colors = rhs.colors;

	}
	Mesh& operator=(const Mesh& rhs);*/

	//void BuildMesh();
	//bool Draw(Shader& mShader);
	void Delete();

	std::size_t GetPointCount() const noexcept;
	std::vector<glm::vec3>   GetPoint() const noexcept;
	void	 SetPoint(std::vector<glm::vec3> point);

	Color4ub    GetColor(std::size_t index = 0) const noexcept;
	std::vector<glm::vec2>      GetTextureCoordinate() const noexcept;

	GLenum GetPointListPattern() const noexcept;
	void  SetPointListType(GLenum type) noexcept;

	void AddColor(Color4ub color) noexcept;
	void AddPoint(glm::vec3  point) noexcept;
	void AddTextureCoordinate(glm::vec2  texture_coordinate) noexcept;

	void ClearColors() noexcept;
	bool HasMoreThanOneColor() const noexcept;
	void setTransfrom(glm::vec2 m);
	void ClearTextureCoordinates() noexcept;
	void ClearPoints() noexcept;
	void Clear() noexcept;
	GLuint* GetVertexArrayObjectPointer(void) noexcept;
	std::vector<glm::vec3> createHexagon(glm::vec3 point) noexcept;
	void SetVertex(glm::vec2 mVec);
private:
	std::vector<glm::vec3> vertex;
	std::vector<glm::vec3>  points{};
	std::vector<Color4ub> colors{};
	std::vector<glm::vec2>  textureCoordinates{};
	int shaderID = 0;
	Shader mShader;
	GLenum      pointListType = GL_LINES;
	GLuint mVertexArrayObject;
	GLuint mPositionVertexBufferObjectID, mColorVertexBufferObjectID;
	Transform transform;
};

namespace MESH
{
	//std::vector<glm::vec3> createHexagon(glm::vec3 point) noexcept;
	std::vector<glm::vec3> create_wire_circle(float radius = 1, Color4ub color = Color4ub{ 255 }, std::size_t point_count = 30) noexcept;
	std::vector<glm::vec3> create_box(float dimension = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	std::vector<glm::vec3> create_rectangle(float width = 1, float height = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	std::vector<glm::vec3> create_wire_rectangle(float width = 1, float height = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	std::vector<glm::vec3> create_wire_box(float dimension = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	std::vector<glm::vec3> create_line(glm::vec2  a = { 0, 0 }, glm::vec2  b = { 1, 0 }, Color4ub color = Color4ub{ 255 }) noexcept;
	std::vector<glm::vec3> create_triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c, float time);
}


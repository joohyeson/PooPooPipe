#pragma once
#include "Color.h"
#include "glm/glm.hpp"
#include "glew.h"
#include <cstddef>
#include <vector>
#include "Component.h"


enum class [[nodiscard]] PointListPattern
{
	Lines, LineStrip, LineLoop, Triangles, TriangleStrip, TriangleFan
	//change to GL_TRIANGLE_FAN and so on
	//GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP, GL_TRIANGLES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN
};

class [[nodiscard]] Mesh : public Component
{
public:	
	void Init() override;
	
	std::size_t GetPointCount() const noexcept;
	std::vector<glm::vec3>   GetPoint() const noexcept;
	void	 SetPoint(std::vector<glm::vec3> point);
	
	Color4ub    GetColor(std::size_t index = 0) const noexcept;
	std::vector<glm::vec2>      GetTextureCoordinate() const noexcept;

	GLenum GetPointListPattern() const noexcept;
	void             SetPointListType(GLenum type) noexcept;

	void AddColor(Color4ub color) noexcept;
	void AddPoint(glm::vec3  point) noexcept;
	void AddTextureCoordinate(glm::vec2  texture_coordinate) noexcept;

	void ClearColors() noexcept;
	bool HasMoreThanOneColor() const noexcept;

	void ClearTextureCoordinates() noexcept;
	void ClearPoints() noexcept;
	void Clear() noexcept;

	glm::vec3 origin = {0, 0, 0};
	float radius_r = 0.f;
	
private:
	std::vector<glm::vec3>  points{};
	std::vector<Color4ub> colors{};
	std::vector<glm::vec2>  textureCoordinates{};
	GLenum      pointListType =GL_LINES;
};

namespace MESH
{
	Mesh create_circle(float radius = 1, Color4ub color = Color4ub{ 255 }, std::size_t point_count = 30, glm::vec3 point = {0, 0, 0}, float time=0) noexcept;
	Mesh create_wire_circle(float radius = 1, Color4ub color = Color4ub{ 255 },
		std::size_t point_count = 30) noexcept;
	Mesh create_box(float dimension = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	Mesh create_rectangle(float width = 1, float height = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	Mesh create_wire_rectangle(float width = 1, float height = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	Mesh create_wire_box(float dimension = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	Mesh create_line(glm::vec3  a = { 0, 0,0 }, glm::vec3  b = { 1, 0,0 }, Color4ub color = Color4ub{ 255 }) noexcept;
	Mesh create_triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c, float time);
}


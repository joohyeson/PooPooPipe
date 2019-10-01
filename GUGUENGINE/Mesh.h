/*
 * Rudy Castan
 * Graphics Library
 * CS230
 */
#pragma once
#include "Color.h"
#include "glm/glm.hpp"
 //#include <CS230/math/vector2.hpp>
#include <cstddef>
#include <vector>


enum class [[nodiscard]] PointListPattern
{
	Lines, LineStrip, LineLoop, Triangles, TriangleStrip, TriangleFan
};

class [[nodiscard]] Mesh
{
public:
	std::size_t GetPointCount() const noexcept;
	std::vector<glm::vec3>   GetPoint() const noexcept;
	Color4ub    GetColor(std::size_t index = 0) const noexcept;
	std::vector<glm::vec2>      GetTextureCoordinate() const noexcept;

	PointListPattern GetPointListPattern() const noexcept;
	void             SetPointListType(PointListPattern type) noexcept;

	void AddColor(Color4ub color) noexcept;
	void AddPoint(glm::vec3  point) noexcept;
	void AddTextureCoordinate(glm::vec2  texture_coordinate) noexcept;

	void ClearColors() noexcept;
	bool HasMoreThanOneColor() const noexcept;

	void ClearTextureCoordinates() noexcept;
	void ClearPoints() noexcept;
	void Clear() noexcept;

private:
	std::vector<glm::vec3>  points{};
	std::vector<Color4ub> colors{};
	std::vector<glm::vec2>  textureCoordinates{};
	PointListPattern      pointListType = PointListPattern::Lines;
};

namespace MESH
{
	Mesh create_circle(float radius = 1, Color4ub color = Color4ub{ 255 }, std::size_t point_count = 30) noexcept;
	Mesh create_wire_circle(float radius = 1, Color4ub color = Color4ub{ 255 },
		std::size_t point_count = 30) noexcept;
	Mesh create_box(float dimension = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	Mesh create_rectangle(float width = 1, float height = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	Mesh create_wire_rectangle(float width = 1, float height = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	Mesh create_wire_box(float dimension = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	Mesh create_line(glm::vec2  a = { 0, 0 }, glm::vec2  b = { 1, 0 }, Color4ub color = Color4ub{ 255 }) noexcept;
	Mesh create_triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c);
}


/* 1.your name            joohye Son
2.the assignment number   4
3.the course name         CS230
4.the term                Spring 2019 */
//#include <CS230/graphics/Mesh.hpp>
//#include <CS230/math/angles.hpp>
#include <cmath>
#include <valarray>
#include "Mesh.h"
////////////////////////////////////////////////////////delete//////////////////////////////////////////////
constexpr float PI = 3.1415926535897932384626433832795f;
constexpr float HALF_PI = PI / 2.0f;
constexpr float QUARTER_PI = PI / 4.0f;
constexpr float TWO_PI = 2.0f * PI;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Returns the total amount of points representing the mesh
	std::size_t Mesh::GetPointCount() const noexcept
	{
		return points.size();
	}

	//Returns the i th point in the mesh
	glm::vec2  Mesh::GetPoint(std::size_t index) const noexcept
	{
		return points[index];
	}
	/*Returns the i th color in the mesh. As long as index is within the range [0,PointCount) then this will return a valid color.
	If the mesh actually has no colors then the Black color will be returned. If the index กร color size then the last (back) color will be returned.*/
	Color4ub Mesh::GetColor(std::size_t index) const noexcept
	{
		Color4ub BLACK = { 255,255,255,255 };

		if (index < colors.size() && index >= 0)
		{
			return colors[index];
		}
		else if (colors.empty() == true)
		{
			return BLACK;
		}
		else
			return colors.back();

	}
	/*Returns the i th texture coordinate in the mesh. As long as index is within the range [0,PointCount) then this will return a valid texture coordinate.
		   If the mesh actually has no texture coordinates then the {0,0} texture coordinate will be returned.
		   If the index กร texture coordinate size then the last (back) texture coordinate will be returned.*/
	glm::vec2  Mesh::GetTextureCoordinate(std::size_t index)  const noexcept
	{
		glm::vec2  ZERO = { 0,0 };

		if (index < textureCoordinates.size() && index >= 0)
		{
			return textureCoordinates[index];
		}
		else if (textureCoordinates.empty() == true)
		{
			return ZERO;
		}
		else
			return textureCoordinates.back();

	}
	//Simple getter for pointListType
	PointListPattern Mesh::GetPointListPattern()  const noexcept
	{
		return pointListType;
	}
	//Simple setter for pointListType
	void Mesh::SetPointListType(PointListPattern type)noexcept
	{
		pointListType = type;
	}
	//Adds a new color to the mesh
	void Mesh::AddColor(Color4ub color) noexcept
	{
		colors.push_back(color);
	}
	//Adds a new point to the mesh
	void Mesh::AddPoint(glm::vec2  point) noexcept
	{
		points.push_back(point);

	}
	//Adds a new texture coordinate to the mesh
	void Mesh::AddTextureCoordinate(glm::vec2  texture_coordinate) noexcept
	{
		textureCoordinates.push_back(texture_coordinate);
	}
	//Remove all colors from the mesh
	void Mesh::ClearColors() noexcept
	{
		colors.clear();

	}
	//Returns true if the mesh has more than 1 color
	bool Mesh::HasMoreThanOneColor()  const noexcept
	{
		// int count = 0;
		if (colors.size() >= 1)
		{
			return true;
		}
		else
			return false;
	}
	//Remove all texture coordinates from the mesh
	void Mesh::ClearTextureCoordinates() noexcept
	{
		textureCoordinates.clear();
	}
	//Remove all points from the mesh
	void Mesh::ClearPoints() noexcept
	{
		points.clear();
	}
	//Remove all points, colors and texture coordinates from the mesh
	void Mesh::Clear() noexcept
	{
		ClearColors();
		ClearPoints();
		ClearTextureCoordinates();
	}

	namespace MESH
	{
		Mesh create_circle(float radius, Color4ub color, std::size_t point_count) noexcept
		{

			Mesh circle;

			/*float theta = (PI*2) / point_count;*/
			float theta = TWO_PI / point_count;
			glm::vec2  originPoint = { 0,0 };

			circle.SetPointListType(PointListPattern::TriangleFan);
			circle.AddPoint(originPoint);

			for (int i = 0; i <= point_count; i++)
			{

				glm::vec2  point = { radius*sin(theta*i), radius*-cos(theta*i) };
				circle.AddPoint(point);
				circle.AddColor(color);
			}

			return circle;
		}
		Mesh create_wire_circle(float radius, Color4ub color,
			std::size_t point_count) noexcept
		{

			Mesh wireCircle;
			wireCircle.AddColor(color);
			wireCircle.SetPointListType(PointListPattern::LineLoop);
			float theta = TWO_PI / point_count;
			/*float theta = (PI*2) / point_count;*/
			for (int i = 0; i < point_count; i++)
			{
				glm::vec2  point = { radius*sin(theta*i), radius*-cos(theta*i) };
				wireCircle.AddPoint(point);
			}

			return wireCircle;
		}
		Mesh create_box(float dimension, Color4ub color) noexcept
		{

			return create_rectangle(dimension, dimension, color);

		}
		Mesh create_rectangle(float width, float height, Color4ub color) noexcept
		{//use tan()
			Mesh rectangle;
			rectangle.SetPointListType(PointListPattern::TriangleFan);
			rectangle.AddTextureCoordinate({ 0,1 });
			rectangle.AddTextureCoordinate({ 0, 0 });
			rectangle.AddTextureCoordinate({ 1,0 });
			rectangle.AddTextureCoordinate({ 1,1 });

			rectangle.AddPoint({ -width / 2, -height / 2 });
			rectangle.AddPoint({ -width / 2,height / 2 });
			rectangle.AddPoint({ width / 2,height / 2 });
			rectangle.AddPoint({ width / 2,-height / 2 });
			rectangle.AddColor(color);

			rectangle.AddColor(color);

			return rectangle;

		}
		Mesh create_wire_rectangle(float width, float height, Color4ub color) noexcept
		{

			Mesh rectangle;

			rectangle.SetPointListType(PointListPattern::LineLoop);
			rectangle.AddTextureCoordinate({ 0,1 });
			rectangle.AddTextureCoordinate({ 0, 0 });
			rectangle.AddTextureCoordinate({ 1,0 });
			rectangle.AddTextureCoordinate({ 1,1 });

			rectangle.AddPoint({ -width / 2, -height / 2 });
			rectangle.AddPoint({ -width / 2,height / 2 });
			rectangle.AddPoint({ width / 2,height / 2 });
			rectangle.AddPoint({ width / 2,-height / 2 });


			rectangle.AddColor(color);

			return rectangle;

		}
		Mesh create_wire_box(float dimension, Color4ub color) noexcept
		{
			return create_wire_rectangle(dimension, dimension, color);
		}
		Mesh create_line(glm::vec2  a, glm::vec2  b, Color4ub color) noexcept
		{
			Mesh line;
			line.SetPointListType(PointListPattern::Lines);
			line.AddColor(color);
			line.AddPoint(a);
			line.AddPoint(b);
			return line;
		}
	}

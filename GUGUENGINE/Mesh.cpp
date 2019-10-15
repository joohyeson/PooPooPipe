/* 1.your name            joohye Son
2.the assignment number   4
3.the course name         CS230
4.the term                Spring 2019 */
//#include <CS230/graphics/Mesh.hpp>
//#include <CS230/math/angles.hpp>
#include <cmath>
#include <valarray>
#include "Mesh.h"
#include "glm/gtx/matrix_transform_2d.hpp"
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
std::vector<glm::vec3> Mesh::GetPoint() const noexcept
{
	return points;
}

void Mesh::SetPoint(std::vector<glm::vec3> point)
{
	points = point;
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
std::vector<glm::vec2>  Mesh::GetTextureCoordinate()  const noexcept
{
	//::vector<glm::vec2>  ZERO = { 0,0 };

	/*if (index < textureCoordinates.size() && index >= 0)
	{
		return textureCoordinates;
	}
	else if (textureCoordinates.empty() == true)
	{
		return ZERO;
	}*/
	/*else
		return textureCoordinates.back*/
	return textureCoordinates;

}
//Simple getter for pointListType
GLenum Mesh::GetPointListPattern()  const noexcept
{
	return pointListType;
}
//Simple setter for pointListType
void Mesh::SetPointListType(GLenum type)noexcept
{
	pointListType = type;
}
//Adds a new color to the mesh
void Mesh::AddColor(Color4ub color) noexcept
{
	colors.push_back(color);
}
//Adds a new point to the mesh
void Mesh::AddPoint(glm::vec3  point) noexcept
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
	Mesh create_circle(float radius, Color4ub color, std::size_t point_count, glm::vec3 point) noexcept
	{

		Mesh circle;

		/*float theta = (PI*2) / point_count;*/
		float theta = TWO_PI / point_count;
		glm::vec3  originPoint = point;

		circle.SetPointListType(GL_TRIANGLE_FAN);
		circle.AddPoint(originPoint);

		for (int i = 0; i <= point_count; i++)
		{

			glm::vec3  point = { radius * sin(theta * i), radius * -cos(theta * i),0 };
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
		wireCircle.SetPointListType(GL_LINE_LOOP);
		float theta = TWO_PI / point_count;
		/*float theta = (PI*2) / point_count;*/
		for (int i = 0; i < point_count; i++)
		{
			glm::vec3  point = { radius * sin(theta * i), radius * -cos(theta * i), 0 };
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
		rectangle.SetPointListType(GL_TRIANGLE_FAN);
		rectangle.AddTextureCoordinate({ 0,1 });
		rectangle.AddTextureCoordinate({ 0, 0 });
		rectangle.AddTextureCoordinate({ 1,0 });
		rectangle.AddTextureCoordinate({ 1,1 });

		rectangle.AddPoint({ -width / 2, -height / 2, 0 });
		rectangle.AddPoint({ -width / 2,height / 2 ,0 });
		rectangle.AddPoint({ width / 2,height / 2 ,0 });
		rectangle.AddPoint({ width / 2,-height / 2 ,0 });
		rectangle.AddColor(color);

		rectangle.AddColor(color);

		return rectangle;

	}
	Mesh create_wire_rectangle(float width, float height, Color4ub color) noexcept
	{

		Mesh rectangle;

		rectangle.SetPointListType(GL_LINE_LOOP);

		rectangle.AddTextureCoordinate({ 0,1 });
		rectangle.AddTextureCoordinate({ 0, 0 });
		rectangle.AddTextureCoordinate({ 1,0 });
		rectangle.AddTextureCoordinate({ 1,1 });

		rectangle.AddPoint({ -width / 2, -height / 2,0 });
		rectangle.AddPoint({ -width / 2,height / 2 ,0 });
		rectangle.AddPoint({ width / 2,height / 2 ,0 });
		rectangle.AddPoint({ width / 2,-height / 2,0 });


		rectangle.AddColor(color);

		return rectangle;

	}
	Mesh create_wire_box(float dimension, Color4ub color) noexcept
	{
		return create_wire_rectangle(dimension, dimension, color);
	}
	Mesh create_line(glm::vec3  a, glm::vec3  b, Color4ub color) noexcept
	{
		Mesh line;
		line.SetPointListType(GL_LINES);
		line.AddColor(color);
		line.AddPoint(a);
		line.AddPoint(b);
		return line;
	}
	Mesh create_triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c)
	{
		Mesh triangle;

		triangle.SetPointListType(GL_TRIANGLES);

		//glm::mat3 myMatrix1 = glm::translate(glm::mat3(), {0.3,0.7});
		//glm::mat3 myMatrix1 = glm::scale(glm::mat3(), { 0.1, 0.1 });
		glm::mat3 myMatrix1 = glm::rotate(glm::mat3(), 0.3f);
		
		glm::vec3 mA = { myMatrix1[0][0] * a.x + myMatrix1[1][0] * a.y + myMatrix1[2][0] * a.z,
		myMatrix1[0][1] * a.x + myMatrix1[1][1] * a.y + myMatrix1[2][1] * a.z ,
		myMatrix1[0][2] * a.x + myMatrix1[1][2] * a.y + myMatrix1[2][2] * a.z };

		glm::vec3 mB = { myMatrix1[0][0] * b.x + myMatrix1[1][0] * b.y + myMatrix1[2][0] * b.z,
		myMatrix1[0][1] * b.x + myMatrix1[1][1] * b.y + myMatrix1[2][1] * b.z ,
		myMatrix1[0][2] * b.x + myMatrix1[1][2] * b.y + myMatrix1[2][2] * b.z };

		glm::vec3 mC = { myMatrix1[0][0] * c.x + myMatrix1[1][0] * c.y + myMatrix1[2][0] * c.z,
		myMatrix1[0][1] * c.x + myMatrix1[1][1] * c.y + myMatrix1[2][1] * c.z ,
		myMatrix1[0][2] * c.x + myMatrix1[1][2] * c.y + myMatrix1[2][2] * c.z };

		triangle.AddPoint(mA);
		triangle.AddPoint(mB);
		triangle.AddPoint(mC);

		return triangle;
	}
}

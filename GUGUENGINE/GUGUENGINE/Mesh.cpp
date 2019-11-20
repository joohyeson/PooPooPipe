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
#include "Transform.h"
#include <iostream>
#include "Shader.h"
////////////////////////////////////////////////////////delete//////////////////////////////////////////////
constexpr float PI = 3.1415926535897932384626433832795f;
constexpr float HALF_PI = PI / 2.0f;
constexpr float QUARTER_PI = PI / 4.0f;
constexpr float TWO_PI = 2.0f * PI;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///

	//Returns the total amount of points representing the mesh
Transform* m;

float color[] = {
	1.0f, 0.0f, 0.0f, //vertex 1 : RED (1,0,0)
	0.0f, 1.0f, 0.0f, //vertex 2 : GREEN (0,1,0) 
	0.0f, 0.0f, 1.0f,  //vertex 3 : GUGU (0,0,1)
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
};//It will be changed when color4up is completed
float verticesFlat[] = {
   0.0f,   0.0f, 0.0f,    //center
   -0.5f,   1.0f, 0.0f,    // left top
   0.5f,   1.0f, 0.0f,    // right top
   1.0f,   0.0f, 0.0f,    // right
   0.5f,   -1.0f, 0.0f,    // right bottom (notice sign)
   -0.5f,  -1.0f, 0.0f,    // left bottom
   -1.0f,   0.0f, 0.0f,     // left
	0.0f, 0.0f, 0.0f
};
Mesh::Mesh() : Component(COMPONENTTYPE_MESH),  mVertexArrayObject (0), mPositionVertexBufferObjectID(0), mColorVertexBufferObjectID(0)
{
	points.clear();
	colors.clear();
	textureCoordinates.clear();
}

Mesh::~Mesh()
{
	Delete();
}
void Mesh::Initialize()
{
	mMesh= MESH::create_circle(0.7f, { 255, 255, 255 }, 6, { 400, 300, 0 }, 0);
	glGenVertexArrays(1, &mVertexArrayObject);
	glBindVertexArray(mVertexArrayObject);

	//Vertex Buffer Object(VBO)ธ
	glGenBuffers(1, &mPositionVertexBufferObjectID);
	glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesFlat), verticesFlat, GL_STATIC_DRAW);

	glGenBuffers(1, &mColorVertexBufferObjectID);
	glBindBuffer(GL_ARRAY_BUFFER, mColorVertexBufferObjectID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);

}
void Mesh::Update()
{
	GLint positionAttribute = glGetAttribLocation(shaderID, "positionAttribute");
	if (positionAttribute == -1) {
		std::cerr << "position error" << std::endl;
		
	}
	glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);

	glEnableVertexAttribArray(0);

	GLint colorAttribute = glGetAttribLocation(shaderID, "colorAttribute");
	if (colorAttribute == -1) {
		std::cerr << "color error" << std::endl;
		
	}
	glBindBuffer(GL_ARRAY_BUFFER, mColorVertexBufferObjectID);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
	glEnableVertexAttribArray(1);

	glBindVertexArray(mVertexArrayObject);
	//glDrawArrays(GL_TRIANGLE_FAN/*mMesh.GetPointListPattern()*/, 0, /*mMesh.GetPointCount()*/24 * sizeof(float));
//	glDrawArray
}

void Mesh::Delete()
{
	glDeleteBuffers(1, &mPositionVertexBufferObjectID);
	glDeleteBuffers(1, &mColorVertexBufferObjectID);
	glDeleteVertexArrays(1, &mVertexArrayObject);
}
GLuint* Mesh::GetVertexArrayObjectPointer(void) noexcept
{
	GLuint* m = &mVertexArrayObject;

	return m;
}
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
	std::vector<glm::vec3> create_circle(float radius, Color4ub color, std::size_t point_count, glm::vec3 point, float time) noexcept
	{
		
		std::vector<glm::vec3> circle;

		/*float theta = (PI*2) / point_count;*/
		float theta = TWO_PI / point_count;

		glm::vec3  originPoint = { (point.x - 400) / 400 , -1 * ((point.y) - 300) / 300, point.z };

		//circle.SetPointListType(GL_TRIANGLE_FAN);
		
		circle.clear();
		
		circle.push_back(originPoint);

		glm::mat3 myMatrix1 = glm::translate(glm::mat3(), { point.x,point.y });
		//glm::mat3 myMatrix1 = glm::scale(glm::mat3(), { 0.1, 0.1 });
		//glm::mat3 myMatrix1 = glm::rotate(glm::mat3(), time);

		for (int i = 0; i <= point_count; i++)
		{
			//glm::vec3  point = { radius * sin(theta * i), radius * -cos(theta * i),0 };
			glm::vec3 mA = m->mMatrix(myMatrix1, { radius * sin(theta * i) + originPoint.x, radius * -cos(theta * i) + originPoint.y, 0 });

			circle.push_back(mA);
			//circle.AddColor(color);
		}
		return circle;
		//return circle;
	}

	std::vector<glm::vec3> create_wire_circle(float radius, Color4ub color,
		std::size_t point_count) noexcept
	{
		std::vector<glm::vec3> wireCircle;
		//wireCircle.AddColor(color);
		//wireCircle.SetPointListType(GL_LINE_LOOP);
		float theta = TWO_PI / point_count;

		//glm::mat3 myMatrix1 = glm::translate(glm::mat3(), {0.3,0.7});
		//glm::mat3 myMatrix1 = glm::scale(glm::mat3(), { 0.1, 0.1 });
		glm::mat3 myMatrix1 = glm::rotate(glm::mat3(), 0.3f);

		/*float theta = (PI*2) / point_count;*/
		for (int i = 0; i < point_count; i++)
		{
			glm::vec3 mA = m->mMatrix(myMatrix1, { radius * sin(theta * i), radius * -cos(theta * i), 0 });
			//glm::vec3  point = { radius * sin(theta * i), radius * -cos(theta * i), 0 };
			wireCircle.push_back(mA);
		}

		return wireCircle;
	}

	std::vector<glm::vec3> create_box(float dimension, Color4ub color) noexcept
	{

		return create_rectangle(dimension, dimension, color);

	}
	std::vector<glm::vec3> create_rectangle(float width, float height, Color4ub color) noexcept
	{//use tan()
		std::vector<glm::vec3> rectangle;
		//rectangle.SetPointListType(GL_TRIANGLE_FAN);
		/*rectangle.AddTextureCoordinate({ 0,1 });
		rectangle.AddTextureCoordinate({ 0, 0 });
		rectangle.AddTextureCoordinate({ 1,0 });
		rectangle.AddTextureCoordinate({ 1,1 });*/

		//glm::mat3 myMatrix1 = glm::translate(glm::mat3(), {0.3,0.7});
		//glm::mat3 myMatrix1 = glm::scale(glm::mat3(), { 0.1, 0.1 });
		glm::mat3 myMatrix1 = glm::rotate(glm::mat3(), 0.3f);

		glm::vec3 mA = m->mMatrix(myMatrix1, { -width / 2, -height / 2,0 });
		glm::vec3 mB = m->mMatrix(myMatrix1, { -width / 2,height / 2 ,0 });
		glm::vec3 mC = m->mMatrix(myMatrix1, { width / 2,height / 2 ,0 });
		glm::vec3 mD = m->mMatrix(myMatrix1, { width / 2,-height / 2,0 });

		rectangle.push_back(mA);
		rectangle.push_back(mB);
		rectangle.push_back(mC);
		rectangle.push_back(mD);

		//ectangle.AddColor(color);

		//rectangle.AddColor(color);

		return rectangle;
		
	}
	std::vector<glm::vec3> create_wire_rectangle(float width, float height, Color4ub color) noexcept
	{

		std::vector<glm::vec3> rectangle;

		/*rectangle.SetPointListType(GL_LINE_LOOP);

		rectangle.AddTextureCoordinate({ 0,1 });
		rectangle.AddTextureCoordinate({ 0, 0 });
		rectangle.AddTextureCoordinate({ 1,0 });
		rectangle.AddTextureCoordinate({ 1,1 });
*/
		//glm::mat3 myMatrix1 = glm::translate(glm::mat3(), {0.3,0.7});
		//glm::mat3 myMatrix1 = glm::scale(glm::mat3(), { 0.1, 0.1 });
		glm::mat3 myMatrix1 = glm::rotate(glm::mat3(), 0.3f);

		glm::vec3 mA = m->mMatrix(myMatrix1, { -width / 2, -height / 2,0 });
		glm::vec3 mB = m->mMatrix(myMatrix1, { -width / 2,height / 2 ,0 });
		glm::vec3 mC = m->mMatrix(myMatrix1, { width / 2,height / 2 ,0 });
		glm::vec3 mD = m->mMatrix(myMatrix1, { width / 2,-height / 2,0 });

		rectangle.push_back(mA);
		rectangle.push_back(mB);
		rectangle.push_back(mC);
		rectangle.push_back(mD);

		//rectangle.AddColor(color);

		return rectangle;

	}
	std::vector<glm::vec3> create_wire_box(float dimension, Color4ub color) noexcept
	{
		return create_wire_rectangle(dimension, dimension, color);
	}
	std::vector<glm::vec3> create_line(glm::vec3  a, glm::vec3  b, Color4ub color) noexcept
	{
		std::vector<glm::vec3> line;
		//line.SetPointListType(GL_LINES);
		//line.AddColor(color);
		//glm::mat3 myMatrix1 = glm::translate(glm::mat3(), {0.3,0.7});
		//glm::mat3 myMatrix1 = glm::scale(glm::mat3(), { 0.1, 0.1 });
		glm::mat3 myMatrix1 = glm::rotate(glm::mat3(), 0.3f);

		glm::vec3 mA = m->mMatrix(myMatrix1, a);
		glm::vec3 mB = m->mMatrix(myMatrix1, b);

		line.push_back(mA);
		line.push_back(mB);
		return line;
	}
	std::vector<glm::vec3> create_triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c, float time)
	{
		std::vector<glm::vec3> triangle;
		/*triangle.ClearPoints();
		triangle.SetPointListType(GL_TRIANGLES);*/

		//glm::mat3 myMatrix1 = glm::translate(glm::mat3(), {0.3, 0.7});
		//glm::mat3 myMatrix1 = glm::scale(glm::mat3(), { 0.1, 0.1 });
		glm::mat3 myMatrix1 = glm::rotate(glm::mat3(), time);

		glm::vec3 mA = m->mMatrix(myMatrix1, a);
		glm::vec3 mB = m->mMatrix(myMatrix1, b);
		glm::vec3 mC = m->mMatrix(myMatrix1, c);

		triangle.push_back(mA);
		triangle.push_back(mB);
		triangle.push_back(mC);

		return triangle;
	}
}

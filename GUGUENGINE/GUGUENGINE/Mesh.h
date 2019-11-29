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
#include "Mathematics/Vector2.hpp"
#include "Mathematics/Vector3.hpp"


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
	std::vector<Mathematics::Vector3<float>>   GetPoint() const noexcept;
	void	 SetPoint(std::vector<Mathematics::Vector3<float>> point);

	Color4ub    GetColor(std::size_t index = 0) const noexcept;
	std::vector<Mathematics::Vector2<float>>      GetTextureCoordinate() const noexcept;

	GLenum GetPointListPattern() const noexcept;
	void  SetPointListType(GLenum type) noexcept;

	void AddColor(Color4ub color) noexcept;
	void AddPoint(Mathematics::Vector3<float>  point) noexcept;
	void AddTextureCoordinate(Mathematics::Vector2<float>  texture_coordinate) noexcept;

	void ClearColors() noexcept;
	bool HasMoreThanOneColor() const noexcept;
	void setTransfrom(Mathematics::Vector2<float> m);
	void ClearTextureCoordinates() noexcept;
	void ClearPoints() noexcept;
	void Clear() noexcept;
	GLuint* GetVertexArrayObjectPointer(void) noexcept;
	std::vector<Mathematics::Vector3<float>> createHexagon(Mathematics::Vector3<float> point) noexcept;
	void SetVertex(Mathematics::Vector2<float> mVec);
	GLuint GetVertexArrayObject(void) noexcept;
	Mathematics::Vector2<float> getTransfrom();
	void setRotation(float m);
	Mathematics::Vector2<float> getVertex(int i);
private:
	std::vector<Mathematics::Vector3<float>> vertex;
	std::vector<Mathematics::Vector3<float>>  points{};
	std::vector<Color4ub> colors{};
	std::vector<Mathematics::Vector2<float>>  textureCoordinates{};
	int shaderID = 0;
	Shader mShader;
	GLenum      pointListType = GL_LINES;
	GLuint mVertexArrayObject;
	GLuint mPositionVertexBufferObjectID, mColorVertexBufferObjectID;
	GLuint mTextureCoordinateBufferObjectID;
	Transform transform;
};

namespace MESH
{
	//std::vector<Mathematics::Vector3<float>> createHexagon(Mathematics::Vector3<float> point) noexcept;
	std::vector<Mathematics::Vector3<float>> create_wire_circle(float radius = 1, Color4ub color = Color4ub{ 255 }, std::size_t point_count = 30) noexcept;
	std::vector<Mathematics::Vector3<float>> create_box(float dimension = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	std::vector<Mathematics::Vector3<float>> create_rectangle(float width = 1, float height = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	std::vector<Mathematics::Vector3<float>> create_wire_rectangle(float width = 1, float height = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	std::vector<Mathematics::Vector3<float>> create_wire_box(float dimension = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	std::vector<Mathematics::Vector3<float>> create_line(Mathematics::Vector2<float>  a = { 0, 0 }, Mathematics::Vector2<float>  b = { 1, 0 }, Color4ub color = Color4ub{ 255 }) noexcept;
	std::vector<Mathematics::Vector3<float>> create_triangle(Mathematics::Vector3<float> a, Mathematics::Vector3<float> b, Mathematics::Vector3<float> c, float time);
}


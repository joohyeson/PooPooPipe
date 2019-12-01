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
	void Delete();

	std::size_t GetPointCount() const noexcept;
	std::vector<Vector3<float>>   GetPoint() const noexcept;
    Color4ub    GetColor(std::size_t index = 0) const noexcept;
    std::vector<Vector2<float>>      GetTextureCoordinate() const noexcept;
    GLenum GetPointListPattern() const noexcept;
    Vector2<float> getTransfrom();
    Vector2<float> getVertex(int i);

	void	 SetPoint(std::vector<Vector3<float>> point);
	void  SetPointListType(GLenum type) noexcept;
    void setRotation(float m);
    void SetVertex(Vector2<float> mVec);

	void AddColor(Color4ub color) noexcept;
	void AddPoint(Vector3<float>  point) noexcept;
	void AddTextureCoordinate(Vector2<float>  texture_coordinate) noexcept;

	void setTransform(Vector2<float> m);
	void Clear() noexcept;

	GLuint* GetVertexArrayObjectPointer(void) noexcept;
	std::vector<Vector3<float>> createHexagon(Vector3<float> point) noexcept;

	GLuint GetVertexArrayObject(void) noexcept;

    std::vector<Vector3<float>> create_wire_circle(float radius = 1, Color4ub color = Color4ub{ 255 }, std::size_t point_count = 30) noexcept;
    std::vector<Vector3<float>> create_box(float dimension = 1, Color4ub color = Color4ub{ 255 }) noexcept;
    std::vector<Vector3<float>> create_rectangle(float width = 1, float height = 1, Color4ub color = Color4ub{ 255 }) noexcept;
    std::vector<Vector3<float>> create_wire_rectangle(float width = 1, float height = 1, Color4ub color = Color4ub{ 255 }) noexcept;
    std::vector<Vector3<float>> create_wire_box(float dimension = 1, Color4ub color = Color4ub{ 255 }) noexcept;
    std::vector<Vector3<float>> create_line(Vector2<float>  a = { 0, 0 }, Vector2<float>  b = { 1, 0 }, Color4ub color = Color4ub{ 255 }) noexcept;
    std::vector<Vector3<float>> create_triangle(Vector3<float> a, Vector3<float> b, Vector3<float> c, float time);
private:
	std::vector<Vector3<float>> vertex;
	std::vector<Vector3<float>>  points{};
	std::vector<Color4ub> colors{};
	std::vector<Vector2<float>>  textureCoordinates{};
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
	//std::vector<Vector3<float>> createHexagon(Vector3<float> point) noexcept;
	
}


/*
 * Rudy Castan
 * Graphics Library
 * CS230
 */
#pragma once

#include "Color.h"

#include "glew.h"
#include <cstddef>
#include <vector>
#include "Component.h"
#include "Transform.h"
#include "Mathematics/Vector2.hpp"
#include "Mathematics/Vector3.hpp"

enum MESHTYPE
{
    hexagon,
    wire_circle,
    box,
    rectangle,
    wire_rectangle,
    wire_box,
    line,
    triangle
};
class Shader;

class [[nodiscard]] Mesh :public Component
{
public:
    Mesh();
    ~Mesh() override;

    void Initialize(void);
    void Update();
    void Delete();

    std::size_t                            GetPointCount() const noexcept;
    std::vector<Vector3<float>>   GetPoint() const noexcept;
    Color4ub                              GetColor(std::size_t index = 0) const noexcept;
    std::vector<Vector2<float>>   GetTextureCoordinate() const noexcept;
    GLenum                     GetPointListPattern() const noexcept;
    Vector2<float>                      GetTransform();
    Vector2<float>                      GetVertex(int i);
	void ColorMeshUpdate();
    void	SetPoint(std::vector<Vector3<float>> point);
    void setRotation(float m);
    void SetVertex(std::vector<Vector3<float>> shapeType);
    void SetOriginVertex(std::vector<Vector3<float>> vertexType);

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
    std::vector<Vector3<float>> create_triangle(Vector3<float> a = { -1.0f,-1.0f, 1.0f }, Vector3<float> b={ 1.0f,-1.0f, 1.0f, }, Vector3<float> c= { 0.f,1.0f, 1.0f, }) noexcept;

    std::vector<Vector3<float>> originVertex;
    std::vector<Vector3<float>> vertex;

    std::vector<Vector3<float>>  points{};
    std::vector<Color4ub> colors{};
    std::vector<Vector2<float>>  textureCoordinates{};

    GLenum      pointListType = GL_TRIANGLE_FAN;
    GLuint mVertexArrayObject;
    GLuint mPositionVertexBufferObjectID, mColorVertexBufferObjectID;
    GLuint mTextureCoordinateBufferObjectID;
    MESHTYPE meshType =hexagon;
    Transform transform;
};



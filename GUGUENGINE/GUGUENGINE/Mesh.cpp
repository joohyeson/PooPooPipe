/* 1.your name            joohye Son
2.the assignment number   4
3.the course name         CS230
4.the term                Spring 2019 */
//#include <CS230/graphics/Mesh.hpp>
//#include <CS230/math/angles.hpp>
#include <cmath>
#include <valarray>
#include "Mesh.h"
#include "Transform.h"
#include <iostream>
#include "Shader.h"
#include <cmath>
#include "Mathematics/MathLibrary.hpp"
////////////////////////////////////////////////////////delete//////////////////////////////////////////////
constexpr float PI = 3.1415926535897932384626433832795f;
constexpr float HALF_PI = PI / 2.0f;
constexpr float QUARTER_PI = PI / 4.0f;
constexpr float TWO_PI = 2.0f * PI;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///

    //Returns the total amount of points representing the mesh
Transform* m;
float verticesFlat[] = {
    0.0f,   0.0f, 0.0f,    //center
    -0.5f,   1.0f, 0.0f,    // left top
    0.5f,   1.0f, 0.0f,    // right top
    1.0f,   0.0f, 0.0f,    // right
    0.5f,   -1.0f, 0.0f,    // right bottom (notice sign)
    -0.5f,  -1.0f, 0.0f,    // left bottom
    -1.0f,   0.0f, 0.0f,     // left
    -0.5f,   1.0f, 0.0f    // left top
};
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

float textureCoordinate[] = {
                        0.5f, 0.5f,0,
                        0.5f, 0.0f,0,
                        1.0f, 0.25f ,0,
                        1.0f, 0.75f,0,
                        0.5f, 1.0f,0,
                        0.0f, 0.75f,0,
                        0.0f, 0.25f,0,
                        0.5f, 0.0f, 0 };

Mesh::Mesh() : Component(COMPONENTTYPE_MESH), mVertexArrayObject(0), mPositionVertexBufferObjectID(0), mColorVertexBufferObjectID(0), mTextureCoordinateBufferObjectID(0)
{
    points.clear();
    colors.clear();
    textureCoordinates.clear();
    transform.Initialize();
}

Mesh::~Mesh()
{
    Delete();
}
void Mesh::setTransform(Vector2<float> m)
{
    transform.SetTranslation({ m.x, m.y });
}
void Mesh::setRotation(float m)
{
    transform.SetRotation(m);
}
Vector2<float> Mesh::GetTransform()
{
    return { transform.GetTranslation().x, transform.GetTranslation().y };
}
Vector2<float> Mesh::GetVertex(int i)
{
    return { vertex.at(i).x, vertex.at(i).y };
}
void Mesh::Initialize()
{
    switch (meshType)
    {
    case hexagon:
        originVertex = createHexagon({ 0, 0, 0 });
        break;
    case box:
        originVertex = create_box();
        break;
    case wire_box:
        originVertex = create_wire_box();
        break;
    case wire_circle:
        originVertex = create_wire_circle();
        break;
    case wire_rectangle:
        originVertex = create_wire_rectangle();
        break;
    case rectangle:
        originVertex = create_rectangle();
        break;
    case triangle:
        originVertex = create_triangle();
        break;
    }

    SetVertex(originVertex);
    glGenVertexArrays(1, &mVertexArrayObject);
    glBindVertexArray(mVertexArrayObject);

    //Vertex Buffer Object(VBO)?
    glGenBuffers(1, &mPositionVertexBufferObjectID);
    glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID);
    glBufferData(GL_ARRAY_BUFFER, /*sizeof(Vector3<float>) * vertex.size()*/sizeof(verticesFlat), &vertex.at(0), GL_DYNAMIC_DRAW);

    glGenBuffers(1, &mTextureCoordinateBufferObjectID);
    glBindBuffer(GL_ARRAY_BUFFER, mTextureCoordinateBufferObjectID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(textureCoordinate), textureCoordinate, GL_DYNAMIC_DRAW);

}
void Mesh::Update()
{
    SetVertex(originVertex);

    glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesFlat), &vertex.at(0), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vector3<float>), (GLvoid*)0);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, mTextureCoordinateBufferObjectID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(textureCoordinate), textureCoordinate, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
    glEnableVertexAttribArray(1);


    //glBindVertexArray(0);
    //glDrawArrays(GL_TRIANGLE_FAN/*mMesh.GetPointListPattern()*/, 0, /*mMesh.GetPointCount()*/7);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
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
GLuint Mesh::GetVertexArrayObject(void) noexcept
{
    GLuint m = mVertexArrayObject;

    return m;
}
std::size_t Mesh::GetPointCount() const noexcept
{
    return points.size();
}
//Returns the i th point in the mesh
std::vector<Vector3<float>> Mesh::GetPoint() const noexcept
{
    return points;
}

void Mesh::SetPoint(std::vector<Vector3<float>> point)
{
    points = point;
}
void Mesh::SetVertex(std::vector<Vector3<float>> shapeType)
{
    Matrix3<float> T = Matrix3<float>::Translate({ transform.GetTranslation().x,  transform.GetTranslation().y,1 });
    Matrix3<float> R = Matrix3<float>::Rotate(transform.GetRotation());
    Matrix3<float> S = Matrix3<float>::Scale({ 0.2f, 0.2f, 0.2f });

    vertex = originVertex;

    for (int i = 0; i < vertex.size(); i++)
    {
        Vector3<float> mA = (T * R * S) * vertex.at(i);
        vertex.at(i) = { mA.x, mA.y, 1 };
    }
}
void Mesh::SetOriginVertex(std::vector<Vector3<float>> vertexType)
{
    originVertex = vertexType;
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
std::vector<Vector2<float>>  Mesh::GetTextureCoordinate()  const noexcept
{
    return textureCoordinates;
}
//Simple getter for pointListType
GLenum Mesh::GetPointListPattern()  const noexcept
{
    return pointListType;
}
//Simple setter for pointListType

//Adds a new color to the mesh
void Mesh::AddColor(Color4ub color) noexcept
{
    colors.push_back(color);
}
//Adds a new point to the mesh
void Mesh::AddPoint(Vector3<float>  point) noexcept
{
    points.push_back(point);

}
//Adds a new texture coordinate to the mesh
void Mesh::AddTextureCoordinate(Vector2<float> texture_coordinate) noexcept
{
    textureCoordinates.push_back(texture_coordinate);
}

//Remove all points, colors and texture coordinates from the mesh
void Mesh::Clear() noexcept
{
    colors.clear();
    points.clear();
    textureCoordinates.clear();
}

std::vector<Vector3<float>> Mesh::createHexagon(Vector3<float>point) noexcept
{
    std::vector<Vector3<float>> hexaVector;
    pointListType = GL_TRIANGLE_FAN;

    float theta = TWO_PI / 6;

    Vector3<float> mA = { 0, 0,1 };
    hexaVector.push_back(mA);
    for (int i = 0; i < 6; i++)
    {
        mA = Vector3<float>(sin(theta * i), -cos(theta * i), 1);
        hexaVector.push_back({ mA.x, mA.y, 1 });

    }
    hexaVector.push_back({ sin(theta * 0), -cos(theta * 0), 1 });

    return hexaVector;
}

std::vector<Vector3<float>> Mesh::create_wire_circle(float radius, Color4ub color,
    std::size_t point_count) noexcept
{
    std::vector<Vector3<float>> wireCircle;
    //wireCircle.AddColor(color);
    //wireCircle.SetPointListType(GL_LINE_LOOP);
    float theta = TWO_PI / point_count;

    //glm::mat3 myMatrix1 = glm::translate(glm::mat3(), {0.3,0.7});
    //glm::mat3 myMatrix1 = glm::scale(glm::mat3(), { 0.1, 0.1 });
    //glm::mat3 myMatrix1 = glm::rotate(glm::mat3(), 0.3f);
    Matrix3<float> myMatrix1 = Matrix3<float>::Rotate(0.3f);
    /*float theta = (PI*2) / point_count;*/
    for (int i = 0; i < point_count; i++)
    {
        Vector3<float> mA = myMatrix1 * Vector3<float>(radius * sin(theta * i), radius * -cos(theta * i), 1);
        //Vector3<float>  point = { radius * sin(theta * i), radius * -cos(theta * i), 0 };
        wireCircle.push_back({ mA.x, mA.y, 1 });
    }

    return wireCircle;
}

std::vector<Vector3<float>> Mesh::create_box(float dimension, Color4ub color) noexcept
{

    return create_rectangle(dimension, dimension, color);

}
std::vector<Vector3<float>> Mesh::create_rectangle(float width, float height, Color4ub color) noexcept
{//use tan()
    std::vector<Vector3<float>> rectangle;
    //rectangle.SetPointListType(GL_TRIANGLE_FAN);
    /*rectangle.AddTextureCoordinate({ 0,1 });
    rectangle.AddTextureCoordinate({ 0, 0 });
    rectangle.AddTextureCoordinate({ 1,0 });
    rectangle.AddTextureCoordinate({ 1,1 });*/

    //glm::mat3 myMatrix1 = glm::translate(glm::mat3(), {0.3,0.7});
    //glm::mat3 myMatrix1 = glm::scale(glm::mat3(), { 0.1, 0.1 });
    Matrix3<float> myMatrix1 = Matrix3<float>::Rotate(0.3f);

    Vector3<float> mA = myMatrix1 * Vector3(-width / 2, -height / 2, 1.f);
    Vector3<float> mB = myMatrix1 * Vector3(-width / 2, height / 2, 1.f);
    Vector3<float> mC = myMatrix1 * Vector3(width / 2, height / 2, 1.f);
    Vector3<float> mD = myMatrix1 * Vector3(width / 2, -height / 2, 1.f);

    rectangle.push_back({ mA.x, mA.y, 1 });
    rectangle.push_back({ mB.x, mB.y, 1 });
    rectangle.push_back({ mC.x, mC.y, 1 });
    rectangle.push_back({ mD.x, mD.y, 1 });

    //ectangle.AddColor(color);

    //rectangle.AddColor(color);

    return rectangle;

}
std::vector<Vector3<float>> Mesh::create_wire_rectangle(float width, float height, Color4ub color) noexcept
{

    std::vector<Vector3<float>> rectangle;

    /*rectangle.SetPointListType(GL_LINE_LOOP);

    rectangle.AddTextureCoordinate({ 0,1 });
    rectangle.AddTextureCoordinate({ 0, 0 });
    rectangle.AddTextureCoordinate({ 1,0 });
    rectangle.AddTextureCoordinate({ 1,1 });
*/
//glm::mat3 myMatrix1 = glm::translate(glm::mat3(), {0.3,0.7});
//glm::mat3 myMatrix1 = glm::scale(glm::mat3(), { 0.1, 0.1 });
    Matrix3<float> myMatrix1 = Matrix3<float>::Rotate(0.3f);

    Vector3<float> mA = myMatrix1 * Vector3(-width / 2, -height / 2, 1.f);
    Vector3<float> mB = myMatrix1 * Vector3(-width / 2, height / 2, 1.f);
    Vector3<float> mC = myMatrix1 * Vector3(width / 2, height / 2, 1.f);
    Vector3<float> mD = myMatrix1 * Vector3(width / 2, -height / 2, 1.f);

    rectangle.push_back({ mA.x, mA.y, 1 });
    rectangle.push_back({ mB.x, mB.y, 1 });
    rectangle.push_back({ mC.x, mC.y, 1 });
    rectangle.push_back({ mD.x, mD.y, 1 });


    //rectangle.AddColor(color);

    return rectangle;

}
std::vector<Vector3<float>> Mesh::create_wire_box(float dimension, Color4ub color) noexcept
{
    return create_wire_rectangle(dimension, dimension, color);
}

std::vector<Vector3<float>> Mesh::create_triangle(Vector3<float> a, Vector3<float> b, Vector3<float> c) noexcept
{
    std::vector<Vector3<float>> triangle;
    /*triangle.ClearPoints();
    triangle.SetPointListType(GL_TRIANGLES);*/

    //glm::mat3 myMatrix1 = glm::translate(glm::mat3(), {0.3, 0.7});
    //glm::mat3 myMatrix1 = glm::scale(glm::mat3(), { 0.1, 0.1 });

    Matrix3<float> myMatrix1 = Matrix3<float>::Rotate(0.3f);

    Vector3<float> mA = myMatrix1 * a;
    Vector3<float> mB = myMatrix1 * b;
    Vector3<float> mC = myMatrix1 * c;
    triangle.push_back(mA);
    triangle.push_back(mB);
    triangle.push_back(mC);

    return triangle;
}

std::vector<Vector3<float>> create_line(Vector2<float> a, Vector2<float> b, Color4ub color) noexcept
{
    std::vector<Vector3<float>> line;
    //line.SetPointListType(GL_LINES);
    //line.AddColor(color);

    Vector3<float> mA = {a.x, a.y, 1.f };
    Vector3<float> mB = { b.x, b.y, 1.f };

    line.push_back(mA);
    line.push_back(mB);
    return line;
}

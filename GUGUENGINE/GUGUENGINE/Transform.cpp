#include "glm/gtc/matrix_transform.hpp"
#include "Transform.h"

void Transform::Initialize(void)
{
	rotation = 0.f;
	translation = { 0.f, 0.f };
	scale = { 1.0f,1.0f };
}

void Transform::Update()
{
	float time = 0;
	time++;
}

glm::vec2 Transform::GetTranslation() const noexcept
{
	return translation;
}
glm::vec2 Transform::GetScale() const noexcept
{
	return scale;
}
void Transform::SetTranslation(const glm::vec2& new_translation) noexcept
{
	translation = new_translation;
}
void Transform::SetScale(const glm::vec2& new_scale) noexcept
{
	scale = new_scale;
}
float Transform::GetRotation() const noexcept
{
	return rotation;
}
void Transform::SetRotation(float new_rotation) noexcept
{
	rotation = new_rotation;
}
glm::vec3 Transform::mMatrix(glm::mat3 myMatrix1, glm::vec3 c) noexcept
{
	glm::vec3 mC = { myMatrix1[0][0] * c.x + myMatrix1[1][0] * c.y + myMatrix1[2][0] * c.z,
	myMatrix1[0][1] * c.x + myMatrix1[1][1] * c.y + myMatrix1[2][1] * c.z ,
	myMatrix1[0][2] * c.x + myMatrix1[1][2] * c.y + myMatrix1[2][2] * c.z };

	return mC;
}

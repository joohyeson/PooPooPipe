#include "glm/gtc/matrix_transform.hpp"
#include "Transform.h"
#include "Mathematics/Vector3.hpp"
#include "Mathematics/Matrix.hpp"

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

Mathematics::Vector2<float> Transform::GetTranslation() const noexcept
{
	return translation;
}
Mathematics::Vector2<float> Transform::GetScale() const noexcept
{
	return scale;
}
void Transform::SetTranslation(const Mathematics::Vector2<float>& new_translation) noexcept
{
	translation = new_translation;
}
void Transform::SetScale(const Mathematics::Vector2<float>& new_scale) noexcept
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
Mathematics::Vector3<float> Transform::mMatrix(glm::mat3 myMatrix1, Mathematics::Vector3<float> c) noexcept
{
	Mathematics::Vector3<float> mC = { myMatrix1[0][0] * c.x + myMatrix1[1][0] * c.y + myMatrix1[2][0] * c.z,
	myMatrix1[0][1] * c.x + myMatrix1[1][1] * c.y + myMatrix1[2][1] * c.z ,
	myMatrix1[0][2] * c.x + myMatrix1[1][2] * c.y + myMatrix1[2][2] * c.z };

	return mC;
}

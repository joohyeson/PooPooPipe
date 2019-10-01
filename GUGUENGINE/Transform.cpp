#include "Transform.h"

void Transform::Init(void)
{
	rotation = 0.f;
	translation = { 0, 0 };
	scale = { 10,10 };
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

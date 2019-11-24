#pragma once
#include "external/glm/glm/glm.hpp"
#include "Component.h"
class Transform : public Component
{
public:
	Transform() :Component(COMPONENTTYPE_TRANSFORM) {
		rotation = 0.f;
		translation = { 0.f, 0.f };
		scale = { 1.0f,1.0f };
	};
	~Transform() override;

	void Initialize(void);
	void Update();
	glm::vec2 GetTranslation() const noexcept;
	glm::vec2 GetScale() const noexcept;
	void SetTranslation(const glm::vec2& new_translation) noexcept;
	void SetScale(const glm::vec2& new_scale) noexcept;
	float GetRotation() const noexcept;
	void SetRotation(float new_rotation) noexcept;
	glm::vec3 mMatrix(glm::mat3 myMatrix1, glm::vec3 c) noexcept;

private:

	glm::vec2 translation{};
	glm::vec2 scale{};
	float rotation;
};

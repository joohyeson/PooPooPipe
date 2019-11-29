#pragma once
#include "external/glm/glm/glm.hpp"
#include "Component.h"
#include "Mathematics/Vector3.hpp"
#include "Mathematics/Vector2.hpp"

class Transform : public Component
{
public:
	Transform() :Component(COMPONENTTYPE_TRANSFORM) {
		rotation = 0.f;
		translation = { 0.f, 0.f };
		scale = { 1.0f,1.0f };
	};
	//~Transform();

	void Initialize(void);
	void Update();
	Mathematics::Vector2<float> GetTranslation() const noexcept;
	Mathematics::Vector2<float> GetScale() const noexcept;
	void SetTranslation(const Mathematics::Vector2<float>& new_translation) noexcept;
	void SetScale(const Mathematics::Vector2<float>& new_scale) noexcept;
	float GetRotation() const noexcept;
	void SetRotation(float new_rotation) noexcept;
	Mathematics::Vector3<float> mMatrix(glm::mat3 myMatrix1, Mathematics::Vector3<float> c) noexcept;

private:

	Mathematics::Vector2<float> translation{};
	Mathematics::Vector2<float> scale{};
	float rotation;
};

#pragma once
#include "glm/glm.hpp"
class Transform {
public:
	Transform() {};
	~Transform() {};

	void Init(void);

	glm::vec2 GetTranslation() const noexcept;
	glm::vec2 GetScale() const noexcept;
	void SetTranslation(const glm::vec2& new_translation) noexcept;
	void SetScale(const glm::vec2& new_scale) noexcept;
	float GetRotation() const noexcept;
	void SetRotation(float new_rotation) noexcept;
	void mtranslation(const glm::vec2& mVector);

private:
	glm::vec2 translation{};
	glm::vec2 scale{};
	float rotation;
};

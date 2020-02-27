#pragma once
#include "Mathematics/Vector2.hpp"
#include "Object.h"
//#include "Texture.h"

class MovePooPoo {
public:
	MovePooPoo();
	MovePooPoo(Vector2<float> startDirection, Vector2<float> endDirection);

	void Init();
	void Update(int shaderHandler);

	void SetIsSuccess(bool success);
	void SetStartD(Vector2<float> start);
	void SetEndD(Vector2<float> end);

private:
	GLuint texturePP;
	Object* objectPP = nullptr;
	bool isSuccess = false;
	Vector2<float> startD = { 0.0f, 0.0f };
	Vector2<float> endD = { 0.5f, 0.5f };
};


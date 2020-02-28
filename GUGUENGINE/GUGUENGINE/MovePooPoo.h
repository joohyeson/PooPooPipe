#pragma once
#include "Mathematics/Vector2.hpp"
#include "Object.h"
//#include "Texture.h"

class MovePooPoo {
public:
	MovePooPoo();
	MovePooPoo(Vector2<float> startDirection, Vector2<float> endDirection, int Speed);

	void Init();
	void Update(int shaderHandler);

	void SetIsSuccess(bool success);
	void SetStartD(float startX, float startY);
	void SetEndD(float endX, float endY);
	void SetSpeed(int Speed);

private:
	GLuint texturePP;
	Object* objectPP = nullptr;
	bool isSuccess = false;
	bool isHidden = true;
	float speed = 100; 
	float elapse = 0.01;
	float distance=0;
	Vector2<float> direction = { 0, 0 };
	Vector2<float> betweenDelta = { 0.0f, 0.0f };
	Vector2<float> startD = { 0.0f, 0.0f };
	Vector2<float> endD = { 0.5f, 0.5f };

	void setDelta();
};


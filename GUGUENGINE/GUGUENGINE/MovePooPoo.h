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
	bool GetIsSuccess()
	{
		return isSuccess;
	}

	
	void SetIsHidden(bool set)
	{
		isHidden = set;
	}
	bool IsFinish()
	{
		return isFinish;
	}

	
	Vector2<float> GetEndD();
	Vector2<float> GetStartD();
	void MoveInPuzzle(std::vector < Vector2<float>>);
	void MoveInPuzzle(int shaderHandler);
	Vector2<float> GetPooPooTransform();
	void AddAngle(DirAngle startA, DirAngle endA, Vector2<float> origin)
	{
		myAngles.push_back(startA);
		myAngles.push_back(endA);
		coor.push_back(origin);
	}
private:
	void SetStartD(float startX, float startY);
	void SetEndD(float endX, float endY);
	void SetSpeed(int Speed);
	void SetEndD(Vector2<float> endDirection);
	void SetStartD(Vector2<float> startDirection);

	GLuint texturePP;
	Object* objectPP = nullptr;
	bool isSuccess = false;
	bool isHidden = true;
	bool isFirst = true;
	float speed = 100; 
	float elapse = 0.01;
	float distance=0;
	Vector2<float> direction = { 0, 0 };
	Vector2<float> betweenDelta = { 0.0f, 0.0f };
	Vector2<float> startD = { 0.0f, 0.0f };
	Vector2<float> endD = { 0.5f, 0.5f };
	Vector2<float> origin = { 0.0f, 0.0f };
	void setDelta();
	Vector2<float> realEndD = { 0.0f, 0.0f };
	bool isFinish = false;
	std::vector<DirAngle> myAngles;
	std::vector < Vector2<float>> coor;
};


#pragma once

class LimitRotate
{
public:
	LimitRotate() : limitTime(10) {}
	~LimitRotate(){}

	int getLimitTime();

	void Update();
	
	void IncLimit();
	void DecLimit();
	
	
private:
	int limitTime = 0;
};
#pragma once
#include "GenerateMap.h"
#include <vector>

class GetDirection
{
public:
	GetDirection(int row, int column) :mapRow(row), mapColumn(column) {};
	bool IsValidLocation(int puzzleNumber, int EdgeNumber);

	void StartGetDirection();

private:
	int mapRow=0;
	int mapColumn=0;

};


#pragma once
#include"ZigZagMap.h"
class GetDirection {
public:
	//void SetAllObjects(std::vector<ObjectWay*> objectSave)
	//{
	//	allObjects = objectSave;
	//}
	GetDirection(int x, int y) :mapRow(x), mapColumn(y) {};
	bool IsValidLocation(int puzzleNumber, int EdgeNumber);

	void StartGetDirection(int startPuzzleNumber, int StartEdgeNumber, int endPuzzleNumber, int endEdgeNumber, ZigZagMap* myMap);
private:
	ZigZagMap* myM;
	int startPuzzleN;
	int StartEdgeN ;
	int endPuzzleN ;
	int endEdgeN ;
	int mapColumn;
	int mapRow;
};


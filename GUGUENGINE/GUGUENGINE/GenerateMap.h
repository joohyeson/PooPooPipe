#pragma once
#include <string>
#include <vector>
#include "Object.h"
#include "HexagonElements.h"
#include "ZigZagMap.h"
#include "GenerateMap.h"
#include "MovePooPoo.h"

class GenerateMap {
public:
	GenerateMap();
	GenerateMap(int column, int row);
	void GetNextCenterCoor(float radius);

	void MapAlignment();
	void SaveObject(Object* objectName);
	void SaveObjectWays();
	int GetObjectSize();
	void SetReadyToStart(bool m)
	{
		readyToStart = m;
	}
	void SetRow(int row) {
		mapRow = row;
	}
	void SetColumn(int column) {
		mapColumn = column;
	}
	void Update();
	std::vector<SaveWay> saveObjectWays;
	ZigZagMap myMap;
	bool IsValidLocation(int puzzleNumber, int EdgeNumber);
	void StartGetDirection(int startPuzzleNumber, int StartEdgeNumber, int endPuzzleNumber, int endEdgeNumber, ZigZagMap* myMap2);
	bool GetHasWay() {
		return hasWay;
	}
private:
	
	std::vector<Object*> objects;
	
	std::vector< Vector2<float> > coorSaver;//saver center coordinate
	std::vector<Vector2<int>> exactVector;
	//ZigZagMap myMapType;
	//GetDirection myDirection;
	bool readyToStart = false;
	bool hasWay = false;
	int mapRow = 6;
	int mapColumn = 5;

	int startPuzzleN;
	int StartEdgeN;
	int endPuzzleN;
	int endEdgeN;
};


#pragma once
#include <vector>
#include "HexagonElements.h"

class ZigZagMap {
public:
	ZigZagMap(int row, int column) :mapRow(row), mapColumn(column) {};
	ZigZagMap() :mapRow(0), mapColumn(0) {};

	void SetAllNeighbor();
	void DoesEdgeHasNeighbor();

	void SetFirstLine(int i, int k);
	void SetLastLine(int i, int k, bool isOdd);
	void SetOddLine(int k, int i);
	void SetEvenLine(int k, int i);

	void SetRow(int k)
	{
		mapRow = k;
	}
	void SetColumn(int i)
	{
		mapColumn = i;
	}

	std::vector<HexagonEdges> neighborSaver;

private:

	int mapRow=6;
	int mapColumn=5;
	int count = 0;

};

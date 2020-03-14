#pragma once
#include <vector>
#include "HexagonElements.h"

class ZigZagMap {
public:
	ZigZagMap(int row, int column) :mapRow(row), mapColumn(column) {};

	void SetAllNeighbor();
	void DoesEdgeHasNeighbor();

	void SetFirstLine(int i, int k);
	void SetLastLine(int i, int k, bool isOdd);
	void SetOddLine(int k, int i);
	void SetEvenLine(int k, int i);

	std::vector<HexagonEdges> neighborSaver;

private:

	int mapRow;
	int mapColumn;
	int count = 0;

};

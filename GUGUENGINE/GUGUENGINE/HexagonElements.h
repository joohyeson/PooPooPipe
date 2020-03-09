/*
 *juhye.son
 *3.10.2020
 *juhye.son990902@gmail.com
 *HexagonElements.h
 *It has generate map's element for hexagon Edge
 */
#pragma once
#include "Mathematics/Vector2.hpp"

class HexagonEdge {
public:
	HexagonEdge(int ID, int edgeID, bool hasNeighbor_);

	HexagonEdge();

	void SetMyEdge(Vector2<float>::Edge temp);
	void SetObjectID(int temp);
	void SetObjectEdgeID(bool temp);
	void SetHasNeigbor(bool temp);

	Vector2<float>::Edge GetMyEdge();
	//int GetObjectID();
	//int GetObjectEdgeID();
	bool GetHasNeighbor();

private:
	Vector2<float>::Edge myEdge;

	int objectID = 0;
	int objectEdgeID = 0;

	bool hasNeighbor = false;

};

class HexagonEdges
{
public:
	HexagonEdges()
	{
		Init();
	}
	void Init();
	void clear();

	HexagonEdge myEdge[6];

};

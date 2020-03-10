/*
 *juhye.son
 *3.10.2020
 *juhye.son990902@gmail.com
 *HexagonElements.cpp
 *It has generate map's element for hexagon Edge
 */
#include "HexagonElements.h"

HexagonEdge::HexagonEdge(int ID, int edgeID, bool hasNeighbor_) :
	objectID(ID), objectEdgeID(edgeID), hasNeighbor(hasNeighbor_) {
	myEdge.start = { 0.f, 0.f };
	myEdge.end = { 0.f, 0.f };
};
HexagonEdge::HexagonEdge() :
	objectID(0), objectEdgeID(0), hasNeighbor(0) {
	myEdge.start = { 0.f, 0.f };
	myEdge.end = { 0.f, 0.f };
};

void HexagonEdge::SetMyEdge(Vector2<float>::Edge temp)
{
	myEdge = temp;
}
void HexagonEdge::SetObjectID(int temp)
{
	objectID = temp;
}
void HexagonEdge::SetObjectEdgeID(bool temp)
{
	objectEdgeID = temp;
}
void HexagonEdge::SetHasNeigbor(bool temp)
{
	hasNeighbor = temp;
}

Vector2<float>::Edge HexagonEdge::GetMyEdge()
{
	return myEdge;
}
//int GenerateMap::HexagonEdge::GetObjectID() {
//	return 
//}
//int GenerateMap::HexagonEdge::GetObjectEdgeID();
bool HexagonEdge::GetHasNeighbor()
{
	return hasNeighbor;
}
void HexagonEdges::Init() {
	for (int i = 0; i < 6; i++)
	{
		myEdge[i].SetHasNeigbor(false);
		myEdge[i].SetMyEdge({ { 0.f, 0.f }, { 0.f, 0.f } });
		myEdge[i].SetObjectEdgeID(0);
		myEdge[i].SetObjectID(i);
	}
}
void HexagonEdges::clear() {
	for (int i = 0; i < 6; i++)
	{
		myEdge[i].SetHasNeigbor(false);
		myEdge[i].SetMyEdge({ { 0.f, 0.f }, { 0.f, 0.f } });
		myEdge[i].SetObjectEdgeID(0);
		myEdge[i].SetObjectID(i);
	}
}
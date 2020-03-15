
#include "GetDirection.h"
#include <stack>
#include "Mathematics/Vector2.hpp"
#include "ZigZagMap.h"

bool GetDirection::IsValidLocation(int puzzleNumber, int EdgeNumber)
{
	int neighborPuzzleN = myM->neighborSaver[puzzleNumber].myEdge[EdgeNumber].GetWhoIsNeighbor().x;
	int neighborEdgeN = myM->neighborSaver[puzzleNumber].myEdge[EdgeNumber].GetWhoIsNeighbor().y;
	if (puzzleNumber == endPuzzleN &&EdgeNumber == endEdgeN)
	{
		return true;
	}
	else if (puzzleNumber < 0 || EdgeNumber < 0 || EdgeNumber >= 6)
	{
		return false;
	}
	//else if (allObjects[puzzleNumber]->)
	//{
	//	return true;
	//}
	else if (myM->neighborSaver[puzzleNumber].myEdge[EdgeNumber].GetHasNeighbor() == false)
	{
		return false;
	}
	else if (myM->neighborSaver[puzzleNumber].myEdge[EdgeNumber].isComeBack == true)
	{
		return false;
	}
	else if (myM->neighborSaver[neighborPuzzleN].myEdge[neighborEdgeN].GetWhoIsNeighbor().x != puzzleNumber ||
		myM->neighborSaver[neighborPuzzleN].myEdge[neighborEdgeN].GetWhoIsNeighbor().y != EdgeNumber)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void GetDirection::StartGetDirection(int startPuzzleNumber, int StartEdgeNumber, int endPuzzleNumber, int endEdgeNumber, ZigZagMap* myMap)
{
	std::stack<Vector2<int>> locStack;
	Vector2<int> entry(startPuzzleNumber, StartEdgeNumber);
	
	locStack.push(entry);

	myM = myMap;
	startPuzzleN = startPuzzleNumber;
	StartEdgeN = StartEdgeNumber;
	endPuzzleN = endPuzzleNumber;
	endEdgeN = endEdgeNumber;


	while (locStack.empty() == false) {
		Vector2<int> here = locStack.top();
		locStack.pop();

		int myRow = here.x;
		int myColumn = here.y;

		std::cout << "(" << myRow << ", " << myColumn << ")";
		if (myRow == endPuzzleNumber &&
			myColumn == endEdgeNumber)
		{
			std::cout << "Get Direction is success" << std::endl;
			return;
		}
		else
		{
			myMap->neighborSaver[myRow].myEdge[myColumn].isComeBack = true;

			for (int i = 0; i < 6; i++)
			{
				if (IsValidLocation(myRow, i))
				{
					locStack.push(Vector2<int>(myRow, i));
				}
			}
			if (IsValidLocation(myMap->neighborSaver[myRow].myEdge[myColumn].GetWhoIsNeighbor().x,
				myMap->neighborSaver[myRow].myEdge[myColumn].GetWhoIsNeighbor().y))
			{
				locStack.push(Vector2<int>(myMap->neighborSaver[myRow].myEdge[myColumn].GetWhoIsNeighbor().x,
					myMap->neighborSaver[myRow].myEdge[myColumn].GetWhoIsNeighbor().y));
			}
		}
	}
	std::cout << "Get Direction is failed" << std::endl;

}
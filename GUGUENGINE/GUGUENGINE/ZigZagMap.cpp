#include "ZigZagMap.h"


void ZigZagMap::SetFirstLine(int i, int k)
{
	HexagonEdges currentHexa;
	if (k == 0)
	{
		currentHexa.myEdge[1].SetHasNeigbor(true);
		currentHexa.myEdge[1].WhoIsNeighbor(count + 1, 4);
		currentHexa.myEdge[2].SetHasNeigbor(true);
		currentHexa.myEdge[2].WhoIsNeighbor(count + mapRow, 5);
		neighborSaver.push_back(currentHexa);
	}
	if (k >= 1 && k < mapRow - 1)//not startpuzzle, and not last puzzle
	{
		currentHexa.myEdge[1].SetHasNeigbor(true);
		currentHexa.myEdge[1].WhoIsNeighbor(count + 1, 4);
		currentHexa.myEdge[2].SetHasNeigbor(true);
		currentHexa.myEdge[2].WhoIsNeighbor(count + mapRow, 5);
		currentHexa.myEdge[3].SetHasNeigbor(true);
		currentHexa.myEdge[3].WhoIsNeighbor(count + mapRow - 1, 0);
		currentHexa.myEdge[4].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
	else if (k == mapRow - 1)
	{
		currentHexa.myEdge[3].SetHasNeigbor(true);
		currentHexa.myEdge[3].WhoIsNeighbor(count + mapRow - 1, 0);
		currentHexa.myEdge[4].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
}
void ZigZagMap::SetLastLine(int i, int k, bool isOdd)
{
	HexagonEdges currentHexa;

	if (k == 0)
	{
		currentHexa.myEdge[0].SetHasNeigbor(true);
		currentHexa.myEdge[1].SetHasNeigbor(true);
		currentHexa.myEdge[1].WhoIsNeighbor(count + 1, 4);
		currentHexa.myEdge[5].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);

	}
	else if (isOdd == true && k == mapRow - 2)
	{
		currentHexa.myEdge[0].SetHasNeigbor(true);
		currentHexa.myEdge[4].SetHasNeigbor(true);
		currentHexa.myEdge[5].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
	else if (isOdd == false && k == mapRow - 1)
	{
		currentHexa.myEdge[0].SetHasNeigbor(true);
		currentHexa.myEdge[4].SetHasNeigbor(true);
		currentHexa.myEdge[5].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
	else
	{
		currentHexa.myEdge[0].SetHasNeigbor(true);
		currentHexa.myEdge[1].SetHasNeigbor(true);
		currentHexa.myEdge[1].WhoIsNeighbor(count + 1, 4);
		currentHexa.myEdge[4].SetHasNeigbor(true);
		currentHexa.myEdge[5].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
}
void ZigZagMap::SetAllNeighbor()
{
	for (int puzzleNumber = 0; puzzleNumber < count; puzzleNumber++)
	{
		for (int edgeNumber = 0; edgeNumber < 6; edgeNumber++)
		{
			if (neighborSaver[puzzleNumber].myEdge[edgeNumber].GetWhoIsNeighbor().x != 0 &&
				neighborSaver[puzzleNumber].myEdge[edgeNumber].GetWhoIsNeighbor().x != 0)
			{
				int mRow = 0;
				int mColumn = 0;

				mRow = neighborSaver[puzzleNumber].myEdge[edgeNumber].GetWhoIsNeighbor().x;
				mColumn = neighborSaver[puzzleNumber].myEdge[edgeNumber].GetWhoIsNeighbor().y;
				if (mRow > puzzleNumber)
				{
					neighborSaver[mRow].myEdge[mColumn].WhoIsNeighbor(puzzleNumber, edgeNumber);
				}
			}
		}
	}

}
void ZigZagMap::SetOddLine(int k, int i)
{
	HexagonEdges currentHexa;
	if (k == 0)
	{
		SetFirstLine(k, i);
	}
	else if (k == mapColumn - 1)
	{
		SetLastLine(k, i, true);
	}
	else if (i == 0)
	{
		currentHexa.myEdge[0].SetHasNeigbor(true);
		currentHexa.myEdge[1].SetHasNeigbor(true);
		currentHexa.myEdge[1].WhoIsNeighbor(count + 1, 4);
		currentHexa.myEdge[2].SetHasNeigbor(true);
		currentHexa.myEdge[2].WhoIsNeighbor(count + mapRow, 5);
		currentHexa.myEdge[3].SetHasNeigbor(true);
		currentHexa.myEdge[3].WhoIsNeighbor(count + mapRow - 1, 0);
		currentHexa.myEdge[5].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
	else if (i == mapRow - 2)
	{
		currentHexa.myEdge[0].SetHasNeigbor(true);
		currentHexa.myEdge[2].SetHasNeigbor(true);
		currentHexa.myEdge[2].WhoIsNeighbor(count + mapRow + 1, 5);
		currentHexa.myEdge[3].SetHasNeigbor(true);
		currentHexa.myEdge[3].WhoIsNeighbor(count + mapRow - 1, 0);
		currentHexa.myEdge[4].SetHasNeigbor(true);
		currentHexa.myEdge[5].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
	else
	{
		currentHexa.myEdge[0].SetHasNeigbor(true);
		currentHexa.myEdge[1].SetHasNeigbor(true);
		currentHexa.myEdge[1].WhoIsNeighbor(count + 1, 4);
		currentHexa.myEdge[2].SetHasNeigbor(true);
		currentHexa.myEdge[2].WhoIsNeighbor(count + mapRow, 5);
		currentHexa.myEdge[3].SetHasNeigbor(true);
		currentHexa.myEdge[3].WhoIsNeighbor(count + mapRow - 1, 0);
		currentHexa.myEdge[4].SetHasNeigbor(true);
		currentHexa.myEdge[5].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
}
void ZigZagMap::SetEvenLine(int k, int i)
{
	HexagonEdges currentHexa;
	if (k == 0)
	{
		SetFirstLine(k, i);
	}
	else if (k == mapColumn - 1)
	{
		SetLastLine(k, i, false);
	}
	else if (i == 0)
	{
		currentHexa.myEdge[0].SetHasNeigbor(true);
		currentHexa.myEdge[1].SetHasNeigbor(true);
		currentHexa.myEdge[1].WhoIsNeighbor(count + 1, 4);
		currentHexa.myEdge[2].SetHasNeigbor(true);
		currentHexa.myEdge[2].WhoIsNeighbor(count + mapRow, 5);
		neighborSaver.push_back(currentHexa);
	}
	else if (i == mapRow - 1)
	{
		currentHexa.myEdge[3].SetHasNeigbor(true);
		currentHexa.myEdge[4].SetHasNeigbor(true);
		currentHexa.myEdge[4].WhoIsNeighbor(count + mapRow - 1, 0);
		currentHexa.myEdge[5].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
	else
	{
		currentHexa.myEdge[0].SetHasNeigbor(true);
		currentHexa.myEdge[1].SetHasNeigbor(true);
		currentHexa.myEdge[1].WhoIsNeighbor(count + 1, 4);
		currentHexa.myEdge[2].SetHasNeigbor(true);
		currentHexa.myEdge[2].WhoIsNeighbor(count + mapRow, 5);
		currentHexa.myEdge[3].SetHasNeigbor(true);
		currentHexa.myEdge[3].WhoIsNeighbor(count + mapRow - 1, 0);
		currentHexa.myEdge[4].SetHasNeigbor(true);
		currentHexa.myEdge[5].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
}

void ZigZagMap::DoesEdgeHasNeighbor() {
	neighborSaver.clear();

	HexagonEdges currentHexa;//neighborSaver에 pushback 할거임

	bool isFirst = true;

	//int count = 0;
	for (int k = 0; k < mapColumn; k++) {
		for (int i = 0; i < mapRow; i++) {
			currentHexa.clear();

			if (k % 2 == 1 &&
				i == mapRow - 1)
			{
				break;
			}//if puzzle is "the smaller" line's last puzzle, not use push back
			if (isFirst == true)
			{
				SetEvenLine(k, i);
				count += 1;
			}
			else
			{
				SetOddLine(k, i);
				count += 1;
			}
		}

		if (isFirst == true)//even
		{
			isFirst = false;
		}
		else
		{
			isFirst = true;//odd
		}
	}

}
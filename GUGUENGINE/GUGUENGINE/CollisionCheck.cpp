/*
 *juhye.son
 *3.3.2020
 *juhye.son990902@gmail.com
 *CollisionChek.cpp
 *for make collision check box
 */
#include "Mathematics/Vector2.hpp"
#include "CollisionCheck.h"
#include "Mesh.h"

//bool CollisionCheck::Box2BoxCollision(Mesh*/*boxA*/, Mesh*/* boxB*/)
//{
//	return false;
//}
bool CollisionCheck::Point2BoxCollision(Vector2<float> point, Mesh* box)
{
	Vector2<float> max = GetMax(box);//maxX, maxY
	Vector2<float>  min = GetMin(box);//minX, minY

	if (point.x >= min.x && point.x <= max.x)
	{
		if (point.y >= min.y && point.y <= max.y)
		{
			return true;
		}
	}
	return false;
}
//bool CollisionCheck::Point2PointCollision(Vector2<float> /*pointA*/, Vector2<float> /*pointB*/)
//{
//	return false;
//}
//bool CollisionCheck::Point2HexagonCollision(Vector2<float>/* point*/, Mesh* /*hexagonCenter*/)
//{
//	return false;
//}
//
Vector2<float> CollisionCheck::GetMin(Mesh* mBox) {
	return mBox->GetVertex(0);
	//return Point(top_left.x, bottom_right.y);
} // bottom-left


Vector2<float> CollisionCheck::GetMax(Mesh* mBox) {
	return mBox->GetVertex(2);
} // top-right
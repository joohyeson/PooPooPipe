/*
 *juhye.son
 *9.17.2019
 *juhye.son990902@gmail.com
 *Camera.cpp
 */
#include "Camera.h"

Camera::Camera(Vector2<float> camera_center, Vector2<float> camera_up) noexcept
	{
		center = camera_center;
		up = camera_up;

	}

	void Camera::ResetUp(Vector2<float> camera_up) noexcept
	{
		up = camera_up;
		right = { up.y, -up.x };
	}

	void Camera::MoveUp(float distance) noexcept
	{
		center += {center.normalize(up).x* distance, center.normalize(up).y* distance};
	}

	void Camera::MoveRight(float distance) noexcept
	{
		center +={ center.normalize(right).x * distance, center.normalize(right).y* distance};
	}

	void Camera::Rotate(float angle_radians) noexcept
	{
		up = up.rotate_by(angle_radians, { up.x, up.y });
		right = right.rotate_by(angle_radians, { right.x, right.y });
	}

	Matrix3<float> Camera::CameraToWorld() const noexcept
	{
		Matrix3<float> cameraToWorldMatrix;
		cameraToWorldMatrix.Column[0]= { right.x, right.y, 0 };
		cameraToWorldMatrix.Column[1] = { up.x, up.y, 0 };
		cameraToWorldMatrix.Column[2] = { center.x, center.y, 1 };
		return cameraToWorldMatrix;
	}

	Matrix3<float> Camera::WorldToCamera() const noexcept
	{
		Matrix3<float> worldToCameraMatrix;
		Vector2<float> m;
		worldToCameraMatrix.Column[0] = { right.x, up.x, 0 };
		worldToCameraMatrix.Column[1] = { right.y, up.y, 0 };
		worldToCameraMatrix.Column[2] = { -m.dot(right, center), -m.dot(up, center), 1 };
		return worldToCameraMatrix;
	}

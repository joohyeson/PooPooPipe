/*
 * juhye.son
 * 9.17.2019
 * juhye.son990902@gmail.com
 * CameraView.cpp
 * for zoom in zoom out
 */
#include "CameraView.h"

// For RightHanded_OriginCenter
// You want to map (-w/2, w/2) to (-1,1) and (-h/2,h/2) to (-1,1)
//           (w/2,h/2)                (1,1)
//      +--------+             +--------+
//      |        |             |        |
//      | cam    |     --->    | ndc    |
//      +--------+             +--------+
// (-w/2,-h/2)              (-1,-1)
//

// For RightHanded_OriginBottomLeft
// You want to map (0, w) to (-1,1) and (0,h) to (-1,1)
//             (w,h)                  (1,1)
//      +--------+             +--------+
//      |        |             |        |
//      | cam    |     --->    | ndc    |
//      +--------+             +--------+
//    (0,0)                 (-1,-1)
//

// For LeftHanded_OriginTopLeft
// You want to map (0, w) to (-1,1) and (0,h) to (1,-1)
//    (0,0)                 (-1,1)
//      +--------+             +--------+
//      |        |             |        |
//      | cam    |     --->    | ndc    |
//      +--------+             +--------+
//             (w,h)                  (1,-1)
//


	void CameraView::SetViewSize(Vector2<float> pixel_size) noexcept
	{
		switch (GetFrameOfReference())
		{
		case RightHanded_OriginCenter:
			cameraToNDC.Column[0] = { 2 / pixel_size.width, 0, 0 };
			cameraToNDC.Column[1] = { 0, 2 / pixel_size.height, 0 };
			cameraToNDC.Column[2] = { 0, 0, 1 };
			break;

		case RightHanded_OriginBottomLeft:
			cameraToNDC.Column[0] = { 2 / pixel_size.width, 0, 0 };
			cameraToNDC.Column[1] = { 0, 2 / pixel_size.height, 0 };
			cameraToNDC.Column[2] = { -1, -1, 1 };
			break;

		case LeftHanded_OriginTopLeft:
			cameraToNDC.Column[0] = { 2 / pixel_size.width, 0, 0 };
			cameraToNDC.Column[1] = { 0, -2 / pixel_size.height, 0 };
			cameraToNDC.Column[2] = { -1, 1, 1 };
			break;

		default:
			break;

		}

		displaySize = pixel_size;
	}

	void CameraView::SetZoom(float new_zoom) noexcept
	{

		switch (GetFrameOfReference())
		{
		case RightHanded_OriginCenter:
			cameraToNDC.Column[0] = { (2 / displaySize.width) * zoom, 0, 0 };
			cameraToNDC.Column[1] = { 0, (2 / displaySize.height) * zoom, 0 };
			cameraToNDC.Column[2] = { 0, 0, 1 };
			break;

		case RightHanded_OriginBottomLeft:
			cameraToNDC.Column[0] = { (2 / displaySize.width) * zoom, 0, 0 };
			cameraToNDC.Column[1] = { 0, (2 / displaySize.height) * zoom, 0 };
			cameraToNDC.Column[2] = { -1, -1, 1 };
			break;

		case LeftHanded_OriginTopLeft:
			cameraToNDC.Column[0] = { (2 / displaySize.width) * zoom, 0, 0 };
			cameraToNDC.Column[1] = { 0, (-2 / displaySize.height) * zoom, 0 };
			cameraToNDC.Column[2] = { -1, 1, 1 };
			break;
		default:
			break;
		}

		zoom = new_zoom;
	}

	void CameraView::SetViewSize(int new_pixel_width, int new_pixel_height) noexcept
	{
		displaySize.width = static_cast<float>(new_pixel_width);
		displaySize.height = static_cast<float>(new_pixel_height);

		switch (GetFrameOfReference())
		{
		case RightHanded_OriginCenter:
			cameraToNDC.Column[0] = { 2 / displaySize.width, 0, 0 };
			cameraToNDC.Column[1] = { 0, 2 / displaySize.height, 0 };
			cameraToNDC.Column[2] = { 0, 0, 1 };
			break;

		case RightHanded_OriginBottomLeft:
			cameraToNDC.Column[0] = { 2 / displaySize.width, 0, 0 };
			cameraToNDC.Column[1] = { 0, 2 / displaySize.height, 0 };
			cameraToNDC.Column[2] = { -1, -1, 1 };
			break;

		case LeftHanded_OriginTopLeft:
			cameraToNDC.Column[0] = { 2 / displaySize.width, 0, 0 };
			cameraToNDC.Column[1] = { 0, -2 / displaySize.height, 0 };
			cameraToNDC.Column[2] = { -1, 1, 1 };
			break;
		default:
			break;
		}

	}

	void CameraView::SetFrameOfReference(FrameOfReference frame_of_reference) noexcept
	{
		frameOfReference = frame_of_reference;

		switch (GetFrameOfReference())
		{

		case RightHanded_OriginCenter:
			cameraToNDC.Column[0] = { 2 / displaySize.width, 0, 0 };
			cameraToNDC.Column[1] = { 0, 2 / displaySize.height, 0 };
			cameraToNDC.Column[2] = { 0, 0, 1 };
			break;

		case RightHanded_OriginBottomLeft:
			cameraToNDC.Column[0] = { 2 / displaySize.width, 0, 0 };
			cameraToNDC.Column[1] = { 0, 2 / displaySize.height, 0 };
			cameraToNDC.Column[2] = { -1, -1, 1 };
			break;

		case LeftHanded_OriginTopLeft:
			cameraToNDC.Column[0] = { 2 / displaySize.width, 0, 0 };
			cameraToNDC.Column[1] = { 0, -2 / displaySize.height, 0 };
			cameraToNDC.Column[2] = { -1, 1, 1 };
			break;
		default:
			break;

		}

	}
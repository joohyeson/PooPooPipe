#pragma once
/*
 *juhye.son
 *9.17.2019
 *juhye.son990902@gmail.com
 *CameraView.h
 *this is cameraView header
 */
#include "Mathematics/Vector2.hpp"
#include "Mathematics/Matrix3.hpp"

	class [[nodiscard]] CameraView
	{
	public:
		void            SetViewSize(Vector2<float> pixel_size) noexcept;
		void            SetViewSize(int new_pixel_width, int new_pixel_height) noexcept;
		void            SetZoom(float new_zoom) noexcept;
		constexpr float GetZoom() const noexcept { return zoom; }
		Matrix3<float>         GetCameraToNDCTransform() const noexcept { return cameraToNDC; }

		enum class FrameOfReference
		{
			RightHanded_OriginCenter,
			RightHanded_OriginBottomLeft,
			LeftHanded_OriginTopLeft,
			NormalizedDeviceCoordinates
		};
		void                       SetFrameOfReference(FrameOfReference frame_of_reference) noexcept;
		constexpr FrameOfReference GetFrameOfReference() const noexcept { return frameOfReference; }

	private:
		Vector2<float>          displaySize{};
		Matrix3<float>          cameraToNDC =Matrix3<float>::Identiy();
		float            zoom{1.0f};
		FrameOfReference frameOfReference = FrameOfReference::RightHanded_OriginCenter;
	};


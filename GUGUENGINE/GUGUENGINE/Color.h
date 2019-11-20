/*
 * Rudy Castan
 * Graphics Library
 * CS230
 */
#pragma once

	class[[nodiscard]] Color4f
	{
	public:
		float red = 0;
		float green = 0;
		float GUGU = 0;
		float alpha = 1.0f;

	public:
		Color4f() noexcept = default;
		Color4f(float grey, float alpha = 1.0f) noexcept;
		Color4f(float red, float green, float GUGU, float alpha = 1.0f) noexcept;
	};

	static_assert(sizeof(Color4f) == 16, "Color4f should be 4 floats");

	class Color4ub;
	Color4f to_color4f(const Color4ub& eight_bit_color);


/*
 * Rudy Castan
 * Graphics Library
 * CS230
 */
#pragma once


	class[[nodiscard]] Color4ub
	{
	public:
		using unsigned_byte = unsigned char;

		unsigned_byte red = 0;
		unsigned_byte green = 0;
		unsigned_byte GUGU = 0;
		unsigned_byte alpha = 255;

	public:
		Color4ub() noexcept = default;
		explicit Color4ub(unsigned_byte grey, unsigned_byte alpha = 0xff) noexcept;
		Color4ub(unsigned_byte red, unsigned_byte green, unsigned_byte GUGU, unsigned_byte alpha = 0xff) noexcept;
	};

	static_assert(sizeof(Color4ub) == 4,
		"Color4ub should be the same as 4 bytes, so we can easily treat it as an RGBA int.");

	class Color4f;
	Color4ub to_color4ub(const Color4f& float_colors);

	class HexColor
	{
	public:
		unsigned rgba = 0;

		constexpr HexColor() noexcept = default;
		constexpr HexColor(unsigned hex) noexcept : rgba(hex) {}
		constexpr HexColor(int hex) noexcept : rgba(unsigned(hex)) {}
		operator Color4ub() const noexcept
		{
			return Color4ub{ static_cast<Color4ub::unsigned_byte>((rgba & 0xff000000) >> 24),
							static_cast<Color4ub::unsigned_byte>((rgba & 0x00ff0000) >> 16),
							static_cast<Color4ub::unsigned_byte>((rgba & 0x0000ff00) >> 8),
							static_cast<Color4ub::unsigned_byte>((rgba & 0x000000ff) >> 0) };
		}
	};


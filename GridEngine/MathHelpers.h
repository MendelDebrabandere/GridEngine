#pragma once
#include <cmath>

namespace grid
{
	/* --- HELPER STRUCTS --- */
	struct Int2
	{
		int x{};
		int y{};
	};

	/* --- CONSTANTS --- */
	constexpr double PI = 3.14159265358979323846;
	constexpr double PI_DIV_2 = 1.57079632679489661923;
	constexpr double PI_DIV_4 = 0.785398163397448309616;
	constexpr double PI_2 = 6.283185307179586476925;
	constexpr double PI_4 = 12.56637061435917295385;

	constexpr double TO_DEGREES = (180.0 / PI);
	constexpr double TO_RADIANS(PI / 180.0);

	/* --- HELPER FUNCTIONS --- */
	inline float Square(float a)
	{
		return a * a;
	}

	inline float Lerpf(float a, float b, float factor)
	{
		return ((1 - factor) * a) + (factor * b);
	}

	inline bool AreEqual(float a, float b, float epsilon = FLT_EPSILON)
	{
		return abs(a - b) < epsilon;
	}

	inline int Clamp(const int v, int min, int max)
	{
		if (v < min) return min;
		if (v > max) return max;
		return v;
	}

	inline float Clamp(const float v, float min, float max)
	{
		if (v < min) return min;
		if (v > max) return max;
		return v;
	}

	inline float Saturate(const float v)
	{
		if (v < 0.f) return 0.f;
		if (v > 1.f) return 1.f;
		return v;
	}
}
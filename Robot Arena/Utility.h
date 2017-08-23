#pragma once
#include <algorithm>


namespace Math
{
	const float PI = 3.14159265359;

	inline float radianToPi(float radian)
	{
		return (radian * 180) / PI;
	}

	inline float clamp(int value, int min, int max)
	{
		return std::min(std::max(value, min), max);
	}
}

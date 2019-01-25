#include <math.h>

float	radians(float degrees)
{
	return (degrees * M_PI / 180.0);
}

float	minf(float a, float b)
{
	return (a < b ? a : b);
}

float	maxf(float a, float b)
{
	return (a > b ? a : b);
}

float	percentage_f(float min, float max, float f)
{
	if (min == max)
		return (0);
	return ((f - min) / (max - min));
}
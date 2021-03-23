#include "../include/libpgm.h"

#include <stdlib.h>

float
get_2Darray_value(const float* data, int cols, int x, int y)
{
	return data[x * cols + y];
}

void
normalize_array(float* data, int len, float new_max)
{
	int i;
	float temp;
	float min = 9999999;
	float max = -999999;

	// find max and min value
	for (i = 0; i < len; ++i)
	{
		temp = data[i];
		if (temp < min)
		{
			min = temp;
		}
		if (temp > max)
		{
			max = temp;
		}
	}

	if ((max - min) < .000000001)
	{
		min = 0.0;
		max = 1.0;
	}

	for (i = 0; i < len; ++i)
	{
		data[i] = (data[i] - min) / (max - min) * new_max;
	}
}

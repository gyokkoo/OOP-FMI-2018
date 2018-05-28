#include <iostream>
#include <cstring>
#include "Color.h"

const char* colors[] = { "White", "Silver", "Black", "Grey", "Blue", "Red", "Brown", "Green", "Yellow" };

Color getColor(char choice[MAX_COLOR_SIZE])
{
	for (int i = 0; i < COLOR_COUNT; i++)
	{
		if (strcmp(choice, colors[i]) == 0)
		{
			return (Color)i;
		}
	}

	return INVALID_COLOR;
}

const char* getColorString(Color color)
{
	for (int i = 0; i < COLOR_COUNT; i++)
	{
		if (i == color)
		{
			return colors[i];
		}
	}

	return "Invalid_Color";
}

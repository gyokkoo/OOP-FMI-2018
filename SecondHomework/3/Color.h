#pragma once

const int MAX_COLOR_SIZE = 16;

enum Color
{
	INVALID_COLOR = -1,

	WHITE,
	SILVER,
	BLACK,
	GREY,
	BLUE,
	RED,
	BROWN,
	GREEN,
	YELLOW,

	COLOR_COUNT
};

Color getColor(char choice[MAX_COLOR_SIZE]);

const char* getColorString(Color color);
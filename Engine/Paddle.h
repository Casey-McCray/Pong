#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Paddle {
	int x;
	int y;
public:
	constexpr static int width = 10;
	constexpr static int height = 60;
	void Draw(Graphics &gfx);
	void Update(char, char, Keyboard &kbd, Graphics &gfx);
	Paddle(int, Graphics &gfx);
	int getX() { return x; }
	int getY() { return y; }
};


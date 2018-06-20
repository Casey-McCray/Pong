#pragma once

#include "Graphics.h"
#include "Paddle.h"
#include "Keyboard.h"
#include "Meter.h"

class Ball {
	int vx;
	int vy;
	int x;
	int y;
	int tempX;
	int tempY;
	int scoreL = 0;
	int scoreR = 0;
	bool pause = false;
	Meter meter;
public:
	void P1_Deflect(Paddle &paddle);
	void P2_Deflect(Paddle &paddle);
	void Draw(Graphics &gfx);
	void Update(Graphics &gfx, Keyboard &kbd);
	Ball(int, int);
};


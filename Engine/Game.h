
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Paddle.h"
#include "Ball.h"
#include "Meter.h"
#include <random>

class Game {
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	std::random_device rd;
	std::mt19937 rn;
	std::uniform_int_distribution<int> VelX;
	std::uniform_int_distribution<int> VelY;
	Paddle P1;
	Paddle P2;
	Ball ball;
//	Meter meter;
	/********************************/
	/*  User Variables              */
	/********************************/
};
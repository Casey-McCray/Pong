#include "Paddle.h"
#include "Graphics.h"
#include "Keyboard.h"

void Paddle::Draw(Graphics &gfx) {
	for(int i = 0; i < width; i++) {
		for(int j = 0; j < height; j++) {
			gfx.PutPixel(x + i, y + j, 255, 255, 255);
		}
	}
}

void Paddle::Update(char Up, char Down, Keyboard &kbd, Graphics &gfx) {
	if(y > 0) {
		if(kbd.KeyIsPressed(Up)) {
			y -= 6;
			if(y <= 0)
				y = 0;
		}
	}
	else {
		y = 0;
	}
	if(y + Paddle::height < gfx.ScreenHeight) {
		if(kbd.KeyIsPressed(Down)) {
			y += 6;
			if(y + Paddle::height >= gfx.ScreenHeight)
				y = gfx.ScreenHeight - Paddle::height - 1;
		}
	}
	else {
		y = gfx.ScreenHeight - Paddle::height - 1;
	}

	
}

Paddle::Paddle(int startX, Graphics &gfx) {
	x = startX;
	y = gfx.ScreenHeight / 2;
}


			
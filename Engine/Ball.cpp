

#include "Ball.h"
#include "Paddle.h"
#include "Keyboard.h"
#include "Meter.h"
#include <random>	

Ball::Ball(int VelX, int VelY) {
	x = 400;
	y = 400;
	vx = VelX + 6;
	vy = VelY + 6;
	tempX = vx;
	tempY = vy;
}

void Ball::Update(Graphics &gfx, Keyboard &kbd) {
	x += vx;
	if(x < 0) {
		x = 0;
	}
	if(x + 20 >= gfx.ScreenWidth) {
		x = gfx.ScreenWidth - 20;
	}
	y += vy;
	if(y < 0) {
		y = 0;
	}
	if(y + 20 > gfx.ScreenHeight) {
		y = gfx.ScreenHeight - 20;
	}
	if(y <= 0) {
		vy = -vy;
	}
	if(y + 20 >= gfx.ScreenHeight - 1) {
		vy = -vy;
	}
	if(x <= 0) {
		if(!pause) {
			scoreL += 20;
		}
		pause = true;
		vx = 0;
		vy = 0;
		tempX = -tempX;
		tempY = -tempY;
	}
	if(x + 20 >= gfx.ScreenWidth - 1) {
		if(!pause) {
			scoreR += 20;
		}
		pause = true;
		vx = 0;
		vy = 0;
		tempX = -tempX;
		tempY = -tempY;
	}
	if(kbd.KeyIsPressed(VK_RETURN)) {
		vx = tempX;
		vy = tempY;
		pause = false;
	}
	meter.Draw(gfx, scoreL, scoreR);
}

void Ball::P1_Deflect(Paddle &paddle) {
	if(x < paddle.getX() + Paddle::width) {
		if(y > paddle.getY() && y < paddle.getY() + Paddle::height) {
			vx = -vx;
			tempX = -tempX;
		}
	}
}

void Ball::P2_Deflect(Paddle &paddle) {
	if(x + 20 > paddle.getX()) {
		if(y > paddle.getY() && y < paddle.getY() + Paddle::height) {
			vx = -vx;
			tempX = -tempX;
		}
	}
}

void Ball::Draw(Graphics & gfx) {
	gfx.PutPixel(7 + x, 2 + y, 87, 35, 50);
	gfx.PutPixel(8 + x, 2 + y, 87, 35, 50);
	gfx.PutPixel(9 + x, 2 + y, 87, 35, 50);
	gfx.PutPixel(10 + x, 2 + y, 87, 35, 50);
	gfx.PutPixel(11 + x, 2 + y, 87, 35, 50);
	gfx.PutPixel(12 + x, 2 + y, 87, 35, 50);
	gfx.PutPixel(5 + x, 3 + y, 87, 35, 50);
	gfx.PutPixel(6 + x, 3 + y, 87, 35, 50);
	gfx.PutPixel(7 + x, 3 + y, 191, 95, 122);
	gfx.PutPixel(8 + x, 3 + y, 191, 93, 121);
	gfx.PutPixel(9 + x, 3 + y, 189, 89, 117);
	gfx.PutPixel(10 + x, 3 + y, 187, 83, 112);
	gfx.PutPixel(11 + x, 3 + y, 185, 77, 108);
	gfx.PutPixel(12 + x, 3 + y, 185, 79, 109);
	gfx.PutPixel(13 + x, 3 + y, 87, 35, 50);
	gfx.PutPixel(14 + x, 3 + y, 87, 35, 50);
	gfx.PutPixel(4 + x, 4 + y, 87, 35, 50);
	gfx.PutPixel(5 + x, 4 + y, 197, 109, 134);
	gfx.PutPixel(6 + x, 4 + y, 194, 102, 128);
	gfx.PutPixel(7 + x, 4 + y, 190, 90, 118);
	gfx.PutPixel(8 + x, 4 + y, 187, 83, 112);
	gfx.PutPixel(9 + x, 4 + y, 185, 77, 108);
	gfx.PutPixel(10 + x, 4 + y, 184, 76, 107);
	gfx.PutPixel(11 + x, 4 + y, 183, 73, 104);
	gfx.PutPixel(12 + x, 4 + y, 183, 75, 106);
	gfx.PutPixel(13 + x, 4 + y, 184, 76, 107);
	gfx.PutPixel(14 + x, 4 + y, 183, 75, 106);
	gfx.PutPixel(15 + x, 4 + y, 87, 35, 50);
	gfx.PutPixel(3 + x, 5 + y, 87, 35, 50);
	gfx.PutPixel(4 + x, 5 + y, 204, 126, 148);
	gfx.PutPixel(5 + x, 5 + y, 202, 122, 145);
	gfx.PutPixel(6 + x, 5 + y, 199, 115, 139);
	gfx.PutPixel(7 + x, 5 + y, 196, 106, 132);
	gfx.PutPixel(8 + x, 5 + y, 193, 97, 124);
	gfx.PutPixel(9 + x, 5 + y, 189, 89, 117);
	gfx.PutPixel(10 + x, 5 + y, 190, 90, 118);
	gfx.PutPixel(11 + x, 5 + y, 190, 90, 118);
	gfx.PutPixel(12 + x, 5 + y, 189, 87, 116);
	gfx.PutPixel(13 + x, 5 + y, 187, 83, 112);
	gfx.PutPixel(14 + x, 5 + y, 186, 80, 110);
	gfx.PutPixel(15 + x, 5 + y, 185, 77, 108);
	gfx.PutPixel(16 + x, 5 + y, 87, 35, 50);
	gfx.PutPixel(2 + x, 6 + y, 87, 35, 50);
	gfx.PutPixel(3 + x, 6 + y, 208, 136, 156);
	gfx.PutPixel(4 + x, 6 + y, 207, 133, 154);
	gfx.PutPixel(5 + x, 6 + y, 87, 35, 50);
	gfx.PutPixel(6 + x, 6 + y, 87, 35, 50);
	gfx.PutPixel(7 + x, 6 + y, 87, 35, 50);
	gfx.PutPixel(8 + x, 6 + y, 199, 113, 137);
	gfx.PutPixel(9 + x, 6 + y, 195, 103, 129);
	gfx.PutPixel(10 + x, 6 + y, 194, 100, 127);
	gfx.PutPixel(11 + x, 6 + y, 193, 99, 126);
	gfx.PutPixel(12 + x, 6 + y, 87, 35, 50);
	gfx.PutPixel(13 + x, 6 + y, 87, 35, 50);
	gfx.PutPixel(14 + x, 6 + y, 87, 35, 50);
	gfx.PutPixel(15 + x, 6 + y, 186, 80, 110);
	gfx.PutPixel(16 + x, 6 + y, 184, 76, 107);
	gfx.PutPixel(17 + x, 6 + y, 87, 35, 50);
	gfx.PutPixel(2 + x, 7 + y, 87, 35, 50);
	gfx.PutPixel(3 + x, 7 + y, 209, 137, 157);
	gfx.PutPixel(4 + x, 7 + y, 87, 35, 50);
	gfx.PutPixel(5 + x, 7 + y, 252, 244, 242);
	gfx.PutPixel(6 + x, 7 + y, 252, 244, 242);
	gfx.PutPixel(7 + x, 7 + y, 252, 244, 242);
	gfx.PutPixel(8 + x, 7 + y, 87, 35, 50);
	gfx.PutPixel(9 + x, 7 + y, 199, 113, 137);
	gfx.PutPixel(10 + x, 7 + y, 194, 102, 128);
	gfx.PutPixel(11 + x, 7 + y, 87, 35, 50);
	gfx.PutPixel(12 + x, 7 + y, 252, 244, 242);
	gfx.PutPixel(13 + x, 7 + y, 252, 244, 242);
	gfx.PutPixel(14 + x, 7 + y, 252, 244, 242);
	gfx.PutPixel(15 + x, 7 + y, 87, 35, 50);
	gfx.PutPixel(16 + x, 7 + y, 186, 80, 110);
	gfx.PutPixel(17 + x, 7 + y, 87, 35, 50);
	gfx.PutPixel(1 + x, 8 + y, 87, 35, 50);
	gfx.PutPixel(2 + x, 8 + y, 213, 147, 166);
	gfx.PutPixel(3 + x, 8 + y, 209, 139, 159);
	gfx.PutPixel(4 + x, 8 + y, 87, 35, 50);
	gfx.PutPixel(5 + x, 8 + y, 252, 244, 242);
	gfx.PutPixel(7 + x, 8 + y, 252, 244, 242);
	gfx.PutPixel(8 + x, 8 + y, 87, 35, 50);
	gfx.PutPixel(9 + x, 8 + y, 198, 112, 136);
	gfx.PutPixel(10 + x, 8 + y, 194, 102, 128);
	gfx.PutPixel(11 + x, 8 + y, 87, 35, 50);
	gfx.PutPixel(12 + x, 8 + y, 252, 244, 242);
	gfx.PutPixel(14 + x, 8 + y, 252, 244, 242);
	gfx.PutPixel(15 + x, 8 + y, 87, 35, 50);
	gfx.PutPixel(16 + x, 8 + y, 184, 76, 107);
	gfx.PutPixel(17 + x, 8 + y, 183, 75, 106);
	gfx.PutPixel(18 + x, 8 + y, 87, 35, 50);
	gfx.PutPixel(1 + x, 9 + y, 87, 35, 50);
	gfx.PutPixel(2 + x, 9 + y, 213, 149, 167);
	gfx.PutPixel(3 + x, 9 + y, 212, 146, 165);
	gfx.PutPixel(4 + x, 9 + y, 87, 35, 50);
	gfx.PutPixel(8 + x, 9 + y, 87, 35, 50);
	gfx.PutPixel(9 + x, 9 + y, 203, 125, 147);
	gfx.PutPixel(10 + x, 9 + y, 203, 125, 147);
	gfx.PutPixel(11 + x, 9 + y, 87, 35, 50);
	gfx.PutPixel(15 + x, 9 + y, 87, 35, 50);
	gfx.PutPixel(16 + x, 9 + y, 187, 85, 114);
	gfx.PutPixel(17 + x, 9 + y, 186, 80, 110);
	gfx.PutPixel(18 + x, 9 + y, 87, 35, 50);
	gfx.PutPixel(1 + x, 10 + y, 87, 35, 50);
	gfx.PutPixel(2 + x, 10 + y, 213, 149, 167);
	gfx.PutPixel(3 + x, 10 + y, 213, 149, 167);
	gfx.PutPixel(4 + x, 10 + y, 210, 142, 161);
	gfx.PutPixel(5 + x, 10 + y, 87, 35, 50);
	gfx.PutPixel(6 + x, 10 + y, 87, 35, 50);
	gfx.PutPixel(7 + x, 10 + y, 87, 35, 50);
	gfx.PutPixel(8 + x, 10 + y, 207, 133, 154);
	gfx.PutPixel(9 + x, 10 + y, 206, 130, 152);
	gfx.PutPixel(10 + x, 10 + y, 205, 129, 151);
	gfx.PutPixel(11 + x, 10 + y, 199, 113, 137);
	gfx.PutPixel(12 + x, 10 + y, 87, 35, 50);
	gfx.PutPixel(13 + x, 10 + y, 87, 35, 50);
	gfx.PutPixel(14 + x, 10 + y, 87, 35, 50);
	gfx.PutPixel(15 + x, 10 + y, 193, 97, 124);
	gfx.PutPixel(16 + x, 10 + y, 190, 92, 120);
	gfx.PutPixel(17 + x, 10 + y, 188, 86, 115);
	gfx.PutPixel(18 + x, 10 + y, 87, 35, 50);
	gfx.PutPixel(1 + x, 11 + y, 87, 35, 50);
	gfx.PutPixel(2 + x, 11 + y, 214, 152, 170);
	gfx.PutPixel(3 + x, 11 + y, 214, 152, 170);
	gfx.PutPixel(4 + x, 11 + y, 213, 149, 167);
	gfx.PutPixel(5 + x, 11 + y, 211, 145, 164);
	gfx.PutPixel(6 + x, 11 + y, 209, 137, 157);
	gfx.PutPixel(7 + x, 11 + y, 207, 135, 155);
	gfx.PutPixel(8 + x, 11 + y, 208, 136, 156);
	gfx.PutPixel(9 + x, 11 + y, 206, 130, 152);
	gfx.PutPixel(10 + x, 11 + y, 206, 130, 152);
	gfx.PutPixel(11 + x, 11 + y, 203, 125, 147);
	gfx.PutPixel(12 + x, 11 + y, 204, 126, 148);
	gfx.PutPixel(13 + x, 11 + y, 203, 123, 146);
	gfx.PutPixel(14 + x, 11 + y, 197, 107, 133);
	gfx.PutPixel(15 + x, 11 + y, 194, 100, 127);
	gfx.PutPixel(16 + x, 11 + y, 190, 92, 120);
	gfx.PutPixel(17 + x, 11 + y, 190, 92, 120);
	gfx.PutPixel(18 + x, 11 + y, 87, 35, 50);
	gfx.PutPixel(1 + x, 12 + y, 87, 35, 50);
	gfx.PutPixel(2 + x, 12 + y, 216, 156, 173);
	gfx.PutPixel(3 + x, 12 + y, 215, 153, 171);
	gfx.PutPixel(4 + x, 12 + y, 215, 153, 171);
	gfx.PutPixel(5 + x, 12 + y, 214, 150, 168);
	gfx.PutPixel(6 + x, 12 + y, 211, 145, 164);
	gfx.PutPixel(7 + x, 12 + y, 209, 137, 157);
	gfx.PutPixel(8 + x, 12 + y, 209, 139, 159);
	gfx.PutPixel(9 + x, 12 + y, 209, 139, 159);
	gfx.PutPixel(10 + x, 12 + y, 207, 133, 154);
	gfx.PutPixel(11 + x, 12 + y, 206, 132, 153);
	gfx.PutPixel(12 + x, 12 + y, 205, 129, 151);
	gfx.PutPixel(13 + x, 12 + y, 203, 123, 146);
	gfx.PutPixel(14 + x, 12 + y, 199, 115, 139);
	gfx.PutPixel(15 + x, 12 + y, 198, 110, 135);
	gfx.PutPixel(16 + x, 12 + y, 197, 107, 133);
	gfx.PutPixel(17 + x, 12 + y, 191, 95, 122);
	gfx.PutPixel(18 + x, 12 + y, 87, 35, 50);
	gfx.PutPixel(2 + x, 13 + y, 87, 35, 50);
	gfx.PutPixel(3 + x, 13 + y, 215, 153, 171);
	gfx.PutPixel(4 + x, 13 + y, 214, 152, 170);
	gfx.PutPixel(5 + x, 13 + y, 213, 149, 167);
	gfx.PutPixel(6 + x, 13 + y, 211, 145, 164);
	gfx.PutPixel(7 + x, 13 + y, 211, 143, 162);
	gfx.PutPixel(8 + x, 13 + y, 211, 143, 162);
	gfx.PutPixel(9 + x, 13 + y, 209, 137, 157);
	gfx.PutPixel(10 + x, 13 + y, 207, 133, 154);
	gfx.PutPixel(11 + x, 13 + y, 206, 132, 153);
	gfx.PutPixel(12 + x, 13 + y, 206, 130, 152);
	gfx.PutPixel(13 + x, 13 + y, 203, 125, 147);
	gfx.PutPixel(14 + x, 13 + y, 197, 109, 134);
	gfx.PutPixel(15 + x, 13 + y, 196, 106, 132);
	gfx.PutPixel(16 + x, 13 + y, 194, 102, 128);
	gfx.PutPixel(17 + x, 13 + y, 87, 35, 50);
	gfx.PutPixel(2 + x, 14 + y, 87, 35, 50);
	gfx.PutPixel(3 + x, 14 + y, 214, 152, 170);
	gfx.PutPixel(4 + x, 14 + y, 213, 149, 167);
	gfx.PutPixel(5 + x, 14 + y, 212, 146, 165);
	gfx.PutPixel(6 + x, 14 + y, 212, 146, 165);
	gfx.PutPixel(7 + x, 14 + y, 209, 139, 159);
	gfx.PutPixel(8 + x, 14 + y, 209, 137, 157);
	gfx.PutPixel(9 + x, 14 + y, 207, 133, 154);
	gfx.PutPixel(10 + x, 14 + y, 205, 129, 151);
	gfx.PutPixel(11 + x, 14 + y, 203, 125, 147);
	gfx.PutPixel(12 + x, 14 + y, 199, 113, 137);
	gfx.PutPixel(13 + x, 14 + y, 194, 100, 127);
	gfx.PutPixel(14 + x, 14 + y, 193, 97, 124);
	gfx.PutPixel(15 + x, 14 + y, 189, 87, 116);
	gfx.PutPixel(16 + x, 14 + y, 188, 86, 115);
	gfx.PutPixel(17 + x, 14 + y, 87, 35, 50);
	gfx.PutPixel(3 + x, 15 + y, 87, 35, 50);
	gfx.PutPixel(4 + x, 15 + y, 213, 147, 166);
	gfx.PutPixel(5 + x, 15 + y, 212, 146, 165);
	gfx.PutPixel(6 + x, 15 + y, 211, 145, 164);
	gfx.PutPixel(7 + x, 15 + y, 209, 139, 159);
	gfx.PutPixel(8 + x, 15 + y, 87, 35, 50);
	gfx.PutPixel(9 + x, 15 + y, 87, 35, 50);
	gfx.PutPixel(10 + x, 15 + y, 87, 35, 50);
	gfx.PutPixel(11 + x, 15 + y, 87, 35, 50);
	gfx.PutPixel(12 + x, 15 + y, 199, 113, 137);
	gfx.PutPixel(13 + x, 15 + y, 197, 109, 134);
	gfx.PutPixel(14 + x, 15 + y, 197, 107, 133);
	gfx.PutPixel(15 + x, 15 + y, 194, 102, 128);
	gfx.PutPixel(16 + x, 15 + y, 87, 35, 50);
	gfx.PutPixel(4 + x, 16 + y, 87, 35, 50);
	gfx.PutPixel(5 + x, 16 + y, 213, 147, 166);
	gfx.PutPixel(6 + x, 16 + y, 213, 147, 166);
	gfx.PutPixel(7 + x, 16 + y, 211, 145, 164);
	gfx.PutPixel(8 + x, 16 + y, 211, 145, 164);
	gfx.PutPixel(9 + x, 16 + y, 210, 140, 160);
	gfx.PutPixel(10 + x, 16 + y, 210, 140, 160);
	gfx.PutPixel(11 + x, 16 + y, 209, 137, 157);
	gfx.PutPixel(12 + x, 16 + y, 207, 133, 154);
	gfx.PutPixel(13 + x, 16 + y, 206, 130, 152);
	gfx.PutPixel(14 + x, 16 + y, 205, 129, 151);
	gfx.PutPixel(15 + x, 16 + y, 87, 35, 50);
	gfx.PutPixel(5 + x, 17 + y, 87, 35, 50);
	gfx.PutPixel(6 + x, 17 + y, 87, 35, 50);
	gfx.PutPixel(7 + x, 17 + y, 211, 145, 164);
	gfx.PutPixel(8 + x, 17 + y, 211, 145, 164);
	gfx.PutPixel(9 + x, 17 + y, 210, 142, 161);
	gfx.PutPixel(10 + x, 17 + y, 210, 140, 160);
	gfx.PutPixel(11 + x, 17 + y, 209, 137, 157);
	gfx.PutPixel(12 + x, 17 + y, 209, 139, 159);
	gfx.PutPixel(13 + x, 17 + y, 87, 35, 50);
	gfx.PutPixel(14 + x, 17 + y, 87, 35, 50);
	gfx.PutPixel(7 + x, 18 + y, 87, 35, 50);
	gfx.PutPixel(8 + x, 18 + y, 87, 35, 50);
	gfx.PutPixel(9 + x, 18 + y, 87, 35, 50);
	gfx.PutPixel(10 + x, 18 + y, 87, 35, 50);
	gfx.PutPixel(11 + x, 18 + y, 87, 35, 50);
	gfx.PutPixel(12 + x, 18 + y, 87, 35, 50);

}







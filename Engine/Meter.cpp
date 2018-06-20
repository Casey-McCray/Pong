#include "Meter.h"

Meter::Meter() {

}

void Meter::Draw(Graphics &gfx, int scoreL, int scoreR) {
	int x1 = 10;
	int y1 = 10;
	for(int i = 0; i < scoreL; i++) {
		for(int j = 0; j < 10; j++)
			gfx.PutPixel(i + x1, j + y1, 0, 0, 255);
	}

	int x2 = 413;
	int y2 = 10;
	for(int k = 0; k < scoreR; k++) {
		for(int l = 0; l < 10; l++)
			gfx.PutPixel(k + x2, l + y2, 0, 0, 255);
	}

	for(int m = 0; m < 3; m++) {
		for(int n = 0; n < 599; n++)
			gfx.PutPixel(m + 400, n, 255, 255, 255);
	}
}

#include "MainWindow.h"
#include "Game.h"
#include "Paddle.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	P1(5, gfx),
	P2(gfx.ScreenWidth - Paddle::width - 5, gfx),
	rn( rd() ),
	VelX(-1, 1),
	VelY(-1, 1),
//	meter(meter),
	ball(VelX(rn), VelY(rn))
{

}

void Game::Go() {
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel() {
	P1.Update('W', 'S', wnd.kbd, gfx);
	P2.Update(VK_UP, VK_DOWN, wnd.kbd, gfx);
	ball.Update(gfx, wnd.kbd);
	ball.P1_Deflect(P1);
	ball.P2_Deflect(P2);
}

void Game::ComposeFrame() {
	P1.Draw(gfx);
	P2.Draw(gfx);
	ball.Draw(gfx);

}

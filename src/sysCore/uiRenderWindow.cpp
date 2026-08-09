#include "RenderWindow.h"

#include "Geometry.h"
#include "Graphics.h"
#include "system.h"

/**
 * @todo Documentation
 */
RenderWindow::RenderWindow(UIWindow* parent, int param_2, int param_3, int param_4, bool param_5)
    : UIWindow(parent, param_2, param_3, param_4, param_5)
{
	_94        = 0;
	mBoxWindow = nullptr;
}

/**
 * @todo Documentation
 */
void RenderWindow::initOpenGL()
{
	// TODO
}

/**
 * @todo Documentation
 */
void RenderWindow::shutdownOpenGL()
{
	// TODO
}

/**
 * @todo Documentation
 */
void RenderWindow::clearRender()
{
	// TODO
}

/**
 * @todo Documentation
 */
void RenderWindow::paintRender(RectArea*)
{
	// TODO
}

/**
 * @todo Documentation
 */
void RenderWindow::update()
{
	if (!mError) {
		paintRender(nullptr);
	}
	UIWindow::update();
}

/**
 * @todo Documentation
 */
void RenderWindow::createWindow(char* param_1, char* param_2, HMENU hMenu)
{
	UIWindow::createWindow(param_1, param_2, hMenu);
	initOpenGL();
	mError = false;
}

/**
 * @brief Process parameters from `UIWindowWndProc` callback.
 */
int RenderWindow::processMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// TODO
}

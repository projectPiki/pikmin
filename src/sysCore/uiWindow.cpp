#include "UIWindow.h"

#include "DebugLog.h"

DEFINE_ERROR(__LINE__)
DEFINE_PRINT("uiWindow")

/**
 * @todo Documentation
 */
UIFrame::UIFrame()
    : Node("UIFrame")
{
}

/**
 * @todo Documentation
 */
void* UIWindow::resizeFrame(void*, RectArea&)
{
}

/**
 * @todo Documentation
 */
void UIWindow::dockTop(int, RectArea&, RectArea&)
{
}

/**
 * @todo Documentation
 */
void* UIWindow::resizeChildren(void*, RectArea&)
{
}

/**
 * @todo Documentation
 */
void UIWindow::updateSizes(int, int)
{
}

/**
 * @todo Documentation
 */
void UIWindow::updateMove(int, int)
{
}

/**
 * @todo Documentation
 */
void UIWindow::activate()
{
}

/**
 * @todo Documentation
 */
int UIWindow::processMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
}

/**
 * @todo Documentation
 */
int UIWindow::returnMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
}

/**
 * @todo Documentation
 */
void UIWindow::sizeWindow(int, int, int)
{
}

/**
 * @todo Documentation
 */
void UIWindow::createWindow(char*, char*, HMENU)
{
}

/**
 * @todo Documentation
 */
void UIWindow::initFrame(UIWindow*, int, int, int, bool)
{
}

/**
 * @todo Documentation
 */
void UIWindow::closeChildren()
{
}

/**
 * @todo Documentation
 */
UIWindow::UIWindow()
{
}

/**
 * @todo Documentation
 */
UIWindow::UIWindow(UIWindow*, int, int, int, bool)
{
}

/**
 * @todo Documentation
 */
UIWindow::~UIWindow()
{
}

/**
 * @todo Documentation
 */
SplitBar::SplitBar(UIWindow*, UIWindow*, unsigned long, int)
{
}

/**
 * @todo Documentation
 */
int SplitBar::processMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
}

/**
 * @todo Documentation
 */
void SplitBar::handleClick(int, int)
{
}

/**
 * @todo Documentation
 */
void SplitBar::handleRelease(int, int)
{
}

/**
 * @todo Documentation
 */
VertSplitBar::VertSplitBar(UIWindow* param_1, UIWindow* param_2, unsigned long param_3, int param_4)
    : SplitBar(param_1, param_2, param_3, param_4)
{
}

/**
 * @todo Documentation
 */
void VertSplitBar::trackMouse(int, int, int)
{
}

/**
 * @todo Documentation
 */
HorzSplitBar::HorzSplitBar(UIWindow* param_1, UIWindow* param_2, unsigned long param_3, int param_4)
    : SplitBar(param_1, param_2, param_3, param_4)
{
}

/**
 * @todo Documentation
 */
void HorzSplitBar::trackMouse(int, int, int)
{
}

/**
 * @todo Documentation
 */
ComboBox::ComboBox(UIWindow* parent, int param_2, int param_3, int param_4, bool param_5)
    : UIWindow(parent, param_2, param_3, param_4, param_5)
{
}

/**
 * @brief Conforms to the `WNDPROC` callback type.
 */
LRESULT CALLBACK subClassProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
}

/**
 * @todo Documentation
 */
int ComboBox::processMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
}

/**
 * @todo Documentation
 */
void ComboBox::createWindow(char*, char*, HMENU)
{
}

/**
 * @todo Documentation
 */
void ComboBox::addOption(char*, bool)
{
}

/**
 * @todo Documentation
 */
void ComboBox::selOption(int)
{
}

/**
 * @todo Documentation
 */
EditBox::EditBox(UIWindow* parent, int param_2, int param_3, int param_4, bool param_5)
    : ComboBox(parent, param_2, param_3, param_4, param_5)
{
}

/**
 * @todo Documentation
 */
void EditBox::entryHandler(char*)
{
}

/**
 * @todo Documentation
 */
int EditBox::processMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
}

/**
 * @todo Documentation
 */
OptionBox::OptionBox(UIWindow* parent, int param_2, int param_3, int param_4, bool param_5)
    : ComboBox(parent, param_2, param_3, param_4, param_5)
{
}

/**
 * @todo Documentation
 */
int OptionBox::processMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
}

/**
 * @todo Documentation
 */
int AppWindow::processMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
}

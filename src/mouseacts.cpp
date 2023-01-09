#include "mouseacts.h"

MouseActs::MouseActs(QWidget *parent) :QWidget (parent) {}

void MouseActs::clickCurPos() {
    GetCursorPos(&pos);
    mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN, pos.x, pos.y, 0, 0);
    mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP, pos.x, pos.y, 0, 0);
}

#include "widget.h"
#include "graphics.hpp"

using namespace genv;
Widget::Widget(int x, int y, int sx, int sy)
{
    x_=x;
    y_=y;
    size_x=sx;
    size_y=sy;
}
bool Widget::onmouse(int mouse_x, int mouse_y) const
{
    return mouse_x>x_ && mouse_x<x_+size_x && mouse_y> y_ && mouse_y<y_+size_y;
}
void Widget::draw() const
{

}

void Widget::handle(event ev)
{

}

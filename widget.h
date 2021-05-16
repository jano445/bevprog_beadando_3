#ifndef WIDGET_H
#define WIDGET_H
#include "graphics.hpp"

class widget
{
    protected:
        int x_, y_;
        int size_x, size_y;

    public:
        Widget(int x, int y, int sx, int sy);
        virtual bool onmouse(int mouse_x, int mouse_y) const;
        virtual void draw() const;
        virtual void handle(genv::event ev);
};

#endif // WIDGET_H

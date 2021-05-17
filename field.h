#ifndef FIELD_H
#define FIELD_H

#include <widget.h>


class field : public widget
{
    int player;
    public:
        field(int x, int y, int sx, int sy);
        virtual void draw() const;
        virtual void handle(genv::event ev);
        virtual unsigned int getplayer(){return player;}
        virtual void resetfield();
};

#endif // FIELD_H

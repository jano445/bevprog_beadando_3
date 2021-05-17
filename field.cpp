#include "field.h"
#include "widget.h"
using namespace std;
using namespace genv;

field::field(int x, int y, int sx, int sy)
    :widget(x,y,sx,sy)
{
    player=0;
}

void field::draw() const
{
    switch(player)
    {
    case 0:
        gout<<move_to(x_,y_)
            <<color(255,255,255)
            <<box(size_x, size_y);
        gout<<move_to(x_+1,y_+1)
            <<color(0,0,0)
            <<box(size_x-2, size_y-2);
        break;

    case 1:
        gout<<move_to(x_,y_)
            <<color(255,255,255)
            <<box(size_x, size_y);
        gout<<move_to(x_+1,y_+1)
            <<color(255,0,0)
            <<box(size_x-2, size_y-2);
        break;

    case 2:
        gout<<move_to(x_,y_)
            <<color(255,255,255)
            <<box(size_x, size_y);
        gout<<move_to(x_+1,y_+1)
            <<color(0,0,255)
            <<box(size_x-2, size_y-2);
        break;
    }
}

void field::handle(event ev)
{
    extern unsigned int turn; //átvenni ezt a változót
    if(ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button == btn_left && player == 0)
    {
        player=turn%2==0 ? 1:2;
        turn++;
    }
}

void field::resetfield()
{
    player=0;
}

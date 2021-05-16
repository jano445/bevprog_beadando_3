#include "button.h"

using namespace std;
using namespace genv;

button::button(int x,int y, int sx, int sy, string inputtext, function<void()>fv):
    widget(x,y,sx,sy),includedtext(inputtext),action(action)
{

}

void button::draw() const
{
    if(!push)
    {
        gout<<move_to(x_,y_)
            <<color(255,255,255)
            <<box(size_x,size_y;
        gout<<move_to(x_+1,y_+1)
            <<color(0,0,0)
            <<box(size_x-2,size_y-2);
        gout<<move_to(x_+2,y_+20)
            <<color(255,255,255)
            <<text(includedtext);
    }
    else
    {
        gout<<move_to(x_,y_)
            <<color(255,255,255)
            <<box(size_x,size_y;
        gout<<move_to(x_+1,y_+1)
            <<color(255,0,0)
            <<box(size_x-2,size_y-2);
        gout<<move_to(x_+2,y_+20)
            <<color(255,255,255)
            <<text(includedtext);
    }
}

void button::handle(event ev)
{
    push=false;
    if(ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button == btn_left)
    {
        push=true;
        action();
    }
}

#include "label.h"

using namespace genv;
label::label(int x, int y, int sx, int sy, std::string inputtext, unsigned int r_, unsigned int g_, unsigned int b_)
:widget(x,y,sx,sy),includedtext(inputtext), r(r_), g(g_), b(b_)
{
}

void label::draw() const
{
    gout<<move_to(x_+1,y_+1)
        <<color(0,0,0)
        <<box(size_x-2, size_y-2);
    gout<<move_to(x_+2,y_+20)
        <<color(r,g,b)
        <text(includedtext);
}

void label::handle(event ev)
{

}

void label::changelabeltext(std::string newtext)
{
    includedtext=newtext;
}

void label::setcolor(unsigned int r_, unsigned int g_, unsigned int b_)
{
    r=r_;
    g=g_;
    b=b_;

}

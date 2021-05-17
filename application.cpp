#include "application.h"

using namespace genv;
application::application()
{
    focus=-1;
}

void application::addwidget(widget* w)
{
    widgets.push_back(w);
}

void application::run()
{
    gout.open(xx,yy);
    for(size_t i=0;i<widgets.size();i++)
        {
            widgets.at(i)->draw();
        }
        gout<<refresh;


    event ev;
    while(gin>>ev && ev.keycode!=key_escape)
    {
        if(ev.type==ev_mouse)
        {
            for(size_t i=0;i<widgets.size();i++)
            {
                if(widgets.at(i)->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus=i;
                }
            }
        }
        if(focus!=-1)
        {
            widgets.at(focus)->handle(ev);
        }
        for(size_t i=0;i<widgets.size();i++)
        {
            widgets.at(i)->draw();
        }
        gout<<refresh;
    }
}

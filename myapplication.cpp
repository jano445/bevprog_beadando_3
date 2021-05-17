#include "myapplication.h"
#include "gamespace.h"
myapplication::myapplication()
{
    gamespace* gs = new gamespace(60,0,600,600);
    addwidget(gs);
}


#ifndef APPLICATION_H
#define APPLICATION_H

#include "widget.h"
#include <vector>

using namespace std;
class application
{
    protected:
        unsigned int xx=600;
        unsigned int yy=700;
        unsigned int focus;
        vector<widget*> widgets;

    public:
        application();
        void addwidget(widget* w);
        virtual void run();
};

#endif // APPLICATION_H

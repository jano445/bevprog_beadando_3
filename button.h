#ifndef BUTTON_H
#define BUTTON_H

#include <widget.h>
#include <string>
#include <functional>

using namespace std;

class button : public widget
{
    string includedtext;
    function<void()> action;
    bool push;
    public:
        button(int x, int y, int sx, int sy, string inputtext, function<void()> fv);
        virtual void draw() const;
        virtual void handle(genv::event ev);

};

#endif // BUTTON_H

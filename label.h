#ifndef LABEL_H
#define LABEL_H

#include <widget.h>
#include <string>

using namespace std;

class label : public widget
{
    string includedtext;
    unsigned int r;
    unsigned int g;
    unsigned int b;
    public:
        label(int x, int y, int sx, int sy, string inputtext, unsigned int r_=255, unsigned int g_=255, unsigned int b_=255);
        virtual void draw() const;
        virtual void handle(genv::event ev);
        virtual void changelabeltext(string newtext);
        virtual void setcolor(unsigned int r_, unsigned int g_, unsigned int b_);
};

#endif // LABEL_H

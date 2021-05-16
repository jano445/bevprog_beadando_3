#ifndef GAMESPACE_H
#define GAMESPACE_H

#include <widget.h>
#include <field.h>
#include <label.h>
#include <button.h>

class gamespace : public widget
{
    field *gamemap[20][20];
    label *actualplayer;
    label *winnerindic;
    button *retrybutton;
    int winner=0;
    bool gameover=false;
    public:
        gamespace(int x, int y, int sx, int sy);
        virtual void draw() const;
        virtual void handle(genv::event ev);
        bool haswon(unsigned int player);
        void setwinner(int player);
        void changeactualplayer();
        bool filledcheck();
        void restart();
};

#endif // GAMESPACE_H

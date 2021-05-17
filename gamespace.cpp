#include "gamespace.h"

using namespace genv;
using namespace std;

unsigned int turn=0;

gamespace::gamespace(int x, int y, int sx, int sy)
:widget(x,y,sx,sy)
{
    for(int i=0;i<400;i++)
    {
        field *b=new field((i%20)*30,x+(i/20)*30,30,30);
        gamemap[i%20][i/20]=b;
    }
    actualplayer = new label(240,10,125,30,"Player 1's turn");
    winnerindic = new label(240,30,125,30,"");
    retrybutton = new button(540,20,60,30,"RESTART",[&](){
        restart();
    });
}

void gamespace::draw() const
{
    for(int i=0;i<400;i++)
    {
        gamemap[i%20][i/20]->draw();
    }
    actualplayer->draw();
    winnerindic->draw();
    retrybutton->draw();
}

void gamespace::handle(event ev)
{
    if(!gameover)
    {
        for(int i=0;i<400;i++)
        {
            gamemap[i%20][i/20]->handle(ev);
        }
        if(haswon(1))
            setwinner(1);
        if(haswon(2))
            setwinner(2);
        if(filledcheck())
            gameover=true;
        changeactualplayer();
    }
    else
    {
        if(winner==0)
        {
            winnerindic->setcolor(255,255,255);
            winnerindic->changelabeltext("Draw");
        }
        if(winner==1)
        {
            winnerindic->setcolor(255,0,0);
            winnerindic->changelabeltext("Player 1 won");
        }
        if(winner==2)
        {
            winnerindic->setcolor(0,0,255);
            winnerindic->changelabeltext("Player 2 won");
        }
    }
    retrybutton->handle(ev);
}

bool gamespace::haswon(unsigned int player)
{
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<20;j++)
        {
          if(gamemap[i][j]->getplayer()==player && gamemap[i+1][j]->getplayer()==player && gamemap[i+2][j]->getplayer() == player && gamemap[i+3][j]->getplayer() == player &&
                    gamemap[i+4][j]->getplayer() == player)
                    return true;
        }
    }

    for(int i=0;i<20;i++)
    {
        for(int j=0;j<16;j++)
        {
            if(gamemap[i][j]->getplayer() == player && gamemap[i][j+1]->getplayer() == player && gamemap[i][j+2]->getplayer() == player && gamemap[i][j+3]->getplayer() == player &&
                    gamemap[i][j+4]->getplayer() == player)
                    return true;
        }
    }

    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            if(gamemap[i][j]->getplayer() == player && gamemap[i+1][j+1]->getplayer() == player && gamemap[i+2][j+2]->getplayer() == player && gamemap[i+3][j+3]->getplayer() == player &&
                    gamemap[i+4][j+4]->getplayer() == player)
                    return true;
        }
    }

    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            if(gamemap[19-i][j]->getplayer() == player && gamemap[19-(i+1)][j+1]->getplayer() == player && gamemap[19-(i+2)][j+2]->getplayer() == player && gamemap[19-(i+3)][j+3]->getplayer() == player &&
                    gamemap[19-(i+4)][j+4]->getplayer() == player)
                    return true;
        }
    }
    return false;
}

void gamespace::setwinner(int player)
{
    winner=player;
    gameover=true;
}

void gamespace::changeactualplayer()
{
    if(!gameover)
    {
        if(turn%2==0)
        {
            actualplayer->changelabeltext("Player 1's turn");
        }
        else
        {
            actualplayer->changelabeltext("Player 2's turn");
        }
    }
    else
    {
        actualplayer->changelabeltext("Game Over");
    }
}

bool gamespace::filledcheck()
{
    int counter=0;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            if(gamemap[i][j]->getplayer() !=0)
                counter++;
        }
    }
    return counter==400;
}

void gamespace::restart()
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            gamemap[i][j]->resetfield();
        }
    }
    gameover=false;
    winner=0;
    winnerindic->changelabeltext("");
    actualplayer->changelabeltext("Player 1's turn");
    turn =0;
}

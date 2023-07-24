#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "turtle.h"
struct{
    int x;
    int y;
    int oldx;
    int oldy;
    int score;
}Reket1;
struct{
    int x;
    int y;
    int oldx;
    int oldy;
    int score;
}Reket2;
struct{
    int dx;
    int dy;
    int x;
    int y;
}Ball;
int loops;
const int ymax=29;
const int xmax=94;

void showScore(){
    pokeChar(xmax+2,2,'0' + Reket1.score);
    pokeChar(xmax+3,2,'|');
    pokeChar(xmax+4,2,'0' + Reket2.score);
}

void drawBall(){
    if((loops%10)==0){
        if(Ball.y == ymax) Ball.dy = -1;
        if(Ball.y == 0)    Ball.dy =  1;

        if(Ball.x == Reket2.x - 1){
            if((Reket2.y < Ball.y)&&(Ball.y < Reket2.y + 5))
                Ball.dx = -1;
            else {
                Reket1.score++;
            }
        }
         if(Ball.x == Reket1.x + 1){
            if((Reket1.y < Ball.y)&&(Ball.y < Reket1.y + 5))
                Ball.dx = 1;
            else{
                Reket2.score++;
            }
        }
        if(Ball.x == 0) Ball.dx = 1;

        pokeChar(Ball.x,Ball.y,' ');
        Ball.y = Ball.y + Ball.dy;
        Ball.x = Ball.x + Ball.dx;
        pokeChar(Ball.x,Ball.y,'O');
    }
}
void drawReket2(int y,int x){
    for(int br=0; br<=5; br++)
        pokeChar(Reket2.oldx, Reket2.oldy + br, ' ');
    setBackColor(WHITE);
    for(int br=0;br<=4;br++)
        pokeChar(x,y+br,'|');
    setBackColor(BLACK);
    Reket2.oldx = x;
    Reket2.oldy = y;

}

void drawReket1(int y,int x){

    for(int br=0; br<=5; br++)
        pokeChar(Reket1.oldx, Reket1.oldy + br, ' ');
    setBackColor(WHITE);
    for(int br=0;br<=4;br++)
        pokeChar(x,y+br,'|');
    setBackColor(BLACK);

    Reket1.oldx = x;
    Reket1.oldy = y;
}
int main()
{
    Reket1.score = 0;
    Reket2.score = 0;
    Reket1.x = 3;
    Reket1.y = 17;
    Reket2.x = 90;
    Reket2.y = 17;
    Ball.x = 45;
    Ball.y = 17;
    Ball.dx = 1;
    Ball.dy = 1;
    loops = 0;
    char ch;
    initTurtle();
    setTitle("pong");

    drawBall();
    drawReket2(Reket2.y, Reket2.x);
    drawReket1(Reket1.y, Reket1.x);

    while(1){
        Sleep(20);
        drawBall();
        showScore();
        if(kbhit()){
            ch=getch();
            if ((ch=='w')&&(Reket1.y > 0)){
                Reket1.y--;
                drawReket1(Reket1.y, Reket1.x);
            }
            if ((ch=='s')&&(Reket1.y+5 < ymax)){
                Reket1.y++;
                drawReket1(Reket1.y, Reket1.x);
            }
            if ((ch=='o')&&(Reket2.y > 0)){
                 Reket2.y--;
                 drawReket2(Reket2.y, Reket2.x);
            }
            if ((ch=='l')&&(Reket2.y+5 < ymax)){
                 Reket2.y++;
                 drawReket2(Reket2.y, Reket2.x);
            }
            if(ch==' ')
                break;
        }
        loops++;
    }
    getchar();
    exitTurtle();
    return 0;
}

#ifndef _SNAKE_H_
#define _SNAKE_H_

const int WIDTH=20;

const int  LENGTH=20;

struct snake
{
    int length=1;
    int X=LENGTH/2,Y=LENGTH/2;
    int dX=1,dY=0;
    int bodyX[WIDTH*LENGTH];
    int bodyY[WIDTH*LENGTH];
};

struct fruit
{
    int X,Y;
};

void PrintScreen(snake shane , fruit banana , int score); 

void MoveSnake(snake shane);

void CollideDetect(snake shane);

#endif  
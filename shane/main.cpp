#include <iostream>
#include <ctime>
#include "snake.h"
#include <conio.h>
#include <windows.h>
#include <cstdlib>

int score=0;

struct fruit apple={rand() % WIDTH , rand() % LENGTH};
struct snake shane;

int main (int argc , char** argv){
    srand(time(0));
    while (true)
    {
       PrintScreen(shane,apple,score);
       if (_kbhit())
       {
        char direction = _getch();
            switch (direction)
            {
            case 'z':
                shane.dX=0;
                shane.dY=-1;
                break;
            
            case 'q':
                shane.dX=-1;
                shane.dY=0;
                break;

            case 's':
                shane.dX=0;
                shane.dY=1;
                break;

            case 'd':
                shane.dX=1;
                shane.dY=0;
                break;    
            }
       }
       MoveSnake(shane);
       CollideDetect(shane);
       if (shane.X==apple.X && shane.Y==apple.Y)
       {
            shane.length++;
            score++;
            apple.X=rand() % WIDTH;
            apple.Y=rand() % LENGTH;
       }
       
       Sleep(100);
    }
    return 0;  
}

#include <iostream>
#include <ctime>
#include "snake.h"
#include <conio.h>
#include <windows.h>
#include <cstdlib>


void PrintScreen( struct snake shane , struct fruit banana , int score){
    system("CLS");
    for (int y=0; y < WIDTH ; y++)
    {
        for (int x=0; x < LENGTH ; x++)
        {
            if (x==shane.X && y==shane.Y)
            {
                std::cout<<"O";
            } else if (x==banana.X && y==banana.Y)
            {
                std::cout<<"c";
            } else {
                bool isBody=false;
                for (int i=0; i<shane.length ;i++)
                {
                    if (x==shane.bodyX[i] && y==shane.bodyY[i])
                    {
                        isBody=true;
                        break;
                    }
                    
                }
                if (isBody)
                {
                    std::cout<<"o";
                }else{
                    std::cout<<".";
                }
                
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"Votre Score est : "<<score<<std::endl;
}

void MoveSnake(struct snake shane){
    for (int i = shane.length; i >0; i--)
    {
        shane.bodyX[i]=shane.bodyX[i-1];
        shane.bodyY[i]=shane.bodyY[i-1];
    }
    shane.bodyX[0]=shane.X;
    shane.bodyY[0]=shane.Y;
    shane.X += shane.dX;
    shane.Y += shane.dY;

}

void CollideDetect(struct snake shane){
    if (shane.X<=0 || shane.X>=LENGTH || shane.Y<=0 || shane.Y>=WIDTH) 
    {
       std::cout<<"Vous avez perdu :le serpent a touché le bord"<<std::endl; 
       exit;
    }
    for (int i = 0; i < shane.length; i++)
    {
        if (shane.X == shane.bodyX[i] && shane.Y==shane.bodyY[i])
        {
            std::cout<<"Vous avez perdu :le serpent s'est mordu la queue"<<std::endl;
            exit;
        }
        
    }
      
}
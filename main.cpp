#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;
bool gameOver;
const int width=40;
const int height=30;
int speed=50;
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100];
int nTail;
enum eDirection {STOP=0, LEFT,RIGHT,UP,DOWN};
eDirection dir;

void setup()
{
    gameOver=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    srand(time(nullptr));
    fruitX=rand()%width;
    fruitY=rand()%height;
    score=0;
}
void draw()
{
    
    for(int i=0;i<width;i++)
    {
        cout<<"# ";
    }
    cout<<endl;
    
    for(int i=2;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(fruitY<2 || fruitY>height-1)
            {
                fruitY=height/2-1;
            }
            if(fruitX<1 || fruitX>width-1)
            {
                fruitX=width/2-3;
            }
            if(j==0 || j==width-1)
            {
                cout<<"# ";
                if(i==height/2 && j==width-1)
                {
                    cout<<"Score: "<<score;
                }
            }
            else if(i==y && j==x)
            {
                cout<<"O ";    
            }
            else if((i==fruitY && j==fruitX))// && (fruitX>1 || fruitX<width-1 || fruitY<height-1 || fruitY>1))
            {
                
                cout<<"F ";
            }
            else if(x==fruitX && y==fruitY)
            {
                fruitX=rand()%width;
                fruitY=rand()%height;
                score++;
                if(score%5==0)
                {
                    speed-=10;
                }
                nTail++;
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    
    for(int i=0;i<width;i++)
    {
        cout<<"# ";
    }
}

void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case char(75):
                dir=LEFT;
                break;
            case char(80):
                dir=DOWN;
                break;
            case char(77):
                dir=RIGHT;
                break;
            case char(72):
                dir=UP;
                break;
            case 'p':
                gameOver=true;
                break;
        }
    }
}

void logic()
{
    switch(dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    if(x>=width || x<1 || y>=height || y<1)
    {
        gameOver=true;
    }
}

int main()
{
    setup();
    
    while(!gameOver)
    {
        draw();
        input();
        logic();
        
        
        Sleep(100);
        if(!gameOver)
        {
            system("cls");
        }
        else
        {
            cout<<"\n\nGAMEOVER"<<endl;
            system("pause");
        }
    }
    
    return 0;
}
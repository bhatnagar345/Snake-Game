#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
const int height = 20;
const int width =  20;
int x,y,fruitX,fruitY,Size;
int ntail;
int tailX[100],tailY[100];
enum direction{STOP = 0,LEFT,RIGHT,UP,DOWN};
direction dir;
void Setup()
{
    gameover = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    srand(time(NULL));
    fruitX = rand()%width;
    fruitY = rand()%height;
    Size = 0;
}
void Draw()
{
    system("cls");
    for(int i=0; i<width+2;i++)
    {
        cout<<"#";
    }
    cout<<endl;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0)
            {
                cout<<"#";
            }

            if(j==x && i==y)
            {
                cout<<"O";
            }
            else if(j == fruitX && i == fruitY)
            {
                cout<<"f";
            }
            else
            {
                bool print = false;
                for(int k =0;k<ntail;k++)
                {
                    if(j == tailX[k] && i == tailY[k])
                    {
                        cout<<"o";
                        print = true;
                    }
                }
                if(!print)
                {
                cout<<" ";
                }

            }
            if(j== width-1)
            {
                cout<<"#";
            }
        }
        cout<<endl;
    }
    for(int i=0; i<width+2;i++)
    {
        cout<<"#";
    }
    cout<<endl<<"Score : "<<Size<<endl;
    cout<<" w = UP , s = DOWN , a = LEFT , d = RIGTH "<<endl;
}


void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            dir = LEFT;
            break;
         case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameover = true;
            break;
        }
    }
}



void logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X,prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for(int i=1;i<ntail;i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch(dir)
    {
    case LEFT :
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
     default:
        break;
    }
    if(x > width || x < 0 || y > height || y < 0)
    {
        gameover = true;
    }
    if(x == fruitX && y == fruitY)
    {
        Size +=10;
        ntail++;
        srand(time(NULL));
        fruitX = rand()%width;
        fruitY = rand()%height;
    }
}
int main()
{
    Setup();
    while(!gameover)
    {
        Draw();
        Input();
        logic();
        Sleep(10);
    }
    return 0;
}


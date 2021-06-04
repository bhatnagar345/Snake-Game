#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
const int height = 20;
const int width =  20;
int x,y,fruitX,fruitY,Size;
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
            if(j == fruitX && i == fruitY)
            {
                cout<<"f";
            }
            else
            {
                cout<<" ";
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

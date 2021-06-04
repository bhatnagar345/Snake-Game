#include<bits/stdc++.h>
using namespace std;
int heigth = 25;
int width = 40;
int main()
{
    system("cls");
    for(int i=0; i<width;i++)
    {
        cout<<"#";
    }
    for(int i=0;i<heigth;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0)
            {
                cout<<"#";
            }
            if(j== width-1)
            {
                cout<<"#";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for(int i=0; i<width+1;i++)
    {
        cout<<"#";
    }
    return 0;
}

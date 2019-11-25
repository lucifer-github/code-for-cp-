#include <iostream>
#include<stdlib.h>
#include<stddef.h>
#include <stdio.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<vector>
using namespace std;
bool GameOver;
int score=0;
const int width=100;
const int height=10;
int x,y,fruitx=1,fruity=1;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
vector<int> tailx;
vector<int> taily;
void gotoxy(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void setup()
{  GameOver=false;
   dir=STOP;
   x=width/2;
   y=height/2;
   srand(time(0));
   while(1)
   {
        fruitx=(rand()%width);
        fruity=(rand()%height);
        if(fruitx==0)
           continue;
        if(fruitx!=x||fruity!=y)
           break;
   }
}

void draw()
{
    system("cls");
    for(int i=0;i<=width;i++)
        cout<<"#";

    cout<<endl;

   for(int j=0;j<=height;j++)
   {
       for(int i=0;i<=width;i++)
       {   if(i==x&&j==y)
             {cout<<"O";continue;}
           else if(i==fruitx&&j==fruity)
                  {cout<<"@";continue;}
           else if(i==0||i==width)
                  {cout<<"#";continue;}

           if(1)
           {  bool Notail=true;
              for(int k=0;k<tailx.size()&&Notail==true;k++)
              {
               if(tailx[k]==i&&taily[k]==j)
               {
                cout<<"o";
                Notail=false;

               }
              }
              if(Notail==true)
              cout<<" ";
       }
       }
       cout<<"\n";

 //   cout<<endl;
   }
    for(int i=0;i<=width;i++)
        cout<<"#";


}

void input()
{
    if(kbhit())
    {
        switch(getch())
        {
         case 'a':if(dir!=RIGHT)
             dir=LEFT;break;
         case 'd':if(dir!=LEFT)
                 dir=RIGHT;break;
         case 'w':if(dir!=DOWN)
                  dir=UP;break;
         case 's':if(dir!=UP)
                  dir=DOWN;break;
         case 'p':GameOver=true;break;
        }
    }
}
void logic()
{
    if(tailx.size()!=0)
        {   int prevx=tailx[0];
            int prevy=taily[0];
            tailx[0]=x;
            taily[0]=y;
           // int tempx,tempy
            for(int i=1;i<tailx.size();i++)
            {
                swap(tailx[i],prevx);
                swap(taily[i],prevy);
            }
        }
    switch(dir)
    {
        case STOP :break;
        case LEFT :x--;
                   break;
        case RIGHT:x++;
                   break;
        case UP   :y--;
                   break;
        case DOWN:y++;
                   break;
     }
     if(x>=width)
        x=1;
     else if(x<1)
        x=width-1;
     if(y>height)
        y=0;
     else if(y<0)
        y=height;


        for(int i=0;i<tailx.size();i++)
        {
             if(tailx[i]==x&&taily[i]==y)
             {   GameOver=true;
                 return ;
             }
        }

     if(fruitx==x&&fruity==y){
       score=score+10;
       tailx.push_back(x);
       taily.push_back(y);
       while(1)
       {    bool CanExitNow=false;

            fruitx=(rand()%width);
            fruity=(rand()%height);
            if(fruitx==0)
               continue;
            if(fruitx!=x&&fruity!=y)
            {
               CanExitNow=true;
               for(int i=0;i<tailx.size();i++)
                   if(tailx[i]==fruitx&&taily[i]==fruity)
                      CanExitNow=false;
            }
            if(CanExitNow==true)
               break;


       }

     }
}

int main()
{  setup();

   while(!GameOver)
   {   Sleep(100);
       draw();
       input();
       logic();
      // system("pause");
   }
   system("cls");
   cout<<"\n     your score is:"<<score<<"\n\n";

    return 0;
}

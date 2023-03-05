#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;
/*
idea :
 have 2d array about
    100x27 for sure

    snake about an array of 5 object each object have an

    tail4-tail3-tail2-tail1-head

    having a dir always update


*/


void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}


class node
{
    public:
            int x;
            int y;
            char dir;

        node(int x=0,int y=0,char dir='>')
        {
            this->x=x;
            this->y=y;
            this->dir=dir;
        }


};


class player
{
    private:
        vector<node> arr;

    public:
        int score;
        player()
        {
            score=0;
            for(int i=0;i<6;i++)
            {
                node x(1+i,1,'>');
                arr.push_back(x);
            }

        }
        void incX()
        {
            if(arr[5].dir=='<')return;
            arr[0].x=arr[1].x;
            arr[1].x=arr[2].x;
            arr[2].x=arr[3].x;
            arr[3].x=arr[4].x;
            arr[4].x=arr[5].x;

            arr[0].y=arr[1].y;
            arr[1].y=arr[2].y;
            arr[2].y=arr[3].y;
            arr[3].y=arr[4].y;
            arr[4].y=arr[5].y;

            arr[0].dir=arr[1].dir;
            arr[1].dir=arr[2].dir;
            arr[2].dir=arr[3].dir;
            arr[3].dir=arr[4].dir;
            arr[4].dir=arr[5].dir;

            arr[5].x++;
            arr[5].dir='>';
        }
        void incY()
        {
            if(arr[5].dir=='^')return;
             arr[0].x=arr[1].x;
            arr[1].x=arr[2].x;
            arr[2].x=arr[3].x;
            arr[3].x=arr[4].x;
            arr[4].x=arr[5].x;

            arr[0].y=arr[1].y;
            arr[1].y=arr[2].y;
            arr[2].y=arr[3].y;
            arr[3].y=arr[4].y;
            arr[4].y=arr[5].y;

            arr[0].dir=arr[1].dir;
            arr[1].dir=arr[2].dir;
            arr[2].dir=arr[3].dir;
            arr[3].dir=arr[4].dir;
            arr[4].dir=arr[5].dir;

            arr[5].y++;
            arr[5].dir='v';
        }
        void decX()
        {
            if(arr[5].dir=='>')return;
             arr[0].x=arr[1].x;
            arr[1].x=arr[2].x;
            arr[2].x=arr[3].x;
            arr[3].x=arr[4].x;
            arr[4].x=arr[5].x;

            arr[0].y=arr[1].y;
            arr[1].y=arr[2].y;
            arr[2].y=arr[3].y;
            arr[3].y=arr[4].y;
            arr[4].y=arr[5].y;

            arr[0].dir=arr[1].dir;
            arr[1].dir=arr[2].dir;
            arr[2].dir=arr[3].dir;
            arr[3].dir=arr[4].dir;
            arr[4].dir=arr[5].dir;

            arr[5].x--;
            arr[5].dir='<';
        }
        void decY()
        {
            if(arr[5].dir=='v')return;
             arr[0].x=arr[1].x;
            arr[1].x=arr[2].x;
            arr[2].x=arr[3].x;
            arr[3].x=arr[4].x;
            arr[4].x=arr[5].x;

            arr[0].y=arr[1].y;
            arr[1].y=arr[2].y;
            arr[2].y=arr[3].y;
            arr[3].y=arr[4].y;
            arr[4].y=arr[5].y;

            arr[0].dir=arr[1].dir;
            arr[1].dir=arr[2].dir;
            arr[2].dir=arr[3].dir;
            arr[3].dir=arr[4].dir;
            arr[4].dir=arr[5].dir;

            arr[5].y--;
            arr[5].dir='^';
        }
        void drawSnake()
        {
            for(int i=0;i<6;i++)
            {
                gotoxy(arr[i].x,arr[i].y);
                cout<<arr[i].dir;
            }
        }
        bool checkOutOfBoundX()
        {

            if(arr[5].x<0)
            {
                return true;
            }
            else if(arr[5].x>27)
            {
                return true;
            }
            return false;
        }
        bool checkOutOfBoundy()
        {

            if(arr[5].y<0)
            {
                return true;

            }
            else if(arr[5].y>27)
            {
                return true;
            }
            return false;
        }

        bool bite()
        {
            unordered_set<string> check;
            for(int i=0;i<6;i++)
            {
                string create=to_string(arr[i].x);+" "+to_string(arr[i].y);
                check.insert(create);
            }
            return check.size()!=5;
        }

        char getDir()
        {
            return arr[5].dir;
        }
        int getx()
        {
            return arr[5].x;
        }
        int gety()
        {
            return arr[5].y;
        }

};

class fruit
{
    private:
            int x;
            int y;
    public:
        fruit()
        {
            x=rand()%26+2;
            y=rand()%26+2;
        }
        void drawFruit()
        {
            gotoxy(x,y);
            cout<<"#";
        }
        void createAnother()
        {
            int anotherx=rand()%26+2;
            int anothery=rand()%26+2;


            x=anotherx;
            y=anothery;
        }
        int getx()
        {
            return x;
        }
        int gety()
        {
            return y;
        }

};


void drawMap()
{
    for(int i=0;i<28;i++)
    {
        gotoxy(i,0);
        cout<<"X";
        gotoxy(i,28);
        cout<<"X";
    }
    for(int i=0;i<28;i++)
    {
        gotoxy(0,i);
        cout<<"X";
        gotoxy(28,i);
        cout<<"X";
    }
}


void gameLoop()
{
    bool End=false;
    player p;
    fruit apple;

    while(End==false)
    {
        // draw the game
        drawMap();
        p.drawSnake();
        apple.drawFruit();

        //if eat first;
        if(p.getx()==apple.getx()&&p.gety()==apple.gety())
        {
            apple.createAnother();
            p.score++;
        }
        //change dir if key press
            if(_kbhit()!=0)
                    {
                        char a;
                        a=_getch();
                        switch(a)
                        {
                        case 'w':p.decY();break;
                        case 's':p.incY();break;
                        case 'a':p.decX();break;
                        case 'd':p.incX();break;
                        case 'e':End=true;break;
                        }

                    }
        //check if eaten after key press
        if(p.getx()==apple.getx()&&p.gety()==apple.gety())
        {
            apple.createAnother();
            p.score++;
        }
        //moving up
                        switch(p.getDir())
                        {
                            case '^':p.decY();break;
                            case 'v':p.incY();break;
                            case '<':p.decX();break;
                            case '>':p.incX();break;
                        }


        gotoxy(30,0);
        cout<<"SCORE: "<<p.score;

        //check if out of bound
        End=p.checkOutOfBoundX()||p.checkOutOfBoundy();
        //check if bite it self;
        //End=p.bite();
        //no need bcz there is no way the player can overlap the snake in such a small time

        Sleep(80-p.score);
        system("cls");
    }
    cout<<"GAME OVER";
    cout<<"\n"<<p.score;
}

int main()
{
    srand(time(NULL));
    gameLoop();

}

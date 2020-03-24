#include<iostream>
#include<conio.h>
#include<cstdlib>
#define Height 25
#define width 25
using namespace std;
class SnakeHd
{
    public :
  int x,y;
  char dir;
}S;
int tailX[100000],tailY[100000];
long len;
bool GameEnd;
int foodX,foodY;
long Points;
void Setup();
void InpLog();
void Screen();
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    Setup();
  while(!GameEnd)
  {
     Screen();
     InpLog();
  }
  printf("\nGAME OVER!!");
  getch();
  return 0;
}
void Setup()
{
GameEnd=false;
S.x=Height/2;
S.y=width/2;
foodX=rand()%width;
foodY=rand()%Height;
Points=0;
len=0;
}
void Screen()
{
  system("CLS");
  for(int i=0;i<width+1;++i)  //displaying horizontal walls
     printf("#");
  printf("\n");
  for(int i=0;i<Height;++i)
  {
    for(int j=0;j<width;++j)
    {
      if (j==0)
        printf("#");
      if(i==S.y && j==S.x)
          printf("O");
      else if(i==foodY && j==foodX)
          printf("@");
      else
      {
        bool space = false;
        for(int k=0;k<len;++k)
        {
          if(tailX[k] ==j && tailY[k]==i)
          {
            printf("0");
            space=true;
          }
        }
        if(!space)
          printf(" ");
      }
      if(j==width-1)
        printf("#");
    }
    printf("\n");
  }

  for(int i=0;i<width+1;++i)  //displaying horizontal walls
     printf("#");
  printf("\n");
  printf("Points : %ld",Points);
}
void InpLog()
{
  int prX,prY;
  prX = tailX[0];
  prY =  tailY[0];
  int pr2X,pr2Y;
  tailX[0] = S.x;
  tailY[0] = S.y;
  for(int i=1;i<len;++i)
  {
    pr2X = tailX[i];
    pr2Y = tailY[i];
    tailX[i] = prX;
    tailY[i] = prY;
    prX = pr2X;
    prY = pr2Y;
  }
  if(kbhit())
  S.dir=getch();
    switch (S.dir) {
      case 'a': S.x--; break;
      case 'd': S.x++; break;
      case 'w': S.y--; break;
      case 's': S.y++; break;
      case 'x': GameEnd=true;
    }
  if(S.x==foodX && S.y==foodY)
  {
    Points+=10;
    foodX=rand()%width;
    foodY=rand()%Height;
    ++len;
  }
  for(int i=1;i<len;++i)
     if(S.x==tailX[i] && S.y==tailY[i])
       GameEnd=true;
  if(S.x==-1 || S.x==width || S.y==-1 || S.y==Height)
  GameEnd=true;
}

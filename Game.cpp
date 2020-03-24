#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
class SnakeHd
{
    public :
  int x,y;
  char dir;
}S;
const int Height=20;
const int width=20;
int tailX[1000],tailY[1000];
bool GameEnd;
int foodX,foodY;
long Points;
void Setup();
void InpLog();
void Screen();
int main()
{
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
      if(i==foodY && j==foodX)
          {printf("@");
          continue;}
      if(i==S.y && j==S.x)
        {printf("O");
        continue;}
      if(j!=0&&j!=width)
          printf(" ");
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
  }
  if(S.x==-1 || S.x==width || S.y==-1 || S.y==Height)
  GameEnd=true;
}

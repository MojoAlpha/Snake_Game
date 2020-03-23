#include<iostream>
#include<conio.h>
#include<dos.h>
#include<cstdlib>
using namespace std;
class SnakeHd
{
    public :
  int x,y;
  char dir;
}S;
const int Height=20;
const int width=40;
bool GameEnd;
int foodX,foodY;
void Setup();
void Screen();
int main()
{
    Setup();
  while(!GameEnd)
  {
     Screen();
  }
  return 0;
}
void Setup()
{
GameEnd=false;
S.x=Height/2;
S.y=width/2;
foodX=rand()%width;
foodY=rand()%Height;
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
      if (j==0||j==width-1)
        printf("#");

        printf(" ");
    }
    printf("\n");
  }

  for(int i=0;i<width+1;++i)  //displaying horizontal walls
     printf("#");
}

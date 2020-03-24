#include<bits/stdc++.h>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include<unistd.h>
#include<string>
#define Height 25
#define width 25
using namespace std;
class SnakeHd
{
    public :
  int x,y;
  char dir;
}S;
class Score
{
  public :
  char nm[100];
  long Sc;
};
int tailX[100000],tailY[100000];
long len;
fstream file;
char play='y';
bool GameEnd;
int foodX,foodY,ModeG;
long Points;
unsigned int tym=9000;
void Setup();
void InpLog();
void Screen();
void New_Game();
void Mode();
void GmSpeed();
void IfHyScore();
void HyScore();
int main()
{
  int choice;
  do                                           //main menu
  {
  system("CLS");
  cout<<"\t\tSNAKE XENIA II\n";
  cout<<"\t\tWelcome To The New Version Of An Old Game!!";
  cout<<"\n\t\t\t1.New Game\n\t\t\t2.Mode\n\t\t\t3.Game Speed\n\t\t\t4.High Score\n\t\t\t5.Exit";
  cout<<"\n\t\tEnter Your Choice : ";
  scanf("%d",&choice);
  switch (choice)
   {
    case 1:New_Game();break;
    case 2:Mode();break;
    case 3:GmSpeed();break;
    case 4:HyScore();break;
    case 5:play='n';break;
    default:cout<<"\t\tInvalid Choice!!\n\t\tPress Any Key To Continue...";
            getch();
  }
}while(play=='y');
  cout<<"\t\tHave A Nice Day :)";
  getch();
  return 0;
}
void New_Game()     //main game
{
  Setup();
  while(!GameEnd)
  {
     Screen();
     InpLog();
     usleep(tym);
  }
  IfHyScore();
  cout<<"\nPress R To Play Again... OR";
  cout<<"\nPress Any Key To Continue...";
  if(getch()=='r')
    New_Game();
}
void Mode()         //different modes
{
  system("CLS");
  cout<<"\t\tSelect Mode :\n\t\t1.Wall E\n\t\t2.Non-Wall Arcade";
  cout<<"\n\t\tEnter Your Choice :";
  cin>>ModeG;
  cout<<"\t\tChanges Applied!! Press Any Key To Continue...";
  getch();
}
void GmSpeed()         //regulating game speed
{
  int choice;
  int speed;
  do{
  system("CLS");
  cout<<"\t\tGAME SPEED:\n\t\tCurrent Speed : "<<tym/3000;
  cout<<"\n\t\t1.Modify\n\t\t2.Back";
  cout<<"\n\t\tEnter Your Choice : ";
  cin>>choice;
  if(choice<=0 || choice>2)
  {cout<<"\n\t\tInvalid Choice!!";
  getch();}
}while(choice<=0 || choice>2);
  switch (choice) {
    case 1:cout<<"\t\tEnter New Speed (1-10) : ";
           cin>>speed;
           tym=speed*3000;
           cout<<"Changes Applied!! Press Any Key To Continue...";
           getch(); break;
    case 2:break;
  }
}
void IfHyScore()
{
  file.open("High_Score.dat",ios::binary|ios::in|ios::out);
  file.seekg(0,ios::beg);
  Score Scr,temp;
  Scr.Sc=Points;
  file.read((char*)&temp,sizeof(Score));
  if(temp.Sc<Scr.Sc)
  {
    cout<<"\n\t\tCongratulations You Have Made A HighScore!!";
    cout<<"\n\t\tEnter Your Name : ";
    scanf("%s",Scr.nm );
    file.seekg(0,ios::beg);
    file.write((char*)&Scr,sizeof(Score));
  }
  file.close();
}
void HyScore()
{
  system("CLS");
  file.open("High_Score.dat",ios::binary|ios::in|ios::out);
  file.seekg(0,ios::beg);
  Score View;
  file.read((char*)&View,sizeof(Score));
  cout<<"\t\tName : "<<View.nm;
  cout<<"\n\t\tScore : "<<View.Sc;
  cout<<"\n\t\tPress R to Reset The Score...";
  cout<<"\n\t\tPress Any Key To Continue...";
  if(getch()=='r')
  {
    View.Sc = 0;
    strcpy(View.nm,"Yet To Be Discovered!!");
    file.seekg(0,ios::beg);
    file.write((char*)&View,sizeof(Score));
    cout<<"\n\t\tReset Complete!!";
    getch();
  }
  file.close();
}
void Setup()        //Initial setup before main game
{
GameEnd=false;
S.x=Height/2;
S.y=width/2;
foodX=rand()%width;
foodY=rand()%Height;
Points=0;
len=0;
}
void Screen()   //displaying the snake
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
void InpLog()      //input and logic
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
  if(ModeG==1){              //different modes implement
  if(S.x==-1 || S.x==width || S.y==-1 || S.y==Height)
  GameEnd=true;}
  else{
  if(S.x<=-1)
  S.x=width-1;
  else if(S.x>=width)
  S.x=0;
  if(S.y<=-1)
  S.y=Height-1;
  if(S.y>=Height)
  S.y=0;}
}

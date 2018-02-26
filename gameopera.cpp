# include <stdio.h>  
# include <time.h>  
# include <conio.h>  
# include <graphics.h> 
#include "face.h"
#include "StartEnter.h" 
#include "gameopera.h"
int a;//产生的方块类型
int pre_a;
int px,py;
int visit[30][15],Color[30][15],minX=30,minY=30,maxX=310,maxY=610,speed=200,score=0,rank=0;  
  int color[]={GREEN,CYAN,MAGENTA,BROWN,RGB(255,105,180),LIGHTBLUE,LIGHTGREEN,LIGHTRED,YELLOW}; 
  extern block[32][5][5],quitgame;
  extern B,C,D;
void nextblock()  
{  
      int i,j,x=391,y=71;  
      setfont(23,0,"楷体");  
      setcolor(B);  
      for(i=0;i<5;i++)  
          for(j=0;j<5;j++)  
              outtextxy(x+20*j,y+20*i,"■");  
          srand(time(NULL));  
          a=rand()%7;		  
          setcolor(color[a]);  
          for(i=0;i<5;i++)  
              for(j=0;j<5;j++)  
                  if(block[4*a][i][j]==1)  
                      outtextxy(x+20*j,y+20*i,"■");  
}  
  void newblock()  
  {  
      int i,j,x=130,y=30,A=a;  
      if(A==0||A==1||A==6)  
          y-=60;  
      else if(A==2||A==3||A==5||A==7||A==8)  
          y-=40;  
      else  
          y-=80;  
      setfont(23,0,"楷体");  
      setcolor(color[A]);  
      for(i=0;i<5;i++)  
          for(j=0;j<5;j++)  
              if(block[4*A][i][j]==1&&y+20*i>=30)  
                  outtextxy(x+20*j,y+20*i,"■");  
              Sleep(100);  
              nextblock();  
              move(x,y,A);
			  if (quitgame==1)
			  {
				  return ;
			  }
  }  
  void move(int x,int y,int A)  
  {  
      int i,j,f,k=0,next=0,Speed=speed,key,nex; 
//	  int stop=0;
	  pre_a=A;
	  int quit;
      while(1)  
      {  
          f=couldmove(x,y+k,A,'x',next);  
          if(f==0)  
          {  
              mark(x,y+k,A,next);  
              break;  
          }  
		  setfont(23,0,"楷体"); 
          setcolor(B);  
          for(i=0;i<5;i++)  
              for(j=0;j<5;j++)  
                  if(block[4*A+next][i][j]==1&&y+20*i+k>=30)  
                      outtextxy(x+20*j,y+20*i+k,"■");  
                  if(kbhit())  
                  {  
                      key=getch(); 
					  if(key==32)
					  {
						  Beep(1060,300);
						  Beep(587,300);
						  setcolor(color[A]); 
						  setfont(25,0,"黑体"); 
						  outtextxy(40,200,"暂停了哦！按空格键继续");
						  while (1)
						  {
							  key=getch();
							  if (key==32)
							  {
								  setcolor(B); 
								  outtextxy(40,200,"■■■■■■■■■■■");
								  break;
							  }
						  }					
					  }
					  else if(key==27)
					  {

						  quit=quitchoose();
						  if (quit==0)
						  {
							  
							setfont(23,0,"楷体"); 
							return ;
						  }
						  continue_face();							
					  }
                      else if(key==72)  
                      {   
						  Beep(1060,200);
						  Beep(523,50);
                          nex=(next+1)%4;  
                          if(couldrotate(x,y+k,A,nex))  
                              next=nex;  
                      }  
                      else if(key==80)
					  {
						  Beep(1060,200);
						  Beep(587,100);  
                          Speed=20;
					  }  
                      else if(key==75&&couldmove(x,y+k+20,A,'z',next))  
					  {  Beep(1060,200);
						  Beep(587,100);
						  x-=20;  
					  }
                      else if(key==77&&couldmove(x,y+k+20,A,'y',next))  
					  {  
						  Beep(1060,200);
						  Beep(587,100);
						  x+=20; 
					  }
                  }  
				  setfont(23,0,"楷体"); 
                  setcolor(color[A]);  
                  for(i=0;i<5;i++)  
				  {
                      for(j=0;j<5;j++)  
					  {
						  if(block[4*A+next][i][j]==1&&y+20*i+k+20>=30)  
                              outtextxy(x+20*j,y+20*i+k+20,"■");
						  if (i==0&&j==0)
						  {
							  px=x;
							  py=y;
						  }
						  
					  }
				  }                          
                          Sleep(Speed);  
                          k+=20;  
              }  
  }  
  int couldmove(int x0,int y0,int A,char dir,int next)  
  {  
      int i,j,x,y,f=1;  
      x=(y0-minY)/20;  
      y=(x0-minX)/20;  
      if(dir=='x')  
      {  
          for(i=0;i<5;i++)  
              for(j=0;j<5;j++)  
              if(block[4*A+next][i][j]==1&&(x+i+1==30||(x+i+1>=0&&x+i+1<30&&y+j>=0&&y+j<15&&visit[x+i+1][y+j]==1)))  
                  f=0;  
      }  
      else if(dir=='z')  
      {  
          for(i=0;i<5;i++)  
              for(j=0;j<5;j++)  
                  if(block[4*A+next][i][j]==1&&(y+j==0||(x+i>=0&&x+i<30&&y+j-1>=0&&y+j-1<15&&visit[x+i][y+j-1]==1)))  
                      f=0;  
      }  
      else if(dir=='y')  
      {  
          for(i=0;i<5;i++)  
              for(j=0;j<5;j++)  
                  if(block[4*A+next][i][j]==1&&(y+j+1==15||(x+i>=0&&x+i<30&&y+j+1>=0&&y+j+1<15&&visit[x+i][y+j+1]==1)))  
                      f=0;  
      }  
      return f;  
  }  
  int couldrotate(int x0,int y0,int A,int next)  
  {  
      int i,j,x,y,f=1;  
      x=(y0-minY)/20;  
      y=(x0-minX)/20;  
      if(!couldmove(x0,y0,A,'x',next))  
          f=0;  
      for(i=0;i<5;i++)  
          for(j=0;j<5;j++)  
              if(block[4*A+next][i][j]==1&&(y+j==-1||y+j==15||(x+i>=0&&x+i<30&&y+j>=0&&y+j<15&&visit[x+i][y+j]==1)))  
                  f=0;  
              return f;  
  }  
  void mark(int x0,int y0,int A,int next)  
  {   
      int i,j,x,y;  
      x=(y0-minY)/20;  
      y=(x0-minX)/20;  
      for(i=0;i<5;i++)  
          for(j=0;j<5;j++)  
              if(block[4*A+next][i][j]==1)  
              {  
                  visit[x+i][y+j]=1;  
                  Color[x+i][y+j]=color[A];  
              }  
  }  
  void full()  
  {  
      int i,j,k=0;  
      char str[10];  
      for(i=29;i>=0;i--)  
      {  
          for(j=0;j<15;j++)  
              if(visit[i][j]==0)  
                  break;  
              if(j==15)  
              {  
                  k++;  
                  down(i);  
                  i++;  
              }  
      }  
      setcolor(RED);  
      score+=10*k;  
      sprintf(str,"%d",score);  
      outtextxy(415,310,str);  
      rank=(score/50);  
      sprintf(str,"%d",rank);  
      outtextxy(425,405,str);  
      if(speed==0)  
          speed=300;  
      if(score>=300)  
          speed=75;  
  }  
  void down(int x)  
  {  
      int i,j;  
      for(i=x;i>0;i--)  
          for(j=0;j<15;j++)  
              if(visit[i-1][j]==1)  
              {  
                  visit[i][j]=visit[i-1][j];  
                  Color[i][j]=Color[i-1][j];  
                  setcolor(Color[i-1][j]);  
                  outtextxy(minX+20*j,minY+20*i,"■");  
              }  
              else  
              {  
                  visit[i][j]=visit[i-1][j];  
                  setcolor(B);  
                  outtextxy(minX+20*j,minY+20*i,"■");  
              }  
              setcolor(B);  
              for(j=0;j<15;j++)  
              {  
                  visit[0][j]=0;  
                  outtextxy(minX+20*j,minY,"■");  
              }  
  }  
  int gameover()  
  {  
      int i;  
      for(i=0;i<15;i++)  
          if(visit[0][i]==1)  
          {  
              return 1;  
          }  
          return 0;  
  } 

#include "StartEnter.h"
#include "face.h"
#include "gameopera.h"
# include <graphics.h> 
#include <stdio.h>
#include <conio.h>
extern Color[30][15];
extern color[];
extern visit[30][15];
extern block[28][5][5];
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
extern minX,minY,maxX,maxY,a,pre_a,score,havegame,quitgame,px,py,rank;
extern B,C,D;
int EnterChooce()
{
	int ikey,ikey1;
	int y=250;	
	Interface();
	setfont(26,0,"黑体"); 
	setcolor(WHITE);
	outtextxy(190,370,"→");//250 310 370
	while (1)
	{
		ikey=getch();
	/*	if (ikey==224)
		{
			ikey1=getch();
			switch (ikey1)
			{
			case 72:
				if (y!=250)
				{
					setcolor(B);
					outtextxy(190,y,"■");
					setcolor(WHITE);
					y-=60;
					if (havegame==0)
					{
						y-=60;
					}
					outtextxy(190,y,"→");
				}
				break;
			case 80:
				if (y!=370)
				{
					setcolor(B);
					outtextxy(190,y,"■");
					setcolor(WHITE);
					y+=60;
					if (havegame==0)
					{
						y+=60;
					}
					outtextxy(190,y,"→");
				}
				break;
			default:
				break;
			}
		}*/
		 if (ikey==13)
		{
			return  (y-250)/60;
		}
		else if (ikey==27)
		{
			return 3;
		}
}
	
	return 0;
}
int gamevoer_chooce()
{
	int i=0;
	int ikey,ikey1;
	int flag=0;//0重新开始 1回到主菜单
	TCHAR fileName[]="C:\\Documents and Settings\\ks59\\桌面\\俄罗斯方块儿\\music.mp3";
	TCHAR shortName[MAX_PATH];
	GetShortPathName(fileName,shortName,sizeof(shortName)/sizeof(TCHAR));
	TCHAR cmd[MAX_PATH+10];
	wsprintf(cmd,"play %s",shortName);
	mciSendString(cmd,"",NULL,NULL);
	  mciSendString("play music.mp3 repeat",0,0,0);
	gameface(); 
	setfont(40,0,"楷体"); 
	setcolor(RGB(255,255,255));
	outtextxy(80,300,"☆");
	while(1)
	{
		setcolor(color[i]);
		i++;
		if(i==9)
		{
			i=0;
		}
		outtextxy(100,100,"Game Over"); 
		outtextxy(65,200,"是否重新开始?"); 
		outtextxy(120,300,"是");
		outtextxy(260,300,"否");
		Sleep(100);
		if(kbhit())  
		{  
			ikey=getch();  
			if(ikey==13)  
				return flag;
			else if(ikey==224)
			{
				
				ikey1=getch();
				switch(ikey1)
				{
				case 75:
					flag=0;
					setfont(40,0,"楷体"); 
					setcolor(RGB(255,255,255));
					outtextxy(80,300,"☆");
					setcolor(B);
					outtextxy(220,300,"■");
					break;
				case 77:
					flag=1;
					setfont(40,0,"楷体"); 
					setcolor(RGB(255,255,255));
					outtextxy(220,300,"☆");
					setcolor(B);
					outtextxy(80,300,"■");
					break;
				default:
					break;
				}
			}
		}  
		
	}
	getch();
	return 0;
  }
int  go_new_game()
{
	int i,iflag=0;
	score=0;
	rank=0;
	havegame=1;
	quitgame=0;
	while(1)
	{
		gameface();      
		nextblock();  
		Sleep(500);  
		memset(visit,0,sizeof(visit));  
		while(1)  
		{  
			newblock(); 
			if (quitgame==1)
			{
				return 2;
			}
			full();  
			if(gameover()==1) 
			{	
				i=gamevoer_chooce();
				if(i==1)
				{
					havegame=0;
					iflag=1;						
				}
				break;
			}
			
		}
		if (iflag==1)
		{
			iflag=0;
			return 1;
		}

	 }
	return 0;
}
int continue_game()
{
	
	int i,iflag=0,n=0;
	havegame=1;
	quitgame=0;
	continue_face();
	
	while(1)
	{
		if (n==1)
		{
			gameface();
			nextblock(); 
			Sleep(200);  
		}		      				 
		while(1)  
		{  
			if (n==1)
			{
				newblock();
			}
			else if (n==0)
			{
				move(px,py,pre_a);
			}
			n=1; 
			if (quitgame==1)
			{
				return 2;
			}
			full();  
			if(gameover()==1) 
			{	
				i=gamevoer_chooce();
				if(i==1)
				{
					havegame=0;
					iflag=1;						
				}
				break;
			}
			
		}
		if (iflag==1)
		{
			iflag=0;
			return 1;
		}
		
	 }
	return 0;
}
int quitchoose()
{
	int i=0;
	int ikey,ikey1;
	int flag=0;//0退出 1取消退出
	setfont(40,0,"楷体"); 
	setcolor(RGB(255,255,255));
	outtextxy(80,300,"☆");
	while(1)
	{
		setcolor(color[i]);
		i++;
		if(i==9)
		{
			i=0;
		}
		outtextxy(65,200,"确 定 退 出?"); 
		outtextxy(120,300,"是");
		outtextxy(260,300,"否");
		Sleep(100);
		if(kbhit())  
		{  
			ikey=getch();  
			if(ikey==13) 
			{
				if (flag==1)
				{
					setcolor(B);
					outtextxy(65,200,"■■■■■■");
					outtextxy(65,300,"■■■■■■");
				}
				else if (flag==0)
				{
					quitgame=1;
				}					
				return flag;
			}
			else if (ikey==27)
			{	
				setcolor(B);
				outtextxy(65,200,"■■■■■"); 
				setcolor(WHITE);
			}
			else if(ikey==224)
			{
				
				ikey1=getch();
				switch(ikey1)
				{
				case 75:
					flag=0;
					setfont(40,0,"楷体"); 
					setcolor(WHITE);
					outtextxy(80,300,"☆");
					setcolor(B);
					outtextxy(220,300,"■");
					break;
				case 77:
					flag=1;
					setfont(40,0,"楷体"); 
					setcolor(RGB(255,255,255));
					outtextxy(220,300,"☆");
					setcolor(B);
					outtextxy(80,300,"■");
					break;
				default:
					break;
				}
			}
		}  
		
	}
	return 0;
}
void set_operate()
{
	setface();
}
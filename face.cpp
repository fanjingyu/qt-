# include <graphics.h> 
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")
extern Color[30][15];
extern color[];
extern visit[30][15];
extern block[28][5][5];
extern minX,minY,maxX,maxY,a,pre_a,score,havegame,quitgame=0,rank,px,py;
int B=RGB(0,0,0);//beijing 
int C=RGB(47,79,79);//开始新居
int D=RGB(72,61,139);//达尔罗斯方块
void Interface()  
{  
	
	initgraph(550, 660);  
	HWND hwnd = GetHWnd();  
	SetWindowText(hwnd, "俄罗斯方块              制作:****"); 
	//mciSendString("open P:\\BGMcom.wav alias yeah",NULL,0,NULL);
	//打开声音

	//mciSendString("play yeah ",NULL,0,NULL);

	PlaySound(TEXT("P:\\BGMcom.wav"),NULL,SND_ASYNC|SND_NODEFAULT);
      setfont(60,0,"隶书"); 
    	setbkcolor(BLACK);
	    cleardevice();
          setcolor(RED);  
          outtextxy(85,100," 俄罗斯方块"); 
		  setfont(30,0,"隶书"); 
     outtextxy(15,580,"  ━━━━━━━◆━━━━━━━ "); 

     outtextxy(150,200," なにつてひひ");  
	 outtextxy(15,35,"  ━━━━━━━◆━━━━━━━ ");

		  setfont(26,0,"隶书"); 
          setcolor(C);  
          outtextxy(220,370,"开始游戏"); 

          
          setfont(20,0,"楷体");  
            setcolor(D);
          outtextxy(60,550,"ENTER：确定"); 
		  
          setfont(20,0,"楷体");  
          
          outtextxy(420,550,"ESC：退出"); 

	
	
} 
void gameface()
{
	char str[10];  
	cleardevice();
	setbkcolor(BLACK);  
	setcolor(WHITE);  
	rectangle(29,29,334,633);  
	rectangle(28,28,335,634);  
	rectangle(370,50,515,195);  
	setfont(22,0, "隶书");  
	setcolor(C);  
	outtextxy(405,215,"下一个:");  
	setcolor(RED);  
	outtextxy(405,280,"分数:");  
	sprintf(str,"%d",score);  
	outtextxy(415,310,str);  
	outtextxy(405,375,"等级:");  
	sprintf(str,"%d",rank);  
	outtextxy(425,405,str);  
	setfont(20,0, "隶书");  
	setcolor(LIGHTBLUE);  
	outtextxy(390,450,"操作说明:");  
	outtextxy(390,475,"↑: 旋转");  
	outtextxy(390,500,"↓: 下降");  
	outtextxy(390,525,"←: 左移");  
	outtextxy(390,550,"→: 右移");  
	outtextxy(390,575,"空格: 暂停");
	outtextxy(390,600,"Esc: 退出");
  }
void continue_face()
{
	int i,j,n,k=0, iflag=0,A=a,x=391,y=71;   
	cleardevice();
	gameface();
	for(i=29;i>=0;i--)  
	{  
		for(j=0;j<15;j++)  
			if(visit[i][j]==1) 
			{
				setcolor(Color[i][j]);
				outtextxy(minX+20*j,minY+20*i,"■");
			}			
	}
	setcolor(color[a]);  
	for(i=0;i<5;i++)  
		for(j=0;j<5;j++)  
			if(block[4*a][i][j]==1)  
				outtextxy(x+20*j,y+20*i,"■");  
	

	return ;
}
void setface()
{
	int key,key1;
	   	setbkcolor(BLACK);  
	   cleardevice(); 
	   setcolor(RED);         
	   setfont(40,0,"楷体");     
	   setfont(22,0,"隶体");  
	   setcolor(477979);  
	   setfont(26,0,"隶书");  	   
	   
		while (1)
		{
			key=getch();
			if (key==224)
			{
				key1=getch();
				switch (key1)
				{
				case 72:
					break;
				case 80:
					break;
				default:
					break;
				}
			}
		}
}

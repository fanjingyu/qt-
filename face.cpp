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
int C=RGB(47,79,79);//蝕兵仟肖
int D=RGB(72,61,139);//器櫛袋帽圭翠
void Interface()  
{  
	
	initgraph(550, 660);  
	HWND hwnd = GetHWnd();  
	SetWindowText(hwnd, "躯袋帽圭翠              崙恬:****"); 
	//mciSendString("open P:\\BGMcom.wav alias yeah",NULL,0,NULL);
	//嬉蝕蕗咄

	//mciSendString("play yeah ",NULL,0,NULL);

	PlaySound(TEXT("P:\\BGMcom.wav"),NULL,SND_ASYNC|SND_NODEFAULT);
      setfont(60,0,"船慕"); 
    	setbkcolor(BLACK);
	    cleardevice();
          setcolor(RED);  
          outtextxy(85,100," 躯袋帽圭翠"); 
		  setfont(30,0,"船慕"); 
     outtextxy(15,580,"  �ォォォォォォァ��ォォォォォォ� "); 

     outtextxy(150,200," なにつてひひ");  
	 outtextxy(15,35,"  �ォォォォォォァ��ォォォォォォ� ");

		  setfont(26,0,"船慕"); 
          setcolor(C);  
          outtextxy(220,370,"蝕兵嗄老"); 

          
          setfont(20,0,"尻悶");  
            setcolor(D);
          outtextxy(60,550,"ENTER�哉袈�"); 
		  
          setfont(20,0,"尻悶");  
          
          outtextxy(420,550,"ESC�才乏�"); 

	
	
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
	setfont(22,0, "船慕");  
	setcolor(C);  
	outtextxy(405,215,"和匯倖:");  
	setcolor(RED);  
	outtextxy(405,280,"蛍方:");  
	sprintf(str,"%d",score);  
	outtextxy(415,310,str);  
	outtextxy(405,375,"吉雫:");  
	sprintf(str,"%d",rank);  
	outtextxy(425,405,str);  
	setfont(20,0, "船慕");  
	setcolor(LIGHTBLUE);  
	outtextxy(390,450,"荷恬傍苧:");  
	outtextxy(390,475,"●: 傴廬");  
	outtextxy(390,500,"◎: 和週");  
	outtextxy(390,525,"○: 恣卞");  
	outtextxy(390,550,"★: 嘔卞");  
	outtextxy(390,575,"腎鯉: 壙唯");
	outtextxy(390,600,"Esc: 曜竃");
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
				outtextxy(minX+20*j,minY+20*i,"＊");
			}			
	}
	setcolor(color[a]);  
	for(i=0;i<5;i++)  
		for(j=0;j<5;j++)  
			if(block[4*a][i][j]==1)  
				outtextxy(x+20*j,y+20*i,"＊");  
	

	return ;
}
void setface()
{
	int key,key1;
	   	setbkcolor(BLACK);  
	   cleardevice(); 
	   setcolor(RED);         
	   setfont(40,0,"尻悶");     
	   setfont(22,0,"船悶");  
	   setcolor(477979);  
	   setfont(26,0,"船慕");  	   
	   
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

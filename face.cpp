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
int C=RGB(47,79,79);//��ʼ�¾�
int D=RGB(72,61,139);//�����˹����
void Interface()  
{  
	
	initgraph(550, 660);  
	HWND hwnd = GetHWnd();  
	SetWindowText(hwnd, "����˹����              ����:****"); 
	//mciSendString("open P:\\BGMcom.wav alias yeah",NULL,0,NULL);
	//������

	//mciSendString("play yeah ",NULL,0,NULL);

	PlaySound(TEXT("P:\\BGMcom.wav"),NULL,SND_ASYNC|SND_NODEFAULT);
      setfont(60,0,"����"); 
    	setbkcolor(BLACK);
	    cleardevice();
          setcolor(RED);  
          outtextxy(85,100," ����˹����"); 
		  setfont(30,0,"����"); 
     outtextxy(15,580,"  ������������������������������ "); 

     outtextxy(150,200," �ʤˤĤƤҤ�");  
	 outtextxy(15,35,"  ������������������������������ ");

		  setfont(26,0,"����"); 
          setcolor(C);  
          outtextxy(220,370,"��ʼ��Ϸ"); 

          
          setfont(20,0,"����");  
            setcolor(D);
          outtextxy(60,550,"ENTER��ȷ��"); 
		  
          setfont(20,0,"����");  
          
          outtextxy(420,550,"ESC���˳�"); 

	
	
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
	setfont(22,0, "����");  
	setcolor(C);  
	outtextxy(405,215,"��һ��:");  
	setcolor(RED);  
	outtextxy(405,280,"����:");  
	sprintf(str,"%d",score);  
	outtextxy(415,310,str);  
	outtextxy(405,375,"�ȼ�:");  
	sprintf(str,"%d",rank);  
	outtextxy(425,405,str);  
	setfont(20,0, "����");  
	setcolor(LIGHTBLUE);  
	outtextxy(390,450,"����˵��:");  
	outtextxy(390,475,"��: ��ת");  
	outtextxy(390,500,"��: �½�");  
	outtextxy(390,525,"��: ����");  
	outtextxy(390,550,"��: ����");  
	outtextxy(390,575,"�ո�: ��ͣ");
	outtextxy(390,600,"Esc: �˳�");
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
				outtextxy(minX+20*j,minY+20*i,"��");
			}			
	}
	setcolor(color[a]);  
	for(i=0;i<5;i++)  
		for(j=0;j<5;j++)  
			if(block[4*a][i][j]==1)  
				outtextxy(x+20*j,y+20*i,"��");  
	

	return ;
}
void setface()
{
	int key,key1;
	   	setbkcolor(BLACK);  
	   cleardevice(); 
	   setcolor(RED);         
	   setfont(40,0,"����");     
	   setfont(22,0,"����");  
	   setcolor(477979);  
	   setfont(26,0,"����");  	   
	   
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

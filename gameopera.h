#ifndef _GAMEOPERA_H_
#define _GAMEOPERA_H_

void nextblock();//������һ������  
void newblock();//����һ���ŵ���������  
void move(int x,int y,int A);//�ƶ�����  
int couldmove(int x0,int y0,int A,char dir,int next);//�ж��ܷ��ƶ�  
int couldrotate(int x0,int y0,int A,int next);//�ж��ܷ���ת  
void mark(int x0,int y0,int A,int next);//��Ƿ���̶����λ��  
void full();//�ж���û���ܹ����е�  
void down(int x);//�����еĽ�����ķ�������һ��  
int gameover();//�ж���Ϸ�Ƿ����  

#endif
#ifndef _GAMEOPERA_H_
#define _GAMEOPERA_H_

void nextblock();//生成下一个方块  
void newblock();//将下一个放到主方框中  
void move(int x,int y,int A);//移动方块  
int couldmove(int x0,int y0,int A,char dir,int next);//判断能否移动  
int couldrotate(int x0,int y0,int A,int next);//判断能否旋转  
void mark(int x0,int y0,int A,int next);//标记方块固定后的位置  
void full();//判断有没有能够消行的  
void down(int x);//有消行的将上面的方块下移一行  
int gameover();//判断游戏是否结束  

#endif
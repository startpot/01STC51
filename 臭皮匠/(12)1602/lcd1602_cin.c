/*************************************************************************************
//LCD1602时钟测试程序
*************************************************************************************/
#include <reg52.h>				//头文件
#define uchar unsigned char		//宏定义
#define uint unsigned int

sbit lcdrs = P2^6;                                                        
sbit lcdrw = P2^5;                                                        
sbit lcden = P2^7;  

//uchar sec,min,hou=12;			//定义全局变量
//uchar tab[8]={0,0,10,0,0,10,0,0};		  //时高位，时低位，：，分高位，分低位，：，秒高位，秒低位
uchar code tab1[11]="0123456789:";
uchar code table[8]={0x00,0x0C,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E};
uchar code table1[8]={0x00,0x00,0x01,0x01,0x05,0x05,0x15,0x15}; 
uchar code table2[8]={0x00,0x00,0x04,0x1F,0x15,0x1F,0x04,0x04}; 
uchar code table3[8]={0x00,0x00,0x1B,0x15,0x11,0x0A,0x04,0x00}; 
uchar code table4[8]={0x00,0x00,0x1F,0x15,0x1F,0x15,0x1F,0x00};
uchar code table5[8]={0x15,0x00,0x1F,0x11,0x0E,0x04,0x1F,0x04}; 
uchar code table6[8]={0x02,0x0A,0x1F,0x02,0x0F,0x02,0x0F,0x00}; 
uchar code table7[8]={0x04,0x04,0x04,0x1F,0x04,0x04,0x04,0x04}; 

/*************************************************************************************
延时函数							   
*************************************************************************************/
void delay(uint x)
{
	uint i,j;
	for(i=0;i<x;i++)
		for(j=0;j<120;j++);
}
/*************************************************************************************
写指令
*************************************************************************************/
void write_com(uchar com)
{
	lcdrw=0;
	lcdrs=0;			//lcdrs为低电平时，写命令
	delay(1);
	lcden=1;
	P0=com;
	delay(1);
	lcden=0;
}
/*************************************************************************************
写数据
*************************************************************************************/
void write_data(uchar dat)
{
	lcdrw=0;
	lcdrs=1;			//lcdrs为高电平时，写数据
	delay(1);	
	P0=dat;
	lcden=1;
	delay(1);
	lcden=0;
}
/*************************************************************************************
初始化
*************************************************************************************/
void init()
{
	lcden=0;
	write_com(0x38);			//显示模式设定
	write_com(0x0c);			//开关显示、光标有无设置、光标闪烁设置
	write_com(0x06);			//写一个字符后指针加一
	write_com(0x01);			//清屏指令
}

/*************************************************************************************
写连续字符函数
*************************************************************************************
void write_word(uchar *s)
{
	while(*s>0)
	{
		write_data(*s);
		s++;
	}
}
/*************************************************************************************
写1602数据,x,y位置
*************************************************************************************/
void write_1602_DATA(uchar x,uchar y,uchar dat)
{
	if(x>0x0f)
	{
		x=0x0f;
	}
	if(y==1)
	{
		write_com(0x80+x);
	}
	else
	{
		write_com(0xc0+x);
	};
	write_data(dat);
}

void LCD1602_Cin(uchar num,uchar *p)
{   
	uchar m=0;
	if(num>7)
	{
		num=7;
	};  				   //仅仅是控制num 最大为7
	write_com(0x40+num*8); 
	for(m=0;m<8;m++)   
	{  
		write_data(p[m]);   
	};  
}
/*************************************************************************************
主函数
*************************************************************************************/
void main()
{
//	uchar i;
	init();
	LCD1602_Cin(0,table);
	LCD1602_Cin(1,table1);
	LCD1602_Cin(2,table2);
	LCD1602_Cin(3,table3);
	LCD1602_Cin(4,table4);
	LCD1602_Cin(5,table5);
	LCD1602_Cin(6,table6);
	LCD1602_Cin(7,table7);
	write_1602_DATA(0,1,0);
	write_1602_DATA(2,1,1);
	write_1602_DATA(4,1,2);
	write_1602_DATA(6,1,3);
	write_1602_DATA(8,1,4);
	write_1602_DATA(10,1,5);
	write_1602_DATA(12,1,6);
	write_1602_DATA(14,1,7);

	while(1)
	{
	}
}

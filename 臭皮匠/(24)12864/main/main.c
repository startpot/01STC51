/******************************************************************************      
* 【名    称】： LCD12864多功能万年历 
* 【语    言】： C语言
* 【编译环境】： Keli3 
* 【晶    振】:  12MHz外部晶振		
* 【芯    片】:  STC89C516RD+
* 【时钟芯片】:  DS1302
* 【温度传感】:  DS18B20 
* 【液 晶 屏】：LCM-12864-ST7920, LCM12864使用并口连接方式,PSB、RST接高电平 		  
* 【程序功能】：
* 【日    期】:  
* 【作    者】: 	
******************************************************************************/	 
#include <reg51.h> 
#include "LCD12864.h"


/*------------------------------主函数---------------------------------------*/
void main()
{	                     
	main_init();			//主程序初始化

	lcm_init();				//液晶初始化

	welcome1();				//显示Kiss
	delayms(250);
	lcm_clr2();				//清屏
	Clean_12864_GDRAM();	//清屏

	welcome2();				//显示信息
	delayms(250);
	lcm_clr2();				//清屏
	Clean_12864_GDRAM();	//清屏

	buzzer=0;				//开蜂鸣器
	delayms(30);
	buzzer=1; 				//关蜂鸣器
	keydone();
	
}

/**********************************************************
主程序初始化
**********************************************************/
void main_init(void)
{	
	LCM_PSB=1;	//液晶并口通信
	LCM_BACKLIGHT=0; //打开背光灯

	key1 = 1;  //A
	key2 = 1;  //B
	key3 = 1;  //C
	key4 = 1;  //D
	key5 = 1;  //背光


} 

/*结束----------------------------------------------------------------------*/

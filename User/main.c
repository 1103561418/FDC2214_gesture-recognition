#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "Buzzer.h"
#include "OLED.h"
#include "Timer.h"
#include "FDC2214.h"
#include "Buzzer.h"
uint8_t KeyNum;
uint8_t i;
float Q=2;
float hq=0;
float res[4];
float temp0,temp1,temp2,temp3;
float flag1,flag2,flag3,flag4,flag5;
int main(void)
	
{	
	
	u8 i;
	u8 res2[4];
	//FDC2X14_Init();
	OLED_Init ();
	Key_Init();
	Buzzer_Init ();
	OLED_ShowString (1,3,"READY");
	while(FDC2214_Init())
	{
		Delay_ms(50);
	}

	
	
	 for(i = 0; i < 10; i++)
  {
    temp0 = Cap_Calculate(0); //采集数据（原始数据） 环境变量
    temp1 = Cap_Calculate(1);
    temp2 = Cap_Calculate(2);
    temp3 = Cap_Calculate(3);
		Delay_ms(20);
	}
	
	Delay_ms(500);
	KeyNum=0;
	while(1)
	{	OLED_Clear();
		KeyNum=Key_GetNum ();
		//OLED_ShowNum(4,4,KeyNum,1);
		if(KeyNum==0)
		{
			
			OLED_ShowString (1,1,"READY!");
		
		}
		
		
		if(KeyNum ==1){
		while(1)
	{	temp0 = Cap_Calculate(0);
		float hq=0;
			hq=temp0;
		OLED_ShowFNum (2,1,temp0,4,2);
		OLED_ShowString (1,1,"MODOL1");
		if(hq<53){
		OLED_ShowString (3,1,"N");	
	    }
		
		else if(56.8<hq && hq<59.5){
		OLED_ShowString (3,1,"S");	
	    }
		else if(59.5<hq && hq<62){
		OLED_ShowString (3,1,"R");
		}
        else if(62<hq){
		OLED_ShowString (3,1,"P");
		}	
	KeyNum =Key_GetNum ();
	if(KeyNum ==4)
	{
		KeyNum =0;
		break ;
	}
	
   }
	}
	 
   
		if(KeyNum ==2){
		while(1)
	{	temp0 = Cap_Calculate(0);
		float hq=0;
			hq=temp0;
		OLED_ShowFNum (2,1,temp0,4,2);
		OLED_ShowString (1,1,"MODOL2");
		if(hq<52.6){
		OLED_ShowString (3,1,"N");	
	    }
		if(52.6<hq && hq<56.5){
		OLED_ShowString (3,1,"1");	
	    }
		else if(56.5<hq && hq<58){
		OLED_ShowString (3,1,"2");
		}
        else if(58<hq && hq<58.8){
		OLED_ShowString (3,1,"3");
		}	
		else if(58.8<hq && hq<61.3){
		OLED_ShowString (3,1,"4");
		}	
		else if(61.3<hq ){
		OLED_ShowString (3,1,"5");
		}	
		
	KeyNum =Key_GetNum ();
	if(KeyNum ==4)
	{
		KeyNum =0;
		break ;
	}
   }
}

	if(KeyNum ==3)
	{
	OLED_Clear ();
	OLED_ShowString (1,1,"Show your hands");
	Delay_ms(3000);
	flag1=Cap_Calculate(0);
	OLED_ShowString (2,1,"Seisors_YES");
	OLED_ShowFNum(2,5,flag1,4,2);
	Buzzer_ON ();
	Delay_ms(3000);
	Buzzer_OFF ();
	OLED_Clear ();
	OLED_ShowString (1,1,"Show your hands");
	Delay_ms(3000);
	flag2=Cap_Calculate(0);
	OLED_ShowString (2,1,"Rock_YES");
	OLED_ShowFNum(2,5,flag2,4,2);
	Buzzer_ON ();
	Delay_ms(3000);
	Buzzer_OFF ();
	OLED_Clear ();
	OLED_ShowString (1,1,"Show your hands");
	Delay_ms(3000);
	flag3=Cap_Calculate(0);
	OLED_ShowString (2,1,"Paper_YES");
	OLED_ShowFNum(2,5,flag3,4,2);
	Buzzer_ON ();
	Delay_ms(3000);
	Buzzer_OFF ();
	OLED_Clear ();
	
	
	while(1)
	{
		OLED_Clear ();
		OLED_ShowString (1,1,"MODOL3");
		OLED_ShowString(2,1,"S");
		OLED_ShowFNum(2,3,flag1,4,2);
		OLED_ShowString(2,9,"R");
		OLED_ShowFNum(2,11,flag2,4,2);
		OLED_ShowString(3,1,"P");
		OLED_ShowFNum(3,3,flag3,4,2);
		hq=Cap_Calculate(0);
		OLED_ShowFNum(4,3,hq,4,2);
		if(hq<53){
		OLED_ShowString (4,1,"N");	
	    }
		
		else if(((flag1+52.00)/2.00)<hq && hq<((flag1+flag2)/2.00)){
		OLED_ShowString (4,1,"S");	
	    }
		else if(((flag1+flag2)/2.00)<hq && hq<((flag2+flag3)/2.00)){
		OLED_ShowString (4,1,"R");
		}
        else if(((flag3+flag2)/2.00)<hq){
		OLED_ShowString (4,1,"P");
		}	
	
		KeyNum =Key_GetNum ();
		if(KeyNum ==4)
	{
		KeyNum =0;
		break ;
	}
	
	}
	
	
	
	}
	if(KeyNum ==4)
	{
	OLED_Clear ();
	OLED_ShowString (1,1,"Show your hands");
	Delay_ms(2500);
	flag1=Cap_Calculate(0);
	OLED_ShowString (2,1,"ONE_YES");
	OLED_ShowFNum(2,5,flag1,4,2);
	Buzzer_ON ();
	Delay_ms(2500);
	Buzzer_OFF ();
	OLED_Clear ();
	OLED_ShowString (1,1,"Show your hands");
	Delay_ms(2500);
	flag2=Cap_Calculate(0);
	OLED_ShowString (2,1,"TWO_YES");
	OLED_ShowFNum(2,5,flag2,4,2);
	Buzzer_ON ();
	Delay_ms(2500);
	Buzzer_OFF ();
	OLED_Clear ();
	OLED_ShowString (1,1,"Show your hands");
	Delay_ms(2500);
	flag3=Cap_Calculate(0);
	OLED_ShowString (2,1,"THREE_YES");
	OLED_ShowFNum(2,5,flag3,4,2);
	Buzzer_ON ();
	Delay_ms(2500);
	Buzzer_OFF ();
	OLED_Clear ();
	OLED_ShowString (1,1,"Show your hands");
	Delay_ms(2500);
	flag4=Cap_Calculate(0);
	OLED_ShowString (2,1,"FOUR_YES");
	OLED_ShowFNum(2,5,flag4,4,2);
	Buzzer_ON ();
	Delay_ms(2500);
	Buzzer_OFF ();
	OLED_Clear ();
	OLED_ShowString (1,1,"Show your hands");
	Delay_ms(2500);
	flag5=Cap_Calculate(0);
	OLED_ShowString (2,1,"FIVE_YES");
	OLED_ShowFNum(2,5,flag5,4,2);
	Buzzer_ON ();
	Delay_ms(2500);
	Buzzer_OFF ();
	OLED_Clear ();
	
	while(1)
	{
		OLED_Clear ();
		OLED_ShowString (1,1,"MODOL4");
		OLED_ShowString(1,8,"1");
		OLED_ShowFNum(1,10,flag1,4,2);
		OLED_ShowString(2,1,"2");
		OLED_ShowFNum(2,3,flag2,4,2);
		OLED_ShowString(2,8,"3");
		OLED_ShowFNum(2,10,flag3,4,2);
		OLED_ShowString(3,1,"4");
		OLED_ShowFNum(3,3,flag4,4,2);
		OLED_ShowString(3,8,"5");
		OLED_ShowFNum(3,10,flag5,4,2);
		hq=Cap_Calculate(0);
		OLED_ShowFNum(4,3,hq,4,2);
		if(hq<53){
		OLED_ShowString (4,1,"N");	
	    }
		
		else if(((flag1+52.00)/2.00)<hq && hq<((flag1+flag2)/2.00)){
		OLED_ShowString (4,1,"1");	
	    }
		else if(((flag1+flag2)/2.00)<hq && hq<((flag2+flag3)/2.00)){
		OLED_ShowString (4,1,"2");
		}
        else if(((flag3+flag2)/2.00)<hq && hq<((flag4+flag3)/2.00)){
		OLED_ShowString (4,1,"3");
		}	
		 else if(((flag3+flag4)/2.00)<hq && hq<((flag4+flag5)/2.00)){
		OLED_ShowString (4,1,"4");
		}	
		 else if(((flag5+flag4)/2.00)<hq ){
		OLED_ShowString (4,1,"5");
		}	
		KeyNum =Key_GetNum ();
		if(KeyNum ==1)
	{
		KeyNum =0;
		break ;
	}
	
	}
	
	
   }
  
   }

}




//#include "stm32f10x.h"// Device header
//uint16_t Num;
//void Timer_Init(void)
//{
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
//	TIM_InternalClockConfig (TIM2);//使用内部时钟
//	
//	TIM_TimeBaseInitTypeDef TIM_BaseInitStrucyure;
//	TIM_BaseInitStrucyure.TIM_ClockDivision =TIM_CKD_DIV1 ;//时钟分频1分频（不分频）
//	TIM_BaseInitStrucyure.TIM_CounterMode =TIM_CounterMode_Up ;//计数模式:向上计数
//	TIM_BaseInitStrucyure.TIM_Period =10000-1;//自动重装载值
//	TIM_BaseInitStrucyure.TIM_Prescaler =7200-1;
//	TIM_BaseInitStrucyure.TIM_RepetitionCounter =0;
//	TIM_TimeBaseInit (TIM2,&TIM_BaseInitStrucyure);
//	
//	TIM_ClearFlag (TIM2,TIM_FLAG_Update);//解决启动定时器就进中断的问题
//	TIM_ITConfig (TIM2,TIM_IT_Update,ENABLE);//开启更新中断到NVIC通路
//	
//	NVIC_PriorityGroupConfig (NVIC_PriorityGroup_2);
//	NVIC_InitTypeDef NVIC_InitStructure;
//	NVIC_InitStructure.NVIC_IRQChannel =TIM2_IRQn;//tim2在NVIC通道
//	NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =2;//抢占优先级
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority =1;//响应优先级
//	NVIC_Init (&NVIC_InitStructure);
//	
//	TIM_Cmd (TIM2,ENABLE);//启动定时器
//	
//}
//void TIM2_IRQHandler(void)
//{
//if(TIM_GetITStatus (TIM2,TIM_IT_Update)==SET)//获取更新中断标志位
//	{
//		Num++;
//		TIM_ClearITPendingBit (TIM2,TIM_IT_Update);//清除更新中断标志位
//	}
//}

//uint16_t Num_Get(void)
//{
//return Num;
//}
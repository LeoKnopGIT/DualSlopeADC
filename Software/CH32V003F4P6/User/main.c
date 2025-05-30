#include <ch32v00x.h>
#include "display.h"
#include "init.h"

volatile int timer_flag = 0;
volatile int number = 69;

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init(115200);
    init_USARTx_CFG();
    init_GPIO_display();
    init_GPIO_INT();
    init_Timer(47999,100); 
    __enable_irq();
    
    while(1)
    {   
        //nop
    } 
}

void TIM2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM2_IRQHandler(void){
    if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
    {
        GPIO_WriteBit(GPIOD, GPIO_Pin_0, (GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_0) == Bit_SET) ? Bit_RESET : Bit_SET);
        TIM2->CNT = 0;
        TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
    }
}

void EXTI7_0_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI7_0_IRQHandler(void)
{
    if (EXTI_GetITStatus(EXTI_Line1) != RESET)
    {
        if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)) {
            printf("Rising edge\n");
        } else {
            printf("Falling edge\n");
        }
        EXTI_ClearITPendingBit(EXTI_Line1);
    }
}

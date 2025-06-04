#include <ch32v00x.h>
#include "display.h"
#include "init.h"

// T = 0,38s
#define CLOCK_DIVIDER_1 48000 -1
#define CLOCK_REGISTER_1 1000 -1

// RC = 100u -> T = 3/17000-> Pulse = f * T = 8470,6
#define CLOCK_DIVIDER_2 1 - 1 // 48 MHz
#define CLOCK_REGISTER_2 8471 -1 //

volatile uint16_t timer_counter = 0;
volatile uint16_t ext_adc_value = 0;

volatile uint8_t ext_adc_idle = 1;
volatile uint8_t ext_adc_mess_vref = 0;
volatile uint8_t ext_adc_mess_vin = 0;

float calculateVoltage_MC() {   
    uint16_t ADCbits = ADC_GetConversionValue(ADC1);
    float vref = 5.0;
    float adcVoltage = (vref * ADCbits) / 1024 * 1000;
    return adcVoltage;
}

uint16_t calculateVoltage_EXT_ADC(uint16_t counter_value, uint16_t timer_counter_value) {
    uint32_t n_mess = counter_value + 8471 * timer_counter_value;
    return 3300 - 14400700/n_mess;
}

int main(void) {
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init(115200);
    init_USARTx_CFG();
    init_GPIO_display();
    init_GPIO_INT();
    init_Timer1(CLOCK_DIVIDER_1, CLOCK_REGISTER_1); // 
    init_Timer2(CLOCK_DIVIDER_2, CLOCK_REGISTER_2); // 
    initADC(); 
    
    while(1) {   
        // MC_ADC
        //while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));  // Warten auf Ende der Konversion
        //display_number(calculateVoltage_MC());
        
        // EXT_ADC
        display_number(ext_adc_value);
    } 
}
void TIM1_UP_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM1_UP_IRQHandler(void){
    if(TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET) {
        // Wenn bis dahin die Spannung nicht auf 3.3V gesteigen ist, liegt 3.3V oder mehr am ADC an
        if (ext_adc_mess_vin) {
            ext_adc_value = 3300;
        }    
        // Start next conversion
        GPIO_WriteBit(GPIOD, GPIO_Pin_0, Bit_SET); // 5V an Eingang
        TIM_ClearITPendingBit(TIM1,TIM_IT_Update);
    }
}

void TIM2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM2_IRQHandler(void){
    if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) {
        if (ext_adc_mess_vin) {
            timer_counter++;
        } 
        if (ext_adc_mess_vref) {
            GPIO_WriteBit(GPIOD, GPIO_Pin_0, Bit_RESET); // Vin an Eingang
            TIM2->CNT = 0; // R¨¹ckssetzen des Z?hlregisters
            ext_adc_mess_vin = 1;
        }
        TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
    }
}

void EXTI7_0_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI7_0_IRQHandler(void){
    if (EXTI_GetITStatus(EXTI_Line1) != RESET) {
        printf("GPIO?");
        if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)) {
            //Positive Flanke
            ext_adc_idle = 0;
            ext_adc_mess_vref = 1;
            timer_counter = 0;
            TIM2->CNT = 0;
            TIM_Cmd(TIM2, ENABLE);
        } else {
            //Negative Flanke
            ext_adc_mess_vin = 0;
            ext_adc_idle = 1;

            ext_adc_value = calculateVoltage_EXT_ADC(TIM2->CNT,timer_counter);
            TIM_Cmd(TIM2, DISABLE);
        }
        EXTI_ClearITPendingBit(EXTI_Line1);
    }
}

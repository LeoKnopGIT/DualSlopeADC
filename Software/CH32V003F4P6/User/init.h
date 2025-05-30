#ifndef INIT_H
#define INIT_H

#include "debug.h"
void init_USARTx_CFG(void);
void init_GPIO_display(void);
void init_GPIO_INT(void);
void init_Timer(uint16_t prsc, uint16_t arr);
#endif 
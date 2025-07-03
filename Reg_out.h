#ifndef REG_OUT_H
#define REG_OUT_H

#include "stm32f1xx_hal.h"
#include <stdint.h>

#define DATA_REG_SW_Pin GPIO_PIN_1
#define CLK_REG_SW_Pin  GPIO_PIN_3
#define CS_REG_SW_Pin   GPIO_PIN_2
#define REG_PORT        GPIOC

void OutCascade(uint8_t *data, uint8_t len);

#endif // REG_OUT_H

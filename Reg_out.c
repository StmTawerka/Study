#include "Reg_out.h"

void OutCascade(uint8_t *data, uint8_t len) {

    HAL_GPIO_WritePin(GPIOC, CS_REG_SW_Pin, GPIO_PIN_RESET);

    for (int8_t byte = len - 1; byte >= 0; byte--) {
        for (int8_t bit = 7; bit >= 0; bit--) {
            HAL_GPIO_WritePin(GPIOC, DATA_REG_SW_Pin, (data[byte] & (1 << bit)) ? GPIO_PIN_SET : GPIO_PIN_RESET);

            HAL_GPIO_WritePin(GPIOC, CLK_REG_SW_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOC, CLK_REG_SW_Pin, GPIO_PIN_RESET);
        }
    }

    HAL_GPIO_WritePin(GPIOC, CS_REG_SW_Pin, GPIO_PIN_SET);
}
/*
 В main:

 uint8_t num_out[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20}; // D0-D5 выводы

 uint8_t out[8] = {0};

 out[0] = num_out[1]; // 0-5
 out[1] = num_out[1]; // 0-5
 out[2] = num_out[1]; // 0-5
 out[3] = num_out[1]; // 0-5
 out[4] = num_out[1]; // 0-5
 out[5] = num_out[1]; // 0-5
 out[6] = num_out[1]; // 0-5
 out[7] = num_out[1]; // 2 вывода:0 и 1

 OutCascade(out, 8);

*/
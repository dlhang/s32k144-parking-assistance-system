#include "uart.h"
#include "sdk_project_config.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void uart_print(char *str)
{
    LPUART_DRV_SendDataBlocking(1, (uint8_t *)str, strlen(str), 1000);
}

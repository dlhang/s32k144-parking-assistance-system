#include "sdk_project_config.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "driver/uart/uart.h"
#include "driver/pir/pir.h"
#include "driver/srf05/srf05.h"


/* -------- PIN DEFINE -------- */
#define TRIG_GPIO   PTD
#define TRIG_PIN    17U

#define ECHO_GPIO   PTD
#define ECHO_RIGHT  14U


#define LED_GPIO    PTD
#define LED_PIN     16U


/* -------- LED -------- */
void led(float x)
{
        if (x > 0 && x < 5)
            PINS_DRV_ClearPins(LED_GPIO, 1UL << LED_PIN);
        else
            PINS_DRV_SetPins(LED_GPIO, 1UL << LED_PIN);

        delay_ms(100);
}

/* -------- MAIN -------- */
int main(void)
{
    char uart_buf[64];
    float distance;

    CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
                   g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
    LPUART_DRV_Init(INST_LPUART_LPUART_1, &lpUartState1, &lpUartInitConfig1);

    uart_print("Start:\r\n");

    while(1)
    {
    	int motion = PIR_Detected();
    	if (motion)
    	{
    		uart_print("Motion: YES | ");
    	}
    	 else
    	{
    		 uart_print("Motion: NO  | ");
    	}
    	delay_ms(50);
        srf_trigger();
        distance = srf_measure(ECHO_RIGHT);

        if (distance > 0)
            sprintf(uart_buf, "Distance: %.2f cm\r\n", distance);
        else
            sprintf(uart_buf, "No echo\r\n");
        uart_print(uart_buf);
        led(distance);
        delay_ms(50);

    }
}

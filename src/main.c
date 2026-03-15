/******************************************************************************
 * Project : S32K144 Parking Assistance System
 * MCU     : NXP S32K144
 *
 * Features
 *  - Distance measurement using ultrasonic sensor
 *  - Motion detection using PIR sensor
 *  - LED indicator
 *  - UART distance monitoring
 ******************************************************************************/

#include "sdk_project_config.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* Ultrasonic sensor pins */
#define TRIG_GPIO   PTD
#define TRIG_PIN    17U

#define ECHO_GPIO   PTD
#define ECHO_PIN    14U

/* LED indicator */
#define LED_PORT    PTD
#define LED_PIN     16U

/* PIR motion sensor */
#define PIR_PORT    PTD
#define PIR_PIN     5U

/* UART instance */
#define UART_INSTANCE 1


/* Delay in microseconds (software delay) */
static void delay_us(uint32_t us)
{
    volatile uint32_t i;

    while (us--)
    {
        for (i = 0; i < 20; i++)
        {
            __asm("nop");
        }
    }
}

/* Delay in milliseconds */
static void delay_ms(uint32_t ms)
{
    while (ms--)
    {
        delay_us(1000);
    }
}

/**
 * @brief Send string via UART
 */
void uart_print(char *str)
{
    LPUART_DRV_SendDataBlocking(UART_INSTANCE,
                                (uint8_t *)str,
                                strlen(str),
                                1000);
}


int main(void)
{
    uint32_t time_us;
    float distance_cm;
    char uart_buf[64];

    /* Initialize system clock */
    CLOCK_DRV_Init(&clockMan1_InitConfig0);

    /* Initialize GPIO pins */
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* Initialize UART */
    LPUART_DRV_Init(UART_INSTANCE,
                    &INST_LPUART_LPUART_1,
                    &lpuart_1_InitConfig0);

    /* Ensure LED is OFF at startup */
    PINS_DRV_ClearPins(LED_PORT, (1 << LED_PIN));

    uart_print("Parking Assistance System Start\r\n");

    while (1)
    {
        /* Send 10us trigger pulse to ultrasonic sensor */
        PINS_DRV_SetPins(TRIG_GPIO, 1UL << TRIG_PIN);
        delay_us(10);
        PINS_DRV_ClearPins(TRIG_GPIO, 1UL << TRIG_PIN);

        /* Wait for echo signal to go HIGH */
        while (!(PINS_DRV_ReadPins(ECHO_GPIO) & (1UL << ECHO_PIN)));

        /* Measure echo pulse width */
        time_us = 0;

        while (PINS_DRV_ReadPins(ECHO_GPIO) & (1UL << ECHO_PIN))
        {
            delay_us(1);
            time_us++;
        }

        /* Calculate distance (cm) */
        distance_cm = time_us / 58.0f;

        /* Send distance to UART */
        sprintf(uart_buf, "Distance: %.2f cm\r\n", distance_cm);
        uart_print(uart_buf);

        /* Check PIR motion sensor */
        if ((PINS_DRV_ReadPins(PIR_PORT) & (1 << PIR_PIN)) == 0)
        {
            /* Motion detected -> LED ON */
            PINS_DRV_SetPins(LED_PORT, (1 << LED_PIN));
        }
        else
        {
            /* No motion -> LED OFF */
            PINS_DRV_ClearPins(LED_PORT, (1 << LED_PIN));
        }

        /* Delay between measurements */
        delay_ms(100);
    }
}

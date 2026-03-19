#include "srf05.h"
#include "sdk_project_config.h"
#include <stdint.h>

#define TRIG_GPIO   PTD
#define TRIG_PIN    17U

#define ECHO_GPIO   PTD

/* -------- DELAY (improved) -------- */
void delay_us(uint32_t us)
{
	volatile uint32_t i;
	while (us--)
		for (i = 0; i < 20; i++) __asm("nop");
}

void delay_ms(uint32_t ms)
{
    while (ms--) delay_us(1000);
}

/* -------- TRIG -------- */
void srf_trigger(void)
{
    PINS_DRV_ClearPins(TRIG_GPIO, 1UL << TRIG_PIN);
    delay_us(2);

    PINS_DRV_SetPins(TRIG_GPIO, 1UL << TRIG_PIN);
    delay_us(10);

    PINS_DRV_ClearPins(TRIG_GPIO, 1UL << TRIG_PIN);
}

/* -------- MEASURE -------- */
float srf_measure(uint32_t echo_pin)
{
	srf_trigger();
    uint32_t count = 0;
    uint32_t timeout;

    /* wait echo high */
    timeout = 300000;
    while (!(PINS_DRV_ReadPins(ECHO_GPIO) & (1UL << echo_pin)))
    {
        if (--timeout == 0)
            return -1.0f;
    }

    /* measure WITHOUT delay */
    timeout = 600000;
    while (PINS_DRV_ReadPins(ECHO_GPIO) & (1UL << echo_pin))
    {
        delay_us(1);
        count++;

        if (--timeout == 0)
            break;
    }

    return (float)count / 13.0f;
}

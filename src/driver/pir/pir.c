#include "pir.h"
#include "sdk_project_config.h"
#include "pins_driver.h"
#include <stdint.h>

/* PIR motion sensor */
#define PIR_PORT    PTD
#define PIR_PIN     5U

int PIR_Detected(void)
{
    uint32_t pinValue=0;
    if ((PINS_DRV_ReadPins(PIR_PORT) & (1 << PIR_PIN)) != 0)
    {
    	pinValue=1;
    }
    /* Return 0 or 1 only */
    return pinValue;
}


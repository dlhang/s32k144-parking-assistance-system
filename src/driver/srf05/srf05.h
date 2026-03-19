#ifndef SRF05_H
#define SRF05_H
#include "sdk_project_config.h"
#include <stdint.h>
#include <stdio.h>


 void delay_us(uint32_t us);
 void delay_ms(uint32_t ms);
 void srf_trigger(void);
 float srf_measure(uint32_t echo_pin);

#endif

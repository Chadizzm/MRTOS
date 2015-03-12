#ifndef __MRTOS_TIMER__
#define __MRTOS_TIMER__

#include <inttypes.h>

#include "nvic.h"

#define MAX_FREQ  2097000 // 2.097 MHz
#define SCALAR    0x1     // 2.097 MHz

static const uint32_t CLK_FREQ = MAX_FREQ / SCALAR;

// Currently just using timer21

void timer_init();

uint16_t timer_count();
void timer_enable_interrupt(uint16_t value);
void timer_disable_interrupt();
void timer_clear_interrupt();

void timer_mask_interrupt();
void timer_unmask_interrupt();

#endif

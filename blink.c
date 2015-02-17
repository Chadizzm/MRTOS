#include "gpio.h"
#include "nvic.h"
#include "timer.h"
#include "vector.h"
#include "vtimer.h"

void turn_off_led() {
  gpio_write(GPIOA, 5, 0);
}

int main() {

  gpio_init(GPIOA);
  gpio_init(GPIOB);
  
  gpio_set_mode(GPIOB, 4, GPIO_OUTPUT_MODE);
  gpio_set_mode(GPIOA, 5, GPIO_OUTPUT_MODE);
  gpio_write(GPIOB, 4, 1);
  gpio_write(GPIOA, 5, 1);

  vtimer_t turn_off;
  vtimer_init();
  vtimer_add_timer(&turn_off, turn_off_led, 10);
  while (1)
    ;
  return 0;
}

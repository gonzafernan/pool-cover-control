/**
 * @file key.c
 * @author Gonzalo G. Fernandez
 *
 */

#include "key.h"

#include <stdbool.h>

#include "stm32g0xx_hal_gpio.h"

#define DEBOUNCE_THRESHOLD_TICKS 500

typedef enum {
  DEBOUNCE_NONE = 0,
  DEBOUNCE_OPEN,
  DEBOUNCE_CLOSE,
  DEBOUNCE_TO_OPEN,
  DEBOUNCE_TO_CLOSE,
} debounce_state_t;

static struct {
  GPIO_TypeDef *open_port;
  GPIO_TypeDef *close_port;
  uint16_t open_pin;
  uint16_t close_pin;
  volatile debounce_state_t debounce_state;
  volatile uint32_t ticks;
} key_;

void key_init(GPIO_TypeDef *open_port, uint16_t open_pin,
              GPIO_TypeDef *close_port, uint16_t close_pin) {
  key_.open_port = open_port;
  key_.open_pin = open_pin;
  key_.close_port = close_port;
  key_.close_pin = close_pin;
  key_.debounce_state = DEBOUNCE_NONE;
  key_.ticks = 0;
}

void key_update(void) {
  bool open_state =
      HAL_GPIO_ReadPin(key_.open_port, key_.open_pin) == GPIO_PIN_RESET;
  bool close_state =
      HAL_GPIO_ReadPin(key_.close_port, key_.close_pin) == GPIO_PIN_RESET;
  switch (key_.debounce_state) {
    case DEBOUNCE_OPEN:
      if (!open_state) {
        key_.debounce_state = DEBOUNCE_NONE;
      }
      return;
    case DEBOUNCE_CLOSE:
      if (!close_state) {
        key_.debounce_state = DEBOUNCE_NONE;
      }
      return;
    case DEBOUNCE_TO_OPEN:
      if (!open_state) {
        key_.debounce_state = DEBOUNCE_NONE;
      } else if (HAL_GetTick() - key_.ticks > DEBOUNCE_THRESHOLD_TICKS) {
        key_.debounce_state = DEBOUNCE_OPEN;
      } else {
        // nop
      }
      return;
    case DEBOUNCE_TO_CLOSE:
      if (!close_state) {
        key_.debounce_state = DEBOUNCE_NONE;
      } else if (HAL_GetTick() - key_.ticks > DEBOUNCE_THRESHOLD_TICKS) {
        key_.debounce_state = DEBOUNCE_CLOSE;
      } else {
        // nop
      }
      return;
    case DEBOUNCE_NONE:
      if (open_state && !close_state) {
        key_.ticks = HAL_GetTick();
        key_.debounce_state = DEBOUNCE_TO_OPEN;
      } else if (!open_state && close_state) {
        key_.ticks = HAL_GetTick();
        key_.debounce_state = DEBOUNCE_TO_CLOSE;
      } else {
        // nop
      }
      return;
  }
}

key_state_t key_get_state(void) {
  if (key_.debounce_state == DEBOUNCE_OPEN) {
    return KEY_OPEN;
  }
  if (key_.debounce_state == DEBOUNCE_CLOSE) {
    return KEY_CLOSE;
  }
  return KEY_NONE;
}

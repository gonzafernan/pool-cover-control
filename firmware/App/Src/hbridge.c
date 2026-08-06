/**
 * @file hbridge.c
 * @author Gonzalo G. Fernandez
 *
 */

#include "hbridge.h"

static struct {
  GPIO_TypeDef *out1_port;
  GPIO_TypeDef *out2_port;
  GPIO_TypeDef *out3_port;
  GPIO_TypeDef *out4_port;
  uint16_t out1_pin;
  uint16_t out2_pin;
  uint16_t out3_pin;
  uint16_t out4_pin;
} hbridge_;

void hbridge_init(GPIO_TypeDef *out1_port, uint16_t out1_pin,
                  GPIO_TypeDef *out2_port, uint16_t out2_pin,
                  GPIO_TypeDef *out3_port, uint16_t out3_pin,
                  GPIO_TypeDef *out4_port, uint16_t out4_pin) {
  hbridge_.out1_port = out1_port;
  hbridge_.out1_pin = out1_pin;
  hbridge_.out2_port = out2_port;
  hbridge_.out2_pin = out2_pin;
  hbridge_.out3_port = out3_port;
  hbridge_.out3_pin = out3_pin;
  hbridge_.out4_port = out4_port;
  hbridge_.out4_pin = out4_pin;
}

void hbridge_set_state(hbridge_state_t state) {
  switch (state) {
    case HBRIDGE_NONE:
      HAL_GPIO_WritePin(hbridge_.out1_port, hbridge_.out1_pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(hbridge_.out2_port, hbridge_.out2_pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(hbridge_.out3_port, hbridge_.out3_pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(hbridge_.out4_port, hbridge_.out4_pin, GPIO_PIN_RESET);
      return;
    case HBRIDGE_NEGATIVE:
      HAL_GPIO_WritePin(hbridge_.out1_port, hbridge_.out1_pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(hbridge_.out2_port, hbridge_.out2_pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(hbridge_.out3_port, hbridge_.out3_pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(hbridge_.out4_port, hbridge_.out4_pin, GPIO_PIN_SET);
      return;
    case HBRIDGE_POSITIVE:
      HAL_GPIO_WritePin(hbridge_.out1_port, hbridge_.out1_pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(hbridge_.out2_port, hbridge_.out2_pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(hbridge_.out3_port, hbridge_.out3_pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(hbridge_.out4_port, hbridge_.out4_pin, GPIO_PIN_RESET);
      return;
  }
}

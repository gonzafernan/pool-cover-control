/**
 * @file hbridge.h
 * @author Gonzalo G. Fernandez
 *
 */

#ifndef HBRIDGE_H_
#define HBRIDGE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "stm32g0xx_hal.h"

typedef enum {
  HBRIDGE_NONE = 0,
  HBRIDGE_POSITIVE,
  HBRIDGE_NEGATIVE,
} hbridge_state_t;

void hbridge_init(GPIO_TypeDef *out1_port, uint16_t out1_pin,
                  GPIO_TypeDef *out2_port, uint16_t out2_pin,
                  GPIO_TypeDef *out3_port, uint16_t out3_pin,
                  GPIO_TypeDef *out4_port, uint16_t out4_pin);

void hbridge_set_state(hbridge_state_t state);

#ifdef __cplusplus
}
#endif

#endif /* HBRIDGE_H_ */

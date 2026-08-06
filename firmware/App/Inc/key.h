/**
 * @file key.h
 * @author Gonzalo G. Fernandez
 *
 */

#ifndef KEY_H_
#define KEY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "stm32g0xx_hal.h"

typedef enum {
  KEY_NONE = 0,
  KEY_OPEN,
  KEY_CLOSE,
} key_state_t;

void key_init(GPIO_TypeDef *open_port, uint16_t open_pin,
              GPIO_TypeDef *close_port, uint16_t close_pin);
void key_update(void);
key_state_t key_get_state(void);

#ifdef __cplusplus
}
#endif

#endif /* KEY_H_ */

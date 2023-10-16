#ifndef __TARGET_H
#define __TARGET_H

#define HEAP_FREE_SIZE (size_t) (7 * 1024)

#define LED_PORT GPIOC
#define LED_PIN  GPIO13

void target_init(void);

#endif /* __TARGET_H */

#ifndef Virtual_machine_KERNEL_H
#define Virtual_machine_KERNEL_H

#include <stdint.h>

extern int Virtual_machine_compile(FILE *output, FILE *input);
extern int Virtual_machine_load(uint8_t *memory, int32_t msize);
extern int Virtual_machine_run(int32_t **output, int32_t *input);

#endif /* Virtual_machine_KERNEL_H */ 

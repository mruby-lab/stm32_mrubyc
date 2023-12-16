/*
 * mrubyc.c
 *
 *  Created on: Dec 16, 2023
 *      Author: kaz05
 */

#include <stdio.h>
#include "mrubyc.h"
#include "vm.h"
#include "rrt0.h"

extern const uint8_t mrbbuf[];

#define MRBC_MEMORY_SIZE (1024*30)
static uint8_t memory_pool[MRBC_MEMORY_SIZE];

void start_mrubyc(void){
	mrbc_init(memory_pool, MRBC_MEMORY_SIZE);

	if( mrbc_create_task(mrbbuf, 0) != NULL ){
		mrbc_run();
	}
}

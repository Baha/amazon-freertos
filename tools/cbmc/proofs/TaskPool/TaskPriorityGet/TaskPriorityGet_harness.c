#include <stdint.h>

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "tcb.h"

/* FreeRTOS+TCP includes. */
#include "FreeRTOS_IP.h"
#include "FreeRTOS_IP_Private.h"

extern PRIVILEGED_DATA TCB_t * volatile pxCurrentTCB;

void harness()
{
	
	TaskHandle_t xTask = nondet_bool() ? malloc(sizeof(TCB_t)) : NULL;
	pxCurrentTCB = malloc(sizeof(TCB_t));

	uxTaskPriorityGet( xTask );
}

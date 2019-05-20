#include <stdint.h>

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "tcb.h"

/* FreeRTOS+TCP includes. */
#include "FreeRTOS_IP.h"
#include "FreeRTOS_IP_Private.h"

extern void prvInitialiseTaskLists( void );
extern PRIVILEGED_DATA TCB_t * pxCurrentTCB;

void harness()
{
	TaskFunction_t pxTaskCode;
	char * pcName = nondet_bool() ? malloc(16) : NULL;
	const uint32_t ulStackDepth = STACK_DEPTH;
	void * const pvParameters;
	UBaseType_t uxPriority;
	StackType_t * const puxStackBuffer = nondet_bool() ? malloc(sizeof(StackType_t) * ulStackDepth) : NULL;
	StaticTask_t * const pxTaskBuffer =  nondet_bool() ? malloc(sizeof(StaticTask_t)) : NULL;

	pxCurrentTCB = nondet_bool() ? malloc(sizeof(TCB_t)) : NULL;
	prvInitialiseTaskLists();

	if (pcName != NULL)
		pcName[15] = 0;

	xTaskCreateStatic(	pxTaskCode,
						pcName,
						ulStackDepth,
						pvParameters,
						uxPriority,
						puxStackBuffer,
						pxTaskBuffer );
}

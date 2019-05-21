#include <stdint.h>

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "tcb.h"

/* FreeRTOS+TCP includes. */
#include "FreeRTOS_IP.h"
#include "FreeRTOS_IP_Private.h"

void *pvPortMalloc( size_t usWantedSize ) {
	return nondet_bool() ? malloc(usWantedSize) : NULL;
}

void harness()
{
	TaskFunction_t pxTaskCode;
	char * const pcName = nondet_bool() ? malloc(configMAX_TASK_NAME_LEN) : NULL;
	configSTACK_DEPTH_TYPE usStackDepth = STACK_DEPTH;
	void * const pvParameters;
	UBaseType_t const uxPriority;
	TaskHandle_t pxCreatedTask = nondet_bool() ? malloc(sizeof(TaskHandle_t)) : NULL;

	pxCurrentTCB = nondet_bool() ? malloc(sizeof(TCB_t)) : NULL;

	if (pcName != NULL)
		pcName[configMAX_TASK_NAME_LEN - 1] = 0;

	prvInitialiseTaskLists();

	xTaskCreate(pxTaskCode,
				pcName,
				usStackDepth,
				pvParameters,
				uxPriority,
				&pxCreatedTask );
}

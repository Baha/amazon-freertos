#include <stdint.h>

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

/* FreeRTOS+TCP includes. */
#include "FreeRTOS_IP.h"
#include "FreeRTOS_IP_Private.h"

void *port;

void *pvPortMalloc( size_t xWantedSize ) {
	uint8_t byte;
	__CPROVER_assume(byte >= 0 && byte < 2);
	return byte ? malloc(xWantedSize) : NULL;
}

void harness()
{
	TaskFunction_t pxTaskCode;
	char * const pcName;
	configSTACK_DEPTH_TYPE usStackDepth;
	void * const pvParameters;
	UBaseType_t uxPriority;
	TaskHandle_t * const pxCreatedTask;

	// port = malloc(100);
	xTaskCreate(pxTaskCode,
				pcName,		/*lint !e971 Unqualified char types are allowed for strings and single characters only. */
				usStackDepth,
				pvParameters,
				uxPriority,
				pxCreatedTask );
}

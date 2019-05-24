#include <stdint.h>

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

/* FreeRTOS+TCP includes. */
#include "FreeRTOS_IP.h"
#include "FreeRTOS_IP_Private.h"

extern PRIVILEGED_DATA UBaseType_t uxTaskNumber = ( UBaseType_t ) 0U;

void harness()
{
	if (uxTaskNumber == 0)
		return;
	else
		return;
}

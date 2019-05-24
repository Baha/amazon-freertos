#include <stdint.h>

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

/* FreeRTOS+TCP includes. */
#include "FreeRTOS_IP.h"
#include "FreeRTOS_IP_Private.h"

extern PRIVILEGED_DATA static volatile UBaseType_t uxCurrentNumberOfTasks;

void harness()
{
	if (uxCurrentNumberOfTasks > 0)
		return;
	else
		return;
}

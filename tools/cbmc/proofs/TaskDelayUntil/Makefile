H_ENTRY = TaskDelayUntil
H_CBMCFLAGS = --unwind 1  --unwindset xTaskResumeAll.1:5,prvInitialiseTaskLists.0:8 --nondet-static #--unsigned-overflow-check --signed-overflow-check
H_OBJS = $(ENTRY)_harness.goto $(FREERTOS)/lib/FreeRTOS/tasks.goto
H_DEF = #"-DlistLIST_IS_EMPTY(pxList)=pdTRUE" "-DINCLUDE_vTaskDelayUntil=1"
H_INC = "-I$(FREERTOS)/lib/FreeRTOS/"

include ../Makefile.common
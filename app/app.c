/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
 * Generated by GaInOS-TK Studio at 2013-06-15:21-32-23.
 * Don't Modify it by hand.
 * Email: parai@foxmail.com
 * URL: https://github.com/parai/gainos-tk  && http://hi.baidu.com/parai
 */

#include "Os.h"
#include <stdio.h>


TASK(vTaskSender)
{
    /* Add your task special code here, but Don't delete this Task declaration.*/
    printf("vTaskSender is running.\r\n");
    ActivateTask(ID_vTaskMainFunction);
    Schedule();
    (void)TerminateTask();
}

TASK(vTaskReceiver)
{
    /* Add your task special code here, but Don't delete this Task declaration.*/
    printf("vTaskReceiver is running.\r\n");
    (void)TerminateTask();
}

TASK(vTaskMainFunction)
{
    /* Add your task special code here, but Don't delete this Task declaration.*/
    printf("vTaskMainFunction is running.\r\n");
    (void)TerminateTask();
}
ALARM(vAlarmSender)
{
    /* Alarm Type: Task, you still can add your special code here.*/
    (void)ActivateTask(ID_vTaskSender);
}
ALARM(vAlarmReceiver)
{
    /* Alarm Type: Task, you still can add your special code here.*/
    (void)ActivateTask(ID_vTaskReceiver);
}
ALARM(vAlarmMainFunction)
{
    /* Alarm Type: Task, you still can add your special code here.*/
    (void)ActivateTask(ID_vTaskMainFunction);
}
            
void StartupHook(void)
{
    /* Add Code Here */
    (void)SetRelAlarm(ID_vAlarmReceiver,50,10);
	(void)SetRelAlarm(ID_vAlarmSender,100,200);
	(void)SetRelAlarm(ID_vAlarmMainFunction,200,1); //so cyclic 1 Ticks = 4ms
	
	(void)ActivateTask(0xFF);
	(void)TerminateTask();
}

void ShutdownHook(StatusType Error)
{
    /* Add Code Here */
}

void PreTaskHook(void)
{
    /* Add Code Here */
}

void PostTaskHook(void)
{
    /* Add Code Here */
}
//---------------------------
LOCAL char* l_error_name_table[] = 
{
    "E_OK",
    "E_OS_ACCESS",
    "E_OS_CALLEVEL",
    "E_OS_ID",
    "E_OS_LIMIT",
    "E_OS_NOFUNC",
    "E_OS_RESOURCE",
    "E_OS_STATE",
    "E_OS_VALUE",
};
LOCAL char* l_service_id_name_table[] =
{
    "ActivateTask",
    "TerminateTask",
    "ChainTask",
    "Schedule",
    "GetTaskID",
    "GetTaskState",
    "GetAlarmBase",
    "GetAlarm",
    "SetRelAlarm",
    "SetAbsAlarm",
    "CancelAlarm",
    "SetEvent",
    "ClearEvent",
    "GetEvent",
    "WaitEvent",
    "GetResource",
    "ReleaseResource",
    "StartOS",
    "ShutdownOS",
};
void ErrorHook(StatusType Error)
{
    printf("%s : %s\r\n",l_error_name_table[Error],l_service_id_name_table[OSErrorGetServiceId()]);
}

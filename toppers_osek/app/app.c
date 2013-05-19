
/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
 * Generated by GaInOS-TK Studio at 2013-05-12:15-51-52. 
 * This is a template for "app.c", you can add your application code here.
 */
#include <stdio.h>
#include "kernel.h"

TASK(vTaskInit)
{
    /* Add your task special code here, but Don't delete this Task declaration.*/
    printf("vTaskInit is running.\r\n");
    SetRelAlarm(ID_vAlarmSender,100,500);
    SetAbsAlarm(ID_vAlarmReceiver,200,500);
    SetRelAlarm(ID_vAlarmMainFunction,300,500);
    (void)ActivateTask(ID_vTaskSender);
    (void)ActivateTask(ID_vTaskReceiver);
    (void)TerminateTask();
}

TASK(vTaskSender)
{
    /* Add your task special code here, but Don't delete this Task declaration.*/
    printf("vTaskSender is running.\r\n");
    GetResource(RES_SCHEDULER);
    SetEvent(ID_vTaskReceiver,1);
    ReleaseResource(RES_SCHEDULER);
    (void)TerminateTask();
}

TASK(vTaskReceiver)
{
    /* Add your task special code here, but Don't delete this Task declaration.*/
    printf("vTaskReceiver is running.\r\n");
    WaitEvent(1);
    ClearEvent(1);
    (void)TerminateTask();
}

TASK(vTaskMainFunction)
{
    /* Add your task special code here, but Don't delete this Task declaration.*/
    printf("vTaskMainFunction is running.\r\n");
    (void)TerminateTask();
}

TASK(vTaskIdle)
{
    /* Add your task special code here, but Don't delete this Task declaration.*/
	for(;;);
    (void)TerminateTask();
}

ALARMCALLBACK(vAlarmSender)
{
    /* Alarm Type: Task, you still can add your special code here.*/
    (void)ActivateTask(ID_vTaskSender);
}
ALARMCALLBACK(vAlarmReceiver)
{
    /* Alarm Type: Task, you still can add your special code here.*/
    (void)ActivateTask(ID_vTaskReceiver);
}
ALARMCALLBACK(vAlarmMainFunction)
{
    /* Alarm Type: Task, you still can add your special code here.*/
    (void)ActivateTask(ID_vTaskMainFunction);
}

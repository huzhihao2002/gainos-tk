
/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
 * Generated by GaInOS-TK Studio at 2013-05-19:10-21-53.
 * Don't Modify it by hand.
 */
#include "osek_os.h"
#include "osek_cfg.h"
#include "knl_task.h"
#include "knl_alarm.h"
#include "knl_event.h"
#include <stdio.h>
GenTaskStack(vTaskInit,1024);
GenTaskStack(vTaskSender,1024);
GenTaskStack(vTaskReceiver,1024);
GenTaskStack(vTaskMainFunction,1024);
GenTaskStack(vTaskIdle,1024);
EXPORT const T_GTSK	knl_gtsk_table[cfgOSEK_TASK_NUM] =
{
	GenTaskInfo(vTaskInit,5,1024,AUTOSTART,INVALID_EVENT),
	GenTaskInfo(vTaskSender,6,1024,0,INVALID_EVENT),
	GenTaskInfo(vTaskReceiver,6,1024,0,ID_vTaskReceiverEvent),
	GenTaskInfo(vTaskMainFunction,4,1024,0,INVALID_EVENT),
	GenTaskInfo(vTaskIdle,10,1024,AUTOSTART,INVALID_EVENT),
};

EXPORT const AlarmBaseType knl_almbase_table[cfgOSEK_COUNTER_NUM]=
{
	GenAlarmBaseInfo(30000,1,10), /* vSystemCounter */
};

EXPORT const T_GALM knl_galm_table[cfgOSEK_ALARM_NUM]=
{
	GenAlarmInfo(vAlarmSender,vSystemCounter),
	GenAlarmInfo(vAlarmReceiver,vSystemCounter),
	GenAlarmInfo(vAlarmMainFunction,vSystemCounter),
};

EXPORT const PRI knl_gres_table[cfgOSEK_RESOURCE_NUM]=
{
	/* ceilpri */ 1,  /* RES_SCHEDULER */
};


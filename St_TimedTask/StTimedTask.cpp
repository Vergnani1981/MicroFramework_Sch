/*
 * StTimedTask.cpp
 *
 *  Created on: May 30, 2025
 *      Author: Vergnani
 */

#include "StTimedTask.h"

/**
 * Costructor of St_TimedTask Class
 */
St_TimedTask::St_TimedTask(uint16_t u16_TaskTimeout, uint16_t u16_TaskCode, enable_state_t isISRtaskenable) {
	// TODO Auto-generated constructor stub
	u16_TaskTimeout =  u16_TaskTimeout;
	u16_TaskCode = u16_TaskCode;

	isenable = enable_state_t::NOT_ENABLE; // ?? MEGLIO INIZALIZATORE

	isISRtaskenable = isISRtaskenable;

	tmrCounter = 0;
}

/**
 * De-costructor of St_TimedTask Class
 */
St_TimedTask::~St_TimedTask() {
	// TODO Auto-generated destructor stub
}

/**
 * Method TaskSetEnablest
 * Description: This method Enable Task
 */
void St_TimedTask::TaskSetEnablest(enable_state_t en)
{
	isenable = en;
}

/**
 * Method TaskGetEnableSt
 * Description: This method returns enable state. It could return ENABLED or NOT_ENABLED
 */
enable_state_t St_TimedTask::TaskGetEnableSt()
{
	return isenable;
}

/**
 * Method TaskGetEnableIsrSt
 * Description: This method return enabled state of 1m second task
 */
enable_state_t St_TimedTask::TaskGetEnableIsrSt()
{
	return isISRtaskenable;
}

/**
 * Method TimerCounterUp
 * Description: This method implemnts loop for initializing every timedTask
 */
void St_TimedTask::TimerCounterUp()
{
	tmrCounter++;
}

/**
 * Method TimerCounterReset
 * Description: This method implemnts loop for initializing every timedTask
 */
void St_TimedTask::TimerCounterReset()
{
	tmrCounter = 0;
}

/**
 * Method TimedTaskSchedulerTaskInit
 * Description: This method return timer counter
 */
uint16_t St_TimedTask::GetTimerCounter()
{
	return tmrCounter;
}

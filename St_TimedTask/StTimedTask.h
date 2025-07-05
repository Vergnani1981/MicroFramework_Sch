/*
 * StTimedTask.h
 *
 *  Created on: May 30, 2025
 *      Author: Vergnani
 */

#ifndef CPP_ST_TIMEDTASK_STTIMEDTASK_H_
#define CPP_ST_TIMEDTASK_STTIMEDTASK_H_

#include <stdint.h>
#include "..\System\System.h"

//enum class LockState_t {LOCK, UNLOCK};
enum class enable_state_t {ENABLE, NOT_ENABLE};

class St_TimedTask {
public:
	St_TimedTask(uint16_t u16_TaskTimeout, uint16_t u16_TaskCode, enable_state_t isISRtaskenable);
	virtual ~St_TimedTask();

	virtual void TaskInitialize() = 0; // potrebbe in futuro diventare un void MLoopTask(typMsg msgdata); ...
	virtual void MLoopTask(std::map<std::string, std::shared_ptr<St_TimedTask>> &sch_array) = 0; // potrebbe in futuro diventare un void MLoopTask(typMsg msgdata); ...
	virtual void SysTTask(std::map<std::string, std::shared_ptr<St_TimedTask>> &sch_array) = 0;  // potrebbe in futuro diventare un void SysTTask(typMsg msgdata); ...
	void TaskSetEnablest(enable_state_t);
	enable_state_t TaskGetEnableSt();
	enable_state_t TaskGetEnableIsrSt();

	void TimerCounterUp();
	void TimerCounterReset();
	uint16_t GetTimerCounter();

	uint16_t u16_TaskTimeout;
	uint16_t u16_TaskCode;

private:
	enable_state_t isenable;
	uint16_t tmrCounter;
	enable_state_t isISRtaskenable;
};

#endif /* CPP_ST_TIMEDTASK_STTIMEDTASK_H_ */

/*
 * MattSch.h
 *
 *  Created on: May 30, 2025
 *      Author: Vergnani
 */

#ifndef CPP_MATT_SCH_MATTSCH_H_
#define CPP_MATT_SCH_MATTSCH_H_

#include "..\config\MainSch_conf.h"
#include "..\System\System.h"

class Matt_Sch {
public:
	Matt_Sch();
	virtual ~Matt_Sch();
	void TimedTaskSchedulerTaskInit();
	void TimedTaskSchedulerTimerISRFunction();
	void TimedTaskSchedulerMainLoopFunction();

private:
	uint8_t u8_tmrCounter;
	uint8_t u8_isr_exe_counter;
	//std::array<std::unique_ptr<SCHEDULED_TYPE>,SCHEDULED_MODULES_SIZE> sch_array = SCHEDULED_MODULES_ARRAY; // In questo esempio schedulazione statica, cioè a tempo di compilazione
	std::map<std::string, std::shared_ptr<St_TimedTask>> sch_array = SCHEDULED_MODULES_ARRAY; // In questo esempio schedulazione statica, cioè a tempo di compilazione
};

#endif /* CPP_MATT_SCH_MATTSCH_H_ */

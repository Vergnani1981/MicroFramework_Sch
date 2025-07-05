/*
 * StTimedTask.h
 *
 *  Created on: May 30, 2025
 *      Author: Vergnani
 */

#ifndef CPP_ST_TIMEOUT_STTIMEDTASK_H_
#define CPP_ST_TIMEOUT_STTIMEDTASK_H_

#include <stdint.h>
#include "..\St_timedTask\StTimedTask.h"
#include "..\config\Timeout_conf.h"

#define TIMER_START(x,y)      TimeoutTask::Timers_start(x, y)
#define TIMER_STOP(x)         TimeoutTask::Timers_stop(x)
#define TIMER_STATE(x)        TimeoutTask::Timers_get_state(x)
#define TIMER_IS_ELAPSED(x)   TimeoutTask::Timers_get_state(x) == Timeout_State_t::ELAPSED

enum class Timeout_State_t{
    NOT_ACTIVE,
    RUNNING,
    STOPPED,
    ELAPSED
};

enum class Timers TIMEOUT_LIST;

struct TimerSW {
	Timers id;
	uint8_t arrayidx;
    Timeout_State_t state;
    uint32_t count;
    uint32_t value;
};


class TimeoutTask : public St_TimedTask {
public:
	using St_TimedTask::St_TimedTask;
	virtual ~TimeoutTask();

	void TaskInitialize() override; // potrebbe in futuro diventare un void MLoopTask(typMsg msgdata); ...
	void MLoopTask(std::map<std::string, std::shared_ptr<St_TimedTask>> &sch_array) override; // potrebbe in futuro diventare un void MLoopTask(typMsg msgdata); ...
	void SysTTask(std::map<std::string, std::shared_ptr<St_TimedTask>> &sch_array)  override;  // potrebbe in futuro diventare un void SysTTask(typMsg msgdata); ...

	static void Timers_start(Timers, uint32_t);
	static void Timers_stop(Timers);
	static Timeout_State_t Timers_get_state(Timers);

private:
	static TimerSW Timers_list[(uint8_t)Timers::TIMEOUT_LIST_SIZE];

};

#endif /* CPP_ST_TIMEDTASK_STTIMEDTASK_H_ */

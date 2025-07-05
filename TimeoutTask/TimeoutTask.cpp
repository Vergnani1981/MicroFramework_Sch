/*
 * StTimedTask.cpp
 *
 *  Created on: May 30, 2025
 *      Author: Vergnani
 */

#include "..\config\MattSch_conf.h"

TimeoutTask::~TimeoutTask()
{
	// TODO Auto-generated destructor stub
}

/**
 * Method TaskInitialize
 * Description: This method initiale Timeout task
 */
void TimeoutTask::TaskInitialize()
{
	for (int u8idx = 0; u8idx < static_cast<int>(Timers::TIMEOUT_LIST_SIZE); ++u8idx)
	{
		Timers_list[u8idx].id = static_cast<Timers>(u8idx);
		Timers_list[u8idx].arrayidx = u8idx;
		Timers_list[u8idx].state = Timeout_State_t::NOT_ACTIVE;
		Timers_list[u8idx].count = 0;
		Timers_list[u8idx].value = 0;
	}
}

/**
 * Method MLoopTask
 * Description: This method run on every timeout period. Inside this method is implemented the real behavior of the task
 * @param std::map<std::string, std::shared_ptr<St_TimedTask>> &sch_array. List of every active TimedTask loaded in the system_manager
 */
void TimeoutTask::MLoopTask(std::map<std::string, std::shared_ptr<St_TimedTask>> &sch_array)
{

}

/**
 * Method SysTTask
 * Description: This method run on every 1m.
 */
void TimeoutTask::SysTTask(std::map<std::string, std::shared_ptr<St_TimedTask>> &sch_array)
{
	for (int u8idx = 0; u8idx < static_cast<int>(Timers::TIMEOUT_LIST_SIZE); ++u8idx)
    {
        if(Timeout_State_t::RUNNING == Timers_list[u8idx].state)
        {
            Timers_list[u8idx].count++;
        }

        if(Timers_list[u8idx].count >= Timers_list[u8idx].value)
        {
            Timers_list[u8idx].state = Timeout_State_t::ELAPSED;
        }
    }
}

/**
 * Method Timers_start
 * Description: This method Enable Task
 * @param Timers timer
 * @param uint32_t value
 */
void TimeoutTask::Timers_start(Timers timer, uint32_t value)
{
	int idx = static_cast<int>(timer);

   if(Timeout_State_t::RUNNING != Timers_list[idx].state)
   {
       Timers_list[idx].state = Timeout_State_t::RUNNING;
       Timers_list[idx].value = value;
       Timers_list[idx].count = 0;
   }
}

/**
 * Method Timers_stop
 * Description: This method Enable Task
 * @param Timers timer
 */
void TimeoutTask::Timers_stop(Timers timer)
{
	int idx = static_cast<int>(timer);
    Timers_list[idx].state = Timeout_State_t::STOPPED;
}

/**
 * Method Timers_get_state
 * Description: This method Enable Task
 * @param Timers timer
 */
Timeout_State_t TimeoutTask::Timers_get_state(Timers timer)
{
	Timeout_State_t ret;

	int idx = static_cast<int>(timer);

	ret = Timers_list[idx].state;

    return ret;
}

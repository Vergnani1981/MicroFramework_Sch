/*
 * MattSch.cpp
 *
 *  Created on: May 30, 2025
 *      Author: Vergnani
 */

#include "MattSch.h"
#include "StTimedTask.h"

enum class Scheduler_States_t {TASK_ENABLE_EVAL,\
						   TRANS_TO_MAINLOOP,\
						   MAINL_LOOP_EXE,\
						   TIMER_ISR_EXE,\
						   TRANS_TO_ENABLE_EVAL
						   };

Scheduler_States_t States;

/**
 * Costructor of Matt_Scheudler Class
 */
Matt_Sch::Matt_Sch() {
	// TODO Auto-generated constructor stub
	u8_tmrCounter = 0;
	States = Scheduler_States_t::TASK_ENABLE_EVAL;
}

/**
* De-costructor of Matt_Scheudler Class
 */
Matt_Sch::~Matt_Sch() {
	// TODO Auto-generated destructor stub
}

/**
 * Method TimedTaskSchedulerTaskInit
 * Description: This method implemnts loop for initializing every timedTask
 */
void Matt_Sch::TimedTaskSchedulerTaskInit()
{
	for(auto& [nome,task] : sch_array)
	{
		task->TaskInitialize();
	}

}

/**
 * Method TimedTaskSchedulerTaskInit
 * Description: This method implemnts loop for initializing every timedTask
 */
void Matt_Sch::TimedTaskSchedulerTimerISRFunction()
{
    u8_tmrCounter++;

	for (auto& [nome,task] : sch_array)
	{
		task->TimerCounterUp();
	}

    switch(States)
    {
    	case Scheduler_States_t::TASK_ENABLE_EVAL:
        	for (auto& [nome,task] : sch_array)
        	{
        		if ( (task->TaskGetEnableSt() == enable_state_t::NOT_ENABLE) && ((task->GetTimerCounter() >= task->u16_TaskTimeout) == 0))
        		{
        			task->TaskSetEnablest(enable_state_t::ENABLE);
        			task->TimerCounterReset();
        		}
        	}

            if(u8_tmrCounter >= SCHEDULED_ISR_TICKS)
            {
            	States = Scheduler_States_t::TIMER_ISR_EXE;
            	u8_isr_exe_counter = 0;
            }

            //if(u8_tmrCounter >= SCHEDULED_MAIN_TICKS){}

    	break;

    	case Scheduler_States_t::MAINL_LOOP_EXE:
    		//Qui non deve fare nulla;
    		//Deve solo attendere
    	break;

    	case Scheduler_States_t::TIMER_ISR_EXE:
    		u8_isr_exe_counter++;

    		for(auto& [nome,task] : sch_array)
    		{
    			if(task->TaskGetEnableIsrSt() == enable_state_t::ENABLE)
    			{
    				task->SysTTask(sch_array);
    			}
    		}

    		if(u8_isr_exe_counter == SCHEDULED_MAIN_TICKS)
    		{
    			States = Scheduler_States_t::MAINL_LOOP_EXE;
    			u8_isr_exe_counter = 0;
    			break;
    		}

    		States = Scheduler_States_t::TRANS_TO_ENABLE_EVAL;
    	break;

    	case Scheduler_States_t::TRANS_TO_ENABLE_EVAL:
    		States = Scheduler_States_t::TASK_ENABLE_EVAL;
    	break;

    	default:

    	break;

    }
}

/**
 * Method TimedTaskSchedulerTaskInit
 * Description: This method implemnts loop for initializing every timedTask
 */
void Matt_Sch::TimedTaskSchedulerMainLoopFunction()
{
	enable_state_t u8_taskSts;

    //for (u8_idx=0; u8_idx < SCHEDULED_MODULES_SIZE; u8_idx++)
	if(States == Scheduler_States_t::MAINL_LOOP_EXE)
	{
		for(auto& [nome,task] : sch_array)
		{
			u8_taskSts = task->TaskGetEnableSt();

			if(enable_state_t::ENABLE == u8_taskSts)
			{
				task->TaskSetEnablest(enable_state_t::NOT_ENABLE);
				task->MLoopTask(sch_array);
			}
		}

		States = Scheduler_States_t::TRANS_TO_ENABLE_EVAL;
	}
}

/*
 * MettSch_cong.h
 *
 *  Created on: May 30, 2025
 *      Author: Vergnani
 */

#ifndef CPP_MATT_SCH_CONFIG_MATTSCH_CONF_H_
#define CPP_MATT_SCH_CONFIG_MATTSCH_CONF_H_
// Moidules Include file here
#include "StTimedTask.h"
#include "StProvaTask.h"
#include "..\TimeoutTask\TimeoutTask.h"
#include "..\ProvoneTask\ProvoneTask.h"
// End module Include

#define MAX_INTER16 65200


/*#define SCHEDULED_MODULES_ARRAY {          	\
									std::make_unique<St_ProvaTask>(MAX_INTER16,3, enable_state_t::ENABLE),\
									std::make_unique<St_ProvaTask>(200,3, enable_state_t::NOT_ENABLE),\
									std::make_unique<St_ProvaTask>(400,5, enable_state_t::NOT_ENABLE)\
								}*/

#define SCHEDULED_MODULES_ARRAY {          	\
									{"Timeout",std::make_shared<TimeoutTask>(MAX_INTER16,3, enable_state_t::ENABLE)},\
									{"St_ProvaTask",std::make_shared<St_ProvaTask>(100,3, enable_state_t::ENABLE)}\
								}

#define SCHEDULED_MODULES_SIZE 2

#define SCHEDULED_MAIN_TICKS  10 //40
#define SCHEDULED_ISR_TICKS   8

#endif /* CPP_MATT_SCH_CONFIG_MATTSCH_CONF_H_ */

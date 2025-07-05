/*
 * FiniteStateMachine.cpp
 *
 *  Created on: Jun 5, 2025
 *      Author: Vergnani
 */

#include "FiniteStateMachine.h"

template <typename S_enum> FiniteStateMachine <S_enum>:: FiniteStateMachine() {
	// TODO Auto-generated constructor stub
	FSM_Init();
}

template <typename S_enum> FiniteStateMachine <S_enum>::~FiniteStateMachine() {
	// TODO Auto-generated destructor stub
}

template <typename S_enum> void FiniteStateMachine <S_enum>::SetState(S_enum state)
{
	FSM_On_exit_state();

	this.state = state;

	FSM_On_enter_state();
}

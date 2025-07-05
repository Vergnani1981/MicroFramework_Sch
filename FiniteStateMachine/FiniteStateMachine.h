/*
 * FiniteStateMachine.h
 *
 *  Created on: Jun 5, 2025
 *      Author: Vergnani
 */

#ifndef CPP_FINITESTATEMACHINE_FINITESTATEMACHINE_H_
#define CPP_FINITESTATEMACHINE_FINITESTATEMACHINE_H_

template <typename S_enum> class FiniteStateMachine {
public:
	FiniteStateMachine();
	virtual ~FiniteStateMachine();

	virtual void FSM_Handler() = 0;
	virtual void FSM_On_enter_state() = 0;
	virtual void FSM_On_exit_state() = 0;

	void SetState(S_enum);

protected:
	S_enum state;
	virtual void FSM_Init();
};

#endif /* CPP_FINITESTATEMACHINE_FINITESTATEMACHINE_H_ */

#pragma once
#include "Transitions.h"

#include <string>

class NondeterministicFiniteAutomaton
{
public:
	bool ReadNFA();
	void PrintNFA();
	void PrintTransitionsAndStates();

public:
	void CreateNewInitialStateS();
	void CreateNewFinalStateF();
	std::string getTheStateToBeDeleted();

	void DeleteSelectedState(std::string stateToErase);
	void EraseTransitonsDeletedState(std::vector<std::string> inTransitions, std::vector<std::string> outTransitions, std::string stateToErase);

public:
	Transitions GetTransitions();
	std::vector<std::string> GetStates();

private:
	bool CheckParanthesisForSymbols(std::string transitionSymbol);
	
private:
	std::vector<std::string> m_states; 
	std::string m_alphabet; 
	std::string m_initialState; 
	std::vector<std::string> m_finalStates;
	Transitions m_transitions;
};

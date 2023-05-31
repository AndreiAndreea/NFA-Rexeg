#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "NonDeterministicFiniteAutomaton.h"

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	NondeterministicFiniteAutomaton NFA;
	if (NFA.ReadNFA())
	{
		NFA.PrintNFA();
		std::cout << std::endl << std::endl;

	
		SetConsoleTextAttribute(hConsole, 6);
		std::cout << "1. Create new inital and final states S and F." << std::endl;
		SetConsoleTextAttribute(hConsole, 7);
		NFA.CreateNewInitialStateS();
		NFA.CreateNewFinalStateF();
		NFA.PrintNFA();
		std::cout << std::endl << std::endl;


		SetConsoleTextAttribute(hConsole, 6);
		std::cout << "2. Reducing the states by priority( inTrnasitions*outTransitions minim,!no loops included!),"
			<< std::endl << "until there are only S and F left ." << std::endl;
		SetConsoleTextAttribute(hConsole, 7);
		while (NFA.GetStates().size() > 2)
		{
			std::string stateToDelete = NFA.getTheStateToBeDeleted();
			SetConsoleTextAttribute(hConsole, 2);
			std::cout << "State to be deleted: " << stateToDelete << std::endl;
			SetConsoleTextAttribute(hConsole, 7);
			NFA.DeleteSelectedState(stateToDelete);
			NFA.PrintTransitionsAndStates();
			std::cout << "--------------------------------------------------------------" << std::endl << std::endl;
		}

		
		auto automaton = NFA.GetTransitions().GetDeltaFunction();
		auto regularExpression = automaton.begin()->first.second;
		SetConsoleTextAttribute(hConsole, 13);
		std::cout << "Regular expression : ";
		SetConsoleTextAttribute(hConsole, 11);
		std::cout << regularExpression << std::endl;
		SetConsoleTextAttribute(hConsole, 7);
	}

	return 0;
}
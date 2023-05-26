#include "../include/Addition.h"
#include "../include/Substraction.h"
#include "../include/Multiplication.h"
#include "../include/Division.h"
#include "../include/Exponentiation.h"
#include "../include/Logarithm.h"
#include "../include/NaturalLogarithm.h"
#include "../include/MyCalculator.h"
#include"../include/Root.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
int main() {

	MyCalculator calculator;
	calculator.Manual();
	std::string users_input;
	while (1)
	{
		std::cout << "enter operation/instruction: ";
		std::cout << '\n';
		std::getline(std::cin, users_input);
		if (users_input == "history")
			calculator.Print_history();
		else if (users_input == "end")
		{
			std::cout << "program is closing";
			break;
		}
		else if (users_input == "manual")
			calculator.Manual();
		else
			calculator.Solve(users_input);

	}
}
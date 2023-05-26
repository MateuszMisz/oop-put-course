#include "../include/Addition.h"
#include "../include/Substraction.h"
#include "../include/Multiplication.h"
#include "../include/Division.h"
#include "../include/Exponentiation.h"
#include "../include/Logarithm.h"
#include "../include/NaturalLogarithm.h"
#include "../include/MyCalculator.h"
#include "../include/Root.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
void MyCalculator::Manual()  {
	std::cout << "Rules of input:\n";
	std::cout << "1.In non Integer numbers use '.', not ','\n";
	std::cout << "2.For division use'\\', for raising to power use '^', for multiplication use'*'\n";
	std::cout << "3.Operations usign +,-,\\,*,^, should look like this:'a + b'/ 'name_of_operation a b'- remember about spaces!\n";
	std::cout << "4.Logarithm of b to base a must be entered like this 'log a b'\n";
	std::cout << "5.Natural logarithm of b looks like this:'ln b'\n";
	std::cout << "6.If you want to use the result of last operation, instead of one number type 'M'(all other rules stays same\n";
	std::cout << "7. Negative numbers look like this: '-a'- dont use bracelets\n";
	std::cout << "8.To print all calculations you have already done type 'history'\n";
	std::cout << "9.To see this instruction later, enter 'manual'\n";
}
void MyCalculator::Print_history() {
	if (history.empty())
		std::cout << "You haven't done any calculations yet";
	else
		for (OperationInterface* x : history)
			x->Print();
}
void MyCalculator::Add_to_history(OperationInterface* calculation) {
	history.push_back(calculation);
}
std::string MyCalculator::Memory(std::string operation)  {
	if (history.empty())
	{
		throw 7;
	}
	std::string m = history.back()->Result();
	int m_pos = operation.find("M");
	std::string new_operation = operation.substr(0, m_pos) + m + operation.substr(m_pos + 1);
	return new_operation;

}
void MyCalculator::Solve(std::string operation) {

	char sign = 'a';
	std::stringstream ss;
	std::string a;
	std::string b;
	std::string o;
	std::string tmp;
	if (operation.find("M") != -1)
	{
		try {
			operation = Memory(operation);
		}
		catch (int err_nr)
		{
			std::cout << "You haven't done any calculations yet\n";
		}
	}
	ss << operation;
	ss >> a;
	ss >> o;
	if (a != "ln")
		ss >> b;

	if (a == "log")
	{
		tmp = a;
		a = o;

		o = tmp;
		sign = 'l';
	}
	else if (a == "ln")
	{
		tmp = a;
		b = o;
		o = tmp;
		sign = 'n';

	}
	else
		sign = o[0];
	char type_a, type_b;

	OperationInterface* calculation;
	if (a.find_first_of(".") == -1)
		type_a = 'i';
	else
		type_a = 'd';
	if (b.find_first_of(".") == -1)
		type_b = 'i';
	else
		type_b = 'd';
	switch (sign) {
	case '+':
		calculation = new Addition(operation, type_a, type_b);
		Add_to_history(calculation->Solve(a, b));
		history.back()->Print();
		break;
	case '-':
		calculation = new Substraction(operation, type_a, type_b);
		Add_to_history(calculation->Solve(a, b));
		history.back()->Print();
		break;
	case'*':
		calculation = new Multiplication(operation, type_a, type_b);
		Add_to_history(calculation->Solve(a, b));
		history.back()->Print();
		break;
	case'/':
		try {
			calculation = new Division(operation, type_a, type_b);
			Add_to_history(calculation->Solve(a, b));
			history.back()->Print();
		}
		catch (int err_nr) {
			if (err_nr == 0)
				std::cout << "You can not divide by 0" << std::endl;
		}
		break;
	case'^':
		try {
			calculation = new Exponentiation(operation, type_a, type_b);
			Add_to_history(calculation->Solve(a, b));
			history.back()->Print();
		}
		catch (int err_nr) {
			if (err_nr == 1)
				std::cout << "You can not raise negative numbers to non-integer power with this calculator\n";
			else if (err_nr == 2)
				std::cout << "0^0 is an undefined symbol and you can not calculate it\n";
		}
		break;
	case 'l':
		if (operation.find("log") != 0)
		{
			std::cout << "incorrect input, try again\n";
			return;
		}
		try {
			calculation = new Logarithm(operation, type_a, type_b);
			Add_to_history(calculation->Solve(a, b));
			history.back()->Print();
		}
		catch (int err_nr) {
			if (err_nr == 4)
				std::cout << "both numbers in logarithm must be different than 0\n";
			else if (err_nr == 5)
				std::cout << "both numbers in logarithm must be greater than 0\n";
			else if (err_nr == 6)
				std::cout << "logarithms base must be different than 1\n";
		}
		break;
	case 'n':
		if (operation.find("ln") != 0)
		{
			std::cout << "incorrect input, try again\n";
			return;
		}
		try {
			calculation = new NaturalLogarithm(operation, type_a, type_b);
			Add_to_history(calculation->Solve(a, b));
			history.back()->Print();
		}
		catch (int err_nr) {
			if (err_nr == 4)
				std::cout << "both numbers in logarithm must be different than 0\n";
			else if (err_nr == 5)
				std::cout << "both numbers in logarithm must be greater than 0\n";
			else if (err_nr == 6)
				std::cout << "logarithms base must be different than 1\n";
		}
		break;
	/*case 'r'://commented due to weird error:( 
		try {
			calculatio=new Root(operation,type_a,type_b);
			Add_to_history(calculation->Solve(a, b));
			history.back()->Print();
		}
		catch (int err_nr) {
			if (err_nr == 10)
				std::cout << "power of the root must be integer value\n";
			else if (err_nr == 11)
				std::cout << "power of the root cant be equal to 0\n";
			else if (err_nr == 12)
				std::cout << "You cant take even power root of negative base\n";
		}
		break;*/
	default:
		std::cout << "zle wczytany znak ";
	}
}
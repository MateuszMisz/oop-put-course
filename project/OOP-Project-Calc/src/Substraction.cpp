#include "../include/Substraction.h"
#include "BasicOperations.h"
#include "OperationInterface.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

Substraction::Substraction(std::string op, char t1, char t2,std::string result) {
	this->operation = op;
	this->type_a = t1;
	this->type_b = t2;
	this->result = result;
}
OperationInterface* Substraction::Solve(std::string a, std::string b) {
	std::string res;
	if (type_a == 'i' && type_b == 'i')
		res = std::to_string(std::stoi(a) - std::stoi(b));
	else
		res = std::to_string(std::stod(a) - std::stod(b));
	return new Substraction(operation, type_a, type_b, res);
}
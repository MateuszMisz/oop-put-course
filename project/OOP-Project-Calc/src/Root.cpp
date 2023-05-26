#include "../include/Root.h"
#include "BasicOperations.h"
#include "OperationInterface.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

Root::Root(std::string op, char t1, char t2, std::string result) {
	this->operation = op;
	this->type_a = t1;
	this->type_b = t2;
	this->result = result;
}
OperationInterface* Root::Solve(std::string a, std::string b) {
	std::string res;
	if (type_a != 'i')
		throw 10;
	if(std::stoi(a)==0)
		throw 11;
	if (llround(std::stod(a)) % 2 == 0 && std::stod(b) < 0)
		throw 12;
	if (type_b == 'i' && std::stoi(b) == 0)
		res = 0;
	else if (std::stod(b) < 0)
		res = std::to_string(-pow(-std::stod(b), 1 / std::stod(a)));
	else
		res = std::to_string(pow(std::stod(b), 1 / std::stod(a)));
	return new Root(operation, type_a, type_b, res);
}
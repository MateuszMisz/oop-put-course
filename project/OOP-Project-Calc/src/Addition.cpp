#include "Addition.h"
#include "BasicOperations.h"
#include "OperationInterface.h"
#include "../include/Addition.h"
#include "../include/BasicOperations.h"
#include "../include/OperationInterface.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
Addition::Addition(std::string op, char t1, char t2,std::string result) {
	this->operation = op;
	this->type_a = t1;
	this->type_b = t2;
	this->result = result;
}
OperationInterface* Addition::Solve(std::string a, std::string b) {
	std::string res;
	if (type_b == 'i' && type_a == 'i')
		res = std::to_string(std::stoi(a) + std::stoi(b));
	else if (type_b == 'd' || type_a == 'd')
		res = std::to_string((double)((double)std::stod(a) + (double)std::stod(b)));
	return new Addition(operation, type_a, type_b, res);
}
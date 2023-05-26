#include "../include/Division.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
Division::Division(std::string op, char t1, char t2,std::string result) {
	this->operation = op;
	this->type_a = t1;
	this->type_b = t2;
	this->result = result;
}
OperationInterface* Division::Solve(std::string a, std::string b) {
	std::string res;
	if (type_b == 'i')
		if (std::stoi(b) == 0)
			throw 0;
	res = std::to_string(std::stod(a) / std::stod(b));
	return new Division(operation, type_a, type_b, res);
}
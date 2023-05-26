#include "../include/NaturalLogarithm.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
NaturalLogarithm::NaturalLogarithm(std::string op, char t1, char t2,std::string result) {
	this->operation = op;
	this->type_a = t1;
	this->type_b = t2;
	this->result = result;
}
OperationInterface* NaturalLogarithm::Solve(std::string a, std::string b) {
	std::string res;
	if (type_b == 'i')
	{
		if (std::stoi(b) < 0)
			throw 5;
		if (std::stoi(b) == 0)
			throw 4;
	}
	res = std::to_string(log(std::stod(b)));
	return new NaturalLogarithm(operation, type_a, type_b, res);
}
#include "../include/Logarithm.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
Logarithm::Logarithm(std::string op, char t1, char t2,std::string result) {
	this->operation = op;
	type_a = t1;
	type_b = t2;
	this->result = result;
}
OperationInterface* Logarithm::Solve(std::string a, std::string b)
{
	std::string res;
	if (type_b == 'i')
		if (std::stoi(b) == 0)
			throw 4;
	if (type_a == 'i')
	{
		if (std::stoi(a) == 1)
			throw 6;
		if (std::stoi(a) == 0)
			throw 4;
		if (std::stoi(a) == 10)
			res = std::to_string(log10(std::stod(b)));
		else if (std::stoi(a) == 2)
			res = std::to_string(log2(std::stod(b)));
		else
			res = std::to_string(log2(std::stod(b)) / log2(std::stod(a)));

	}

	if (std::stod(a) < 0 || std::stod(b) < 0)
		throw 5;
	if (type_b == 'd')
		res = std::to_string(logb(std::stod(b)) / logb(std::stod(a)));
	return new Logarithm(operation, type_a, type_b, res);



}
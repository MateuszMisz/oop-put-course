#include "../include/Exponentiation.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
Exponentiation::Exponentiation(std::string op, char t1, char t2,std::string result) {
	this->operation = op;
	this->type_a = t1;
	this->type_b = t2;
	this->result = result;
}
OperationInterface* Exponentiation::Solve(std::string a, std::string b) {
	std::string res;
	if (std::stod(a) < 0 && type_b == 'd')
		throw 1;
	if (type_a == 'i' && type_b == 'i' && std::stoi(a) == 0 && std::stoi(b) == 0)
		throw 2;
	else if (type_a == 'i' && std::stoi(a) == 0)
		res = std::to_string(0);
	else
		res = std::to_string(pow(std::stod(a), std::stod(b)));
	return new Exponentiation(operation, type_a, type_b, res);

}
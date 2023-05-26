#pragma once
#include "BasicOperations.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
class Multiplication :public BasicOperations {
public:
	Multiplication(std::string op, char t1, char t2, std::string result = "\0");
	OperationInterface* Solve(std::string a, std::string b)override;
};
#pragma once
#include "BasicOperations.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

class Root :public BasicOperations {
public:
	Root(std::string op, char t1, char t2, std::string result = "\0");
	OperationInterface* Solve(std::string a, std::string b)override;
};
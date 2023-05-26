#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include "BasicOperations.h"
class Division :public BasicOperations {
public:
	Division(std::string op, char t1, char t2, std::string result = "\0");
	OperationInterface* Solve(std::string a, std::string b)override;
};
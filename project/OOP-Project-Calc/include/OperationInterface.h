#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
class OperationInterface {
public:
	virtual OperationInterface* Solve(std::string a, std::string b) = 0;
	virtual void Print() = 0;
	virtual std::string Result() = 0;
};
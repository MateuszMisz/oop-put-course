#pragma once
#include "OperationInterface.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

class Calculator {
public:
	virtual void Solve(std::string operation) = 0;
	virtual void Add_to_history(OperationInterface* calculation) = 0;
	virtual void Print_history() = 0;
	virtual std::string Memory(std::string operation) = 0;
	virtual void Manual() = 0;
};
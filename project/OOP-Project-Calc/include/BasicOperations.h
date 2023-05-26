#pragma once
#include "OperationInterface.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
class BasicOperations :public OperationInterface {
protected:
	std::string operation;
	std::string result;
	char type_a;
	char type_b;
public:
	void Print()override;
	std::string Result()override;
};
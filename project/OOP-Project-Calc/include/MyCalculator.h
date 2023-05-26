#pragma once
#include "Calculator.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

class MyCalculator : public Calculator {
	std::vector<OperationInterface*>history;

public:
	void Manual()override;
	void Print_history()override;
	void Add_to_history(OperationInterface* calculation)override;
	std::string Memory(std::string operation)override;
	void Solve(std::string operation)override;
};
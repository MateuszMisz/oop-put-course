#include "../include/BasicOperations.h"
#include "BasicOperations.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
void BasicOperations::Print() { std::cout << operation << " = " << result << '\n'; }
std::string BasicOperations::Result()  { return result; }
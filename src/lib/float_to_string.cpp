#include "computer.hpp"
#include <iostream>
#include <sstream>

std::string float_to_string(double value) {
    ostringstream oss;
    oss.precision(7);
    oss << defaultfloat << value;
    return oss.str();
}
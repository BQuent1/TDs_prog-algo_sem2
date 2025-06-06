#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <stack>

std::vector<std::string> split_string(std::string const& s);
bool is_floating (std::string const& s);
float npi_evaluate(std::vector<std::string> const& tokens);

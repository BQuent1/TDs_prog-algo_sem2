#pragma once

#include <vector>
#include <string>
#include "token.hpp"

int operator_precedence(Operator op);

bool is_left_associative(Operator op);

std::vector<std::string> split_string(const std::string &s);

std::vector<Token> infix_to_npi_tokens(const std::string &expression);

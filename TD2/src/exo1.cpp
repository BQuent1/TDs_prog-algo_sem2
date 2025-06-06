#include "exo1.hpp"
#include <iostream>
#include <sstream>
#include <iterator>
#include <stack>
#include <vector>
#include <string>
#include <cctype>

std::vector<std::string> split_string(const std::string &s)
{
    std::istringstream in(s);
    return {std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()};
}

bool is_floating(const std::string &s)
{
    bool has_dot = false;
    for (char c : s)
    {
        if (c == '.')
        {
            if (has_dot)
                return false;
            has_dot = true;
        }
        else if (!std::isdigit(c))
        {
            return false;
        }
    }
    return !s.empty();
}

float npi_evaluate(const std::vector<std::string> &tokens)
{
    std::stack<float> stack;
    for (const auto &token : tokens)
    {
        if (is_floating(token))
        {
            stack.push(std::stof(token));
        }
        else if (stack.size() >= 2)
        {
            float b = stack.top();
            stack.pop();
            float a = stack.top();
            stack.pop();
            float result = 0;
            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else if (token == "/")
                result = a / b;
            stack.push(result);
        }
        else
        {
            std::cout << "Erreur: opérateur sans opérandes suffisants" << std::endl;
            return 0;
        }
    }
    if (stack.size() != 1)
    {
        std::cout << "Erreur: expression invalide" << std::endl;
        return 0;
    }
    return stack.top();
}

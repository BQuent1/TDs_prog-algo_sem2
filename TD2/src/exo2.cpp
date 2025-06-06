#include "exo2.hpp"
#include <stack>
#include <iostream>
#include <vector>
#include <string>

Token make_token(float value)
{
    return Token{TokenType::OPERAND, value, Operator::ADD};
}

Token make_token(Operator op)
{
    return Token{TokenType::OPERATOR, 0.0f, op};
}

std::vector<Token> tokenize(const std::vector<std::string> &words)
{
    std::vector<Token> tokens;
    for (const auto &word : words)
    {
        if (word == "+")
            tokens.push_back(make_token(Operator::ADD));
        else if (word == "-")
            tokens.push_back(make_token(Operator::SUB));
        else if (word == "*")
            tokens.push_back(make_token(Operator::MUL));
        else if (word == "/")
            tokens.push_back(make_token(Operator::DIV));
        else
            tokens.push_back(make_token(std::stof(word)));
    }
    return tokens;
}

float npi_evaluate_ex2(const std::vector<Token> &tokens)
{
    std::stack<float> stack;
    for (const auto &token : tokens)
    {
        if (token.type == TokenType::OPERAND)
        {
            stack.push(token.value);
        }
        else if (stack.size() >= 2)
        {
            float b = stack.top();
            stack.pop();
            float a = stack.top();
            stack.pop();
            switch (token.op)
            {
            case Operator::ADD:
                stack.push(a + b);
                break;
            case Operator::SUB:
                stack.push(a - b);
                break;
            case Operator::MUL:
                stack.push(a * b);
                break;
            case Operator::DIV:
                stack.push(a / b);
                break;
            }
        }
        else
        {
            std::cout << "Erreur: opérateur sans assez d'opérandes" << std::endl;
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

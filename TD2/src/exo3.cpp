#include "ex3.hpp"

#include <stack>
#include <sstream>
#include <iterator>
#include <cctype>
#include <iostream>

Token make_token(float value)
{
    return Token{TokenType::OPERAND, value, Operator::ADD};
}

Token make_token(Operator op)
{
    return Token{TokenType::OPERATOR, 0.0f, op};
}

int operator_precedence(Operator op)
{
    switch (op)
    {
    case Operator::ADD:
    case Operator::SUB:
        return 1;
    case Operator::MUL:
    case Operator::DIV:
        return 2;
    case Operator::POW:
        return 3;
    default:
        return 0;
    }
}

bool is_left_associative(Operator op)
{
    return op != Operator::POW;
}

std::vector<std::string> split_string(const std::string &s)
{
    std::istringstream in(s);
    return {std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()};
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
        else if (word == "^")
            tokens.push_back(make_token(Operator::POW));
        else if (word == "(")
            tokens.push_back(make_token(Operator::OPEN_PAREN));
        else if (word == ")")
            tokens.push_back(make_token(Operator::CLOSE_PAREN));
        else
            tokens.push_back(make_token(std::stof(word)));
    }
    return tokens;
}

std::vector<Token> infix_to_npi_tokens(const std::string &expression)
{
    std::vector<std::string> words = split_string(expression);
    std::vector<Token> input = tokenize(words);
    std::vector<Token> output;
    std::stack<Token> op_stack;

    for (const auto &token : input)
    {
        if (token.type == TokenType::OPERAND)
        {
            output.push_back(token);
        }
        else
        {
            if (token.op == Operator::OPEN_PAREN)
            {
                op_stack.push(token);
            }
            else if (token.op == Operator::CLOSE_PAREN)
            {
                while (!op_stack.empty() && op_stack.top().op != Operator::OPEN_PAREN)
                {
                    output.push_back(op_stack.top());
                    op_stack.pop();
                }
                if (!op_stack.empty() && op_stack.top().op == Operator::OPEN_PAREN)
                {
                    op_stack.pop();
                }
            }
            else
            {
                while (!op_stack.empty())
                {
                    Operator top_op = op_stack.top().op;
                    if (top_op == Operator::OPEN_PAREN)
                        break;
                    int prec1 = operator_precedence(token.op);
                    int prec2 = operator_precedence(top_op);
                    if ((prec2 > prec1) || (prec2 == prec1 && is_left_associative(token.op)))
                    {
                        output.push_back(op_stack.top());
                        op_stack.pop();
                    }
                    else
                        break;
                }
                op_stack.push(token);
            }
        }
    }

    while (!op_stack.empty())
    {
        output.push_back(op_stack.top());
        op_stack.pop();
    }

    return output;
}

float npi_evaluate(const std::vector<Token> &tokens)
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
            case Operator::POW:
                stack.push(std::pow(a, b));
                break;
            default:
                break;
            }
        }
        else
        {
            std::cout << "Erreur: opérateur sans assez d'opérandes\n";
            return 0;
        }
    }

    if (stack.size() != 1)
    {
        std::cout << "Erreur: expression invalide\n";
        return 0;
    }

    return stack.top();
}

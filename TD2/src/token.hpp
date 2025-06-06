#pragma once

enum class Operator
{
    ADD,
    SUB,
    MUL,
    DIV,
    POW,
    OPEN_PAREN,
    CLOSE_PAREN
};

enum class TokenType
{
    OPERATOR,
    OPERAND
};

struct Token
{
    TokenType type;
    float value = 0.0f;
    Operator op;
};

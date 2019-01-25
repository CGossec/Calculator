#include "calculator.hh"
#include "lexer.hh"

Calculator::Calculator()
{
    values_ = std::vector<Token>();
    operators_ = std::vector<Token>();
}

Calculator::add_tkn(Token t)
{
    if (t.get_type() == NUMBER)
    {
        values_.push_back(t);
    }
    else if (t.get_type() == LPAR)
    {
        operators_.push_back(t);
    }
    else if (t.get_type() == RPAR)
    {
        while (operators_.back().type != LPAR)
            //pop -> compute -> pushback onto value
    }
}

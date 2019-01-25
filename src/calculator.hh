#ifndef CALCULATOR_HH
#define CALCULATOR_HH
#include <vector>

class Token;

class Calculator
{
public:
    Calculator();
    void clear();
    void add_tkn(const Token t);
    void compute();
private:
    std::vector<Token> values_;
    std::vector<Token> operators_;
};

#endif /* ! CALCULATOR_HH */

#ifndef CALCULATOR_HH
#define CALCULATOR_HH
#include <vector>

class Token;

class Calculator
{
public:
    Calculator();
private:
    std::vector<Token> values_;
    std::vector<Token> operators_;
};

#endif /* ! CALCULATOR_HH */

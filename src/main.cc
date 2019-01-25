#include <iostream>
#include "lexer.hh"
#include "calculator.hh"

void tty()
{
    Calculator calc;
    while (true)
    {
        calc.clear();
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        if (line == "exit" || line[0] == EOF)
            break;
        std::cout << "input is: " << line << "\n";
        Lexer lexer(line);
        while (lexer.has_tokens())
        {
            Token t = lexer.read_tkn();
            calc.add_tkn(t);
        }
        calc.compute();
    }
    return;
}

int main()
{
    tty();
}

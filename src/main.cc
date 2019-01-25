#include <iostream>
#include "shunting_yard.hh"
#include "lexer.hh"

using namespace std;

void tty()
{
    while (true)
    {
        std::string line;
        std::cout << ">";
        getline(std::cin, line);
        if (line == "exit" || line[0] == EOF)
            break;
        std::cout << "input is: " << line << "\n";
        Lexer lexer(line);
        while (lexer.has_tokens())
        {
            Token t = lexer.read_tkn();
        }
    }
    return;
}

int main()
{
    tty();
}

#include "shunting_yard.hh"

void print(std::vector<std::string> line)
{
    unsigned sz = line.size();
    for (unsigned i = 0; i < sz; ++i)
    {
        std::cout << line[i];
    }
}

void tty()
{
    std::vector<std::string> line;
    std::string token;
    while (std::cin >> token)
        line.push_back(token);
    std::cout << "input is: ";
    print(line);
    std::cout << "\nShunting yard returned: " << shunting_yard(line);
}

int shunting_yard(std::vector<std::string> str)
{
    if (str.empty())
    {
        return 0;
    }
    return -1; // FIXME
}
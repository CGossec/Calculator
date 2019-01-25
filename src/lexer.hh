#ifndef LEXER_HH
#define LEXER_HH

#include <iostream>
#include <vector>

enum type
{
    NUMBER,
    OPERATOR,
    LPAR,
    RPAR
};

class Token
{
public:
    Token(const std::string s, const enum type t)
        : val_{s}
        , type_{t}
    {}
    enum type get_type() const
    {
        return type_;
    }
    const std::string get_val() const
    {
        return val_;
    }
    int precedence() const
    {
        if (val_ == "^")
            return 4;
        if (val_ == "*" || val_ == "/")
            return 3;
        if (val_ == "+" || val_ == "-")
            return 2;
        return -1;
    }
    bool left_assoc() const
    {
        if (val_ == "*" || val_ == "/" || val_ == "+" || val_ == "-")
            return true;
        return false;
    }
private:
    const std::string val_;
    enum type type_;
};

class Lexer
{
public:
    Lexer();
    Lexer(const std::string str);
    Token read_tkn();
    void set_src(std::string str);
    bool has_tokens() const;
private:
    std::string read_number(std::string src);
    std::string src_;
    unsigned cursor_;
};

#endif /* ! LEXER_HH */
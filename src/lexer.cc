#include "lexer.hh"
#include <string>

Lexer::Lexer()
{
    src_ = "";
    cursor_ = 0;
}

Lexer::Lexer(const std::string str)
{
    src_ = str;
    cursor_ = 0;
}

void Lexer::set_src(const std::string src)
{
    src_ = src;
    cursor_ = 0;
}

std::string Lexer::read_number(std::string src)
{
    int tmp = cursor_;
    while (isdigit(src[cursor_]))
    {
        cursor_++;
    }
    return src.substr(tmp, cursor_ - tmp);
}

std::ostream& operator<<(std::ostream& os, const Token& t)
{
    if (t.get_type() == OPERATOR)
        os << "{OP";
    else if (t.get_type() == NUMBER)
        os << "{NUMBER";
    else if (t.get_type() == LPAR || t.get_type() == RPAR)
        os << "{PAR";
    os << ", ";
    os << t.get_val() << "}";
    return os;
}

Token Lexer::read_tkn()
{
    while (src_[cursor_] == ' ' || src_[cursor_] == '\t')
    {
        cursor_++;
    }
    if (isdigit(src_[cursor_]))
    {
        return Token(read_number(src_), NUMBER);
    }
    else if (src_[cursor_] == '(')
    {
        cursor_++;
        return Token("(", LPAR);
    }
    else if (src_[cursor_] == ')')
    {
        cursor_++;
        return Token(")", RPAR);
    }
    else
    {
        return Token(std::string(1, src_[cursor_++]), OPERATOR);
    }
}

bool Lexer::has_tokens() const
{
    return cursor_ != src_.size();
}

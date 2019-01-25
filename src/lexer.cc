#include "lexer.hh"
#include <string>

Lexer::Lexer()
{
    src_ = "";
}

Lexer::Lexer(const std::string str)
{
    src_ = str;
}

void Lexer::set_src(const std::string src)
{
    src_ = src;
}

std::string Lexer::read_number(std::string src, unsigned& cursor_)
{
    int tmp = cursor_;
    while (isdigit(src[cursor_]))
    {
        cursor_++;
    }
    return src.substr(tmp, cursor_);
}

Token Lexer::read_tkn()
{
    while (src_[cursor_] == ' ' || src_[cursor_] == '\t')
    {
        cursor_++;
    }
    if (isdigit(src_[cursor_]))
    {
        return Token(read_number(src_, cursor_), NUMBER);
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
        cursor_++;
        return Token(std::string(1, src_[cursor_]), OPERATOR);
    }
}

bool Lexer::has_tokens() const
{
    return cursor_ != src_.size();
}

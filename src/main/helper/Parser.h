#pragma once

#include <deque>
#include <regex>
#include "../database/TokenDatabase.h"
#include "../database/Token.h"

class Parser {
public:
    static bool IsNumber(const Token &t) {
        return std::regex_match(t, std::regex{"[[:digit:]]+"});
    }

    static bool IsOperator(const Token &t) {
        return TokenDatabase::IsOperatorConfiguredCheckByToken(t);
    }

    static bool IsOpenParenthesis(const Token &t) {
        return t == "(";
    }

    static bool IsCloseParenthesis(const Token &t) {
        return t == ")";
    }

    static std::deque<TokenMaster> Parse(const std::vector<Token> &tokens);

    static std::deque<TokenMaster> parsedToken;

    static bool IsParenthesis(const Token &t) {
        return (IsOpenParenthesis(t) || IsCloseParenthesis(t));
    }
};

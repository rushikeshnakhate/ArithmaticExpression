#include <iostream>
#include "TokenDatabase.h"


std::unordered_map<TokenName, TokenInformation> TokenDatabase::tokenMapWithPrecedenceAssociativity{
        {TokenName::Multiply,              {PrecedenceType::Four,    Associativity::LeftToRight}},
        {TokenName::Divide,                {PrecedenceType::Four,    Associativity::LeftToRight}},
        {TokenName::Plus,                  {PrecedenceType::Three,   Associativity::LeftToRight}},
        {TokenName::Minus,                 {PrecedenceType::Three,   Associativity::LeftToRight}},
        {TokenName::OpenParenthesisToken,  {PrecedenceType::Highest, Associativity::NoAssociativity}},
        {TokenName::CloseParenthesisToken, {PrecedenceType::Highest, Associativity::NoAssociativity}}
};

int TokenDatabase::GetPrecedenceByToken(const Token &token) {
    return tokenMapWithPrecedenceAssociativity[GetTokenName(token)].precedence;
}

Associativity TokenDatabase::GetAssociativityByToken(const Token &token) {
    return tokenMapWithPrecedenceAssociativity[GetTokenName(token)].associativity;
}


Precedence TokenDatabase::GetPrecedenceByTokenName(const TokenName &tokenName) {
    return tokenMapWithPrecedenceAssociativity[tokenName].precedence;
}

Associativity TokenDatabase::GetAssociativityByTokenName(const TokenName &tokenName) {
    return tokenMapWithPrecedenceAssociativity[tokenName].associativity;
};


bool TokenDatabase::IsOperatorConfiguredCheckByToken(const Token &token) {
    return tokenMapWithPrecedenceAssociativity.count(GetTokenName(token));
}

bool TokenDatabase::IsOperatorConfiguredCheckByTokenName(const TokenName &tokenName) {
    return tokenMapWithPrecedenceAssociativity.count(tokenName);
}

TokenType TokenDatabase::GetTokenType(const Token &token) {
    try {
        if (token == "(")
            return TokenType::OpenParenthesis;
        else if (token == ")")
            return TokenType::CloseParenthesis;
        else if (IsOperatorConfiguredCheckByToken(token)) {
            return TokenType::Operator;
        } else {
            throw std::runtime_error(" Unsupported token" + token);
        }
    } catch (std::exception &ex) {
        std::cout << __func__ << ex.what();
    }
};

TokenName TokenDatabase::GetTokenName(const Token &token) {
    try {
        if (token == "(")
            return TokenName::OpenParenthesisToken;
        else if (token == ")")
            return TokenName::CloseParenthesisToken;
        else if (token == "*")
            return TokenName::Multiply;
        else if (token == "/")
            return TokenName::Divide;
        else if (token == "+")
            return TokenName::Plus;
        else if (token == "-")
            return TokenName::Minus;
        else {
            throw std::runtime_error("TokenDatabase Unsupported token Name" + token);
        }

    } catch (std::exception &ex) {
        std::cout << __func__ << ex.what();
    }
};

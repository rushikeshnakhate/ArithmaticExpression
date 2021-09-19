#pragma once

#include <string>
#include <unordered_map>
#include "Token.h"

struct TokenInformation {
    Precedence precedence;
    Associativity associativity;
};

using Database = std::unordered_map<TokenName, TokenInformation>;

class TokenDatabase {
public:
    static Database tokenMapWithPrecedenceAssociativity;

    static Precedence GetPrecedenceByToken(const Token &token);

    static Associativity GetAssociativityByToken(const Token &token);

    static Precedence GetPrecedenceByTokenName(const TokenName &tokenName);

    static Associativity GetAssociativityByTokenName(const TokenName &tokenName);

    static bool IsOperatorConfiguredCheckByToken(const Token &token);

    static bool IsOperatorConfiguredCheckByTokenName(const TokenName &tokenName);

    static TokenType GetTokenType(const Token &token);

    static TokenName GetTokenName(const Token &token);

};
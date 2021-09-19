#include <iostream>
#include "Parser.h"

std::deque<TokenMaster> Parser::Parse(const std::vector<Token> &tokens) {
    std::deque<TokenMaster> parsedToken;
    try {
        for (auto &token : tokens) {
            if (token.empty()) {
                throw std::runtime_error("Empty token provided token=" + token);
            }
            if (IsNumber(token)) {
                parsedToken.emplace_back(token, TokenType::Number, TokenName::Digit);
            } else if (IsOperator(token)) {
                parsedToken.emplace_back(token, TokenDatabase::GetTokenType(token),
                                         TokenDatabase::GetTokenName(token),
                                         TokenDatabase::GetPrecedenceByToken(token),
                                         TokenDatabase::GetAssociativityByToken(token));
            } else {
                throw std::runtime_error("Parser:Invalid token provided token=" + token);
            }
        }
        return parsedToken;
    } catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
}
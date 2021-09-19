#pragma  once

#include <string>
#include <utility>

enum TokenType {
    Number,
    Operator,
    OpenParenthesis,
    CloseParenthesis,
    Unknown
};

enum PrecedenceType {
    Three,
    Four,
    NoPrecedence,
    Highest
};

enum TokenName {
    Multiply,
    Divide,
    Plus,
    Minus,
    OpenParenthesisToken,
    CloseParenthesisToken,
    Digit
};


enum Associativity {
    LeftToRight,
    RightToLeft,
    NoAssociativity
};



using Token = std::string;
using Precedence = int;


struct TokenMaster {
    Token token;
    TokenType type;
    TokenName tokenName;
    Precedence precedence;
    Associativity associativity;


    TokenMaster(const Token &_token,
                const TokenType &_type,
                const TokenName &_tokenName,
                const Precedence &_precedence = -1,
                const Associativity &_associativity = Associativity::LeftToRight)
            : token(_token), type(_type),
              tokenName(_tokenName),
              precedence(_precedence),
              associativity(_associativity) {}

    TokenMaster &operator=(const TokenMaster &obj) {
        this->token = obj.token;
        this->type = obj.type;
        this->tokenName = obj.tokenName;
        this->precedence = obj.precedence;
        this->associativity = obj.associativity;
    }

    TokenMaster(const TokenMaster &obj) {
        this->token = obj.token;
        this->type = obj.type;
        this->tokenName = obj.tokenName;
        this->associativity = obj.associativity;
        this->precedence = obj.precedence;
    }
};
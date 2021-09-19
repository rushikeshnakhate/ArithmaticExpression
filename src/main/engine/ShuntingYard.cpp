#include <stdexcept>
#include <iostream>
#include "ShuntingYard.h"
#include "../helper/Parser.h"


//Below functions can be refactored
//For each token type we can have a dedicated functions/lambda,class and code
//duplication can be avoided
std::deque<TokenMaster> ShuntingYard::Process(const std::deque<TokenMaster> &tokens) {
    try {
        for (const auto &token : tokens) {
            switch (token.type) {
                case TokenType::Number:
                    //if the token is a number: put it into the output queue
                    queue.push_back(token);
                    break;
                case TokenType::Operator: {
                    // If the token is operator, o1, then:
                    // while there is an operator token,
                    if (!stack.empty()) {
                        auto tokenAtTopOfStack = stack.back();
                        if (!Parser::IsParenthesis(tokenAtTopOfStack.token)) {
                            if ((token.associativity == Associativity::LeftToRight &&
                                 token.precedence <= tokenAtTopOfStack.precedence)
                                || (token.associativity == Associativity::RightToLeft &&
                                    token.precedence < tokenAtTopOfStack.precedence)) {
                                stack.pop_back();
                                queue.push_back(tokenAtTopOfStack);
                            }
                        }
                    }
                    stack.push_back(token);
                    break;
                }

                case TokenType::OpenParenthesis: {
                    stack.push_back(token);
                    break;
                }

                case TokenType::CloseParenthesis: {
                    bool match = false;
                    while (!stack.empty() && stack.back().type != TokenType::OpenParenthesis) {
                        queue.push_back(stack.back());
                        stack.pop_back();
                        match = true;
                    }
                    // pop the left parenthesis from the operator stack and discard it
                    stack.pop_back();

                    if (!match && stack.empty()) {
                        throw std::runtime_error("Missing closing Parenthesis");
                    }
                }
                    break;
                default:
                    throw std::runtime_error("Parser:Invalid token provided token=" + token.tokenName);
            }
        }
        while (!stack.empty()) {
            if (stack.back().type == TokenType::OpenParenthesis) {
                throw std::runtime_error("Parenthesis are missing in expression");
            }
            queue.push_back(std::move(stack.back()));
            stack.pop_back();
        }
    } catch (std::exception &ex) {
        std::cout << "ShuntingYard=" << ex.what() << std::endl;
    }
    return queue;
}


#pragma once

#include <string>
#include "../database/Token.h"
#include <deque>

class Tree {
public:
    virtual bool CreateTree(std::deque<TokenMaster> queue) = 0;

    virtual int SolveExpression(std::deque<TokenMaster> &queue) = 0;

    virtual bool TraverseTree() = 0;
};
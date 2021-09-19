#pragma once

#include <deque>
#include <vector>
#include "../database/Token.h"
#include "CoreEngine.h"

class ShuntingYard : public CoreEngine {
    std::deque<TokenMaster> queue;
    std::vector<TokenMaster> stack;
public:
    std::deque<TokenMaster> Process(const std::deque<TokenMaster> &tokens) override;
};



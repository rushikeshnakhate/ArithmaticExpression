#pragma once


class CoreEngine {
public:
    virtual std::deque <TokenMaster> Process(const std::deque <TokenMaster> &tokens) = 0;
};
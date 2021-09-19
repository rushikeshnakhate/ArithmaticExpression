#pragma once

#include <gtest/gtest.h>
#include "../../main/engine/ShuntingYard.h"
#include<memory>

class ShuntingYardTest : public ::testing::Test {
public:
    std::unique_ptr<ShuntingYard> coreEngine;
    std::string actual = "";

    void SetUp() override {
        coreEngine = std::make_unique<ShuntingYard>();
    }

};


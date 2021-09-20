#pragma once

#include <gtest/gtest.h>
#include "../../main/tree/Tree.h"
#include "../../main/tree/BinaryTree.h"

class BinaryTest : public ::testing::Test {
public:
    std::unique_ptr <Tree> tree = std::make_unique<BinaryTree>();
};

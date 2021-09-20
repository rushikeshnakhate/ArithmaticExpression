#include "BinaryTreeTest.h"
#include "../../main/engine/ShuntingYard.h"
#include "../../main/helper/Parser.h"
#include "../../main/helper/Utils.h"

TEST_F(BinaryTest, binar_tree_is_created) {
    std::deque<TokenMaster> queue =
            {{"1", TokenType::Number,   TokenName::Digit, PrecedenceType::NoPrecedence, Associativity::LeftToRight},
             {"2", TokenType::Number,   TokenName::Digit, PrecedenceType::NoPrecedence, Associativity::LeftToRight},
             {"+", TokenType::Operator, TokenName::Plus,  PrecedenceType::Three,        Associativity::LeftToRight}
            };
    tree->CreateTree(queue);
    tree->TraverseTree();
    EXPECT_EQ(tree->SolveExpression(queue), 3);
}

#include <gtest/gtest.h>
#include "../../main/helper/Utils.h"

TEST(ExpressionsIntoTokens, input_strings_is_parsed) {
    std::string expressions = "((15/(7-1)+1";
    std::vector<std::string> expectedUntokenize{"(", "(", "15", "/", "(", "7", "-", "1", ")", "+", "1"};
    EXPECT_EQ(expectedUntokenize, Utils::ExpressionsIntoTokens(expressions));
}

TEST(ExpressionsIntoTokens, input_strings_is_parse1d) {
    std::string expressions = "((15/(7-(1+1)))-3)-(2+(1+1))";
    std::vector<std::string> expectedUntokenize{"(", "(", "15", "/", "(", "7", "-", "(", "1", "+", "1", ")", ")", ")",
                                                "-", "3", ")", "-", "(", "2", "+", "(", "1", "+", "1", ")", ")"};
    EXPECT_EQ(expectedUntokenize, Utils::ExpressionsIntoTokens(expressions));
}
#include "ShuntingYardTest.h"
#include "../../main/engine/ShuntingYard.h"
#include "../../main/helper/Parser.h"
#include "../../main/helper/Utils.h"
#include<queue>


auto BuildActual = [](const auto &collection, std::string &actual) {
    for_each(collection.begin(), collection.end(), [&](const TokenMaster &t) {
        if (actual.empty())
            actual = t.token;
        else
            actual += "," + t.token;
    });
};

TEST_F(ShuntingYardTest, shuting_yard_alogrithm_works) {
    auto queue = coreEngine->Process(Parser::Parse({"1", "+", "2"}));
    std::string expectedAlgoOutput = "1,2,+";
    BuildActual(queue, actual);
    EXPECT_EQ(expectedAlgoOutput, actual);
}

TEST_F(ShuntingYardTest, shuting_yard_alogrithm_works_for) {
    std::vector<std::string> untokenize{"(", "(", "15", "/", "(", "7", "-", "(", "1", "+", "1", ")", ")", ")",
                                        "*", "-", "3", ")", "-", "(", "2", "+", "(", "1", "+", "1", ")", ")"};
    auto queue = coreEngine->Process(Parser::Parse(untokenize));
    std::string expectedAlgoOutput = "15,7,1,1,+,-,/,*,3,-,2,1,1,+,+,-";
    BuildActual(queue, actual);
    EXPECT_EQ(expectedAlgoOutput, actual);
}

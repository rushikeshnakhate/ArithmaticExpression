
#include "ParserTest.h"

#include "../../main/helper/Utils.h"
#include "../../main/helper/Parser.h"

TEST_F(ParserTest, invalid_token_reported) {
    std::vector<std::string> untokenize{"^^"};
    auto queue = Parser::Parse(untokenize);
    EXPECT_FALSE(queue.empty());
}

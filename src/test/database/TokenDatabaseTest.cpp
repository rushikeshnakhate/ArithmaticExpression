#include "TokenDatabaseTest.h"
#include "../../main/database/TokenDatabase.h"

TEST_F(TokenDatabaseTest, when_test_database_initialized_data_is_loaded) {
EXPECT_TRUE(TokenDatabase::IsOperatorConfiguredCheckByTokenName(TokenName::Minus));
}

TEST_F(TokenDatabaseTest, token_assosiativity_recorded) {
EXPECT_EQ(TokenDatabase::GetAssociativityByTokenName(TokenName::CloseParenthesisToken),
        Associativity::NoAssociativity);
}

TEST_F(TokenDatabaseTest, token_precedence_recorded) {
EXPECT_EQ(TokenDatabase::GetPrecedenceByTokenName(TokenName::CloseParenthesisToken), PrecedenceType::Highest);
}

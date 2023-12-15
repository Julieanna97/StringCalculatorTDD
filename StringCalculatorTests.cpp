#include <gtest/gtest.h>

extern "C"
{
    #include "StringCalculator.h"

}

class StringCalculatorTest : public testing::Test
{
    protected:
        void SetUp() override
        {
            /* Without this the Tests could break */
        }

};

TEST_F(StringCalculatorTest, IfInputIsEmptyShouldReturnZero)
{
    // ARRANGE
    const char input[] = "";

    // ACT
    CALCULATION_RESULT result = Add(input);

    // ASSERT

    ASSERT_EQ(result, RESULT_EMPTY_STRING);

}

TEST_F(StringCalculatorTest, IfInputHasValuesMoreThanOneShouldReturnResultIsValid)
{
	// ARRANGE
    const char input[] = "1,2,3,4,5";

    // ACT
    CALCULATION_RESULT result = Add(input);

    // ASSERT

    ASSERT_EQ(result, RESULT_VALID);

}

TEST_F(StringCalculatorTest, IfInputHasOnlyOneValueShouldReturnNumber)
{
	// ARRANGE
    const char input[] = "1";

    // ACT
    CALCULATION_RESULT result = Add(input);

    // ASSERT

    ASSERT_EQ(result, RESULT_ONE_INPUT);

}

TEST_F(StringCalculatorTest, IfInputHasInvalidValueShouldReturnInvalidNumber)
{
	// ARRANGE
    const char input[] = "a";

    // ACT
    CALCULATION_RESULT result = Add(input);

    // ASSERT

    ASSERT_EQ(result, RESULT_INVALID_NUMBER);

}
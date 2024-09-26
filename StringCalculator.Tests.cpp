#include <gtest/gtest.h>
#include "StringCalculator.h"

TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
    int expectedresult = 0;
    std::string input = "";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
    int expectedresult = 0;
    std::string input = "0";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);
    ASSERT_EQ(result, expectedresult);
}

// Test for two numbers
TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
    int expectedresult = 3;
    std::string input = "1,2";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);
    ASSERT_EQ(result, expectedresult);
}

// Test for exception with negative numbers
TEST(StringCalculatorAddTests, ExpectExceptionForNegativeNumbers) {
    ASSERT_THROW({
        std::string input = "-1,2";
        StringCalculator objUnderTest;
        objUnderTest.add(input);
    }, std::runtime_error);
}

TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
    int expectedresult = 6;
    std::string input = "1\n2,3";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
    int expectedresult = 1;
    std::string input = "1,1001";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
    int expectedresult = 3;
    std::string input = "//;\n1;2";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);
    ASSERT_EQ(result, expectedresult);
}

// Additional test cases
TEST(StringCalculatorAddTests, ExpectSumWithMultipleCustomDelimiters) {
    int expectedresult = 6;
    std::string input = "//[***]\n1***2***3";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectExceptionForMultipleNegativeNumbers) {
    ASSERT_THROW({
        std::string input = "-1,-2,3";
        StringCalculator objUnderTest;
        objUnderTest.add(input);
    }, std::runtime_error);
}

TEST(StringCalculatorAddTests, ExpectExceptionMessageForMultipleNegatives) {
    try {
        std::string input = "-1,-2,3";
        StringCalculator objUnderTest;
        objUnderTest.add(input);
    } catch (const std::runtime_error& e) {
        ASSERT_STREQ(e.what(), "negatives not allowed: -1,-2");
    }
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiterAndNewlines) {
    int expectedresult = 10;
    std::string input = "//[;]\n1;2\n3;4";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);
    ASSERT_EQ(result, expectedresult);
}

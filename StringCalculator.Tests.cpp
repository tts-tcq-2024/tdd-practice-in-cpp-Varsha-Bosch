#include <gtest/gtest.h>
#include "StringCalculator.h"

TEST(StringCalculator, ExpectZeroForEmptyInput) {
    int expectedresult = 0;
    std::string input = "";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculator, ExpectZeroForSingleZero) {
    int expectedresult = 0;
    std::string input = "0";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculator, ExpectSumForTwoNumbers) {
    int expectedresult = 3;
    std::string input = "1,2";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculator, ExpectExceptionForNegativeNumbers) {
    ASSERT_THROW({
        std::string input = "-1,2";
        StringCalculator objUnderTest;
       objUnderTest.add(input);
        }, std::runtime_error);
}

TEST(StringCalculator, ExpectSumWithNewlineDelimiter) {
    int expectedresult = 6;
    std::string input = "1\n2,3";
     StringCalculator objUnderTest;
    int result =objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculator, IgnoreNumbersGreaterThan1000) {
    int expectedresult = 1;
    std::string input = "1,1001";
    StringCalculator objUnderTest;
    int result =objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculator, ExpectSumWithCustomDelimiter) {
    int expectedresult = 3;
    std::string input = "//;\n1;2";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculator, ExpectZeroForEmptyInput) {
    int expectedresult = 0;
    std::string input = "";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculator, ExpectZeroForSingleZero) {
    int expectedresult = 0;
    std::string input = "0";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculator, ExpectSumForTwoNumbers) {
    int expectedresult = 3;
    std::string input = "1,2";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculator, ExpectExceptionForNegativeNumbers) {
    ASSERT_THROW({
        std::string input = "-1,2";
        StringCalculator objUnderTest;
       objUnderTest.add(input);
        }, std::runtime_error);
}

TEST(StringCalculator, ExpectSumWithNewlineDelimiter) {
    int expectedresult = 6;
    std::string input = "1\n2,3";
     StringCalculator objUnderTest;
    int result =objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculator, IgnoreNumbersGreaterThan1000) {
    int expectedresult = 1;
    std::string input = "1,1001";
    StringCalculator objUnderTest;
    int result =objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculator, ExpectSumWithCustomDelimiter) {
    int expectedresult = 3;
    std::string input = "//;\n1;2";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

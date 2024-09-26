#include "StringCalculator.h"
#include <algorithm>
#include <numeric>
#include <sstream>
#include <stdexcept>

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    // Extract the delimiter and sanitize the input
    std::string delimiter = getDelimiter(numbers);
    std::string modifiedNumbers = sanitizeInput(numbers, delimiter);

    // Split the numbers into a list
    std::vector<int> numberList = convertToNumbers(modifiedNumbers, delimiter);

    // Check for and handle negative numbers
    checkAndHandleNegatives(numberList);

    // Sum the numbers, ignoring values greater than 1000
    return sumIgnoringLargeNumbers(numberList);
}

// Get the delimiter, defaulting to "," unless a custom one is provided
std::string StringCalculator::getDelimiter(const std::string& numbers) {
    std::string delimiter = ",";
    if (numbers.rfind("//", 0) == 0) {
        delimiter = extractDelimiter(numbers);
    }
    return delimiter;
}

// Replace newline characters with the custom delimiter to sanitize input
std::string StringCalculator::sanitizeInput(const std::string& numbers, const std::string& delimiter) {
    std::string modifiedNumbers = numbers;
    std::string processedNumbers = modifiedNumbers;

    // Remove custom delimiter line if present
    if (numbers.rfind("//", 0) == 0) {
        processedNumbers = modifiedNumbers.substr(modifiedNumbers.find("\n") + 1);
    }

    // Replace newline characters with the custom delimiter
    std::replace(processedNumbers.begin(), processedNumbers.end(), '\n', delimiter[0]);

    return processedNumbers;
}

// Convert the input string to a list of integers, split by the delimiter
std::vector<int> StringCalculator::convertToNumbers(const std::string& modifiedNumbers, const std::string& delimiter) {
    std::vector<std::string> stringTokens = split(modifiedNumbers, delimiter);
    std::vector<int> numberList;

    for (const std::string& token : stringTokens) {
        if (!token.empty()) {
            numberList.push_back(std::stoi(token));
        }
    }
    return numberList;
}

// Check for negative numbers and throw an exception if any are found
void StringCalculator::checkAndHandleNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives = checkForNegatives(numbers);
    if (!negatives.empty()) {
        throw std::runtime_error("negatives not allowed: " + formatNegatives(negatives));
    }
}

// Sum all numbers in the list, ignoring numbers larger than 1000
int StringCalculator::sumIgnoringLargeNumbers(const std::vector<int>& numbers) {
    return std::accumulate(numbers.begin(), numbers.end(), 0, [](int sum, int number) {
        return number <= 1000 ? sum + number : sum;
    });
}

// Find all negative numbers in the list
std::vector<int> StringCalculator::checkForNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(negatives), [](int number) {
        return number < 0;
    });
    return negatives;
}

// Format negative numbers as a comma-separated string for exception messages
std::string StringCalculator::formatNegatives(const std::vector<int>& negatives) {
    if (negatives.empty()) {
        return "";
    }

    return std::accumulate(negatives.begin() + 1, negatives.end(),
        std::to_string(negatives[0]), [](const std::string& a, int b) {
            return a + "," + std::to_string(b);
        });
}

// Extract custom delimiter from the input string
std::string StringCalculator::extractDelimiter(const std::string& numbers) {
    std::string delimiter = ",";
    if (numbers.rfind("//", 0) == 0) {
        size_t newlinePos = numbers.find("\n");
        delimiter = numbers.substr(2, newlinePos - 2);
    }
    return delimiter;
}

// Split the string by the given delimiter
std::vector<std::string> StringCalculator::split(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = 0;

    while ((end = str.find(delimiter, start)) != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
    }
    tokens.push_back(str.substr(start));

    return tokens;
}

#include "StringCalculator.h"
#include <algorithm>
#include <numeric>
#include <sstream>
#include <stdexcept>

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string delimiter = getDelimiter(numbers);
    std::string modifiedNumbers = sanitizeInput(numbers, delimiter);

    std::vector<int> numberList = convertToNumbers(modifiedNumbers, delimiter);

    checkAndHandleNegatives(numberList);

    return sumIgnoringLargeNumbers(numberList);
}

std::string StringCalculator::getDelimiter(const std::string& numbers) {
    std::string delimiter = ",";
    if (numbers.rfind("//", 0) == 0) {
        delimiter = extractDelimiter(numbers);
    }
    return delimiter;
}

std::string StringCalculator::sanitizeInput(const std::string& numbers, const std::string& delimiter) {
    std::string modifiedNumbers = numbers;
    std::replace(modifiedNumbers.begin(), modifiedNumbers.end(), '\n', delimiter[0]);
    return modifiedNumbers;
}

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

void StringCalculator::checkAndHandleNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives = checkForNegatives(numbers);
    if (!negatives.empty()) {
        throw std::runtime_error("negatives not allowed: " + formatNegatives(negatives));
    }
}

int StringCalculator::sumIgnoringLargeNumbers(const std::vector<int>& numbers) {
    return std::accumulate(numbers.begin(), numbers.end(), 0, [](int sum, int number) {
        return number <= 1000 ? sum + number : sum;
    });
}

// Remainder of the methods (no changes needed)

std::vector<int> StringCalculator::checkForNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(negatives), [](int number) {
        return number < 0;
    });
    return negatives;
}

std::string StringCalculator::formatNegatives(const std::vector<int>& negatives) {
    if (negatives.empty()) {
        return "";
    }

    return std::accumulate(negatives.begin() + 1, negatives.end(),
        std::to_string(negatives[0]), [](const std::string& a, int b) {
            return a + "," + std::to_string(b);
        });
}

std::string StringCalculator::extractDelimiter(std::string& numbers) {
    size_t newlinePos = numbers.find("\n");
    std::string delimiter = numbers.substr(2, newlinePos - 2);
    numbers = numbers.substr(newlinePos + 1);  // Remove delimiter line from the numbers string
    return delimiter;
}

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

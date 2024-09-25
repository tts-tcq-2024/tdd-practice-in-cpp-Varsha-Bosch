#include "StringCalculator.h"

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string delimiter = ",";
    std::string modifiedNumbers = numbers;

    // Check for custom delimiter
    if (numbers.rfind("//", 0) == 0) {
        delimiter = extractDelimiter(modifiedNumbers);
    }

    // Replace newline with the delimiter to handle the "\n" case
    std::replace(modifiedNumbers.begin(), modifiedNumbers.end(), '\n', delimiter[0]);

    std::vector<int> numberList = split(modifiedNumbers, delimiter);
    int sum = 0;
    std::vector<int> negatives;

    for (int number : numberList) {
        if (number < 0) {
            negatives.push_back(number);
        }
        if (number <= 1000) { // Ignore numbers greater than 1000
            sum += number;
        }
    }

    if (!negatives.empty()) {
        std::ostringstream oss;
        oss << "negatives not allowed: ";
        for (size_t i = 0; i < negatives.size(); ++i) {
            if (i > 0) oss << ",";
            oss << negatives[i];
        }
        throw std::runtime_error(oss.str());
    }

    return sum;
}

std::vector<int> StringCalculator::split(const std::string& numbers, const std::string& delimiter) {
    std::vector<int> result;
    std::string token;
    size_t start = 0;
    size_t end = numbers.find(delimiter);

    while (end != std::string::npos) {
        token = numbers.substr(start, end - start);
        result.push_back(std::stoi(token));
        start = end + delimiter.length();
        end = numbers.find(delimiter, start);
    }
    
    // Last token
    result.push_back(std::stoi(numbers.substr(start)));

    return result;
}

std::string StringCalculator::extractDelimiter(std::string& numbers) {
    size_t delimiterStart = 2; // Skipping the "//"
    size_t delimiterEnd = numbers.find("\n");

    std::string delimiter = numbers.substr(delimiterStart, delimiterEnd - delimiterStart);
    numbers = numbers.substr(delimiterEnd + 1); // Remove the delimiter part from the numbers

    return delimiter;
}

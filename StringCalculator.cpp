#include "StringCalculator.h"
#include <algorithm> 
#include <numeric>  
#include <sstream>   
#include <stdexcept> 

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string delimiter = ",";
    std::string modifiedNumbers = numbers;

   
    if (numbers.rfind("//", 0) == 0) {
        delimiter = extractDelimiter(modifiedNumbers);
    }

    // Replace newline with the delimiter to handle the "\n" case
    std::replace(modifiedNumbers.begin(), modifiedNumbers.end(), '\n', delimiter[0]);

    std::vector<int> numberList = split(modifiedNumbers, delimiter);

    // Get the list of negative numbers from the pure function
    std::vector<int> negatives = checkForNegatives(numberList);

    // If there are any negative numbers, throw an exception
    if (!negatives.empty()) {
        throw std::runtime_error("negatives not allowed: " + formatNegatives(negatives));
    }

    // Ignore numbers greater than 1000 and return the sum
    return ignoreNumbersGreaterThan1000(numberList);
}

std::vector<int> StringCalculator::checkForNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;

    // Use std::copy_if to collect all negative numbers
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(negatives), [](int number) {
        return number < 0;
    });

    return negatives; // Returning the negatives (empty if none found)
}

std::string StringCalculator::formatNegatives(const std::vector<int>& negatives) {
    if (negatives.empty()) {
        return "";
    }

    // Use std::accumulate to concatenate the negative numbers into a string
    return std::accumulate(negatives.begin() + 1, negatives.end(),
        std::to_string(negatives[0]), [](const std::string& a, int b) {
            return a + "," + std::to_string(b);
        });
}

// Ignore numbers greater than 1000 and return the sum
int StringCalculator::ignoreNumbersGreaterThan1000(const std::vector<int>& numbers) {
    int sum = 0;

    for (int number : numbers) {
        if (number <= 1000) {
            sum += number;
        }
    }
    return sum;
}
std::string StringCalculator::extractDelimiter(std::string& numbers) {
    std::string delimiter = ",";
    
    if (numbers.rfind("//", 0) == 0) {
        size_t newlinePos = numbers.find("\n");
        delimiter = numbers.substr(2, newlinePos - 2);
        numbers = numbers.substr(newlinePos + 1);  // Remove delimiter line from the numbers string
    }
    
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

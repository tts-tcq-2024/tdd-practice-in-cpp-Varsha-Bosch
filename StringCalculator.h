#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& numbers);

private:
    std::string extractDelimiter(std::string& numbers);
    std::vector<std::string> split(const std::string& str, const std::string& delimiter);
    std::vector<int> checkForNegatives(const std::vector<int>& numbers); // Pure function
    int ignoreNumbersGreaterThan1000(const std::vector<int>& numbers);
    std::string formatNegatives(const std::vector<int>& negatives); // New helper function
};

#endif // STRINGCALCULATOR_H

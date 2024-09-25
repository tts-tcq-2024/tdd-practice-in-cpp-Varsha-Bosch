#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <algorithm>

class StringCalculator {
public:
    int add(const std::string& numbers);

private:
    std::vector<int> split(const std::string& numbers, const std::string& delimiter);
    std::string extractDelimiter(std::string& numbers);
    void checkForNegatives(const std::vector<int>& numbers);
    int ignoreNumbersGreaterThan1000(const std::vector<int>& numbers);
    std::string formatNegatives(const std::vector<int>& negatives);
};

#endif // STRINGCALCULATOR_H

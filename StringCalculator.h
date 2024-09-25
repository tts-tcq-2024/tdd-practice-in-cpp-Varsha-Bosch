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
};

#endif // STRINGCALCULATOR_H


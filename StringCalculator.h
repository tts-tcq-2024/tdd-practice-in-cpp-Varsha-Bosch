#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& numbers);

private:
    std::string getDelimiter(const std::string& numbers);
    std::string sanitizeInput(const std::string& numbers, const std::string& delimiter);
    std::vector<int> convertToNumbers(const std::string& modifiedNumbers, const std::string& delimiter);
    void checkAndHandleNegatives(const std::vector<int>& numbers);
    int sumIgnoringLargeNumbers(const std::vector<int>& numbers);

    std::string extractDelimiter(const std::string& numbers);
    bool isCustomDelimiter(const std::string& numbers) const;
    std::string parseCustomDelimiter(const std::string& numbers) const;
    bool isBracketedDelimiter(const std::string& delimiterPart) const;
    std::string extractBracketedDelimiter(const std::string& delimiterPart) const;
    std::vector<int> checkForNegatives(const std::vector<int>& numbers);
    std::string formatNegatives(const std::vector<int>& negatives);
    std::vector<std::string> split(const std::string& str, const std::string& delimiter);
};

#endif // STRINGCALCULATOR_H

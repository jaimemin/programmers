#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

bool isValidNumber(const string& num, int base) 
{
    for (char c : num) 
    {
        if (c < '0' || c > '9') 
        {
            return false;
        }
        
        int digit = c - '0';
        
        if (digit >= base) 
        {
            return false;
        }
    }
    
    return true;
}

int convertToDecimal(const string& num, int base) 
{
    int decimalNumber = 0;
    
    for (char c : num) 
    {
        int digit = c - '0';
        
        decimalNumber = decimalNumber * base + digit;
    }
    
    return decimalNumber;
}

string convertFromDecimal(int number, int base) 
{
    if (number == 0) 
    {
        return "0";
    }
    
    string result = "";
    
    while (number > 0) 
    {
        int digit = number % base;
        
        result += (char)('0' + digit);
        number /= base;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<string> knownExpressions;
    vector<pair<int, string>> missingExpressions;

    int maxDigitUsed = 0;

    for (int i = 0; i < expressions.size(); i++) 
    {
        string expr = expressions[i];
        
        for (char c : expr) 
        {
            if (c >= '0' && c <= '9') 
            {
                int digit = c - '0';
                
                if (digit > maxDigitUsed) 
                {
                    maxDigitUsed = digit;
                }
            }
        }
        
        stringstream ss(expr);
        string operand1, op, operand2, equalSign, result;
        ss >> operand1 >> op >> operand2 >> equalSign >> result;
        
        if (result == "X") 
        {
            missingExpressions.push_back({i, expr});
        } 
        else 
        {
            knownExpressions.push_back(expr);
        }
    }

    int minBase = max(maxDigitUsed + 1, 2);
    vector<int> possibleBases;
    
    for (int base = minBase; base <= 9; base++) 
    {
        bool isValidBase = true;
        
        for (const string expr : knownExpressions) 
        {
            for (char c : expr) 
            {
                if (c >= '0' && c <= '9') 
                {
                    int digit = c - '0';
                    
                    if (digit >= base) 
                    {
                        isValidBase = false;
                        
                        break;
                    }
                }
            }
            
            if (!isValidBase) 
            {
                break;
            }
            
            stringstream ss(expr);
            string operand1, op, operand2, equalSign, result;
            ss >> operand1 >> op >> operand2 >> equalSign >> result;

            if (!isValidNumber(operand1, base) 
                || !isValidNumber(operand2, base) 
                || !isValidNumber(result, base)) 
            {
                isValidBase = false;
                
                break;
            }

            int num1 = convertToDecimal(operand1, base);
            int num2 = convertToDecimal(operand2, base);
            int res = convertToDecimal(result, base);

            if (op == "+") 
            {
                if (num1 + num2 != res) 
                {
                    isValidBase = false;
                    
                    break;
                }
            } 
            else if (op == "-") 
            {
                if (num1 - num2 != res) 
                {
                    isValidBase = false;
                    
                    break;
                }
            } 
            else 
            {
                isValidBase = false;
                
                break;
            }
        }
        
        if (isValidBase) 
        {
            possibleBases.push_back(base);
        }
    }

    for (const auto [index, expr] : missingExpressions) 
    {
        stringstream ss(expr);
        string operand1, op, operand2, equalSign, result;
        ss >> operand1 >> op >> operand2 >> equalSign >> result;
        
        set<string> possibleResults;

        for (int base : possibleBases) 
        {
            bool digitsValid = true;
            
            for (char c : operand1 + operand2) 
            {
                if (c >= '0' && c <= '9') 
                {
                    int digit = c - '0';
                    
                    if (digit >= base) 
                    {
                        digitsValid = false;
                        
                        break;
                    }
                }
            }
            
            if (!digitsValid) 
            {
                continue;
            }
            
            if (!isValidNumber(operand1, base) 
                || !isValidNumber(operand2, base)) 
            {
                continue;
            }

            int num1 = convertToDecimal(operand1, base);
            int num2 = convertToDecimal(operand2, base);
            int res = 0;

            if (op == "+") 
            {
                res = num1 + num2;
            } 
            else if (op == "-") 
            {
                res = num1 - num2;
                
                if (res < 0) 
                {
                    continue;
                }
            } 
            else 
            {
                continue;
            }

            string resStr = convertFromDecimal(res, base);
            bool resultDigitsValid = true;
            
            for (char c : resStr) 
            {
                if (c >= '0' && c <= '9') 
                {
                    int digit = c - '0';
                    
                    if (digit >= base) 
                    {
                        resultDigitsValid = false;
                        
                        break;
                    }
                }
            }
            
            if (!resultDigitsValid) 
            {
                continue;
            }
            
            possibleResults.insert(resStr);
        }

        string filledExpression = operand1 + " " + op + " " + operand2 + " = ";
        
        if (possibleResults.size() == 1) 
        {
            filledExpression += *possibleResults.begin();
        } 
        else 
        {
            filledExpression += "?";
        }

        answer.push_back(filledExpression);
    }

    return answer;
}

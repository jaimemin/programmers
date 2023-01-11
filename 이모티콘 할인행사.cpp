#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int maxEmoticonPlus = 0;
int maxSales = 0;

void calculate(vector<int> &salesRates, vector<vector<int>> &users, vector<int> &emoticons)
{
    int emoticonPlus = 0;
    int sales = 0;
    
    for (vector<int> user : users)
    {
        int temp = 0;
        
        for (int i = 0; i < salesRates.size(); i++)
        {
            if (user[0] > salesRates[i])
            {
                continue;
            }
            
            temp += (emoticons[i] / 100) * (100 - salesRates[i]);
        }
        
        if (temp >= user[1])
        {
            emoticonPlus++;
        }
        else
        {
            sales += temp;
        }
    }
    
    if (maxEmoticonPlus > emoticonPlus)
    {
        return;
    }
    
    if (maxEmoticonPlus == emoticonPlus 
        && maxSales >= sales)
    {
        return;
    }
    
    maxEmoticonPlus = emoticonPlus;
    maxSales = sales;
}

void func(vector<int> salesRates, vector<vector<int>> &users, vector<int> &emoticons)
{
    if (salesRates.size() == emoticons.size())
    {
        calculate(salesRates, users, emoticons);
        
        return;
    }
    
    for (int i = 10; i <= 40; i += 10)
    {
        salesRates.push_back(i);
        func(salesRates, users, emoticons);
        salesRates.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> v;
    
    func(v, users, emoticons);
    
    vector<int> answer;
    answer.push_back(maxEmoticonPlus);
    answer.push_back(maxSales);
    
    return answer;
}

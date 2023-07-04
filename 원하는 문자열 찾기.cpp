#include <string>
#include <vector>
using namespace std;

string getLowerCase(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = s[i] >= 'a' ? s[i] : s[i] - 'A' + 'a';
    }
    
    return s;
}

int solution(string myString, string pat) {
    myString = getLowerCase(myString);
    pat = getLowerCase(pat);
    
    return myString.find(pat) != std::string::npos;
}
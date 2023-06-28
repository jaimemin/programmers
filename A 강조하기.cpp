#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    for (int i = 0; i < myString.length(); i++)
    {
        if (myString[i] == 'a') 
        {
            myString[i] = myString[i] - 'a' + 'A';
        }
        else if (myString[i] > 'A' && myString[i] <= 'Z')
        {
            myString[i] = myString[i] - 'A' + 'a';
        }
    }
    
    return myString;
}
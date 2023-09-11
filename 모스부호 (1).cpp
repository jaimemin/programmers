#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, char> sign2char;

void init() 
{
    sign2char[".-"] = 'a';
    sign2char["-..."] = 'b';
    sign2char["-.-."] = 'c';
    sign2char["-.."] = 'd';
    sign2char["."] = 'e';
    sign2char["..-."] = 'f';
    sign2char["--."] = 'g';
    sign2char["...."] = 'h';
    sign2char[".."] = 'i';
    sign2char[".---"] = 'j';
    sign2char["-.-"] = 'k';
    sign2char[".-.."] = 'l';
    sign2char["--"] = 'm';
    sign2char["-."] = 'n';
    sign2char["---"] = 'o';
    sign2char[".--."] = 'p';
    sign2char["--.-"] = 'q';
    sign2char[".-."] = 'r';
    sign2char["..."] = 's';
    sign2char["-"] = 't';
    sign2char["..-"] = 'u';
    sign2char["...-"] = 'v';
    sign2char[".--"] = 'w';
    sign2char["-..-"] = 'x';
    sign2char["-.--"] = 'y';
    sign2char["--.."] = 'z';
}

string solution(string letter) {
    init();
    
    string answer = "";
    string temp = "";
    
    for (char c : letter)
    {
        if (c == ' ')
        {
            answer += sign2char[temp];
            temp = "";
            
            continue;
        }
        
        temp += c;
    }
    
    if (temp != "")
    {
        answer += sign2char[temp];
    }
    
    return answer;
}

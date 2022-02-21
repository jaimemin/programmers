#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
	int maskLength = phone_number.length() - 4;
	string answer = "";

	for (int i = 0; i < maskLength; i++)
	{
		answer += "*";
	}

	answer += phone_number.substr(maskLength);

	return answer;
}
#include <string>
#include <vector>
using namespace std;

string solution(vector<string> seoul) {
	for (int i = 0; i < seoul.size(); i++)
	{
		if (seoul[i] == "Kim")
		{
			string result = "�輭���� " + to_string(i) + "�� �ִ�";

			return result;
		}
	}
}
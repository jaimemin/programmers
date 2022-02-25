#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct
{
	string head;
	string number;
	string tail;
	int idx;
} FileName;

string convertToLowercase(string s)
{
	string result;

	for (char c : s)
	{
		if (c >= 'A' && c <= 'Z')
		{
			result += tolower(c);
		}
		else
		{
			result += c;
		}
	}

	return result;
}

bool cmp(FileName a, FileName b)
{
	string aHead = convertToLowercase(a.head);
	string bHead = convertToLowercase(b.head);

	if (aHead < bHead)
	{
		return true;
	}

	if (aHead == bHead)
	{
		if (stoi(a.number) < stoi(b.number))
		{
			return true;
		}

		if (stoi(a.number) == stoi(b.number))
		{
			return a.idx < b.idx;
		}
	}

	return false;
}

vector<string> solution(vector<string> files) {
	vector<FileName> fileNames;
	int idx = 0;

	for (string file : files)
	{
		bool isNumber = false;
		string temp;
		int numberStart = file.length();
		int tailStart = file.length();

		for (int i = 0; i < file.length(); i++)
		{
			if (file[i] >= '0' && file[i] <= '9')
			{
				if (numberStart == file.length())
				{
					numberStart = i;
				}
			}
			else
			{
				if (numberStart != file.length())
				{
					tailStart = i;

					break;
				}
			}
		}

		fileNames.push_back({ file.substr(0, numberStart)
			, file.substr(numberStart, tailStart - numberStart)
			, file.substr(tailStart, file.length())
			, idx++ });
	}

	sort(fileNames.begin(), fileNames.end(), cmp);

	vector<string> answer;

	for (FileName fileName : fileNames)
	{
		answer.push_back({ fileName.head + fileName.number + fileName.tail });
	}

	return answer;
}

int main(void)
{
	vector<string> files = {
		"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"
	};

	vector<string> answer = solution(files);

	for (string a : answer)
	{
		cout << a << " ";
	}
	cout << "\n";

	return 0;
}
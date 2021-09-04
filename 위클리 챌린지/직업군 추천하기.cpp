#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef struct
{
	string area;
	int sum;
} Job;

bool cmp(Job a, Job b)
{
	if (a.sum > b.sum)
	{
		return true;
	}

	if (a.sum == b.sum && a.area < b.area)
	{
		return true;
	}

	return false;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
	map<string, int> language2preference;

	for (int i = 0; i < languages.size(); i++)
	{
		language2preference[languages[i]] = preference[i];
	}

	vector<Job> jobs;

	for (string s : table)
	{
		stringstream stream;
		stream.str(s);
		
		string input;
		vector<string> inputs;

		while (stream >> input)
		{
			inputs.push_back(input);
		}

		string area = inputs[0];
		int sum = 0;

		for (int i = 1; i < inputs.size(); i++)
		{
			if (language2preference.find(inputs[i]) == language2preference.end())
			{
				continue;
			}

			sum += (inputs.size() - i)*language2preference[inputs[i]];
		}

		jobs.push_back({ area, sum });
	}

	sort(jobs.begin(), jobs.end(), cmp);

	return jobs[0].area;
}

int main(void)
{
	vector<string> table = { "SI JAVA JAVASCRIPT SQL PYTHON C#",
		"CONTENTS JAVASCRIPT JAVA PYTHON SQL C++",
		"HARDWARE C C++ PYTHON JAVA JAVASCRIPT",
		"PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP",
		"GAME C++ C# JAVASCRIPT C JAVA" };

	vector<string> languages = {
		"PYTHON",
		"C++",
		"SQL"
	};

	vector<int> preference = {
		7,
		5,
		5
	};

	cout << solution(table, languages, preference) << "\n";

	return 0;
}
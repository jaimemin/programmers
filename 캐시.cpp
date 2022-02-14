#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

string convertToLowerCase(string city)
{
	string result;

	for (char c : city)
	{
		result += tolower(c);
	}

	return result;
}

queue<string> markRecentlyUsed(queue<string> &q, string city)
{
	queue<string> result;

	while (!q.empty())
	{
		string curCity = q.front();
		q.pop();

		if (curCity == city)
		{
			continue;
		}

		result.push(curCity);
	}

	result.push(city);

	return result;
}

int solution(int cacheSize, vector<string> cities) {
	if (cacheSize == 0)
	{
		return cities.size() * 5;
	}

	int answer = 0;
	set<string> visited;
	queue<string> q;

	for (string city : cities)
	{
		string lowerCasedCity = convertToLowerCase(city);

		if (visited.find(lowerCasedCity) == visited.end())
		{
			answer += 5;
		}
		else
		{
			answer++;
		}

		q = markRecentlyUsed(q, lowerCasedCity);
		visited.insert(lowerCasedCity);

		if (visited.size() > cacheSize)
		{
			string lruCity = q.front();
			q.pop();

			visited.erase(lruCity);
		}
	}

	return answer;
}
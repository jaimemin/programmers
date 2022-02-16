#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct
{
	string title;
	int duration;
	int idx;
} Music;

bool cmp(Music a, Music b)
{
	if (a.duration == b.duration)
	{
		return a.idx < b.idx;
	}

	return a.duration > b.duration;
}

int getDuration(string from, string to)
{
	int fromHour = stoi(from.substr(0, 2));
	int fromMinute = stoi(from.substr(3, 2));
	int toHour = stoi(to.substr(0, 2));
	// toHour = toHour == 0 ? 24 : toHour;
	int toMinute = stoi(to.substr(3, 2));

	return (toHour - fromHour) * 60 + (toMinute - fromMinute);
}

string convertMusic(string music)
{
	string result;

	for (int i = 0; i < music.length(); i++)
	{
		if (i != music.length() - 1 && music[i + 1] == '#')
		{
			result += (music[i++] + 7);

			continue;
		}

		result += music[i];
	}

	return result;
}

string solution(string m, vector<string> musicinfos) {
	vector<Music> answer;
	m = convertMusic(m);
	int idx = 0;

	for (string musicinfo : musicinfos)
	{
		vector<string> inputs;
		string temp;

		for (char c : musicinfo)
		{
			if (c == ',')
			{
				inputs.push_back(temp);
				temp.clear();

				continue;
			}

			temp += c;
		}

		inputs.push_back(temp);

		int duration = getDuration(inputs[0], inputs[1]);
		string music;
		int musicIdx = 0;

		for (int i = 0; i < duration; i++)
		{
			char nextC = inputs[3][(musicIdx + 1) % inputs[3].length()];

			music += inputs[3][musicIdx];

			if (nextC == '#')
			{
				music += "#";
			}

			musicIdx = (musicIdx + (nextC == '#' ? 2 : 1)) % inputs[3].length();
		}

		music = convertMusic(music);

		if (music.find(m) != string::npos)
		{
			answer.push_back({ inputs[2], duration, idx++ });
		}
	}

	sort(answer.begin(), answer.end(), cmp);

	return answer.empty() ? "(None)" : answer[0].title;
}
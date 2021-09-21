#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 100 + 10;

struct Music
{
	string genre;
	int total;

	Music operator+(Music m)
	{
		Music result;
		result.genre = m.genre;
		result.total = total + m.total;

		return result;
	}
};

bool cmp(Music a, Music b)
{
	return a.total > b.total;
}

typedef struct
{
	int idx;
	int total;
} Play;

bool cmp2(Play a, Play b)
{
	if (a.total > b.total)
	{
		return true;
	}

	if (a.total == b.total 
		&& a.idx < b.idx)
	{
		return true;
	}

	return false;
}

vector<Play> playList[MAX];

vector<int> solution(vector<string> genres, vector<int> plays) {
	map<string, int> music2idx;
	vector<Music> musics;

	int idx = 0;

	for (int i=0; i < genres.size(); i++)
	{
		string genre = genres[i];

		if (music2idx.count(genre))
		{
			playList[music2idx[genre]].push_back({ i, plays[i] });

			continue;
		}

		music2idx[genre] = idx;
		musics.push_back({ genre, 0 });
		playList[idx++].push_back({ i, plays[i] });
	}

	for (int i = 0; i < plays.size(); i++)
	{
		string genre = genres[i];
		int idx = music2idx[genre];
		Music temp = { genre, plays[i] };

		musics[idx] = musics[idx] + temp;
	}

	sort(musics.begin(), musics.end(), cmp);

	vector<int> answer;

	for (int i = 0; i < musics.size(); i++)
	{
		int idx = music2idx[musics[i].genre];
		vector<Play> tempPlays;

		for (Play play : playList[idx])
		{
			tempPlays.push_back(play);
		}

		sort(tempPlays.begin(), tempPlays.end(), cmp2);

		int tempPlaysSize = tempPlays.size();

		for (int j = 0; j < min(tempPlaysSize, 2); j++)
		{
			answer.push_back(tempPlays[j].idx);
		}
	}

	return answer;
}

int main(void)
{
	vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> plays = { 500, 600, 150, 800, 2500 };

	vector<int> answers = solution(genres, plays);

	for (int answer : answers)
	{
		cout << answer << " ";
	}

	cout << "\n";

	return 0;
}
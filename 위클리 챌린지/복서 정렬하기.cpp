#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
	int idx;
	int weight;
	double winRatio;
	int winAgainstHeavier;
} Boxer;

bool cmp(Boxer a, Boxer b)
{
	if (a.winRatio > b.winRatio)
	{
		return true;
	}

	if (a.winRatio == b.winRatio)
	{
		if (a.winAgainstHeavier > b.winAgainstHeavier)
		{
			return true;
		}

		if (a.winAgainstHeavier == b.winAgainstHeavier)
		{
			if (a.weight > b.weight)
			{
				return true;
			}

			if (a.weight == b.weight && a.idx < b.idx)
			{
				return true;
			}
		}
	}

	return false;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
	vector<Boxer> boxers;

	for (int i = 0; i < head2head.size(); i++)
	{
		double wins = 0;
		double total = 0;
		int winAgainstHeavier = 0;

		for (int j = 0; j < head2head[i].length(); j++)
		{
			if (head2head[i][j] == 'N')
			{
				continue;
			}

			total++;
			
			if (head2head[i][j] == 'W')
			{
				wins++;

				if (weights[i] < weights[j])
				{
					winAgainstHeavier++;
				}
			}
		}

		boxers.push_back({ i + 1, weights[i], total ? wins / total : 0, winAgainstHeavier });
	}

	sort(boxers.begin(), boxers.end(), cmp);

	vector<int> answers;

	for (Boxer boxer : boxers)
	{
		answers.push_back(boxer.idx);
	}

	return answers;
}

int main(void)
{
	vector<int> weights = { 60, 70, 60 };
	vector<string> head2head = { "NNN", "NNN", "NNN" };

	vector<int> answers = solution(weights, head2head);

	for (int answer : answers)
	{
		cout << answer << " ";
	}

	cout << "\n";

	return 0;
}
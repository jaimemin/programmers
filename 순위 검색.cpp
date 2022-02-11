#include <string>
#include <vector>
using namespace std;

const int LANGUAGE_MAX = 3;
const int DUTY_MAX = 2;
const int CAREER_MAX = 2;
const int FOOD_MAX = 2;

typedef struct
{
	vector<string> queries;
	int score;
} State;

typedef struct
{
	int lIdx; // language
	int dIdx; // duty
	int cIdx; // career
	int fIdx; // food
} ScoreIdx;

vector<int> scores[LANGUAGE_MAX][DUTY_MAX][CAREER_MAX][FOOD_MAX];

State getState(string s)
{
	vector<string> queries;
	int score;
	string temp;

	for (char c : s)
	{
		if (c == ' ')
		{
			if (temp != "and")
			{
				queries.push_back(temp);
			}

			temp.clear();

			continue;
		}

		temp += c;
	}

	score = stoi(temp);

	return { queries, score };
}

ScoreIdx getScoreIdx(State state)
{
	int languageIdx;

	if (state.queries[0] == "java")
	{
		languageIdx = 0;
	}
	else if (state.queries[0] == "python")
	{
		languageIdx = 1;
	}
	else if (state.queries[0] == "cpp")
	{
		languageIdx = 2;
	}
	else
	{
		languageIdx = 3;
	}

	int dutyIdx = state.queries[1] == "-" ? 2 : (state.queries[1] == "frontend" ? 0 : 1);
	int careerIdx = state.queries[2] == "-" ? 2 : (state.queries[2] == "junior" ? 0 : 1);
	int foodIdx = state.queries[3] == "-" ? 2 : (state.queries[3] == "pizza" ? 0 : 1);

	return { languageIdx, dutyIdx, careerIdx, foodIdx };
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;

	for (string i : info)
	{
		State infoState = getState(i);
		ScoreIdx scoreIdx = getScoreIdx(infoState);

		scores[scoreIdx.lIdx][scoreIdx.dIdx][scoreIdx.cIdx][scoreIdx.fIdx].push_back(infoState.score);
	}

	for (string q : query)
	{
		State queryState = getState(q);
		ScoreIdx scoreIdx = getScoreIdx(queryState);
		int lStart = scoreIdx.lIdx == LANGUAGE_MAX ? 0 : scoreIdx.lIdx;
		int lEnd = scoreIdx.lIdx == LANGUAGE_MAX ? LANGUAGE_MAX - 1 : scoreIdx.lIdx;
		int dStart = scoreIdx.dIdx == DUTY_MAX ? 0 : scoreIdx.dIdx;
		int dEnd = scoreIdx.dIdx == DUTY_MAX ? DUTY_MAX - 1 : scoreIdx.dIdx;
		int cStart = scoreIdx.cIdx == CAREER_MAX ? 0 : scoreIdx.cIdx;
		int cEnd = scoreIdx.cIdx == CAREER_MAX ? CAREER_MAX - 1 : scoreIdx.cIdx;
		int fStart = scoreIdx.fIdx == FOOD_MAX ? 0 : scoreIdx.fIdx;
		int fEnd = scoreIdx.fIdx == FOOD_MAX ? FOOD_MAX - 1 : scoreIdx.fIdx;
		int cnt = 0;

		for (int i = lStart; i <= lEnd; i++)
		{
			for (int j = dStart; j <= dEnd; j++)
			{
				for (int k = cStart; k <= cEnd; k++)
				{
					for (int l = fStart; l <= fEnd; l++)
					{
						for (int score : scores[i][j][k][l])
						{
							if (score >= queryState.score)
							{
								cnt++;
							}
						}
					}
				}
			}
		}

		answer.push_back(cnt);
	}

	return answer;
}
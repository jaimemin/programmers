#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string getGrade(double average)
{
	if (average >= 90.0)
	{
		return "A";
	}
	else if (average >= 80.0)
	{
		return "B";
	}
	else if (average >= 70.0)
	{
		return "C";
	}
	else if (average >= 50.0)
	{
		return "D";
	}
	else
	{
		return "F";
	}
}

string solution(vector<vector<int>> scores) {
	string result = "";
	int size = scores.size();

	for (int i = 0; i < size; i++)
	{
		int ownScore = scores[i][i];
		bool isMax = true;
		bool isMin = true;
		double total = 0;

		for (vector<int> tempScores : scores)
		{
			total += tempScores[i];

			if (tempScores[i] == max(tempScores[i], ownScore)
				&& ownScore != tempScores[i])
			{
				isMax = false;
			}

			if (tempScores[i] == min(tempScores[i], ownScore)
				&& ownScore != tempScores[i])
			{
				isMin = false;
			}
		}

		bool isUnique = false;

		if (isMax || isMin)
		{
			isUnique = true;

			for (int j = 0; j < scores.size(); j++)
			{
				if (j == i)
				{
					continue;
				}

				if (ownScore == scores[j][i])
				{
					isUnique = false;

					break;
				}
			}
		}

		if (isUnique)
		{
			total = (total - ownScore) / (size - 1);
		}
		else
		{
			total /= size;
		}

		result += getGrade(total);
	}

	return result;
}
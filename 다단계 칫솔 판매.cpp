#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

const int MAX = 10000 + 100;
const int TOOTH_BRUSH_PRICE = 100;

int parents[MAX];

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	map<string, int> name2idx;
	int idx = 0;

	for (string name : enroll)
	{
		name2idx[name] = idx++;
	}

	for (int i = 0; i < referral.size(); i++)
	{
		if (referral[i] == "-")
		{
			parents[i] = -1;

			continue;
		}

		parents[i] = name2idx[referral[i]];
	}

	vector<int> answers(enroll.size());

	for (int i = 0; i < seller.size(); i++)
	{
		int idx = name2idx[seller[i]];
		int total = amount[i] * TOOTH_BRUSH_PRICE;

		while (idx != -1)
		{
			answers[idx] += ceil(total * 0.9);
			total /= 10;

			idx = parents[idx];
		}
	}

	return answers;
}
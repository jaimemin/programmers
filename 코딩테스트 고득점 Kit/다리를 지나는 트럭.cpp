#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	deque<int> bridge;

	for (int i = 0; i < bridge_length; i++)
	{
		bridge.push_back(-1);
	}

	int answer = 0;
	int total = 0;
	int lastIdx = -1;
	int truckCnt = 0;
	int startIdx = 0;

	while (1)
	{
		int last = bridge.back();
		bridge.pop_back();

		answer++;

		if (last != -1)
		{
			total -= truck_weights[last];
			truckCnt--;
			lastIdx = last;
		}

		if (lastIdx == truck_weights.size() - 1)
		{
			break;
		}

		if (startIdx != truck_weights.size()
			&& total + truck_weights[startIdx] <= weight
			&& truckCnt + 1 <= bridge_length)
		{
			bridge.push_front(startIdx);
			total += truck_weights[startIdx++];
			truckCnt++;
		}
		else
		{
			bridge.push_front(-1);
		}
	}

	return answer;
}

int main(void)
{
	int bridge_length = 100;
	int weight = 100;
	vector<int> truck_weights = { 10 };

	cout << solution(bridge_length, weight, truck_weights) << "\n";

	return 0;
}
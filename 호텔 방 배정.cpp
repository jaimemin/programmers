#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<long long, long long> room;

long long findRoom(long long n)
{
	if (room[n] == 0)
	{
		return n;
	}

	return room[n] = findRoom(room[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	for (long long num : room_number)
	{
		if (room[num] == 0)
		{
			room[num] = findRoom(num + 1);
			answer.push_back(num);

			continue;
		}

		long long next_num = findRoom(num);
		room[next_num] = findRoom(next_num + 1);

		answer.push_back(next_num);
	}

	return answer;
}
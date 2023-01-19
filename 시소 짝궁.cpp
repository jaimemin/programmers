#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

const int ratio[3] = { 2, 4, 3 };

const int divider[3] = { 1, 3, 2 };

long long solution(vector<int> weights) {
    int idx = 0;
    long long answer = 0;
    set<int> weightSet;
    map<int, int> weight2cnt;

    for (int weight : weights)
    {
        weightSet.insert(weight);
        weight2cnt[weight]++;
    }

    for (int weight : weightSet)
    {
        long long weightSize = weight2cnt[weight];
        answer += (weightSize * (weightSize - 1)) / 2;

        for (int i = 0; i < 3; i++)
        {
            if (weight % divider[i])
            {
                continue;
            }

            int calculatedWeight = (weight / divider[i]) * ratio[i];
            long long size = weight2cnt[calculatedWeight];
            answer += weightSize * size * 1LL;
        }
    }

    return answer;
}
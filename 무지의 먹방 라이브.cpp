#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

int solution(vector<int> food_times, long long k) {
    if (accumulate(food_times.begin(), food_times.end(), 0LL) <= k) 
    {
        return -1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < food_times.size(); i++) 
    {
        pq.push({food_times[i], i + 1});
    }

    long long totalTime = 0;
    long long previousTime = 0;
    long long foodCount = food_times.size();

    while (totalTime + (pq.top().first - previousTime) * foodCount <= k) 
    {
        int currentTime = pq.top().first;
        totalTime += (currentTime - previousTime) * foodCount;
        foodCount--;
        previousTime = currentTime;
        pq.pop();
    }

    vector<pair<int, int>> remaining_foods;
    
    while (!pq.empty()) 
    {
        remaining_foods.push_back(pq.top());
        pq.pop();
    }

    sort(remaining_foods.begin(), remaining_foods.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    });

    return remaining_foods[(k - totalTime) % foodCount].second;
}

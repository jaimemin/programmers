#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> name2rank;
    
    for (int i = 0; i < players.size(); i++)
    {
        name2rank[players[i]] = i;
    }
    
    for (string calling : callings)
    {
        int idx = name2rank[calling];

        name2rank[players[idx - 1]] = idx;
        name2rank[players[idx]] = idx - 1;
        swap(players[idx], players[idx - 1]);
    }
    
    return players;
}

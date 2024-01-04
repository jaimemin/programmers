#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 50;

int arr[MAX][MAX];
map<string, int> name2idx;
map<string, int> name2factor;

void init(vector<string> &friends)
{
    int idx = 0;
    
    for (string f : friends)
    {
        name2idx[f] = idx++;
    }
}

bool cmp(int a, int b)
{
    return a > b;
}

int solution(vector<string> friends, vector<string> gifts) {
    init(friends);
    vector<int> v(friends.size(), 0);
    
    for (string gift : gifts)
    {
        istringstream iss(gift);
        string name, name2;
        iss >> name >> name2;
        
        name2factor[name]++;
        name2factor[name2]--;
        arr[name2idx[name]][name2idx[name2]]++;
    }
    
    for (int i = 0; i < friends.size(); i++)
    {
        for (int j = i + 1; j < friends.size(); j++)
        {
            string name = friends[i];
            string name2 = friends[j];
            int idx = name2idx[name];
            int idx2 = name2idx[name2];
            
            if (arr[idx][idx2] > arr[idx2][idx])
            {
                v[idx]++;
            }
            else if (arr[idx][idx2] < arr[idx2][idx])
            {
                v[idx2]++;
            }
            else
            {
                if (name2factor[name] > name2factor[name2])
                {
                    v[idx]++;
                }
                else if (name2factor[name] < name2factor[name2])
                {
                    v[idx2]++;
                }
            }
        }
    }
    
    sort(v.begin(), v.end(), cmp);
    
    return v[0];
}

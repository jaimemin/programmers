#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
using namespace std;

const int MAX = 100 * 600 + 1;

int N;
vector<int> A, B;
vector<int> Asums, Bsums;
map<pair<set<int>, set<int>>, bool> visited;

void init()
{
    A.clear();
    B.clear();
    Asums.clear();
    Bsums.clear();
}

void func(int idx, int total, bool isA, vector<int> &v, vector<vector<int>> &dice)
{
    if (idx == N / 2)
    {
        isA ? Asums.push_back(total) : Bsums.push_back(total);
        
        return;
    }
    
    for (int i = 0; i < 6; i++)
    {
        func(idx + 1, total + dice[v[idx]][i], isA, v, dice);
    }
}

vector<int> convertSetToVector(set<int> &s)
{
    vector<int> v;
    
    for (int data : s)
    {
        v.push_back(data);
    }
    
    return v;
}

vector<int> solution(vector<vector<int>> dice) {
    N = dice.size();
    vector<int> v(N);
    
    for (int i = 0; i < N; i++)
    {
        v[i] = i;
    }
    
    vector<int> answer(N / 2);
    int maxWin = 0;
    
    do
    { 
        init();
        int win = 0;
        
        set<int> ASet, BSet;
        
        for (int i = 0; i < N / 2; i++)
        {
            A.push_back(v[i]);
            ASet.insert(v[i]);
            
            B.push_back(v[i + N / 2]);
            BSet.insert(v[i + N / 2]);
        }
        
        if (!visited.count({ASet, BSet}))
        {
            func(0, 0, true, A, dice);
            func(0, 0, false, B, dice);
            
            sort(Bsums.begin(), Bsums.end());
            map<int, int> sum2winCnt;

            for (int Asum : Asums)
            {
                if (sum2winCnt.count(Asum))
                {
                    win += sum2winCnt[Asum];

                    continue;
                }

                int low = 0, high = Bsums.size();

                while (low + 1 < high)
                {
                    int mid = (low + high) / 2;

                    if (Asum > Bsums[mid])
                    {
                        low = mid;
                    }
                    else
                    {
                        high = mid;
                    }
                }

                sum2winCnt[Asum] = low;
                win += sum2winCnt[Asum];
            }

            if (win > maxWin)
            {
                for (int i = 0; i < A.size(); i++)
                {
                    answer[i] = A[i] + 1;    
                }

                maxWin = win;
            }

            visited[{ASet, BSet}] = true;
        }
    } while (next_permutation(v.begin(), v.end()));
    
    return answer;
}

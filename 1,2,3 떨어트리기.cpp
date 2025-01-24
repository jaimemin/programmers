#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int ROOT = 1;

int N;

vector<vector<int>> childrenList;

// 각 노드가 현재 가리키는 자식 인덱스
vector<int> childIndex;

vector<bool> isLeaf;

vector<bool> hasChild;

vector<int> targetGlobal;

vector<int> currentRoundLeaf;

unordered_set<int> zeroLeafSet;

int sumOfTargets;

int getCurrentRoundLeafNode() 
{
    int cur = ROOT;
    vector<int> path;
    path.push_back(cur);

    while (!isLeaf[cur]) 
    {
        int idx = childIndex[cur];
        int nxt = childrenList[cur][idx];
        
        cur = nxt;
        path.push_back(cur);
    }

    for (int node : path) 
    {
        if (childrenList[node].size() > 1) 
        {
            childIndex[node] = (childIndex[node] + 1) % childrenList[node].size();
        }
    }
    
    return cur;
}

vector<int> tryAssign(int dropBallCnt) 
{
    vector<int> remain(N + 1, 0);
    vector<vector<int>> leaf2visitedIdxes(N + 1);

    for (int node = 1; node <= N; node++)
    {
        if (isLeaf[node]) 
        {
            remain[node] = targetGlobal[node - 1]; 
        }
    }
    
    for (int i = 0; i < dropBallCnt; i++)
    {
        int leaf = currentRoundLeaf[i];
        
        leaf2visitedIdxes[leaf].push_back(i);
    }

    vector<int> drops(dropBallCnt, 0);

    for (int i = 0; i < dropBallCnt; i++)
    {
        int leaf = currentRoundLeaf[i];
        
        if (leaf2visitedIdxes[leaf].empty() || leaf2visitedIdxes[leaf][0] != i)
        {
            return {};
        }
        
        leaf2visitedIdxes[leaf].erase(leaf2visitedIdxes[leaf].begin());

        int r = remain[leaf];
        int visitRemainCnt = leaf2visitedIdxes[leaf].size() + 1;

        // 가능한 값 x 범위: 1 <= x <= 3, 그리고
        // x >= r - 3 * (vRemain-1) (뒤 방문에서 최대 3씩 가능)
        // x <= r
        int low = max(1, r - 3 * (visitRemainCnt - 1));
        int high = min(3, r);

        if (low > high) 
        {
            return {};
        }
        
        // 최소값 선택
        int x = low;
        drops[i] = x;
        remain[leaf] = r - x;
    }

    // 모든 리프 remain == 0 인지 확인
    for (int node = 1; node <= N; node++)
    {
        if (isLeaf[node] && remain[node] != 0)
        {
            return {};
        }
    }
    
    return drops;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    int E = edges.size();
    N = E + 1;
    childrenList.assign(N+1, {});
    childIndex.assign(N+1, 0);
    isLeaf.assign(N+1, true);
    hasChild.assign(N+1, false);
    targetGlobal = target;
    sumOfTargets = 0;

    for (auto e : edges)
    {
        int p = e[0];
        int c = e[1];
        
        hasChild[p] = true;
        childrenList[p].push_back(c);
    }
    
    for (int i = 1; i <= N; i++)
    {
        if (hasChild[i]) 
        {
            sort(childrenList[i].begin(), childrenList[i].end());
            
            isLeaf[i] = false;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (isLeaf[i]) 
        {
            sumOfTargets += target[i-1];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        childIndex[i] = 0;
    }
    
    currentRoundLeaf.reserve(sumOfTargets);
    
    for (int i = 0; i < sumOfTargets; i++)
    {
        int leaf = getCurrentRoundLeafNode();
        
        currentRoundLeaf.push_back(leaf);
    }

    // target=0인 리프 기록 (이 리프가 방문되면 안됨)
    for (int i = 1; i <= N; i++)
    {
        if (isLeaf[i] && target[i - 1] == 0)
        {
            zeroLeafSet.insert(i);
        }
    }

    for (int dropBallCnt = 1; dropBallCnt <= sumOfTargets; dropBallCnt++)
    {
        bool visitedZero = false;
        
        for (int i = 0; i < dropBallCnt; i++)
        {
            if (zeroLeafSet.count(currentRoundLeaf[i])) 
            {
                visitedZero = true;
                
                break;
            }
        }
        
        if (visitedZero)
        {
            continue;
        }

        // 리프 방문 횟수 * 3 >= 해당 리프 target인지 체크
        vector<int> cnt(N + 1, 0);
        
        for (int i = 0; i < dropBallCnt; i++)
        {
            cnt[currentRoundLeaf[i]]++;
        }
        
        bool possible = true;
        
        for (int node = 1; node <= N; node++)
        {
            if (isLeaf[node] && target[node - 1] > 0)
            {
                if (cnt[node] * 3 < target[node - 1]) 
                {
                    possible = false;
                    
                    break;
                }
            }
        }
        
        if (!possible) 
        {
            continue;
        }

        // 실제 1,2,3 할당 시도
        vector<int> result = tryAssign(dropBallCnt);
        
        if (!result.empty()) 
        {
            return result;
        }
    }

    return {-1};
}

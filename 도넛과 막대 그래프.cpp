#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e6 + 1;

int input[MAX];
int output[MAX];

bool isCreatorNode(int node)
{
    return input[node] == 0 && output[node] >= 2;
}

int getDonutShapedGraphCnt(vector<int> &answer)
{
    return output[answer[0]] - (answer[2] + answer[3]);
}

bool isBarShapedGraph(int node)
{
    return output[node] == 0;
}

bool is8ShapedGraph(int node)
{
    return input[node] >= 2 && output[node] >= 2;
}

vector<int> solution(vector<vector<int>> edges) {
    int maxNode = 0;
    
    for (vector<int> edge : edges)
    {
        input[edge[1]]++;
        output[edge[0]]++;
        
        maxNode = max(maxNode, max(edge[0], edge[1]));
    }
    
    vector<int> answer(4, 0);
    
    for (int node = 1; node <= maxNode; node++)
    {
        if (isCreatorNode(node))
        {
            answer[0] = node;
        }
        else if (isBarShapedGraph(node))
        {
            answer[2]++;
        }
        else if (is8ShapedGraph(node))
        {
            answer[3]++;
        }
    }
    
    answer[1] = getDonutShapedGraphCnt(answer);
    
    return answer;
}

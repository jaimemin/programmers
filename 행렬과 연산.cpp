#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    int r = rc.size();
    int c = rc[0].size();
    deque<int> col, col2;
    
    for(int i = 0; i < r; i++)
    {
        col.push_back(rc[i][0]);
        col2.push_back(rc[i][c - 1]);
    }

    deque<int> rows[r];
    
    for(int i = 0; i < r; i++)
    {
        for(int j = 1; j <= c-2; j++)
        {
            rows[i].push_back(rc[i][j]);
        }
    }
    
    int idx = 0;
    
    for(auto op : operations)
    {
        if(op == "ShiftRow")
        {
            col.push_front(col.back());
            col.pop_back();
            
            col2.push_front(col2.back());
            col2.pop_back();
            
            if(--idx == -1) 
            {
                idx = r-1;
            }
        }
        else
        {
            rows[idx].push_front(col.front());
            col.pop_front();
            
            col2.push_front(rows[idx].back());
            rows[idx].pop_back();
            
            rows[(idx + (r - 1)) % r].push_back(col2.back());
            col2.pop_back();
            
            col.push_back(rows[(idx + (r - 1)) % r].front());
            rows[(idx + (r - 1)) % r].pop_front();
        }
    }
    
    
    vector<vector<int>> answer(r, vector<int>(c));
    
    for(int i = 0; i < r; i++)
    {
        answer[i][0] = col[i];
        
        for(int j = 1; j <= c - 2; j++)
        {
            answer[i][j] = rows[(i + idx) % r][j - 1];
        }
        
        answer[i][c - 1] = col2[i];
    }
    
    return answer;
}

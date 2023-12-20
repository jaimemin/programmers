#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    for (vector<int> d : data)
    {
        if (ext == "code")
        {
            if (d[0] >= val_ext)
            {
                continue;
            }
        }
        else if (ext == "date")
        {
            if (d[1] >= val_ext)
            {
                continue;
            }
        }
        else if (ext == "maximum")
        {
            if (d[2] >= val_ext)
            {
                continue;
            }
        }
        else
        {
            if (d[3] >= val_ext)
            {
                continue;
            }
        }
        
        answer.push_back(d);
    }
    
    sort(answer.begin(), answer.end(),  [&sort_by]( const vector<int>& a, const vector<int>& b)
    {
        if (sort_by == "code")
        {
            return a[0] < b[0];
        }
        else if (sort_by == "date")
        {
            return a[1] < b[1];
        }
        else if (sort_by == "maximum")
        {
            return a[2] < b[2];
        }
        else
        {
            return a[3] < b[3];
        }
    });
    
    return answer;
}

#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef struct
{
    int score, score2;
    int idx;
} Employee;

bool cmp(Employee a, Employee b)
{
    return a.score > b.score;
}

int solution(vector<vector<int>> scores) {
    int target = scores[0][0] + scores[0][1];
    vector<Employee> employees;
    int idx = 0;
    
    for (vector<int> score : scores)
    {
        if (score[0] > scores[0][0] && score[1] > scores[0][1])
        {
            return -1;
        }
        
        employees.push_back({ score[0], score[1], idx++ });
    }
    
    sort(employees.begin(), employees.end(), cmp);
    
    map<int, int> sum2cnt;
    vector<int> scoreList;
    
    for (int i = 0; i < employees.size(); i++)
    {
        bool flag = true;
        Employee e = employees[i];
        
        for (int j = 0; j < i; j++)
        {
            Employee e2 = employees[j];
            
            if (e2.score > e.score 
                && e2.score2 > e.score2)
            {
                flag = false;
                
                break;
            }
        }
        
        if (flag == false)
        {
            continue;
        }
        
        int sum = e.score + e.score2;
        
        if (!sum2cnt.count(sum))
        {
            scoreList.push_back(sum);
        }
        
        sum2cnt[sum]++;
    }
    
    sort(scoreList.begin(), scoreList.end());
    
    int answer = 1;
    
    for (int i = scoreList.size() - 1; i >= 0; i--)
    {
        if (scoreList[i] == target)
        {
            return answer;
        }
        
        answer += sum2cnt[scoreList[i]];
    }
}

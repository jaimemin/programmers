#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_LEN = 1e4;

vector<int> solution(vector<string> words, vector<string> queries) {
    // 길이별로 단어를 그룹화합니다.
    vector<vector<string>> wordsByLength(MAX_LEN + 1);
    // 접두사에 와일드카드가 있는 쿼리를 처리하기 위해 단어를 뒤집은 배열도 만듭니다.
    vector<vector<string>> reversedWordsByLength(MAX_LEN + 1);
    
    for (string word : words) 
    {
        int len = word.size();
        wordsByLength[len].push_back(word);
        string revWord = word;
        
        reverse(revWord.begin(), revWord.end());
        reversedWordsByLength[len].push_back(revWord);
    }
    
    for (int i = 1; i <= MAX_LEN; i++) 
    {
        if (!wordsByLength[i].empty())
        {
            sort(wordsByLength[i].begin(), wordsByLength[i].end());
            sort(reversedWordsByLength[i].begin(), reversedWordsByLength[i].end());
        }
    }
    
    vector<int> answer;
    
    // 각 쿼리에 대하여 매치되는 단어 개수를 계산합니다.
    for (string query : queries) 
    {
        int qLen = query.size();
        
        // 해당 길이의 단어가 없으면 0을 추가합니다.
        if (wordsByLength[qLen].empty())
        {
            answer.push_back(0);
            
            continue;
        }
        
        int count = 0;
        
        // 쿼리의 첫 문자가 '?'가 아니면, 와일드카드가 접미사에 있다는 뜻입니다.
        if (query[0] != '?')
        {
            // '?'를 각각 'a'와 'z'로 치환하여 lower_bound와 upper_bound를 위한 범위를 만듭니다.
            string leftQuery = query;
            string rightQuery = query;
            
            for (int i = 0; i < qLen; i++)
            {
                if (leftQuery[i] == '?')
                {
                    leftQuery[i] = 'a';
                    rightQuery[i] = 'z';
                }
            }
            
            auto lower = lower_bound(wordsByLength[qLen].begin(), wordsByLength[qLen].end(), leftQuery);
            auto upper = upper_bound(wordsByLength[qLen].begin(), wordsByLength[qLen].end(), rightQuery);
            
            count = upper - lower;
        } 
        // 쿼리의 첫 문자가 '?'이면, 와일드카드가 접두사에 있으므로 단어들을 뒤집어 처리합니다.
        else 
        {
            string revQuery = query;
            reverse(revQuery.begin(), revQuery.end());
            string leftQuery = revQuery;
            string rightQuery = revQuery;
            
            for (int i = 0; i < qLen; i++)
            {
                if(leftQuery[i] == '?')
                {
                    leftQuery[i] = 'a';
                    rightQuery[i] = 'z';
                }
            }
            
            auto lower = lower_bound(reversedWordsByLength[qLen].begin(), reversedWordsByLength[qLen].end(), leftQuery);
            auto upper = upper_bound(reversedWordsByLength[qLen].begin(), reversedWordsByLength[qLen].end(), rightQuery);
            
            count = upper - lower;
        }
        
        answer.push_back(count);
    }
    
    return answer;
}

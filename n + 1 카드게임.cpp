#include <string>
#include <vector>
#include <set>
using namespace std;

int N;

bool canGoToNextRound(set<int> &s, set<int> &matching)
{
    for (int card : s)
    {
        int matchingCard = (N + 1) - card;
        
        if (matching.find(matchingCard) != matching.end())
        {
            s.erase(card);
            matching.erase(matchingCard);
            
            return true;
        }
    }
    
    return false;
}

int solution(int coin, vector<int> cards) {
    int answer = 1;
    N = cards.size();
    set<int> hands, draw;
    
    for (int i = 0; i < N / 3; i++)
    {
        hands.insert(cards[i]);
    }
    
    int nextIdx = N / 3;
    
    while (nextIdx < N)
    {
        for (int i = 0; i < 2; i++)
        {
            draw.insert(cards[nextIdx++]);
        }
        
        if (canGoToNextRound(hands, hands))
        {
            answer++;
        }
        else if (coin >= 1 && canGoToNextRound(hands, draw))
        {
            answer++;
            coin--;
        }
        else if (coin >= 2 && canGoToNextRound(draw, draw))
        {
            answer++;
            coin -= 2;
        }
        else
        {
            break;
        }
    }
    
    return answer;
}

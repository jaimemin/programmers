#include <string>
#include <vector>

using namespace std;

double getHourHand(int h, int m, int s)
{
    double dH = (double) h;
    double dM = (double) m;
    double dS = (double) s;
    
    // 시침은 분침 기준 5분씩 증가
    // ex) 1시 -> 분침 기준 5, 2시 -> 분침 기준 10
    return 5 * (dH + dM / 60 + dS / 3600);
}

double getMinuteHand(int m, int s)
{
    double dM = (double) m;
    double dS = (double) s;
    
    return dM + (dS / 60);
}

int getOverlapCntFromZeroSecond(int h, int m, int s)
{
    if (h == 0 && m == 0 && s == 0)
    {
        return 0;
    }
    
    int overlap = (h * 59) + (h * 60) + (m * 2) - 1;
    
    if ((double) s > getHourHand(h, m, s))
    {
        overlap++;
    }
    
    if ((double) s > getMinuteHand(m, s))
    {
        overlap++;
    }
    
    return overlap;
}

int getOverlapCnt(int h, int m, int s)
{
    return h >= 12 ? 
        getOverlapCntFromZeroSecond(11, 59, 59) + getOverlapCntFromZeroSecond(h - 12, m, s) 
        : 
        getOverlapCntFromZeroSecond(h, m, s);  
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = getOverlapCnt(h2, m2, s2) - getOverlapCnt(h1, m1, s1);
    
    if (s2 == getHourHand(h2, m2, s2) 
        || s2 == getMinuteHand(m2, s2))
    {
        answer++;
    }
    
    return answer;
}

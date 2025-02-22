#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int MAX = 26;

long long solution(string s) {
    int n = s.size();
    long long answer = 0;
    
    char prevChar = s[0];
    int currentSegmentLength = 1;
    
    vector<bool> isFirstOccurrence(MAX, false);
    vector<long long> cumulativeIdxSum(n + 1, 0);
    
    for (int i = 1; i < n; i++) 
    {
        cumulativeIdxSum[i] = cumulativeIdxSum[i - 1] + i;
    }
    
    vector<map<int, int>> segmentFrequency(MAX);
    vector<long long> sameLetterMovePoints(MAX, 0);
    vector<long long> diffLetterMovePoints(MAX, 0);
    vector<long long> totalContinuousLength(MAX, 0);
    vector<long long> totalNonContinuousCnt(MAX, 0);
    vector<int> lastSegmentEndIdx(MAX, 0);
    
    for (int i = 1; i < n; i++) 
    {
        int prevIdx = i - 1;
        int prevAlphaIdx = prevChar - 'a';
        
        if (s[i] == prevChar) 
        {
            currentSegmentLength++;
        } 
        else 
        {
            if (!isFirstOccurrence[prevAlphaIdx]) 
            {
                isFirstOccurrence[prevAlphaIdx] = true;
                diffLetterMovePoints[prevAlphaIdx] = cumulativeIdxSum[prevIdx] - cumulativeIdxSum[currentSegmentLength - 1];
                totalContinuousLength[prevAlphaIdx] = currentSegmentLength;
                totalNonContinuousCnt[prevAlphaIdx] = prevIdx - currentSegmentLength + 1;
                lastSegmentEndIdx[prevAlphaIdx] = prevIdx;
                segmentFrequency[prevAlphaIdx][currentSegmentLength]++;
            } 
            else 
            { 
                int lastEnd = lastSegmentEndIdx[prevAlphaIdx];
                diffLetterMovePoints[prevAlphaIdx] += (prevIdx - lastEnd) * totalNonContinuousCnt[prevAlphaIdx]
                    + (cumulativeIdxSum[prevIdx - lastEnd - 1] - cumulativeIdxSum[currentSegmentLength - 1]);

                sameLetterMovePoints[prevAlphaIdx] += (prevIdx - lastEnd) * totalContinuousLength[prevAlphaIdx];
                segmentFrequency[prevAlphaIdx][currentSegmentLength]++;
                totalContinuousLength[prevAlphaIdx] += currentSegmentLength;
                totalNonContinuousCnt[prevAlphaIdx] = (prevIdx + 1) - totalContinuousLength[prevAlphaIdx];
                lastSegmentEndIdx[prevAlphaIdx] = prevIdx;
            }

            prevChar = s[i];
            currentSegmentLength = 1;
        }
        
        int curAlphaIdx = s[i] - 'a';
        long long curContribution = 0;
        int lastEndForCurrent = lastSegmentEndIdx[curAlphaIdx];
        
        if (!isFirstOccurrence[curAlphaIdx]) 
        {
            curContribution = cumulativeIdxSum[i] - cumulativeIdxSum[currentSegmentLength - 1];
        } 
        else 
        {
            curContribution += diffLetterMovePoints[curAlphaIdx] + (i - lastEndForCurrent) * totalNonContinuousCnt[curAlphaIdx] * 1LL;
            curContribution += cumulativeIdxSum[i - lastEndForCurrent - 1] - cumulativeIdxSum[currentSegmentLength - 1];
        }
        
        for (auto segment : segmentFrequency[curAlphaIdx]) 
        {
            int segmentLength = segment.first;
            int frequency = segment.second;
            
            if (currentSegmentLength < segmentLength) 
            {
                curContribution += (cumulativeIdxSum[(i - currentSegmentLength) - (lastEndForCurrent - segmentLength + 1)]
                                         - cumulativeIdxSum[i - (lastEndForCurrent + 1)]) * frequency;
            }

            curContribution += (i - (lastEndForCurrent + 1)) * frequency * min(currentSegmentLength, segmentLength) * 1LL;
        }

        curContribution += sameLetterMovePoints[curAlphaIdx];
        
        answer += curContribution;
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

const int NEG_INF = -1000000000;

int getOneBitCnt(int mask)
{
    int result = 0;
    
    while (mask)
    {
        result += mask % 2;
        
        mask /= 2;
    }
    
    return result;
}

int solution(vector<vector<int>> visible, vector<vector<int>> hidden, int k) {
    int nRows = visible.size();
    
    if (nRows == 0) 
    {
        return 0;
    }
    
    int nCols = visible[0].size();
    
    int initSum = 0;
    
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            initSum += visible[i][j];
        }
    }

    vector<vector<int>> diff(nRows, vector<int>(nCols, 0));
    
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            diff[i][j] = hidden[i][j] - visible[i][j];
        }
    }

    bool needCorrection = false;
    
    if (nRows >= 2 && nCols >= 2)
    {
        if (((nRows + nCols) % 2 == 0) && ((nRows * nCols) % 2 == 0))
        {
            needCorrection = true;
        }
    }
    
    int answer = NEG_INF;
    int totalRowConfigs = 1 << nRows;
    
    for (int rowMask = 0; rowMask < totalRowConfigs; rowMask++)
    {
        int flipCount = getOneBitCnt(rowMask);
        int rowCost = flipCount * k;
        int baseScore = initSum - rowCost;
        
        vector<int> colProfit0(nCols, 0), colProfit1(nCols, 0);
        
        for (int col = 0; col < nCols; col++)
        {
            int sumFlipped = 0, sumNotFlipped = 0;
            
            for (int row = 0; row < nRows; row++)
            {
                if (rowMask & (1 << row))
                {
                    sumFlipped += diff[row][col];
                }
                else
                {
                    sumNotFlipped += diff[row][col];
                }
            }
            
            colProfit0[col] = sumFlipped;
            colProfit1[col] = sumNotFlipped;
        }
        
        if (!needCorrection) 
        {
            int colTotal = 0;
            
            for (int col = 0; col < nCols; col++)
            {
                colTotal += max(colProfit0[col], colProfit1[col] - k);
            }
            
            answer = max(answer, baseScore + colTotal);
        } 
        else 
        {
            vector<int> minOdd0(nCols, INF), minOdd1(nCols, INF);
            
            for (int col = 0; col < nCols; col++)
            {
                for (int row = 0; row < nRows; row++)
                {
                    if (((row + col) & 1) == 1) 
                    {
                        int val0, val1;
                        
                        if (rowMask & (1 << row)) 
                        { 
                            val0 = visible[row][col] + diff[row][col];
                            val1 = visible[row][col];
                        } 
                        else 
                        {
                            val0 = visible[row][col];
                            val1 = visible[row][col] + diff[row][col];
                        }
                        
                        minOdd0[col] = min(minOdd0[col], val0);
                        minOdd1[col] = min(minOdd1[col], val1);
                    }
                }
            }
            
            vector<int> thresholds;
            
            for (int col = 0; col < nCols; col++)
            {
                thresholds.push_back(minOdd0[col]);
                thresholds.push_back(minOdd1[col]);
            }
            
            sort(thresholds.begin(), thresholds.end());
            thresholds.erase(unique(thresholds.begin(), thresholds.end()), thresholds.end());
            
            int bestConfigScore = NEG_INF;
            
            for (int thr : thresholds) 
            {
                bool valid = true;
                int profitSum = 0;
                int globalOddMin = INF;
                
                for (int col = 0; col < nCols; col++)
                {
                    int bestColProfit = NEG_INF;
                    int chosenOdd = INF;
                    
                    if (minOdd0[col] >= thr) 
                    {
                        bestColProfit = colProfit0[col];
                        chosenOdd = minOdd0[col];
                    }
                    
                    if (minOdd1[col] >= thr) 
                    {
                        int profitOpt = colProfit1[col] - k;
                        
                        if (profitOpt > bestColProfit) 
                        {
                            bestColProfit = profitOpt;
                            chosenOdd = minOdd1[col];
                        }
                    }
                    
                    if (bestColProfit == NEG_INF) 
                    {
                        valid = false;
                        
                        break;
                    }
                    
                    profitSum += bestColProfit;
                    globalOddMin = min(globalOddMin, chosenOdd);
                }
                
                if (valid) 
                {
                    bestConfigScore = max(bestConfigScore, baseScore + profitSum - globalOddMin);
                }
            }
            
            answer = max(answer, bestConfigScore);
        }
    }
    
    return answer;
}

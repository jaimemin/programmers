#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int targetRow = (num - 1) / w;
    int remainder = (num - 1) % w;
    int targetCol;

    if (targetRow % 2 == 0) 
    {
        targetCol = remainder;
    } 
    else 
    {
        targetCol = w - 1 - remainder;
    }
    
    int totalRows = (n - 1) / w + 1;
    int answer = 1;

    for (int r = targetRow + 1; r < totalRows; r++) 
    {    
        int boxesInRow;

        if (r == totalRows - 1 && n % w != 0)
        {
            boxesInRow = n % w;
        }
        else
        {
            boxesInRow = w;
        }

        if (r % 2 == 0) 
        {
            if (targetCol < boxesInRow) 
            {
                answer++;
            }
        } 
        else 
        {  
            if (targetCol >= w - boxesInRow && targetCol < w) 
            {
                answer++;
            }
        }
    }
    
    return answer;
}

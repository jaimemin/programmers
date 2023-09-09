#include <string>
#include <vector>

using namespace std;

const int MAX = 30;

int arr[MAX + 1][MAX + 1];

int solution(int balls, int share) {
    for(int i = 0; i <= MAX; i++) 
    {   
        arr[i][0]=arr[i][i]=1;
    }
    
    for(int i = 2; i <= MAX; i++)
    {
        for(int j = 1; j < i; j++)
        {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }
    
    return arr[balls][share];
}

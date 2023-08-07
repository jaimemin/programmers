#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

const int PICK_SIZE = 3;

const int CNT_PER_TURN = 5;

const int fatigues[3][3] = {
    {1, 1, 1},
    {5, 1, 1},
    {25, 5, 1}
};

typedef struct
{
    int diamond;
    int iron;
    int stone;
} Ore;

bool cmp(const Ore a, const Ore b)
{
    if (a.diamond > b.diamond)
    {
        return true;
    }
    
    if (a.diamond == b.diamond)
    {
        if (a.iron > b.iron)
        {
            return true;
        }
        
        if (a.iron == b.iron)
        {
            return a.stone > b.stone;
        }
    }
    
    return false;
}

int solution(vector<int> picks, vector<string> minerals) {
    vector<Ore> ores;
    int size = minerals.size();
    int total = 0;
    
    for (int pick : picks)
    {
        total += pick;
    }

    for (int i = 0; i < size && ores.size() < total; i += CNT_PER_TURN) {
        int diamond = 0;
        int iron = 0;
        int stone = 0;
        
        for (int j = i; j < min(i + 5, size); j++) {
            string mineral = minerals[j];
            
            if (mineral == "diamond")
            {
                diamond++;
            }
            else if (mineral == "iron")
            {
                iron++;
            }
            else
            {
                stone++;
            }
        }
        
        ores.push_back({diamond, iron, stone});
    }

    sort(ores.begin(), ores.end(), cmp);
    
    int answer = 0;

    for (Ore ore : ores)
    {
        int pickIdx = -1;
        
        for (int i = 0; i < PICK_SIZE; i++)
        {
            if (picks[i])
            {
                pickIdx = i;
                
                break;
            }
        }
        
        if (pickIdx == -1)
        {
            break;
        }

        picks[pickIdx]--;
        
        answer += (ore.diamond * fatigues[pickIdx][0] 
            + ore.iron * fatigues[pickIdx][1] 
            + ore.stone * fatigues[pickIdx][2]);
    }

    return answer;
}

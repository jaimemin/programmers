#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int MAX = 1e5 + 1;

const int NUMBER_MAX = 10;

const int Y_MAX = 4;

const int X_MAX = 3;

const int steps[NUMBER_MAX][NUMBER_MAX] = {
    { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 },
    { 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 },
    { 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 },
    { 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 },
    { 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 },
    { 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 },
    { 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 },
    { 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 },
    { 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 },
    { 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 }
};

typedef struct
{
    int y, x;
} Coord;

bool operator<(Coord a, Coord b)
{
    if (a.y == b.y)
    {
        return a.x < b.x;
    }

    return a.y < b.y;
}

Coord coords[NUMBER_MAX] = { {3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2} };

int cache[MAX][Y_MAX][X_MAX][Y_MAX][X_MAX];

map<Coord, int> coord2num;

bool thumbOnNumber(Coord thumb, Coord num)
{
    return thumb.y == num.y && thumb.x == num.x;
}

void init()
{
    memset(cache, -1, sizeof(cache));

    int num = 0;

    for (Coord coord : coords)
    {
        coord2num[coord] = num++;
    }
}

int func(int idx, Coord left, Coord right, string numbers)
{
    if (idx == numbers.length())
    {
        return 0;
    }

    int& result = cache[idx][left.y][left.x][right.y][right.x];

    if (result != -1)
    {
        return result;
    }

    int curNum = numbers[idx] - '0';
    Coord cur = coords[curNum];

    if (thumbOnNumber(left, cur) || thumbOnNumber(right, cur))
    {
        return result = 1 + func(idx + 1, left, right, numbers);
    }

    return result = min(func(idx + 1, cur, right, numbers) + steps[coord2num[left]][curNum]
        , func(idx + 1, left, cur, numbers) + steps[coord2num[right]][curNum]);
}

int solution(string numbers) {
    init();

    return func(0, coords[4], coords[6], numbers);
}
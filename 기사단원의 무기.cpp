#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

const int MAX = 100000 + 10;

int cache[MAX];

vector<int> primes;

void eratosthenes()
{
    cache[0] = cache[1] = -1;

    for (int i = 2; i < MAX; i++)
    {
        cache[i] = i;
    }

    for (int i = 2; i * i < MAX; i++)
    {
        if (cache[i] != i)
        {
            continue;
        }

        for (int j = i * i; j < MAX; j += i)
        {
            if (cache[j] == j)
            {
                cache[j] = i;
            }
        }
    }

    for (int i = 2; i < MAX; i++)
    {
        if (cache[i] == i)
        {
            primes.push_back(i);
        }
    }
}

int getDivsorCnt(int number)
{
    map<int, int> prime2cnt;
    set<int> visited;

    while (1)
    {
        for (int prime : primes)
        {
            if (number % prime != 0)
            {
                continue;
            }

            prime2cnt[prime]++;
            visited.insert(prime);
            number /= prime;

            break;
        }

        if (number == 1)
        {
            break;
        }
    }

    int result = 1;

    for (int a : visited)
    {
        result *= (prime2cnt[a] + 1);
    }

    return result;
}

int solution(int number, int limit, int power) {
    eratosthenes();

    int answer = 1;

    for (int i = 2; i <= number; i++)
    {
        int cnt = getDivsorCnt(i);

        answer += cnt > limit ? power : cnt;
    }

    return answer;
}
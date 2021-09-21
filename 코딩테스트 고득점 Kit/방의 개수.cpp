#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

typedef struct
{
	int y, x;
} Node;

bool operator<(const Node &a, const Node &b)
{
	if (a.y < b.y)
	{
		return true;
	}

	if (a.y == b.y
		&& a.x < b.x)
	{
		return true;
	}

	return false;
}

bool operator==(const Node &a, const Node &b)
{
	return a.y == b.y && a.x == b.x;
}

typedef struct
{
	Node u;
	Node v;
} Edge;

bool operator<(const Edge &a, const Edge &b)
{
	if (a.u < b.u)
	{
		return true;
	}

	if (a.u == b.u
		&& a.v < b.v)
	{
		return true;
	}

	return false;
}

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

map<Node, bool> nodeVisited;
map<Edge, bool> edgeVisited;

int solution(vector<int> arrows) {
	int answer = 0;

	int y = 0, x = 0;
	Node start = { y, x };
	nodeVisited[start] = true;

	for (int arrow : arrows)
	{
		for (int i = 0; i < 2; i++)
		{
			int nextY = y + moveDir[arrow].y;
			int nextX = x + moveDir[arrow].x;

			// 해당 노드는 이미 방문했지만
			// 해당 노드로 가는 간선은 방문하지 않은 상태라면 사이클
			if (nodeVisited.count({ nextY, nextX })
				&& !edgeVisited.count({ {y, x}, {nextY, nextX} }))
			{
				answer++;
			}

			nodeVisited[{nextY, nextX}] = true;
			
			// 양방향
			edgeVisited[{ {y, x}, { nextY, nextX }}] = true;
			edgeVisited[{ {nextY, nextX}, { y, x }}] = true;

			y = nextY;
			x = nextX;
		}
	}

	return answer;
}

int main(void)
{
	vector<int> arrows = { 6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0 };

	cout << solution(arrows) << "\n";

	return 0;
}
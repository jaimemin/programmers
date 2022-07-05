#include <string>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
using namespace std;

struct Node
{
	int idx;
	Node *prev;
	Node *next;

	Node(int idx, Node *prev, Node *next) {
		this->idx = idx;
		this->prev = prev;
		this->next = next;
	}
};

string solution(int n, int k, vector<string> cmd) {
	string answer(n, 'X');

	Node *node = new Node(0, NULL, NULL);
	Node *it = node;

	for (int i = 1; i < n; i++)
	{
		node->next = new Node(i, node, NULL);
		node = node->next;
	}

	for (int i = 0; i < k; i++)
	{
		it = it->next;
	}

	stack<Node *> deletedNodes;

	for (string c : cmd)
	{
		if (c[0] == 'U' || c[0] == 'D')
		{
			int X = stoi(c.substr(2));

			for (int x = 0; x < X; x++)
			{
				it = c[0] == 'U' ? it->prev : it->next;
			}
		}
		else if (c[0] == 'C')
		{
			deletedNodes.push(it);

			if (it->prev != NULL)
			{
				it->prev->next = it->next;
			}

			if (it->next != NULL)
			{
				it->next->prev = it->prev;
				it = it->next;
			}
			else
			{
				it = it->prev;
			}
		}
		else if (c[0] == 'Z')
		{
			Node *deletedNode = deletedNodes.top();
			deletedNodes.pop();

			if (deletedNode->prev != NULL)
			{
				deletedNode->prev->next = deletedNode;
			}

			if (deletedNode->next != NULL)
			{
				deletedNode->next->prev = deletedNode;
			}
		}
	}

	answer[it->idx] = 'O';

	while (it->prev != NULL)
	{
		answer[it->prev->idx] = 'O';
		it = it->prev;
	}

	while (it->next != NULL)
	{
		answer[it->next->idx] = 'O';
		it = it->next;
	}

	return answer;
}
int main(void) {
	int n = 8;
	int k = 2;
	vector<string> cmd = { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" };

	string answer = solution(n, k, cmd);

	return 0;
}
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct BinaryTree
{
	int idx;
	BinaryTree *left;
	BinaryTree *right;
};

vector<int> preorder, postorder;

BinaryTree *drawTree(int left, int right, vector<vector<int>> &nodeinfo)
{
	if (left > right)
	{
		return NULL;
	}

	int maxY = nodeinfo[left][1];
	int root = left;

	for (int i = left + 1; i <= right; i++)
	{
		if (nodeinfo[i][1] > maxY)
		{
			maxY = nodeinfo[i][1];
			root = i;
		}
	}

	BinaryTree *tree = new BinaryTree();
	tree->idx = nodeinfo[root][2];
	tree->left = drawTree(left, root - 1, nodeinfo);
	tree->right = drawTree(root + 1, right, nodeinfo);

	return tree;
}

void getPreorder(BinaryTree *node)
{
	if (node == NULL)
	{
		return;
	}

	preorder.push_back(node->idx);
	getPreorder(node->left);
	getPreorder(node->right);
}

void getPostorder(BinaryTree *node)
{
	if (node == NULL)
	{
		return;
	}

	getPostorder(node->left);
	getPostorder(node->right);
	postorder.push_back(node->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	for (int i = 0; i < nodeinfo.size(); i++)
	{
		nodeinfo[i].push_back(i + 1);
	}

	sort(nodeinfo.begin(), nodeinfo.end());

	BinaryTree *binaryTree = drawTree(0, nodeinfo.size() - 1, nodeinfo);
	getPreorder(binaryTree);
	getPostorder(binaryTree);

	vector<vector<int>> answer;
	answer.push_back(preorder);
	answer.push_back(postorder);

	return answer;
}
// PAT1064-CompleteBinarySearchTree.cpp
// Ad
// Init: 19Sep02

// UNCOMPLETED

#include <iostream>
#include <deque>
#include <vector>

struct Node;
Node *buildTree(const vector<int> &keys);
vector<int> levelTraversal(Node *root);

// Class -----------------------------------------------------------------------

struct Node
{
	int key;
	Node *left;
	Node *right;
};

// Main ------------------------------------------------------------------------

int main()
{
	int numNodes = 0;
	cin >> numNodes;
	vector<int> keys;
	for (int i = 0; i < numNodes; ++i)
	{
		int key = 0;
		cin >> key;
		keys.push_back(key); 
	}
	
	Node *root = buildTree(keys);
	
	vector<int> lvlTra = levelTraversal(root);
	
	cout << lvlTra.front();
	for (int i = 1; i < numNodes; ++i)
		cout << ' ' << lvlTra[i];	
	cout << endl;
	
	return 0;
}

// Functions -------------------------------------------------------------------

Node *buildTree(const vector<int> &keys)
{
	if (keys.emplace())
		return nullptr;

	Node *root = new Node{keys.front(), nullptr, nullptr};
	for (int i = 1; i < keys.size(); ++i)
		buildTree(root, keys[i]);
		
	return root;
}

void buildTree(Node *root, int key)
{
	if (key < root.key)
	{
		if (!root->left)
			root->left = new Node{key, nullptr, nullptr};
		else
			buildTree(root->left, key);
	}
	else
	{
		if (!root->right)
			root->right = new Node{key, nullptr, nullptr};
		else
			buildTree(root->right, key);
	}
}

vector<int> levelTraversal(Node *root)
{
}


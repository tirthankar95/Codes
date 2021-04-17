//This problem can't be solved using BST since its not self balancing. 
// It strictly increasing array is given time taken would be O(N*2).
// AVL tree is required. 
#include<bits/stdc++.h>
using namespace std;

// BST node structure
class Node{
	
public:
	int val;
	int count;
	Node* left;
	Node* right;
	
	// Constructor
	Node(int num1, int num2)
	{
		this->val = num1;
		this->count = num2;
		this->left = this->right = NULL;
	}
};
// Function to addNode and find the smaller
// elements on the right side
int addNode(Node*& root, int value)
{
	
	// Base case
	if (root == NULL)
	{
		root = new Node(value,1);
		return 0;
	}
	if (root->val < value)
	{
		return root->count +
		addNode(root->right,value);
	}
	else
	{
		root->count++;
		return addNode(root->left,value);
	}
}

// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int data[] = { 10, 6, 15, 20, 30, 5, 7 };
	int size = sizeof(data) / sizeof(data[0]);
	int ans[size] = {0};

	Node* root = NULL;
	
	for(int i = size - 1; i >= 0; i--)
	{
		ans[i] = addNode(root, data[i]);
	}

	for(int i = 0; i < size; i++)
		cout << ans[i] << " ";

	return 0;
}
///////////////////////////////////////////////////////////////
// AVL tree insertion. 
https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
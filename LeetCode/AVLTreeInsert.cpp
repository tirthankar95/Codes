#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
	TreeNode *left,*right;
	int height;
	int value;
	TreeNode(int value,int height)
	{
		this->value=value;
		this->height=height;
		left=right=NULL;
	}
};
void inorder(TreeNode* root)
{
	if(root==NULL)return;
	inorder(root->left);
	printf("%d ",root->value);
	inorder(root->right);
}
int getHeight(TreeNode* root)
{
	if(root==NULL)return 0;
	return root->height;
}
int getBalance(TreeNode* root)
{
	return getHeight(root->left)-getHeight(root->right);
}
void insert(TreeNode*& root,int value)
{
	if(root==NULL)
		root=(new TreeNode(value,1));
	if(value<root->value)
		insert(root->left,value);
	else if(value>root->value)
		insert(root->right,value);
	else return;

	root->height=1+max(getHeight(root->left),getHeight(root->right));
	int balance=getBalance(root);
	//left left.
	if(balance>1 && )
}
int main(){
	TreeNode* root=NULL;
	int arr[4]={3,6,1,4};
	for(int i=0;i<4;i++)
		insert(root,arr[i]);
	inorder(root);
	return 0;
}
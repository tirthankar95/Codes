// https://www.geeksforgeeks.org/avl-tree-set-1-insertion/?ref=leftbar-rightbar
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define DBG

class AVLTree{
	class node{
	public:
		node *left,*right;
		int height;
		int value;
		node(int value,int height)
		{
			this->value=value;
			this->height=height;
			left=right=NULL;
		}
	};
	node* root;
	node* leftRotate(node* src){
		node* R=src->right; 
		src->right=R->left;
		R->left=src;
		R->height=1+max(R->left->height,R->right->height);	
		src->height=1+max(src->left->height,src->right->height);
		return R;
	}
	node* rightRotate(node* src){
		node* L=src->left;
		src->left=L->right;
		L->right=src;
		src->height=1+max(src->left->height,src->right->height);
		L->height=1+max(L->left->height,L->right->height);	
		return L;	
	}
	node* insertUtil(node* src,int value){
		if(!src)
			return (new node(value,1));
		int lh=0,rh=0;
		if(src->value>=value){
			src->left=insertUtil(src->left,value);
			lh=src->left->height;
		}
		else{
			src->right=insertUtil(src->right,value);
			rh=src->right->height;
		}
		src->height=1+max(lh,rh);
		//Balancing Act.
		int delta=abs(lh-rh);
		if(delta<=1)
			return src;
		else{
			//Left Left case ~ Right Rotate.[Diagram Helps]
			if(lh>rh && src->left->left->height>src->left->right->height)
				return rightRotate(src);
			//Left Right case ~ Left|Right Rotate.
			else if(lh>rh && src->left->left->height<src->left->right->height){
				src->left=leftRotate(src->left);
				return rightRotate(src);
			}
			//Left Right case ~ Right|Lefft Rotate.
			else if(rh>lh && src->left->left->height<src->left->right->height){
				src->right=rightRotate(src->right);
				return leftRotate(src);
			}
			//Right Right case ~ Left Rotate.
			else
				return leftRotate(src);			
		}
	}
	node* deleteUtil(node* src,int value){
		return src;
	}
	bool findUtil(node* src,int value){
		if(!src)return false;
		if(src->value==value)return true;
		if(src->value>value)return findUtil(src->left,value);
		else return findUtil(src->right,value);
	}
	void inorderUtil(node* src)
	{	
		if(!src)return;
		inorderUtil(src->left);
		printf("(Val[%d],Ht[%d]), ",src->value,src->height);
		inorderUtil(src->right);
	}
	void verifyUtil(node* src,vi& arr)
	{
		if(!src)return;
		verifyUtil(src->left,arr);
		arr.push_back(src->value);
		verifyUtil(src->right,arr);
	}
public :
	AVLTree(){
		root=NULL;
	}
	void insert_(int value){
#ifdef DBG
		cout<<value<<", ";
#endif
		root=insertUtil(root,value);
	}
	void delete_(int value){
		root=deleteUtil(root,value);
	}
	void update_(int val0,int val1){
		root=deleteUtil(root,val0);
		root=insertUtil(root,val1);
	}
	bool find_(int value){
		return findUtil(root,value);
	}
	void inorder_()
	{	
		printf("\nPrinting AVLTree.\n");
		inorderUtil(root);
		printf("\n----------------\n");
	}
	bool verify()
	{
		vi arr;
		verifyUtil(root,arr);
		int n=arr.size();
		for(int i=0;i<n-1;i++)
			if(arr[i]>arr[i+1])return false;
		return true;
	}
};

#define MAXN (3)
#define LIMIT (100)
//Driver Function.
int main(){
	AVLTree obj;
	for(int i=0;i<MAXN;i++)
		obj.insert_(i%LIMIT);
	obj.inorder_();
	printf("isPresent[67]-%d\n",obj.find_(67));
	printf("isPresent[10]-%d\n",obj.find_(10));
	if(obj.verify())
		printf("VERIFIED.\n");
	else
		printf("NOT VERIFIED.\n");
	return 0;
}
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
	inline int gH(node* root){
	    if(!root)return 0;
	    return root->height;
	}
	node* leftRotate(node* src){
		node* R=src->right; 
		src->right=R->left;
		R->left=src;
		src->height=1+max(gH(src->left),gH(src->right));
		R->height=1+max(gH(R->left),gH(R->right));	
		return R;
	}
	node* rightRotate(node* src){
		node* L=src->left;
		src->left=L->right;
		L->right=src;
		src->height=1+max(gH(src->left),gH(src->right));
		L->height=1+max(gH(L->left),gH(L->right));	
		return L;	
	}
	node* insertUtil(node* src,int value){
		if(!src)
			return (new node(value,1));
		if(src->value>=value)
			src->left=insertUtil(src->left,value);
		else
			src->right=insertUtil(src->right,value);
		int lh=gH(src->left);
		int rh=gH(src->right);
		src->height=1+max(lh,rh);
		//Balancing Act.
		int delta=abs(lh-rh);
		if(delta<=1)
			return src;
		else{
			//Left Left case ~ Right Rotate.[Diagram Helps]
			if(lh>rh && src->left->value>value)
				return rightRotate(src);
			//Left Right case ~ Left|Right Rotate.
			else if(lh>rh && src->left->value<value){
				src->left=leftRotate(src->left);
				return rightRotate(src);
			}
			//Left Right case ~ Right|Lefft Rotate.
			else if(rh>lh && src->right->value>value){
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

#define MAXN (5)
#define LIMIT (100)
//Driver Function For Testing.
int main(){
	AVLTree t1,t2,t3;
//Tree 1.
	for(int i=0;i<MAXN;i++)
		t1.insert_(i%LIMIT);
	t1.inorder_();
	printf("isPresent[67]-%d\n",t1.find_(67));
	printf("isPresent[10]-%d\n",t1.find_(10));
	if(t1.verify())
		printf("t1 VERIFIED.\n");
	else
		printf("t1 NOT VERIFIED.\n");
//Tree 2
	printf("\n\n");
	for(int i=MAXN-1;i>=0;i--)
		t2.insert_(i%LIMIT);
	t2.inorder_();
	printf("isPresent[67]-%d\n",t2.find_(67));
	printf("isPresent[10]-%d\n",t2.find_(10));
	if(t2.verify())
		printf("t2 VERIFIED.\n");
	else
		printf("t2 NOT VERIFIED.\n");
//Tree 3
	printf("\n\n");
	int data[5]={5,1,8,2,3};
	int sz=sizeof(data)/sizeof(data[0]);
	for(int i=0;i<sz;i++)
		t3.insert_(data[i]);
	t3.inorder_();
	printf("isPresent[67]-%d\n",t3.find_(data[0]));
	printf("isPresent[10]-%d\n",t3.find_(data[4]));
	if(t3.verify())
		printf("t3 VERIFIED.\n");
	else
		printf("t3 NOT VERIFIED.\n");
	return 0;
}
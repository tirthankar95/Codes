#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
struct node{
    double value;
    bool isLeaf;
    node* right;
    node* left;
};
const int mxSize=1e6+1;
node pool[mxSize];
int poolPtr=0;
node* create(double value){
    node* tmp=&pool[poolPtr];
    poolPtr=(poolPtr+1)%mxSize;
    tmp->isLeaf=false;
    tmp->right=NULL;tmp->left=NULL;
    tmp->value=value;
    return tmp;
}
class Solution {
    node* finTree;
    double mxVal;
    string dfs(node* root)
    {
        if(root==NULL)return "";
        string tmpL="",tmpR="";
        if(root->left)
            tmpL=(root->left->isLeaf)?to_string((int)root->left->value):dfs(root->left);
        if(root->right)
            tmpR=(root->right->isLeaf)?to_string((int)root->right->value):dfs(root->right);
        return "("+tmpL+"/"+tmpR+")";
    }
    void construct(vector<node*> subTrees)
    {
        int n=subTrees.size();
        if(n==1)
        {
            if(mxVal<subTrees[0]->value)
            {
                mxVal=subTrees[0]->value;
                finTree=subTrees[0];
            }
            return;
        }
        vector<node*> nT(n-1);
        int f=-1;int s=1;
        for(int i=0;i<n-1;i++)
        {
            if(f!=-1)nT[f]=subTrees[i-1];
            f++;
            nT[f]=create(subTrees[i]->value/subTrees[i+1]->value);
            nT[f]->left=subTrees[i];
            nT[f]->right=subTrees[i+1];
            for(int k=i+2;k<n;k++)
                nT[f+(k-(i+1))]=subTrees[k];
            construct(nT);
        }
    }
public:
    string optimalDivision(vi& nums) {
        int n=nums.size();
        if(n==1)return to_string(nums[0]);
        vector<node*> subTrees(n);
        for(int i=0;i<n;i++)
        {
            subTrees[i]=create(nums[i]);
            subTrees[i]->isLeaf=true;
        }//end of for.
        finTree=NULL;mxVal=INT_MIN;
        construct(subTrees);
        return dfs(finTree);
    }
};
//Check the pattern;
int main(){
    Solution obj;
    for(int t=1;t<=100;t++)
    {
        int n=5;
        vi nums(n);
        for(int i=0;i<n;i++)
        {
            int no=rand()%100;
            nums[i]=no;
        }
        cout<<obj.optimalDivision(nums)<<endl;
    }
    return 0;
}


/*
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans="";
        ans=to_string(nums[0])+"/(";
        int n=nums.size();
        if(n==1)return to_string(nums[0]);
        if(n==2)return to_string(nums[0])+"/"+to_string(nums[1]);
        for(int i=1;i<n-1;i++)
            ans+=to_string(nums[i])+"/";
        ans+=to_string(nums[n-1])+')';
        return ans;
    }
};
*/
////////////////////////////////// SOL 1. //////////////////////////////////
const int mxSize=5e4+1;
typedef long long ll;

struct node{
    ll val;
    ll number;
    node *left,*right;
};
node pool[mxSize];
ll poolPtr;
node* create(ll element)
{
    node* tmp=&pool[poolPtr];
    poolPtr=(poolPtr+1)%mxSize;
    tmp->val=element;
    tmp->number=1;
    tmp->left=tmp->right=NULL;
    return tmp;
}

class Btree{
public:
    node* insert(node* root,ll element)
    {
        if(root==NULL)
            return create(element);
        if(root->val<=element)
        {
            root->right=insert(root->right,element);
            root->number+=1;   
        }
        else 
            root->left=insert(root->left,element);
        return root;
    }
    ll calc(node* root,ll element)
    {
        if(root==NULL)return 0;
        if(root->val>2*element)
            return calc(root->left,element)+root->number;
        else
            return calc(root->right,element);
    }
};
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int j,gCnt,cnt=0;
        Btree obj;node* root=NULL;
        for(int i=0;i<n;i++)
        {
            cnt+=obj.calc(root,nums[i]);
            root=obj.insert(root,nums[i]);
        }
        return cnt;
    }
};
////////////////////////////////// SOL 2. //////////////////////////////////
https://www.topcoder.com/thrive/articles/Binary%20Indexed%20Trees
typedef vector<int> vi;
typedef long long ll;

class BIT{
    int n;
    vi tree;
public:
    BIT(int mxSize)
    {
        this->n=mxSize;
        tree.resize(2*this->n+1,0);
    }
    int read(int indx)
    {
        int sum=0;
        while(indx>0)
        {
            sum+=tree[indx];
            indx-=(-indx&indx);
        }
        return sum;
    }
    void update(int indx,int freq)
    {
        while(indx<(2*this->n+1))
        {
            tree[indx]+=freq;
            indx+=(-indx&indx);
        }
    }
};
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        vector<ll> nums_copy(2*n);
        for(int i=0;i<n;i++)
            nums_copy[i]=nums[i];
        for(int i=0;i<n;i++)
            nums_copy[n+i]=nums[i]*2LL;
        sort(nums_copy.begin(),nums_copy.end());
        unordered_map<ll,int> id;int iter=1;
        for(int i=0;i<2*n;i++)
            if(id.find(nums_copy[i])==id.end())
                id[nums_copy[i]]=iter++;
        BIT obj(2*n);
        int cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            cnt+=obj.read(id[nums[i]]-1);
            obj.update(id[2LL*nums[i]],1);
        }
        return cnt;
    }
};
*************ALT*************
int reversePairs(vector<int>& nums)
{
    int n = nums.size();
    vector<int> nums_copy(nums);

    sort(nums_copy.begin(), nums_copy.end());

    vector<int> BITS(n + 1, 0);
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += query(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), 2LL * nums[i] + 1) - nums_copy.begin() + 1);
        update(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), nums[i]) - nums_copy.begin() + 1, 1);
    }
    return count;
}
*****************************
///////////////////////////////// SOL 3. //////////////////////////////////
typedef vector<int> vi;
typedef long long ll;

class Solution {
    int cnt;
    int lower_(int lb,int ub,vi& nums,ll element)
    {
        int mid;
        while(lb<=ub)
        {
            mid=(lb+ub)/2;
            if((ll)nums[mid]<=element)lb=mid+1;
            else if(nums[mid]>element)ub=mid-1;
        }
        return (lb>=0)?lb:0;
    }
    void merge(vi& nums,int lb,int mid,int ub)
    {
        int p1=lb,p2=mid+1;
        int e1=mid,e2=ub;
        vi tmp(e2-p1+1);int iter=0;
        while(p1<=e1 && p2<=e2)
        {
            if(nums[p1]<nums[p2])
                tmp[iter++]=nums[p1++];
            else
                tmp[iter++]=nums[p2++];
        }//end of while.
        while(p1<=e1){
            tmp[iter++]=nums[p1++];
        }
        while(p2<=e2){
            tmp[iter++]=nums[p2++];
        }
        for(int i=lb;i<=ub;i++)
            nums[i]=tmp[i-lb];
    }
    void msort(vi& nums,int lb,int ub)
    {
        if(lb>=ub)return;
        int mid=(lb+ub)/2;
        msort(nums,lb,mid);
        msort(nums,mid+1,ub);
        int j=lb;
        for(int i=mid+1;i<=ub;i++)
        {
            while(j<=mid && nums[j]<=2LL*nums[i])
                j++;
            cnt+=(mid-j+1);
        }
        merge(nums,lb,mid,ub);
    }
public:
    int reversePairs(vector<int>& nums) {
        cnt=0;
        msort(nums,0,nums.size()-1);
        return cnt;
    }
};


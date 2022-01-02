// This will give TLE as number of common subproblems is much lesser 
// Instead if fn(lb,mid)+fn(mid,ub) is passed, the number of subproblems will me much higher.
typedef vector<int> vi;
const int mxSize=1e5+1;
const int mxSize2=501;
struct node{
    int key[mxSize2];
    int value;
    node* next;
};
int N;
node pool[3*mxSize];
int poolPtr;

class hashMap{
    node** dp;
    int getHash(vi& arr){
        int hash=0,pow2=1;
        for(int i=0;i<N;i++)
        {
            hash=(hash+arr[i]*pow2)%mxSize;
            pow2=(pow2<<1)%mxSize;
        }
        return hash%mxSize;
    }
    node* getNode(vi& arr,int val){
        node* tmp=&pool[poolPtr];
        poolPtr=(poolPtr+1)%mxSize;
        for(int i=0;i<N;i++)tmp->key[i]=arr[i];
        tmp->value=val;tmp->next=NULL;
        return tmp;
    }
public:
    hashMap(){
        poolPtr=0;
        dp=new node*[mxSize];
        for(int i=0;i<mxSize;i++)dp[i]=NULL;
    }
    void insert(vi& arr,int val){
        int gH=getHash(arr);
        node* tmp=getNode(arr,val);
        tmp->next=dp[gH];
        dp[gH]=tmp;
    }
    int found(vi& arr){
        int gH=getHash(arr),i;
        if(dp[gH]==NULL)return -1;
        node* head=dp[gH];
        while(head!=NULL){
            for(i=0;i<N;i++){
                if(head->key[i]!=arr[i])
                    break;
            }//end of for.
            if(i==N)return head->value;
            head=head->next;
        }//end of while.
        return -1;
    }
};
class Solution {
    hashMap dp;
    int fn(vi& nums,vi& flag){
        int mx=0,prod,lb=-1,mid=-1,res;
        if((res=dp.found(flag)) && res!=-1)
            return res;
        for(int ub=0;ub<N;ub++){
            if(flag[ub] && mid!=-1){
                flag[mid]=0;
                prod=nums[mid]*nums[ub];
                if(lb!=-1)
                    prod*=nums[lb];
                mx=max(mx,prod+fn(nums,flag));
                flag[mid]=1;
                lb=mid;mid=ub;
            }//end of if.
            else if(flag[ub])mid=ub;
        }//end of for.
// It means no element are present.
        if(mid==-1)
            return 0;
// It means only one element is present.
        if(lb==-1)
            return nums[mid];
// For the last two elements.
        flag[mid]=0;
        prod=nums[lb]*nums[mid];
        mx=max(mx,prod+fn(nums,flag));
        flag[mid]=1;
        dp.insert(flag,mx);
        return mx;
    }
public:
    int maxCoins(vi& nums) {
        N=nums.size(); 
        vi flag(N,1);
        hashMap* obj=new hashMap;
        dp=*obj;
        return fn(nums,flag);
    }
};

/* Optimized Solution That Will Work */
/*
First of all, dp[i][j] in here means, the maximum coins we get after we burst all the balloons between i and j in the original array.
For example with input [3,1,5,8] :
dp[0][0] means we burst ballons between [0,0], which means we only burst the first balloon in original array. So dp[0][0] is 1 * 3 * 1 = 3.
dp[1][1] means we burst balloons between [1][1], which means we only burst the second ballon in the original array. So dp[1][1] is 3 * 1 * 5 = 15.

So in the end for this problem we want to find out dp[0][ arr.length - 1 ], which is the maximum value we can get when we burst all the balloon between [0 , length -1]
To get that we need the transition function :

for (int k = left; k <= right; ++k)
dp[left][right] = max(dp[left][right], nums[left-1] * nums[k] * nums[right+1] + dp[left][k-1] + dp[k+1][right])**
This transition function basically says in order to get the maximum value we can get for bursting all the balloons between [ i , j] , we just loop through each balloon between these two indexes and make them to be the last balloon to be burst,

why we pick it as the last balloon to burst ?
For example when calculating dp[0,3] and picking index 2 as the last balloon to burst,
[ 3 , 1 , 5 , 8] , that means 5 is the last balloon to burst between [0,3] , to get the maximum value when picking 5 as the last balloon to burst :
max = maximum value of bursting all the balloon on the left side of 5 + maximum value of bursting all the balloon on the right side of 5 + bursting balloon 5 when left side and right side are gone.

That is dp[0, 1] + nums[0 - 1] * nums[2] * nums[3 + 1] + dp[3,3];
That is dp[left, k - 1] + nums[left - 1] * nums[k] * nums[right + 1] + dp[k+1, right] ;
to get the maximum dp[left, right] we just loop through all the possible value of k to get the maximum.
Thanks to @hi-malik
*/
const int mxSize=502;
typedef vector<int> vi;
int dp[mxSize][mxSize];
class Solution {
public:
    int maxCoins(vi& arr) {
        int n=arr.size();
        int left,right,mid,ub,mx;
        for(int gap=0;gap<n;gap++){ 
            for(int j=0;j+gap<n;j++){
                ub=j+gap;
                mx=0;
                for(int l=j;l<=ub;l++)
                {
                    left=(l==j)?0:dp[j][l-1];
                    right=(l==ub)?0:dp[l+1][ub];
                    mid=((j==0)?1:arr[j-1])*arr[l]*((ub==n-1)?1:arr[ub+1]);
                    mx=max(mx,left+right+mid);
                }
                dp[j][ub]=mx;
            }
        }
        return dp[0][n-1];
    }
};

/* Working */
#define ll long long
ll dp[504][504];
class Solution {
public:
    vector<int> nums;
    int n;
    ll simul(int l,int r)
    {
        if(l>=r)return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        ll temp=0,prev=nums[l],next=nums[r];
        for(int i=l+1;i<r;i++)
            temp=max(temp,(prev*next*nums[i])+simul(l,i)+simul(i,r) );
        return dp[l][r]=temp;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        this->nums=nums;
        this->nums.push_back(1);
        this->nums.insert(this->nums.begin(),1);
        n=this->nums.size();
        return simul(0,n-1);
    }
};
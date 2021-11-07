typedef long long ll;
int isFirst=true;
const int mxSize=20;
ll dp[mxSize];

class Solution {
    int fn(vector<int>& nodes,int lb,int ub){
        if(dp[ub-lb+1]!=-1)return dp[ub-lb+1];
        int cnt=0;
        for(int i=lb;i<=ub;i++)
            cnt+=fn(nodes,lb,i-1)*fn(nodes,i+1,ub);
        return dp[ub-lb+1]=cnt;
    }
public:
    int numTrees(int n) {
        if(isFirst)
        {
            vector<int> nodes(mxSize-1);
            memset(dp,-1,sizeof(dp));
            for(int i=0;i<mxSize-1;i++)
                nodes[i]=i+1;
            dp[0]=1;dp[1]=1;
            fn(nodes,0,mxSize-2);
            isFirst=false;
        }
        return dp[n];
    }
};
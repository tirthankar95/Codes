//#define TLE
typedef long long ll;
const ll CONST=1e5+1;
inline ll make(int a,int b){
    return (ll)((ll)a*CONST+(ll)b);
}

const int mxSize=1e3+1;
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n=nums.size();
        int m=mul.size();
        int gap=n-m,ub;
        int bigG=n-m;
        int iter=m-1;
#ifdef TLE        
        unordered_map <ll,int> dp;
#endif
        int dp[mxSize][mxSize];
//EDGE Case.
        for(int lb=0;lb+gap<n;lb++){
            ub=lb+gap;
            dp[lb][gap-bigG]=max(mul[iter]*nums[lb],mul[iter]*nums[ub]);
#ifdef TLE
            dp[make(lb,ub)]=max(mul[iter]*nums[lb],mul[iter]*nums[ub]);
#endif
        }
        iter--;
        gap++;
//GENERAL Case.
        while(iter>=0)
        {
            for(int lb=0;lb+gap<n;lb++){
                ub=lb+gap;
                dp[lb][gap-bigG]=max(mul[iter]*nums[lb]+dp[lb+1][gap-1-bigG],\
                                    mul[iter]*nums[ub]+dp[lb][gap-1-bigG]);
#ifdef TLE
                dp[make(lb,ub)]=max(mul[iter]*nums[lb]+dp[make(lb+1,ub)],\
                                    mul[iter]*nums[ub]+dp[make(lb,ub-1)]);
#endif
            }//end of for-inner.
            iter--;
            gap++;
        }//end of while.
#ifdef TLE
        return dp[make(0,n-1)];
#endif
        return dp[0][gap-1-bigG];
    }
};
typedef pair<int,int> ii;
typedef vector<int> vi;
class Solution {
public:
    vi largestDivisibleSubset(vi& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),mx=0,id;
        vector<ii> dp(n);//first=length;second=indexOfNxtElement;
        for(int i=n-1;i>=0;i--){
            dp[i].first=1,dp[i].second=-1;
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0 && dp[i].first<1+dp[j].first){
                    dp[i].first=1+dp[j].first;
                    dp[i].second=j;
                }//end of if.
            }//end of inner-for.
            if(mx<dp[i].first){
                mx=dp[i].first;
                id=i;
            }
        }//end of outer-for. 
        vi sol(dp[id].first);
        int iter=id;
        for(int i=0;i<dp[id].first;i++)
        {
            sol[i]=nums[iter];
            iter=dp[iter].second;
        }
        return sol;
    }
};
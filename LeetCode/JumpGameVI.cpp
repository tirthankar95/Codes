typedef pair<int,int> ii;
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n,0);
        priority_queue<ii> pQ;ii element;
        dp[0]=nums[0];
        pQ.push(ii(dp[0],0));
        for(int i=1;i<n;i++){
            dp[i]=nums[i];
            while(!pQ.empty())
            {
                element=pQ.top();
                if(element.second+k>=i)
                    break;
                pQ.pop();
            }
            /*mx=INT_MIN;
            for(int j=i-1;j>=max(0,i-k);j--){
                if(nums[j]>=0)
                {
                    mx=dp[j];
                    break;
                }
                else mx=max(mx,dp[j]);
            }//inner.*/
            dp[i]+=element.first;
            pQ.push(ii(dp[i],i));
        }//outer.
        return dp[n-1];
    }
};
const int mxSize=1e3+1;
bool dp[mxSize][mxSize];
class Solution {
    void debug(int r,int c)
    {
        for(int i=0;i<r;i++)
        {
            cout<<i+1<<"-th row :\n";
            for(int j=0;j<c;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
    }
    int minPatches2(vector<int>& nums, int n)
    {
        memset(dp,false,sizeof(dp));
        for(int i=0;i<mxSize;i++)dp[i][0]=true;
        int m=nums.size();
        dp[0][nums[0]]=true; // row 0 means only taking the first element.
        n=min(mxSize-1,n);
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j>=nums[i]) dp[i][j]|=dp[i-1][j-nums[i]];
            }//end of inner for.
        }//end of outer for.
        int cnt=0;
        for(int i=m;i<mxSize;i++)
        {
            int missing_=-1;
            for(int j=1;j<=n;j++)
            {
                if(i-1>=0 && dp[i-1][j]==false)
                {
                    missing_=j;
                    break;
                }
            }//end of for-j.
            if(missing_==-1)break;
            cnt++;cout<<missing_<<endl;
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j>=missing_) dp[i][j]|=dp[i-1][j-missing_];
            }//end of inner for.
        }
        //debug(m,n+1);
        return cnt;        
    }
public:
    int minPatches(vector<int>& nums, int n)
    {
        int cnt=0,i=0;
        long long recSum=0;
        int sz=nums.size();
        // For 1.
        if(i<sz && nums[i]==1)recSum=1,i++;
        else{
            recSum=1;
            cnt=1;
        }
        while(recSum<n)
        {
            if(i<sz && recSum+1>=nums[i])recSum+=nums[i++];
            else{
                recSum+=(recSum+1);
                cnt+=1;
            }//end of else.
            //cout<<recSum<<" "<<cnt<<endl;
        }
        //cout<<minPatches2(nums,n)<<endl;
        return cnt;
       
    }
};
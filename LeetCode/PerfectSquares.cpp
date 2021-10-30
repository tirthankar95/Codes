bool first=true;
const int mxSize=1e4+1;
int dp[mxSize];
vector<int> squares;

class Solution {
public:
    int numSquares(int n) {
        if(first)
        {
            first=false;
            for(int i=1;i<=100;i++)
                squares.push_back(i*i);
            int nn=squares.size();
            dp[0]=0;
            for(int i=1;i<mxSize;i++)
            {
                dp[i]=mxSize;
                for(int j=0;j<nn;j++)
                {
                    if(squares[j]>i)break;
                    dp[i]=min(dp[i],1+dp[i-squares[j]]);
                }
            }//end of for-i. 
        }
        return dp[n];
    }
};
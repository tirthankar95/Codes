const int mxSize=501;
int dp[mxSize][mxSize];

class Solution {
    void init(int dim0,int dim1){
        for(int i=0;i<=dim0;i++){
            for(int j=0;j<=dim1;j++)
                dp[i][j]=0;
        }
    }
public:
    int minDistance(string word1, string word2){
        int n0=word1.length();
        int n1=word2.length();
        init(n0,n1);
        for(int i=0;i<n0;i++)
        {
            for(int j=0;j<n1;j++)
            {
                if(word1[i]==word2[j])
                    dp[i+1][j+1]=1+dp[i][j];
                else 
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);                
            }//end of for-j.
        }//end of for-i.
        return (n0+n1-2*dp[n0][n1]);
    }
};
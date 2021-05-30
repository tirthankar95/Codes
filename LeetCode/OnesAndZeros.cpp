typedef pair<int,int> ii;
typedef vector<ii> vii;
const int dim1=601;
const int dim2=101;
int dp[dim1][dim2][dim2];

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N=strs.size();
        vii  count(N);
        for(int i=0;i<N;i++)
        {
            int one=0;
            for(int j=0;j<strs[i].length();j++)
                if(strs[i][j]=='1')one++;
            count[i]=ii(strs[i].length()-one,one);
        }
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                    dp[i][j][k]=0;
            }
        }//end of outer-i.
        int tmp;
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    if(count[i-1].first>j || count[i-1].second>k)
                        dp[i][j][k]=max(dp[i-1][j][k],dp[i][j][k]);
                    else
                    {
                        tmp=dp[i-1][j-count[i-1].first][k-count[i-1].second];
                        dp[i][j][k]=max(max(dp[i-1][j][k],1+tmp),dp[i][j][k]);    
                    }
                }//k.
            }//j.
        }//i.
        return dp[N][m][n]; 
    }
};
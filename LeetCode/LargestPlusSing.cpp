typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int m=mines.size();
        if(m==n*n)return 0;
        vvi matrix(n,vi(n,1));
        for(int i=0;i<m;i++)
            matrix[mines[i][0]][mines[i][1]]=0;
/////////////////////////////////////////////////////////////
        vvi lr(n,vi(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0){
                    lr[i][j]=matrix[i][j];
                    continue;
                }
                if(matrix[i][j]==0)lr[i][j]=0;
                else lr[i][j]=lr[i][j-1]+1;
            }
        }
/////////////////////////////////////////////////////////////
        vvi rl(n,vi(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(j==n-1){
                    rl[i][j]=matrix[i][j];
                    continue;
                }
                if(matrix[i][j]==0)rl[i][j]=0;
                else rl[i][j]=rl[i][j+1]+1;
            }
        }
/////////////////////////////////////////////////////////////
        vvi ud(n,vi(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0){
                    ud[i][j]=matrix[i][j];
                    continue;
                }
                if(matrix[i][j]==0)ud[i][j]=0;
                else ud[i][j]=ud[i-1][j]+1;
            }
        }
/////////////////////////////////////////////////////////////
        vvi du(n,vi(n,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(i==n-1){
                    du[i][j]=matrix[i][j];
                    continue;
                }
                if(matrix[i][j]==0)du[i][j]=0;
                else du[i][j]=du[i+1][j]+1;
            }
        }
/////////////////////////////////////////////////////////////
        int lr_,rl_,ud_,du_;
        int mx=0;
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(matrix[i][j]==0)continue;    
                lr_=lr[i][j-1];
                rl_=rl[i][j+1];
                ud_=ud[i-1][j];
                du_=du[i+1][j];
                mx=max(mx,min(min(lr_,rl_),min(ud_,du_)));
            }
        }
        return 1+mx;
    }
};
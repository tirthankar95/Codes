//Better to use BFS from the edges.
//Complicated method for same elements. 
//Another DFS implementation [ from edges ]
https://leetcode.com/problems/pacific-atlantic-water-flow/discuss/1126812/JS-Python-Java-C%2B%2B-or-Easy-DFS-Recursion-DP-Solution-w-Explanation
/*
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& M) {
        vector<vector<int>> ans;
        if (M.empty()) return ans;
        int y = M.size(), x = M[0].size();
        vector<char> dp(y * x);
        for (int i = 0; i < y; i++) {
            dfs(M, dp, i, 0, 1, 0);
            dfs(M, dp, i, x - 1, 2, 0);
        }
        for (int i = 0; i < x; i++) {
            dfs(M, dp, 0, i, 1, 0);
            dfs(M, dp, y - 1, i, 2, 0);
        }
        for (int i = 0; i < y; i++) 
            for (int j = 0; j < x; j++) 
                if (dp[i * x + j] == 3) 
                    ans.push_back({i, j});
        return ans;
    }
private:
    void dfs(const vector<vector<int>>& M, vector<char>& dp, int i, int j, int w, int h) {
        int y = M.size(), x = M[0].size(), ij = i * x + j, newh = M[i][j];;
        if ((dp[ij] & w) || M[i][j] < h) return;
        dp[ij] += w;
        if (i + 1 < y) dfs(M, dp, i + 1, j, w, newh);
        if (i > 0) dfs(M, dp, i - 1, j, w, newh);
        if (j + 1 < x) dfs(M, dp, i, j + 1, w, newh);
        if (j > 0) dfs(M, dp, i, j - 1, w, newh);
    }
};
*/

typedef vector<int> vi;
typedef vector<vi> vvi;
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const int PACIFIC=1;
const int ATLANTIC=2;
const int mxSize=201;
vvi dp(mxSize,vi(mxSize));
vector<vector<bool>> vis(mxSize,vector<bool>(mxSize));

class Solution {
    int R,C;
    int dfs(int i,int j,vvi& heights)
    {
        vis[i][j]=true;
        int deli,delj;
        bool tmp;
        vvi travLater;
        for(int iter=0;iter<4;iter++)
        {
            deli=i+dir[iter][0];
            delj=j+dir[iter][1];
            if(deli>=0 && delj>=0 && deli<R && delj<C)
            {
                if(heights[deli][delj]<heights[i][j])
                {
                    if(!vis[deli][delj])dp[i][j]|=dfs(deli,delj,heights);
                    else dp[i][j]|=dp[deli][delj];
                }
                else if(heights[deli][delj]==heights[i][j])
                {
                    travLater.push_back(vi({deli,delj}));
                }
            }
        }
        for(int iter=0;iter<travLater.size();iter++)
        {
            deli=travLater[iter][0];
            delj=travLater[iter][1];
            if(!vis[deli][delj])dp[i][j]|=dfs(deli,delj,heights);
            else dp[i][j]|=dp[deli][delj];            
        }
        return dp[i][j];
    }
public:
    vvi pacificAtlantic(vvi& heights) {
        R=heights.size();
        C=heights[0].size();
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                dp[i][j]=0,vis[i][j]=false;
        for(int i=0;i<R;i++)
        {
            dp[i][0]|=PACIFIC;
            dp[i][C-1]|=ATLANTIC;
        }
        for(int j=0;j<C;j++)
        {
            dp[0][j]|=PACIFIC;
            dp[R-1][j]|=ATLANTIC;
        }
        vvi sol;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                //last row from left side...  15,16,16. that is why we traverse elements already traversed.
                if( dfs(i,j,heights)==(ATLANTIC|PACIFIC) )
                    sol.push_back(vi({i,j}));
            }
        }//end of outer-for. 
        return sol;
    }
};
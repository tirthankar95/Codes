static int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
class Solution {
    int r,c;
    int res;
    public:
    void path(vector<vector<int>>& grid,vector<vector<bool>>& vis,int i_,int j_,int cnt)
    {
        if(grid[i_][j_]==2 && cnt==0)
        {    
            res++;
            return;
        }
        else if(cnt==0 || grid[i_][j_]==2)
            return;
        vis[i_][j_]=true;
        int ic,jc;
        for(int delta=0;delta<4;delta++)
        {
            ic=i_+dir[delta][0];
            jc=j_+dir[delta][1];
            if(ic<0 || jc<0 || ic>=r || jc>=c || vis[ic][jc] || grid[ic][jc]==-1)
                continue;
            path(grid,vis,ic,jc,cnt-1);
        }
        vis[i_][j_]=false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        r=grid.size();
        c=grid[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        int cnt=0;int init_i,init_j;
        res=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==0)cnt++;
                else if(grid[i][j]==1){
                    init_i=i;
                    init_j=j;
                }
            }
        }//end of outer-for.
        path(grid,vis,init_i,init_j,cnt+1);
        return res;
    }
};
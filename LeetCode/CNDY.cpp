int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
class Solution {
    int r,c,count,id;
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,vector<vector<int>>& islandId,int srci,int srcj)
    {
        vis[srci][srcj]=1;
        islandId[srci][srcj]=id;
        count++;
        int ci,cj;
        for(int d=0;d<4;d++)
        {
            ci=srci+dir[d][0];
            cj=srcj+dir[d][1];
            if(ci<0 || ci>=r || cj<0 || cj>=c || vis[ci][cj])continue;
            else if(grid[ci][cj])dfs(grid,vis,islandId,ci,cj);
        }
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        r=grid.size();
        c=grid[0].size();
        unordered_map<int,int> hashMap;
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        vector<vector<int>> islandId(r,vector<int>(c,0)); // starts from 1. 
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    id++;
                    count=0;
                    dfs(grid,vis,islandId,i,j);
                    hashMap[id]=count;
                }
            }
        }//end of outer for-i.
/////////////////////////////////////////////////
        int mx=1;
        for(int iter=1;iter<=id;iter++)
            mx=max(mx,hashMap[iter]);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==0)
                {
                    int xx,yy,tmp=1;
                    unordered_map<int,bool> _used_;
                    for(int k=0;k<4;k++)
                    {
                        xx=(i+dir[k][0]);
                        yy=(j+dir[k][1]); 
                        if(xx>=0 && yy>=0 && xx<r && yy<c && !_used_[islandId[xx][yy]])
                        {
                            tmp+=hashMap[islandId[xx][yy]];
                            _used_[islandId[xx][yy]]=true;
                        }
                            
                    }
                    mx=max(mx,tmp);
                }//end of if.
            }//end of outer-j.
        }//end of outer-i.
/////////////////////////////////////////////////
        return mx;
    }
};
typedef pair<int,int> ii;
static int delta[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        queue<ii> qu;
        int ip,jp,ip_,jp_;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2)
                {
                    qu.push(ii(i*c+j,0));
                    vis[i][j]=true;
                }
            }
        }//end of for-i.
        int ans=0;
        while(!qu.empty())
        {
            ii element=qu.front();
            qu.pop();
            ip=element.first/c;
            jp=element.first%c;
            for(int i=0;i<4;i++)
            {
                ip_=ip+delta[i][0];
                jp_=jp+delta[i][1];
                if(ip_<0 || jp_<0 || ip_>=r || jp_>=c || vis[ip_][jp_])continue;
                if(!(grid[ip_][jp_]==1))continue;
                qu.push(ii(ip_*c+jp_,element.second+1));
                vis[ip_][jp_]=true;
                grid[ip_][jp_]=2;
                ans=max(ans,element.second+1);
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)return -1;
            }
        }
        return ans;
    }
};
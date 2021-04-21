class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int tmp,ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                tmp=4;
                if(grid[i][j])
                {
                    if(i-1>=0 && grid[i-1][j])tmp--;
                    if(i+1<n && grid[i+1][j])tmp--;
                    if(j-1>=0 && grid[i][j-1])tmp--;
                    if(j+1<m && grid[i][j+1])tmp--;
                    ans+=tmp;
                }
            }//end of inner-for.
        }//end of outer-for. 
        return ans;
    }
};
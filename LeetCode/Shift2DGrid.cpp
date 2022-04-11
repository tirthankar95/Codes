class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r=grid.size();
        int c=grid[0].size();
        int temp;
        vector<vector<int>> sol(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                temp=(i*c+j+k)%(r*c);
                sol[temp/c][temp%c]=grid[i][j];
            }//end of for-j.
        }//end of for-i.
        return sol;
    }
};

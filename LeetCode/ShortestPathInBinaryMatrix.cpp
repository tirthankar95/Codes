int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> paths(r,vector<int>(c,-1));
        queue<int> q;
        if(!grid[0][0])
        {
            q.push(0);
            paths[0][0]=1;
        }
        int sr,sc,cr,cc;
        while(!q.empty()){
            sr=q.front()/c;
            sc=q.front()%c;
            q.pop();
            for(int i=0;i<8;i++){
                cr=sr+dir[i][0];
                cc=sc+dir[i][1];
                if( cc>=0 && cc<c && cr>=0 && cr<r && !grid[cr][cc] && paths[cr][cc]==-1 ){
                    paths[cr][cc]=paths[sr][sc]+1;
                    q.push(cr*c+cc);
                }
            }//end of for.
        }
        return paths[r-1][c-1];
    }
};
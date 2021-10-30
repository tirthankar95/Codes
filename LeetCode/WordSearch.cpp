uFormat1Index;static int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
typedef pair<int,int> ii;

class Solution {
    int n,m,sz;
    bool dfs(ii src,vector<vector<char>>& board,vector<vector<bool>>& vis,string word,int index)
    {
        vis[src.first][src.second]=true;
        if(index>=sz)return true;
        for(int i=0;i<4;i++)
        {
            int ic=src.first+dir[i][0];
            int jc=src.second+dir[i][1];
            if(ic<0 || jc<0 || ic>=n || jc>=m || vis[ic][jc])continue;
            if(word[index]==board[ic][jc] && dfs(ii(ic,jc),board,vis,word,index+1))
                return true;
        }
        vis[src.first][src.second]=false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        sz=word.length();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(ii(i,j),board,vis,word,1))return true;
                }
            }//end of inner for.
        }//end of outer for. 
        return false;
    }
};
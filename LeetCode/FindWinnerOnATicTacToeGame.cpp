static string player[2]={"A","B"};

class Solution {
    bool ifWon(int grid[3][3],int symbol)
    {
        for(int i=0;i<3;i++)
        {
            if(grid[i][0]==symbol && grid[i][1]==symbol && grid[i][2]==symbol)return true;
            if(grid[0][i]==symbol && grid[1][i]==symbol && grid[2][i]==symbol)return true;
        }
        if(grid[0][0]==symbol && grid[1][1]==symbol && grid[2][2]==symbol)return true;
        if(grid[0][2]==symbol && grid[1][1]==symbol && grid[2][0]==symbol)return true;
        return false;
    }
public:
    string tictactoe(vector<vector<int>>& moves) {
        int grid[3][3];
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                grid[i][j]=-1;
        int n=moves.size();int cnt=0;
        for(int i=0;i<n;i++)
        {
            grid[moves[i][0]][moves[i][1]]=cnt;
            if(ifWon(grid,cnt))
                return player[cnt];
            cnt=(cnt+1)%2;
        }
        if(n==9)return "Draw";
        else return "Pending";
    }
};
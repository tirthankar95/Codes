//#define PRINT
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r=dungeon.size();
        int c=dungeon[0].size();
        for(int i=r-1;i>=0;i--)
        {
            for(int j=c-1;j>=0;j--)
            {
                if(i==r-1 && j==c-1)continue;
                else if(i==r-1)
                    dungeon[i][j]=min(dungeon[i][j],dungeon[i][j]+dungeon[i][j+1]);
                else if(j==c-1)
                    dungeon[i][j]=min(dungeon[i][j],dungeon[i][j]+dungeon[i+1][j]);
                else
                    dungeon[i][j]=min(dungeon[i][j],dungeon[i][j]+max(dungeon[i+1][j],dungeon[i][j+1]));
            }
        }//end of for-loop.
#ifdef PRINT
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cout<<dungeon[i][j]<<" ";
            cout<<endl;
        }
#endif
        return (dungeon[0][0]<=0)?-dungeon[0][0]+1:1;
    }
};
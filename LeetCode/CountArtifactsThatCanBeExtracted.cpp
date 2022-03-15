const int mxSize=1e6+1;

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        int m=dig.size();
        for(int i=0;i<m;i++)
            grid[dig[i][0]][dig[i][1]]=mxSize;
        m=artifacts.size();
        int count=0;bool dntIncr;
        for(int i=0;i<m;i++){
            dntIncr=false;
            for(int j=artifacts[i][0];j<=artifacts[i][2];j++){
                for(int k=artifacts[i][1];k<=artifacts[i][3];k++){
                    if(grid[j][k]!=mxSize){
                        dntIncr=true;
                        break;
                    }
                }//end of for-k.
            }//end of for-j.
            if(!dntIncr)
                count++;
        }//end of for-i.
        return count;
    }
};
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m=accounts.size();
        int temp,mx=0;
        for(int i=0;i<m;i++){
            temp=0;
            for(int j=0;j<accounts[i].size();j++)
                temp+=accounts[i][j];
            mx=max(mx,temp);
        }//end of for.
        return mx;
    }
};
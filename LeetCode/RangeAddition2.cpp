class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mi=INT_MAX;
        int mx=INT_MAX;
        for(int i=0;i<ops.size();i++)
            mi=min(mi,ops[i][0]),mx=min(mx,ops[i][1]);
        if(ops.size()==0)return m*n;
        return mi*mx;
    }
};
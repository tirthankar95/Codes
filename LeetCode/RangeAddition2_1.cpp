class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int sz=ops.size();
        int mi_x=m,mi_y=n;
        for(int i=0;i<sz;i++)
        {
            mi_x=min(mi_x,ops[i][0]);
            mi_y=min(mi_y,ops[i][1]);
        }
        return mi_x*mi_y;
    }
};
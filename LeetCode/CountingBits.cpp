class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> sol(n+1,0);
        for(int i=1;i<=n;i++)
            sol[i]=1+sol[(i&(i-1))];
        return sol;
    }
};
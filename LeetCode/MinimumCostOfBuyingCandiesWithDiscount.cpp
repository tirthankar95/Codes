typedef vector<int> vi;
class Solution {
public:
    int minimumCost(vi& cost) {
        int n=cost.size();
        sort(cost.begin(),cost.end());
        int ans=0;
        for(int i=1;i<=n;i++){
            if(i%3)
                ans+=cost[n-i];
        }
        return ans;
    }
};
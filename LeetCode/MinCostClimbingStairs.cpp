class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int ppCost=cost[0],pCost=cost[1],cost_;
        int n=cost.size();
        for(int i=2;i<n;i++){
            cost_=cost[i]+min(ppCost,pCost);
            ppCost=pCost;
            pCost=cost_;
        }//end of for. 
        return min(pCost,ppCost);
    }
};
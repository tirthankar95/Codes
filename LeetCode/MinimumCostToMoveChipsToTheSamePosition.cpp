class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n=position.size();
        int odd=0,even=0;
        for(int i=0;i<n;i++)
        {
            if(position[i]%2)odd++;
            else even++;
        }//end of for.
        return min(odd,even);
    }
};
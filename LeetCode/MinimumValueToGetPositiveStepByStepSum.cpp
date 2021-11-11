typedef vector<int> vi;
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n=nums.size();
        int cSum=0;int mi=1;
        for(int i=0;i<n;i++)
        {
            cSum+=nums[i];
            mi=min(mi,cSum);
        }//end of for. 
        if(mi>=0)return 1;
        else return -mi+1;
    }
};
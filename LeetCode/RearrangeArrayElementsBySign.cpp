typedef vector<int> vi;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vi sol(n);int ptrP=0;int ptrN=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0)
                sol[ptrP]=nums[i],ptrP+=2;
            else 
                sol[ptrN]=nums[i],ptrN+=2;
        }
        return sol;
    }
};
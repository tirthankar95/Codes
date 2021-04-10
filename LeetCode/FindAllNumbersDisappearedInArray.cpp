typedef vector<int> vi;
class Solution {
public:
    vi findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
            if(nums[abs(nums[i])-1]>0)
                nums[abs(nums[i])-1]*=-1;
        vi sol;
        for(int i=1;i<=n;i++)
            if(nums[i-1]>0)sol.push_back(i);
        return sol;
    }
};
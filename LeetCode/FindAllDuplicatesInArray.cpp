typedef vector<int> vi;

class Solution {
public:
    vi findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vi sol;
        for(int i=0;i<n;i++)
        {
            if(nums[abs(nums[i])-1]<0)
                sol.push_back(abs(nums[i]));
            else nums[abs(nums[i])-1]*=-1;
        }
        return sol;
    }
};
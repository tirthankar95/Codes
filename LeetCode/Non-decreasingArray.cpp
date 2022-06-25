class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size(),p_id;
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i])
            {
                p_id=i;
                cnt++;
            }
        }//
        if(cnt>1)return false;
        if(cnt==0)return true;
        if(p_id+1==n || nums[p_id-1]<=nums[p_id+1])return true;
        if(p_id-1==0 || nums[p_id-2]<=nums[p_id])return true;
        else return false;
    }
};
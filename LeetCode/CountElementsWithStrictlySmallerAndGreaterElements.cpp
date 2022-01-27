class Solution {
public:
    int countElements(vector<int>& nums) {
        int n=nums.size();
        int mi=nums[0],mx=nums[0];
        for(int i=1;i<n;i++){
            mi=min(mi,nums[i]);
            mx=max(mx,nums[i]);
        }
        int cnt=n;
        for(int i=0;i<n;i++)
            if(nums[i]==mi || nums[i]==mx)
                cnt--;
        return cnt;
    }
};
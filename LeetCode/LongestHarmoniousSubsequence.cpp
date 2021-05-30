class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> cMap;
        for(int i=0;i<n;i++)
            cMap[nums[i]]++;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            if(cMap.find(nums[i]-1)!=cMap.end())
                mx=max(cMap[nums[i]-1]+cMap[nums[i]],mx);
        }
        return mx;
    }
};
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> hashMap;
        int n=nums.size();
        for(int i=0;i<n;i++)
            hashMap[nums[i]]++;
        vector<int> sol;
        for(int i=0;i<n;i++){
            if(hashMap[nums[i]]==1 && !hashMap[nums[i]-1] && !hashMap[nums[i]+1])
                sol.push_back(nums[i]);
        }
        return sol;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hMap;
        hMap[0]=1;
        int n=nums.size();
        int sum=0,res=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            res=res+hMap[sum-k];
            hMap[sum]++;
        }
        return res;
    }
};
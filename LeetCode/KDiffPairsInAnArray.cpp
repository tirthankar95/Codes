class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,bool> hashMap;
        int n=nums.size();
        int ans=0;
        if(k==0){
            unordered_map<int,bool> dontUse;
            for(int i=0;i<n;i++){
                if(hashMap[nums[i]] && !dontUse[nums[i]]){
                    dontUse[nums[i]]=true;
                    ans++;
                }
                hashMap[nums[i]]=true;
            }//end of for.
            return ans;
        }
        for(int i=0;i<n;i++){
            if(!hashMap[nums[i]] && hashMap[nums[i]+k])ans++;
            if(!hashMap[nums[i]] && hashMap[nums[i]-k])ans++;
            hashMap[nums[i]]=true;
        }//end of for.
        return ans;
    }
};

/*
    https://leetcode.com/problems/k-diff-pairs-in-an-array/discuss/1756874/C%2B%2B-MULTIPLE-APPROACHES-%3A-MAPS-TWO-POINTER
    Sol 1. HashMap.
    Sol 2. Two Pointer Solution
*/
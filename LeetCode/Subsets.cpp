typedef vector<int> vi;
class Solution {
    vector<vi> res;
    vi sol;
    int n;
    void fn(vi& nums,int i){
        if(i==n){
            res.push_back(sol);
            return;
        }
        fn(nums,i+1);
        sol.push_back(nums[i]);
        fn(nums,i+1);
        sol.pop_back();
    }
public:
    vector<vi> subsets(vi& nums) {
        n=nums.size();
        sol.clear();res.clear();
        fn(nums,0);
        return res;
    }
};
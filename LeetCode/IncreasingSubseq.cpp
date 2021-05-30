typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
    int N;
    vvi sol;
    map<vi,bool> hMap;
    void fn(vi& nums,vi& tmp,int lb){
        if(tmp.size()>=2 && hMap.find(tmp)==hMap.end())
            hMap[tmp]=true,sol.push_back(tmp);
        for(int i=lb+1;i<N;i++)
        {
            if(nums[lb]<=nums[i])
            {
                tmp.push_back(nums[i]);
                fn(nums,tmp,i);
                tmp.erase(tmp.end()-1);
                while(i+1<N && nums[i]==nums[i+1])i++;
            }
        }
    }
public:
    vvi findSubsequences(vi& nums) {
        N=nums.size();
        sol.clear();
        hMap.clear();
        vi tmp;
        for(int i=0;i<N;i++)
        {
            tmp.push_back(nums[i]);
            fn(nums,tmp,i);
            tmp.erase(tmp.end()-1);
            while(i+1<N && nums[i]==nums[i+1])i++;
        }
        return sol;
    }
};
////////////////// Using Set. //////////////////
class Solution {
public:
    set<vector<int>> result;
    vector<int> temp;
    void solve(vector<int> nums,int src,int last){
        if(temp.size()>1)
            result.insert(temp);
        for(int i=src;i<nums.size();i++){
            if(nums[i]>=last){
                temp.push_back(nums[i]);
                solve(nums,i+1,nums[i]);
                temp.pop_back();
            }else{
                solve(nums,i+1,last);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solve(nums,0,INT_MIN);
        vector<vector<int>> res(result.begin(),result.end());
        return res;
    }
};
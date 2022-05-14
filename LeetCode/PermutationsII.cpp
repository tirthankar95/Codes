/* Sol 1 usinig map */
class Solution {
    vector<vector<int>> sol;
    map<vector<int>,bool> isPresent;
    int n;
    void fn(vector<int>& nums,int start,vector<int> temp){
        if(start==n && isPresent.find(temp)==isPresent.end()){
            isPresent[temp]=true;
            sol.push_back(temp);
            return;
        }
        for(int i=start;i<n;i++){
            temp[start]=nums[i];
            swap(nums[i],nums[start]);
            fn(nums,start+1,temp);
            swap(nums[i],nums[start]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        vector<int> temp(n);
        sol.clear();isPresent.clear();
        fn(nums,0,temp);
        return sol;
    }
};
/* Sol 2 using hashMap */
class Solution {
    unordered_map<int,int> freq;
    vector<vector<int>> sol;
    int n;
    void fn(vector<int> temp,int cnt){
        if(cnt==n){
            sol.push_back(temp);
            return;
        }
        unordered_map<int,int>:: iterator it=freq.begin();
        for(;it!=freq.end();it++){
            if(it->second){
                it->second--;
                temp[cnt]=it->first;
                fn(temp,cnt+1);
                it->second++;
            }
        }//end of for.
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        freq.clear();
        for(int i=0;i<n;i++)
            freq[nums[i]]++;
        vector<int> temp(n);
        sol.clear();
        fn(temp,0);
        return sol;
        
    }
};
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size(),i=0,lower_,upper_;
        vector<string> res;
        while(i<n){
            if(i+1<n && nums[i]+1==nums[i+1]){
                lower_=nums[i];
                while(i+1<n && nums[i]+1==nums[i+1])i++;
                upper_=nums[i++];
                res.push_back(to_string(lower_)+"->"+to_string(upper_));
            }
            else
                res.push_back(to_string(nums[i++]));
        }//end of while
        return res;
    }
};
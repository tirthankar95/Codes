class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0,element;
        for(int i=0;i<n;i++){
            if(cnt==0){
                element=nums[i];
            }
            if(element==nums[i])cnt++;
            else cnt--;
        }//end of for. 
        return element;
    }
};
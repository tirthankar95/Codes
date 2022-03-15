class Solution {
    int maxVector(vector<int>& nums,int n){
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
            mx=max(mx,nums[i]);
        return mx;
    }
    int special(vector<int>& nums){
        int n=nums.size();
        int element;
        if((element=maxVector(nums,n))!=nums[n-1])
            return element;
        else
            return maxVector(nums,n-1);
    }
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1){
            if(k%2)return -1;
            return nums[0];
        }
        if(k>n)
            return maxVector(nums,n);
        if(k==n)
            return special(nums);
        //OPTION 1 - Take the last element.
        int mx=nums[k];
        /*OPTION 2 - Take maximum out of the k-1 elemnts. 
                     And insert that element at the top at the last moment. */
        return max(mx,maxVector(nums,k-1));
    }
};
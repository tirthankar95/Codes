typedef vector<int> vi;

class Solution {
public:
    int numberOfArithmeticSlices(vi& nums) {
        int lb=0,n=nums.size();
        int sum=0,diff;
        while(lb<n-1){
            int i=1;
            diff=nums[lb+1]-nums[lb];
            while(i<n && (nums[lb]+i*diff)==nums[lb+i])i++;
            sum+=(i-1)*(i-2)/2;
            lb+=(i-1);
        }//end of while. 
        return sum;
    }
};
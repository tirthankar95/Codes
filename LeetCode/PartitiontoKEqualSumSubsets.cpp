typedef vector<int> vi;

class Solution {
    int sum;
    int N;
    unordered_map<int,bool> isUsed;
    bool fn(int rSum,vi& nums,int i,int k){  
        if(rSum==sum){
            rSum=0;
            i=0;
            k--;
            if(k==0)return true;
        }
        while(i<N && isUsed[i])i++;
        if(i==N)return false;
        if(rSum+nums[i]<=sum )
        {
            rSum+=nums[i];
            isUsed[i]=true;
            if(fn(rSum,nums,i+1,k))return true;
            rSum-=nums[i];
            isUsed[i]=false;
        }//end of if. 
        return fn(rSum,nums,i+1,k);
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        isUsed.clear();
        N=nums.size();sum=0;
        for(int i=0;i<N;i++){
            sum+=nums[i];
            isUsed[i]=false;
        }
        if(sum%k)return false;
        sum=sum/k;
        return fn(0,nums,0,k);
    }
};
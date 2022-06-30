typedef long long ll;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //MEAN doesn't work.
        /*int n=nums.size();
        ll sum=0;
        for(int i=0;i<n;i++)sum=sum+(ll)nums[i];
        int avg0=(int)(sum/n);int avg1=ceil((double)sum/(double)n);
        cout<<avg0<<" "<<avg1<<endl;
        int res0=0,res1=0;
        for(int i=0;i<n;i++){
            res0+=abs(avg0-nums[i]);
            res1+=abs(avg1-nums[i]);
        }
        return min(res0,res1);*/
        
        //MEDIAN might work. 
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int median=0,res=0;
        if(n%2)median=nums[n/2];
        else median=(nums[n/2 - 1]+nums[n/2])/2;
        for(int i=0;i<n;i++)res+=abs(nums[i]-median);
        return res;
    }
};









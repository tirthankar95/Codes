//#define BRUTE_FORCE
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
#ifdef BRUTE_FORCE
        int n=nums.size();
        int ones,zeros;
        vector<int> oCnt(n,0);
        oCnt[0]=nums[0];
        for(int i=1;i<n;i++)
            oCnt[i]=oCnt[i-1]+nums[i];
        for(int mid=n;mid>=1;mid--)
        {
            for(int i=0;i<=n-mid;i++)
            {
                ones=oCnt[i+mid-1]-((i>0)?oCnt[i-1]:0);
                zeros=mid-ones;
                if(ones==zeros)
                    return mid;
            }
        }//end of for.
        return 0;
#endif
        int n=nums.size();
        unordered_map<int,int> hashMap;
        hashMap[0]=-1;
        int mx=0,cSum=0;
        for(int i=0;i<n;i++)
        {
            cSum=cSum+((nums[i]==0)?-1:1);
            if(hashMap.find(cSum)==hashMap.end()){
                hashMap[cSum]=i;
            }
            else
                mx=max(mx,i-hashMap[cSum]);
        }//end of for.
        return mx;
    }
};
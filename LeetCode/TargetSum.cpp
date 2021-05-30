typedef vector<int> vi;

class Solution {
    vi expr(int lb,int ub,vi& target)
    {
        if(lb>ub)return {};
        if(lb==ub) return {-target[lb],target[lb]};
        int mid=(lb+ub)/2;
        vi a0=expr(lb,mid,target);
        vi a1=expr(mid+1,ub,target);
        vi sol(a0.size()*a1.size());
        int iterSol=0;
        for(int i=0;i<a0.size();i++)
            for(int j=0;j<a1.size();j++)
                sol[iterSol++]=a0[i]+a1[j];
        return sol;
    }
public:
    int findTargetSumWays(vi& nums, int target) {
        int lb=0;int ub=nums.size()-1;
        int mid=(lb+ub)/2,cnt=0;
        vi A0=expr(lb,mid,nums);
        vi A1=expr(mid+1,ub,nums);
        unordered_map<int,int> hashMap;
        for(int i=0;i<A0.size();i++)
            hashMap[A0[i]]++;
        if(nums.size()==1)cnt+=hashMap[target];
        for(int i=0;i<A1.size();i++)
            cnt+=hashMap[target-A1[i]];
        return cnt;
    }
};
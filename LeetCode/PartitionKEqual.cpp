#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class Solution
{
	int pSum;
	int N;int K;
	bool fn(int sum,int start,vi nums,int CNT,vi sol)
	{
		if(pSum==sum){
			sum=0;
			for(int j=0;j<sol.size();j++)
				nums.erase(nums.begin()+sol[j]-j);
			sol.clear();
			start=0;
			CNT++;
		}
		if(nums.size()==0 && CNT==K)return true;
        if(start>=nums.size() || CNT>K)return false;
		for(int i=start;i<nums.size();i++)
		{
			if(sum+nums[i]<=pSum)
			{
				sol.push_back(i);
				if(fn(sum+nums[i],i+1,nums,CNT,sol))return true;
				sol.pop_back();
			}
		}//end of for. 
	    return false;
	}
public:
	bool canPartitionKSubsets(vi& nums,int k)
	{
		N=nums.size();K=k;
		int sum=0;
		for(int i=0;i<N;i++)sum+=nums[i];
		if(sum%k)return false;
		pSum=sum/k;
		for(int i=0;i<N;i++)
			if(pSum<nums[i])return false;
		sum=0;int start=0;
		vi sol;
		return fn(sum,start,nums,0,sol);
	}
};

//Driver Function.
int main()
{
	freopen("ip.txt","r",stdin);
	int t;cin>>t;
	Solution obj;
	while(t--)
	{
		int n;cin>>n;
		vi arr(n);
		for(int i=0;i<n;i++)cin>>arr[i];
		int k;cin>>k;
		cout<<obj.canPartitionKSubsets(arr,k)<<endl;
	}
	return 0;
}
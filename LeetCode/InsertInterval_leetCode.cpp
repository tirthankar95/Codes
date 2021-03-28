#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

/*
class Solution{
public:
	vvi insert(vvi& intervals,vi& newInterval)
	{
		int m=intervals.size();
		vvi ans;
		bool flag=false;
		for(int i=0;i<m;i++)
		{
			if(flag)
			{
				ans.push_back(intervals[i]);
			}
			else if(newInterval[1]<intervals[i][0])
			{
				ans.push_back(newInterval);
				flag=true;
			}
			else if(newInterval[0]>=intervals[i][0] && newInterval[1]<=intervals[i][1])
			{
				flag=true;
			}
			else if(!(newInterval[0]>intervals[i][1]))
			{
				newInterval[0]=min(newInterval[0],intervals[i][0]);
				newInterval[1]=max(newInterval[1],intervals[i][1]);
				ans.push_back(newInterval);
				flag=true;
			}
			else ans.push_back(intervals[i]);
		}
		return ans;
	}
};
*/
int main()
{
	/*
	freopen("ip.txt","r",stdin);
	int t;cin>>t;
	while(t--)
	{
		int m;cin>>m;
		vvi intervals;
		int a,b;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			intervals.push_back({a,b});
		}
		cin>>a>>b;
		vi newInterval({a,b});
		Solution obj;
		vvi ans=obj.insert(intervals,newInterval);
		int n=ans.size();
		cout<<endl;cout<<"TC ~ "<<t<<endl;cout<<"[ ";
		for(int i=0;i<n;i++)
		{
			cout<<"["<<ans[i][0]<<","<<ans[i][1]<<"],";
		}
		cout<<"]\n";
	}
	*/
	return 0;
}
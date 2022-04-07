//Maximum Candies Allocated To K Children.
class Solution2{
	typedef long long ll;
	typedef vector<int> vi;
	int n;
public:
	bool isPossible(vi& candies,ll k,int mid) {
		ll count = 0;
		for (int i = 0; i < n; i++)
			count =count+(ll)(candies[i] / mid);
		return (count >= k);
	}
	int maximumCandies(vi& candies,ll k) {
		ll sum = 0; int mx = INT_MIN;
		n = candies.size();
		for (int i = 0; i < n; i++)
		{
			sum =sum+(ll)candies[i];
			mx = max(mx, candies[i]);
		}
		if (sum < k)return 0;
		int lb = 1,ub = mx,ans;
		while (lb <= ub) {
			int mid = lb + (ub - lb) / 2;
			if (isPossible(candies,k,mid))
			{
				ans = mid;
				lb = mid + 1;
			}
			else
				ub = mid - 1;
		}//end of while.
		return ans;
	}
};
/* 
	Dynamic solution may not work because optimal solution in 
	subproblems may not lead to optimal solution in the main problem.
	Example:- [10,5,13,4,8,4,5,11,14,9,16,10,20,8], 8
	Read about dynamic programming.

	In the code you write below all possible combinations are not explored for the i-th element and j-th state.
	This is kind of a greedy solution, what I have written.
*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int mxSize1 = 1e3 + 1;
const int mxSize2 = 51;
template<class T> inline T max_(T a,T b){
	return (a > b) ? a : b;
}
struct node {
	vi arr;
	int sz;
	int mx;
};
node dp[mxSize1][mxSize2];

class Solution {
	void clear(int n,int m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dp[i][j].arr.clear();
				dp[i][j].sz = 0;
				dp[i][j].mx = INT_MAX;
			}
		}
	}
public:
	int splitArray(vi& nums, int m) {
		int n = nums.size();
		clear(n,m);
		dp[0][0].arr.push_back(nums[0]), dp[0][0].sz = 1, dp[0][0].mx = nums[0];
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j <= min(i,m-1); j++) 
			{
				node a0, a1;
				// Modifying the second element.
				a1 = dp[i - 1][j];
                if(a1.sz)
                {
				    a1.arr[a1.sz - 1] += nums[i];
				    a1.mx = max_(a1.mx, a1.arr[a1.sz - 1]);
                }
				dp[i][j] = a1;
                // Modifying the first element.
				if (j > 0)
				{
					a0 = dp[i - 1][j - 1];
					a0.arr.push_back(nums[i]);
					a0.sz++;
					a0.mx = max_(a0.mx, a0.arr[a0.sz - 1]);
                    dp[i][j] = (a1.mx > a0.mx) ? a0 : a1;
				}
			}//end of inner-for.
		}//end of outer-for.
		return dp[n-1][m-1].mx;
	}
};
//Driver Function.
int main() {
	Solution obj;
	vector<int> array({1,2,3,4});
	int n=array.size();
	for(int i=0;i<n;i++)
	{
		cout<<"Partition["<<i+1<<"] "<< obj.splitArray(array, i+1) << endl;
	}
	return 0;
}
*/
typedef vector<int> vi;

class Solution {
    bool possible(vi& nums,int lim,int m){
        int n=nums.size();
        int count=0,rSum=0;
        for(int i=0;i<n;i++){
            rSum+=nums[i];
            if(rSum>=lim){
                count++;
                rSum=(rSum==lim)?0:nums[i];
            }
        }
        if(rSum)count++;
        return (count<=m);
    } 
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        int ub=0,lb=-1;
        for(int i=0;i<n;i++){
            lb=max(lb,nums[i]);
            ub+=nums[i];
        }
        int res;
        while(lb<=ub){
            int mid=(lb+ub)/2;
            if(possible(nums,mid,m)){
                res=mid;
                ub=mid-1;
            }
            else lb=mid+1;
        }//end of while.
        return res;
    }
};
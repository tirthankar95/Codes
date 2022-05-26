/*
https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
1. If A[i] is smallest among all end 
   candidates of active lists, we will start 
   new active list of length 1.
2. If A[i] is largest among all end candidates of 
  active lists, we will clone the largest active 
  list, and extend it by A[i].
3. If A[i] is in between, we will find a list with 
  largest end element that is smaller than A[i]. 
  Clone and extend this list by A[i]. We will discard all
  other lists of same length as that of this modified list.

https://en.wikipedia.org/wiki/Patience_sorting

#include <iostream>
#include <vector>
 
// Binary search (note boundaries in the caller)
int CeilIndex(std::vector<int>& v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
 
    return r;
}
 
int LongestIncreasingSubsequenceLength(std::vector<int>& v)
{
    if (v.size() == 0)
        return 0;
 
    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
 
        // new smallest value
        if (v[i] < tail[0])
            tail[0] = v[i];
 
        // v[i] extends largest subsequence
        else if (v[i] > tail[length - 1])
            tail[length++] = v[i];
 
        // v[i] will become end candidate of an existing
        // subsequence or Throw away larger elements in all
        // LIS, to make room for upcoming greater elements
        // than v[i] (and also, v[i] would have already
        // appeared in one of LIS, identify the location
        // and replace it)
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }
 
    return length;
}
 
int main()
{
    std::vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    std::cout << "Length of Longest Increasing Subsequence is "
              << LongestIncreasingSubsequenceLength(v) << '\n';
    return 0;
}

*/
// O(N^2) solution.
//#define DBG
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end());
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1])
                    dp[i]=max(dp[i],1+dp[j]);
            }
        }//end of for-i.
        int mx=1;
        for(int i=0;i<n;i++)
        {
#ifdef DBG
            cout<<dp[i]<<" ";
#endif
            mx=max(mx,dp[i]);
        }
#ifdef DBG
        cout<<endl;
#endif
        return mx;
    }
};
//O(NlogN) solution.
typedef vector<int> vi;

class Solution {
    int lowerBound(vi& tail,int lb,int ub,int element){
        int mid;
        while(lb<=ub){
            mid=lb+(ub-lb)/2;
            if(tail[mid]>=element)
                ub=mid-1;
            else 
                lb=mid+1;
        }
        return lb;
    }
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
public:
    int maxEnvelopes(vector<vi>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),cmp);
/*
        sort(envelopes.begin(),envelopes.end());
        Normal sort will not work. 
        Eg:- [[4,5],[4,6],[6,7],[2,3],[1,1]]
             After Sort ~ [[1,1],[2,3],[4,5],[4,6],[6,7]]
             According to current logic this will give 5 as answer.
        Soln. Either put extra check conditions(will not work) or change sorting logic. 
*/
        vector<int> tail(n);
        tail[0]=envelopes[0][1];
        int iter=1;
        for(int i=1;i<n;i++){
            if(tail[iter-1]<envelopes[i][1])
                tail[iter++]=envelopes[i][1];
            else
                tail[lowerBound(tail,0,iter-1,envelopes[i][1])]=envelopes[i][1];
        }//end of for-i.
        return iter;
    }
};
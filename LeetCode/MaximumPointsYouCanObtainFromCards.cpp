class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size();
        int sum=0,sol=0;
        for(int i=n-k;i<n+k;i++){
            sum+=arr[i%n];
            if(i>=n)sum-=arr[i-k];
            sol=max(sol,sum);
        }
        return sol;
    }
};
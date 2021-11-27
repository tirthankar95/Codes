/*
typedef vector<int> vi;
class Solution {
public:
    vi productExceptSelf(vi& nums) {
        int n=nums.size();
        vi front(n-1);vi back(n-1);
        front[0]=nums[0];
        back[n-2]=nums[n-1];
        for(int i=1;i<=n-2;i++)
        {
            front[i]=front[i-1]*nums[i];
            back[n-i-2]=back[n-i-1]*nums[n-i-1];
        }
        vi sol(n);
        sol[0]=back[0];sol[n-1]=front[n-2];
        for(int i=1;i<=n-2;i++)
            sol[i]=front[i-1]*back[i];
        return sol;
    }
};
*/
typedef vector<int> vi;
class Solution {
public:
    vi productExceptSelf(vi& nums) {
        int n=nums.size();
        vi sol(n);
        sol[0]=1;
        for(int i=1;i<n;i++)
            sol[i]=sol[i-1]*nums[i-1];
        int tmp=nums[n-1];
        for(int i=1;i<n;i++)
        {
            sol[n-i-1]*=tmp;
            tmp=tmp*nums[n-i-1];
        }
        return sol;
    }
};
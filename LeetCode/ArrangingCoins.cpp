typedef unsigned long long ull;
class Solution {
public:
    int arrangeCoins(int N) {
        ull lb=1,ub=N,mid=0,n=N;
        while(lb<=ub)
        {
            mid=(lb+ub)/2;
            if(n<(mid*(mid+1)/2))ub=mid-1;
            else if(n>(mid*(mid+1)/2))lb=mid+1;
            else return mid;
        }
        return ub;
        // for(i=1;;i++)
        // {
        //     if(n<(i*(i+1)/2))
        //         break;
        // }
        // return (int)(i-1);
    }
};
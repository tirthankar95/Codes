typedef long long ll;
class Solution {
public:
    int arrangeCoins(int n) {
        ll lb=0,ub=2*sqrt(n),mid,tot;
        while(lb<=ub)
        {
            mid=(lb+ub)/2;
            tot=((mid+1)*mid)/2; //total number of staircases.
            if(tot<n)lb=mid+1;
            else if(tot>n)ub=mid-1;
            else return mid;
        }
        return ub;
    }
};
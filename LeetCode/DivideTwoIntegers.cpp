typedef long long ll;

class Solution {
    ll getIt(ll no,ll mask){
        ll temp=0;
        for(int i=0;i<31;i++){
            if(mask&((ll)1<<i)){
               temp+=((ll)no<<i); 
            }
        }
        return temp;
    }
public:
    int divide(int dividend_, int divisor_) {
        if(dividend_==INT_MIN && divisor_==-1)return INT_MAX;
        ll dividend=dividend_;ll divisor=divisor_;
        int sign_dividend=1,sign_divisor=1;
        if(dividend<0){
            dividend=0-dividend;
            sign_dividend=-1;
        }
        if (divisor<0){
            divisor=0-divisor;
            sign_divisor=-1;
        }
        ll lb=0;ll ub=dividend;ll mid;
        ll no;
        while(lb<=ub){
            mid=(lb+ub);
            mid>>=1;
            no=getIt(divisor,mid); 
            if(no<dividend)
                lb=mid+1;
            else if(no>dividend)
                ub=mid-1;
            else{
                ub=mid;
                break;
            }
        }
        if((sign_divisor==1 && sign_dividend==1)||(sign_divisor==-1 && sign_dividend==-1))
            return ub;
        else 
            return (0-ub);
    }
};
typedef long long ll;
const int MOD=1e9+7;
//#define BRUTE_FORCE
#define LOGN
class Solution {
    ll bf(int n,int a,int b){
        ll f=1,s=1;
        ll res;
        while(n--){
            if(f*a<s*b)res=f*a,f++;
            else if(f*a>s*b)res=s*b,s++;
            else res=f*a,f++,s++;
        }
        return res;
    }
    ll logn(int n,int a,int b,int lcm){
        ll lb=1,ub=n,mida,midb,midc;
        ll tmp;
        while(lb<=ub){
            mida=(lb+ub)/2;
            midb=((ll)a*(ll)mida)/b;
            midc=((ll)a*(ll)mida)/lcm;
            tmp=mida+midb-midc;
            if(tmp<n)lb=mida+1;
            else if(tmp>n)ub=mida-1;
            else return (ll)a*(ll)mida;
        }
        lb=1,ub=n;
        while(lb<=ub){
            midb=(lb+ub)/2;
            mida=((ll)b*(ll)midb)/a;
            midc=((ll)b*(ll)midb)/lcm;
            tmp=mida+midb-midc;
            if(tmp<n)lb=midb+1;
            else if(tmp>n)ub=midb-1;
            else return (ll)b*(ll)midb;
        }
        return -1;
    }
    int hcf_(int a,int b){
        if(b==0)return a;
        return hcf_(b,a%b);
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        if(a<b && b%a==0)return ((ll)a*(ll)n)%MOD;
        if(b<=a && a%b==0)return ((ll)b*(ll)n)%MOD;
#ifdef BRUTE_FORCE
        return bf(n,a,b)%MOD;
#endif
#ifdef LOGN
        ll lcm=((ll)a*(ll)b)/hcf_(a,b);
        return logn(n,a,b,(int)lcm)%MOD;
#endif 
    }
};
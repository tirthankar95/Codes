#include<bits/stdc++.h>
using namespace std;
const int mxSize=1e9+7;
const int mxSize1=1e3+1;
const int MOD=998244353;
typedef long long ll;


namespace nCr1
{
	ll C[mxSize1][mxSize1];
	ll comb(int n,int r)
	{
		if(r==0 || r==n)return (ll)1;
		if(r==1)return n;
		if(C[n][r]!=0)return C[n][r];
		return (C[n][r]=(comb(n-1,r)+comb(n-1,r-1))%MOD);
	}
}
namespace nCr2
{
	#define ll long long
	#define ull unsigned ll
	#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
	#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
	const int mxn=1e3+1;
	int fact[mxn];
	int inv[mxn];
    int power(int x,int y){
        int s=1;
        for (;y;y/=2,x=1ll*x*x%MOD)
            if (y&1) s=1ll*s*x%MOD;
        return s;
    }	
	void pre()
	{
	    fact[0] = 1;
	    int i;
	    For(i,1,mxn-1)
	        fact[i] = fact[i-1]*1ll*i%MOD;
	    inv[mxn-1] = power(fact[mxn-1], MOD-2);    
	    Rep(i, mxn-2, 0)
	        inv[i] = inv[i+1]*1ll*(i+1)%MOD;
	}
	int comb(int n, int r)
	{
	    if(n < 0 || r < 0 || n < r)
	        return 0;
	    int ans = fact[n]*1ll*inv[r]%MOD;
	    ans = ans*1ll*inv[n-r]%MOD;
	    return ans;    
	}	
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);	
    nCr2::pre();
	cout<<nCr1::comb(1000,500)<<endl;
	cout<<nCr2::comb(1000,500)<<endl;
	return 0;
}
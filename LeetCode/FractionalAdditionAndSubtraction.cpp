typedef long long ll;
typedef pair<ll,ll> pll;
class Solution {
    ll gcd(ll a,ll b)
    {
        if(a%b==0)return b;
        return gcd(b,a%b);
    }
public:
    string fractionAddition(string expr) {
        vector<pll> operands;
        int n=expr.length();
        int sign=1,i=0;
        while(i<n)
        {
            if(expr[i]=='+' || expr[i]=='-')
            {
                sign=(expr[i]=='-')?-1:1;
                i++;
            }
            ll nu=0,dn=0;
            while(i<n && expr[i]>='0' && expr[i]<='9')
                nu=nu*10+(ll)(expr[i++]-'0');
            nu*=sign;
            i++;
            while(i<n && expr[i]>='0' && expr[i]<='9')
                dn=dn*10+(ll)(expr[i++]-'0');
            operands.push_back(pll(nu,dn));
        }
        pll tmp=operands[0];
        for(int i=1;i<operands.size();i++)
        {
            tmp.first=tmp.first*operands[i].second+operands[i].first*tmp.second;
            tmp.second=tmp.second*operands[i].second;
        }
        ll div=gcd(abs(tmp.first),tmp.second);
        tmp.first/=div;
        tmp.second/=div;
        string ans=to_string(tmp.first)+"/"+to_string(tmp.second);
        return ans;
    }
};
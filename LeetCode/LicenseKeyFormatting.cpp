const int offset=(int)('a'-'A');
class Solution {
public:
    string licenseKeyFormatting(string s, int k) { 
        int n=s.length();
        int sz=0;
        for(int i=0;i<n;i++)
            if(s[i]!='-')sz++;
        string only="",ans="";
        only.resize(sz);
        int iter=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!='-')
                only[iter++]=(s[i]>='a' && s[i]<='z')?(char)(s[i]-offset):s[i];
        }
        iter=0;
        int ansSz=sz+((sz-1)/k);
        ans.resize(ansSz);
        for(int i=0;i<sz;i++)
        {
            ans[--ansSz]=only[i];
            iter++;
            if(i!=sz-1 && iter==k)
                iter=0,ans[--ansSz]='-';
        }
        return ans;
    }
};
typedef vector<int> vi;
class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans=s;
        if(k==1)
        {
            char mi_ch=s[0];string tmp;
            for(int i=1;i<ans.length();i++)
                mi_ch=min(mi_ch,ans[i]);
            for(int i=0;i<s.length();i++)
            {
                if(mi_ch==s[i])
                {
                    tmp=s.substr(i,s.length()-i)+s.substr(0,i);
                    if(tmp<ans)ans=tmp;
                }
            }
        }
        else sort(ans.begin(),ans.end());
        return ans;
    }
};
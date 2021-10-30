const int mxSize=26;
int hashMap[mxSize];

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.length();
        memset(hashMap,0,sizeof(int)*mxSize);
        for(int i=0;i<n;i++)
            hashMap[(int)(text[i]-'a')]++;
        string TT="balon";
        int ans=INT_MAX;
        for(int i=0;i<TT.length();i++)
        {
            if(TT[i]=='b' || TT[i]=='a' || TT[i]=='n')ans=min(ans,hashMap[(int)(TT[i]-'a')]);
            else ans=min(ans,hashMap[(int)(TT[i]-'a')]/2);
        }
        return ans;
    }
};
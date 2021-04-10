const int mxSize=('z'-'a'+1);
char orig[mxSize];
char window[mxSize];

class Solution {
    bool fullMatch(){
        for(int i=0;i<mxSize;i++)
            if(orig[i]!=window[i])return false;
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int n=p.length(),m=s.length();
        vector<int> sol;
        if(m<n)return sol;
        memset(orig,0,mxSize*sizeof(char));
        memset(window,0,mxSize*sizeof(char));
        for(int i=0;i<n;i++){
            orig[(int)(p[i]-'a')]++;
            window[(int)(s[i]-'a')]++;
        }//end of for-loop.
        bool isMatching=fullMatch();
        int lb=n;
        if(isMatching)sol.push_back(lb-n);
        for(;lb<m;lb++)
        {
            window[(int)(s[lb-n]-'a')]--;
            window[(int)(s[lb]-'a')]++;
            if(isMatching)
            {
                if(s[lb-n]==s[lb])sol.push_back(lb-n+1);
                else isMatching=false;
            }
            else
            {
                if(window[(int)(s[lb-n]-'a')]==orig[(int)(s[lb-n]-'a')] && 
                   window[(int)(s[lb]-'a')]==orig[(int)(s[lb]-'a')])
                {
                    if(fullMatch())
                    {
                        isMatching=true;
                        sol.push_back(lb-n+1);
                    }
                }
            }//if not matching. 
        }//end of for-loop.
        return sol;
    }
};
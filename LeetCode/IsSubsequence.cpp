class Solution {
public:
    bool isSubsequence(string s, string t) {
        int nt=t.length();
        int ns=s.length(),i=0;
        if(ns>nt)return false;
        for(int j=0;j<nt;j++){        
            if(s[i]==t[j])
                i++;
        }
        return (i==ns);
    }
};
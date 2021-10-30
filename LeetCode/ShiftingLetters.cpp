class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
        shifts[n-1]=shifts[n-1]%26;
        for(int i=n-2;i>=0;i--)
            shifts[i]=(shifts[i]+shifts[i+1])%26;
        int m=s.length();
        for(int i=0;i<m;i++)
            s[i]=(char)('a'+ ( (s[i]-'a')+shifts[i] )%26 );
        return s;
    }
};
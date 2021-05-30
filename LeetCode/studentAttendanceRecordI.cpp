class Solution {
public:
    bool checkRecord(string s) {
        int n=s.length();
        int abs=0;
        for(int i=0;i<n;i++)
            if(s[i]=='A')abs++;
        if(abs>=2)return false;
        int consec=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L')consec++;
            else consec=0;
            if(consec==3)return false;
        }
        return true;
    }
};
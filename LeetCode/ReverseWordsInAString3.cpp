class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        string sen="";
        int n=s.length();
        int i=0;bool first=true;
        while(i<n)
        {
            string wrd="";
            while(s[i]!=' ')
            {
                wrd=s[i]+wrd;
                i++;
            }
            i++;
            if(!first)sen=sen+" "+wrd;
            else{
                sen=wrd;
                first=false;
            }
        }
        return sen;
    }
};
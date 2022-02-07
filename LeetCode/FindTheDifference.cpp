class Solution {
public:
    char findTheDifference(string s, string t) {
        int hMap[(int)('z'-'a')+1];
        memset(hMap,0,sizeof(hMap));
        int n=s.length();
        for(int i=0;i<n;i++)
            hMap[(int)(s[i]-'a')]++;
        for(int i=0;i<=n;i++){
            if(!hMap[(int)(t[i]-'a')])
                return t[i];
            hMap[(int)(t[i]-'a')]--;
        }
        char ch=0;
        return ch;
    }
};
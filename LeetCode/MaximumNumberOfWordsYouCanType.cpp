class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n=brokenLetters.length();
        bool isPresent[26];
        memset(isPresent,false,26*sizeof(bool));
        for(int i=0;i<n;i++)
            isPresent[(int)(brokenLetters[i]-'a')]=true;
        int cnt=0;
        text+=' ';int i=0;
        int m=text.length();
        while(i<m)
        {
            if(text[i]!=' ' && isPresent[(int)(text[i]-'a')])
                while(i<m && text[i]!=' ')i++;
            else if(text[i]==' ')cnt++;
            i++;
        }
        return cnt;
    }
};
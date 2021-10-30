inline bool isELetter(char ch)
{
    return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
}
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int fptr=0;
        int lptr=s.length()-1;
        while(fptr<lptr)
        {
            if(isELetter(s[fptr]))
            {
                if(isELetter(s[lptr]))
                {
                    swap(s[fptr],s[lptr]);
                    fptr++;
                    lptr--;
                }
                else lptr--;
            }
            else fptr++;
        }
        return s;
    }
};
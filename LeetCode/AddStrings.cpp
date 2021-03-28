class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.length();
        int n2=num2.length();
        int tmp=0;
        string ans="";
        while(n1>0 && n2>0)
        {
            n1--;
            n2--;
            tmp+=(int)(num1[n1]-'0')+(int)(num2[n2]-'0');
            ans=(char)('0'+tmp%10)+ans;
            tmp/=10;
        }//end of while.
        while(n1>0)
        {
            n1--;
            tmp+=(int)(num1[n1]-'0');
            ans=(char)('0'+tmp%10)+ans;
            tmp/=10;            
        }//end of while.
        while(n2>0)
        {
            n2--;
            tmp+=(int)(num2[n2]-'0');
            ans=(char)('0'+tmp%10)+ans;
            tmp/=10;            
        }//end of while.
        if(tmp)
            ans=(char)(tmp+'0')+ans;
        return ans;
    }
};
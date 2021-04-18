class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        for(int i=0;i<n/2;i++)
        {
            if(n%(i+1)==0)
            {
                bool flag=true;
                int offset=i+1;
                for(int j=0;j<offset;j++)
                {
                    char character=s[j];
                    for(int k=j+offset;k<n;k+=offset)
                    {
                        if(character!=s[k])
                        {
                            flag=false;
                            break;
                        }
                    }
                    if(flag==false)break;
                }//end of inner-for.
                if(flag==true)return true;
            }
        }//end of outer-for. 
        return false;
    }
};
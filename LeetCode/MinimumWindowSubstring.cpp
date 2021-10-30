const int mxSize=(int)('z'-'A')+1;
int hashMap[mxSize];
int hashMap1[mxSize];

class Solution {
public:
    string minWindow(string s, string t) {
        memset(hashMap,0,mxSize*sizeof(int));
        memset(hashMap1,0,mxSize*sizeof(int));
        int m=t.length();int n=s.length();
        for(int i=0;i<m;i++)
            hashMap[(int)(t[i]-'A')]++;
        int lb=0;int ub=0;
        int min_=INT_MAX;int cntM=m;
        int strtPt;
        while(ub<n)
        {
            if(cntM && hashMap[(int)(s[ub]-'A')]>hashMap1[(int)(s[ub]-'A')])
                cntM--;
            hashMap1[(int)(s[ub]-'A')]++;ub++;
            if(cntM==0)
            {
                while(lb<ub)
                {
                    if(min_>(ub-lb))
                    {
                        min_=ub-lb;
                        strtPt=lb;
                    }
                    hashMap1[(int)(s[lb]-'A')]--;lb++;
                    if(hashMap1[(int)(s[lb-1]-'A')]<hashMap[(int)(s[lb-1]-'A')])
                    {    
                        cntM++;
                        break;
                    }
                }//end of inner-while.
            }
        }//end of outer-while.
        if(min_==INT_MAX)return "";
        return s.substr(strtPt,min_);
    }
};
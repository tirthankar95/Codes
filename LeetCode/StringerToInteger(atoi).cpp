typedef long long ll;
const ll LB=-(1<<31);
const ll UB=(1<<31)-1;
class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        ll i=0,res=0,sign=1;
        bool firstSign=true;
        while(i<n && s[i]==' ')i++;
        while(i<n){
            if(s[i]=='+' || s[i]=='-'){
                if(firstSign){
                    firstSign=false;
                    sign*=(s[i]=='-')?-1:1;
                }
                else break;
            }
            else if(s[i]>='0' && s[i]<='9'){
                res=res*10+(int)(s[i]-'0');
                firstSign=false;
                if((res*sign)<=LB){
                    return LB;
                }
                if((res*sign)>=UB){
                    return UB;
                }
            }
            else 
                break;
            i++;
        }//end of while.
        return sign*res;
    }
};
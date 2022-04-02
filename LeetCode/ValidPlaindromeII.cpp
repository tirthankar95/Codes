/* Test Case: "abecebea" */

class Solution {
    bool isPalin(string s,int lb,int ub){
        while(lb<=ub){
            if(s[lb++]!=s[ub--])
                return false;
        }
        return (lb>ub);
    }
public:
    bool validPalindrome(string s) {
        bool first=false;
        int lb=0;int ub=s.length()-1;
        while(lb<=ub){
            if(s[lb]!=s[ub])
                return isPalin(s,lb+1,ub)|isPalin(s,lb,ub-1);
            lb++;
            ub--;
        }//end of while. 
        return true;
    }
};
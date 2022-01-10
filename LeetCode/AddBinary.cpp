class Solution {
public:
    string addBinary(string a, string b) {
        int na=a.length();
        int nb=b.length();
        int temp,carry=0;
        string res="";
        while(na>0 && nb>0){
            temp=(a[--na]-'0')+(b[--nb]-'0')+carry;
            carry=temp/2;
            res=((char)('0'+(temp%2)))+res;
        }
        while(na>0){
            temp=(a[--na]-'0')+carry;  
            carry=temp/2;
            res=((char)('0'+(temp%2)))+res;
        }
        while(nb>0){
            temp=(b[--nb]-'0')+carry;    
            carry=temp/2;
            res=((char)('0'+(temp%2)))+res;
        }
        if(carry)res=((char)('0'+(carry%2)))+res;
        return res;
    }
};
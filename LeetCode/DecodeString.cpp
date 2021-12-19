inline bool isDigit(char ch){
    return (ch>='0' && ch<='9');
}
class Solution {
    string fn(string s,int &ptr){
        int no=0;string str="";
        while(s[ptr]!='[')no=no*10+(s[ptr++]-'0');
        ptr++;
        while(s[ptr]!=']'){
            if(isDigit(s[ptr]))
                str+=fn(s,ptr);
            else
                str=str+s[ptr++];
        }
        if(s[ptr]==']')ptr++;
        string res="";
        while(no--)res+=str;
        return res;
    }
public:
    string decodeString(string s) {
        string par="";
        int i=0;int n=s.length();
        while(i<n){
            if(isDigit(s[i]))par+=fn(s,i);
            else par+=s[i++];
        }
        return par;
    }
};
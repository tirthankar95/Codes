const int mxSize=128;
char hMap[mxSize];

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        hMap[(int)'(']=')';hMap[(int)'{']='}';hMap[(int)'[']=']';
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else{
                if(!st.empty() && hMap[(int)st.top()]==s[i])
                    st.pop();
                else return false;
            }
        }//end of for. 
        return st.empty();
    }
};
const int mxSize=3e4+1;
char chArr[mxSize];

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        stack<int> st;
        vector<int> count(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                st.push(i);
            if(s[i]==')' && !st.empty()){
                count[i]=(i-st.top())+1;
                st.pop();
            }
        }//end of for.
        int mx=0;
        for(int i=0;i<n;i++)
        {
            if(count[i])
            {
                count[i]+=(i-count[i]>=0)?count[i-count[i]]:0;
                mx=max(mx,count[i]);
            }
        }
        return mx;
    }
};
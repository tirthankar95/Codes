const int mxSize=(int)('z'-'a'+1);
int hashMap[mxSize];
bool isPresent[mxSize];

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans="";
        memset(hashMap,0,mxSize*sizeof(int));
        memset(isPresent,false,mxSize*sizeof(bool));
        int n=s.length();
        for(int i=0;i<n;i++)
            hashMap[(int)(s[i]-'a')]++;
        stack<char> st;
        for(int i=0;i<n;i++)
        {  
            while(!st.empty() && !isPresent[(int)(s[i]-'a')] && st.top()>s[i] && hashMap[(int)(st.top()-'a')]>0)
            {
                isPresent[(int)(st.top()-'a')]=false;
                st.pop();
            }
            if(!isPresent[(int)(s[i]-'a')])
            {
                st.push(s[i]);
                isPresent[(int)(s[i]-'a')]=true;
            }
            hashMap[(int)(s[i]-'a')]--;
        }//end of for-loop.
        while(!st.empty())
            ans=st.top()+ans,st.pop();
        return ans;
    }
};
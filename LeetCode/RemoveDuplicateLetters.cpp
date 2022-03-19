const int mxSize=(int)('z'-'a')+1;
int freq[mxSize];
bool alreadyAdded[mxSize];

class Solution {
public:
    string removeDuplicateLetters(string s) {
        memset(freq,0,sizeof(freq));
        memset(alreadyAdded,false,sizeof(alreadyAdded));
        int n=s.length();
        for(int i=0;i<n;i++)
            freq[(int)(s[i]-'a')]++;
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if((st.empty() || st.top()<s[i]) && !alreadyAdded[(int)(s[i]-'a')])
            {
                st.push(s[i]);
                alreadyAdded[(int)(s[i]-'a')]=true;
            }
            else if(st.top()>=s[i] && !alreadyAdded[(int)(s[i]-'a')]){
                while(!st.empty() && freq[(int)(st.top()-'a')] && st.top()>=s[i]){
                    alreadyAdded[(int)(st.top()-'a')]=false;
                    st.pop();
                }
                    st.push(s[i]),alreadyAdded[(int)(s[i]-'a')]=true;
            }
            freq[(int)(s[i]-'a')]--;
        }//end of for.
        string res="";
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};
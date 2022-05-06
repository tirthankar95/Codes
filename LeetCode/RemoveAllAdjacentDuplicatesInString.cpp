typedef pair<char,int> ci;
const int mxSize=26;

class Solution {
    int freq[mxSize];
    stack<ci> st;
    void clear(){
        memset(freq,0,sizeof(freq));
        while(!st.empty())
            st.pop();
    }
    string build(){
        stack<ci> stR;int sz=0;
        while(!st.empty()){
            stR.push(st.top());
            sz+=st.top().second;
            st.pop();
        }//end of while(1)
        if(sz==0)return "";
        char res[sz];int resCnt=0;
        char ch;int szC;
        while(!stR.empty()){
            ch=stR.top().first;
            szC=stR.top().second;
            stR.pop();
            for(int i=0;i<szC;i++)
                res[resCnt++]=ch;
        }//end of while(2)
        string res_(resCnt,'*');
        for(int i=0;i<resCnt;i++)res_[i]=res[i];
        return res_;
    }
public:
    string removeDuplicates(string s, int k) {
        clear();
        int n=s.length();
        for(int i=0;i<n;i++){
            freq[(int)(s[i]-'a')]++;
            if(st.empty() || st.top().first!=s[i]){
                if(!st.empty())
                {
                    st.top().second=freq[(int)(st.top().first-'a')];
                    freq[(int)(st.top().first-'a')]=0;
                }
                st.push(ci(s[i],0));
            }
            if(freq[(int)(s[i]-'a')]==k){
                freq[(int)(s[i]-'a')]=0;
                st.pop();
                if(!st.empty())
                    freq[(int)(st.top().first-'a')]=st.top().second;
            }
        }//end of for.
        if(!st.empty())
            st.top().second=freq[(int)(st.top().first-'a')];
        return build();
    }
};
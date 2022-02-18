class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        stack<char> st;
        if(k>=n)return "0";
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>num[i] && k){
                st.pop();
                k--;
                if(k==0)break;
            }//end of inner-while.
            st.push(num[i]);
        }//end of outer-while.
        string res="";
        for(int i=0;i<k;i++)
            st.pop();
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        int rn=res.length(),lZ=0;
/* Condition: It means leading zeros. */
        if(rn>1 && res[lZ]=='0'){
            while(res[lZ]=='0')lZ++;
            if(rn==lZ)return "0";
            return res.substr(lZ,rn-lZ);
        }
        return res;
    }
};
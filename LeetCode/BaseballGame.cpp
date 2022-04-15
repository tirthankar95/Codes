class Solution {
    int toInteger(string s){
        int i=0,n=s.length();
        int sign=1;
        if(s[0]=='-'){
            sign=-1;
            i++;
        }
        int no=0;
        for(;i<n;i++)
            no=no*10+(int)(s[i]-'0');
        return sign*no;
    }
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int n=ops.size();
        for(int i=0;i<n;i++)
        {
            switch(ops[i][0]){
                case 'C':
                    if(!st.empty())st.pop();
                    break;
                case 'D':
                    if(!st.empty())st.push(st.top()*2);
                    break;
                case '+':
                    {
                        if(st.empty())break;
                        int temp0=st.top();
                        st.pop();
                        if(st.empty()){
                            st.push(temp0);
                            break;
                        }
                        int temp1=st.top();
                        st.push(temp0);
                        st.push(temp0+temp1);
                        break;
                    }
                default:
                    st.push(toInteger(ops[i]));
            }//end of switch.
        }//end of for. 
        int res=0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};

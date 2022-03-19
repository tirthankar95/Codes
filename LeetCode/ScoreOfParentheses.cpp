typedef pair<char,int> ci;
class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.length();
        stack<ci> st;
        int iter=0,score=0,score_=0;
        while(iter<n){
            if(!st.empty() && st.top().first=='(' && s[iter]==')'){
                score_=(st.top().second==0)?1:2*st.top().second;
                st.pop();
                if(!st.empty())
                    st.top().second+=score_;
                else 
                    score+=score_;
            }//end of if. 
            else if(s[iter]=='(')
                st.push(ci('(',0));
            iter++;
        }//end of while. 
        return score;
    }
};
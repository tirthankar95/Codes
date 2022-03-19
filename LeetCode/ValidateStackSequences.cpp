class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n=pushed.size(),iterPush=0,iterPop=0;
        while(iterPush<n && iterPop<n){
            if(st.empty() || st.top()!=popped[iterPop])
                st.push(pushed[iterPush++]);
            else if(st.top()==popped[iterPop])
                st.pop(),iterPop++;
        }//end of while. 
        if(iterPush<n)
            return false;
        if(iterPop<n){
            while(!st.empty()){
                if(st.top()!=popped[iterPop])
                    return false;
                st.pop();
                iterPop++;
            }//end of while.
        }
        if(iterPush==n && iterPop==n && st.empty())
            return true;
        else 
            return false;
    }
};
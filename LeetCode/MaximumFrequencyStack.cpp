class FreqStack {
    unordered_map<int,int> freq;
    stack<int> st; // this stack is for keeping the original values.
    stack<int> mxF; // this stack stores the maximum freq.
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        if(mxF.empty() || freq[mxF.top()]<=freq[val])
            mxF.push(val);
        else 
            mxF.push(mxF.top());
        st.push(val);
    }
    
    int pop() {
        int ret=mxF.top();
        mxF.pop();
        stack<int> temp;
        while(ret!=st.top()){
            temp.push(st.top());
            freq[st.top()]--;
            st.pop();
            mxF.pop();
        }
        freq[st.top()]--;
        st.pop();
        while(!temp.empty())
        {
            push(temp.top());
            temp.pop();
        }
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

 /********** SOLUTION 2 *****************/
 class FreqStack {
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> bucket; // <freq,stack>
    int mxF;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        mxF=max(mxF,freq[val]);
        bucket[freq[val]].push(val);
    }
    
    int pop() {
        if(bucket[mxF].empty())
            mxF--;
        int ret=bucket[mxF].top();
        bucket[mxF].pop();
        freq[ret]--;
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
 /***************************************/
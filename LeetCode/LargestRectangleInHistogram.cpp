class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(),temp,mx=0,i;
        stack<int> st;
        for(i=0;i<n;i++)
        {
            if(st.empty() || heights[st.top()]<=heights[i])
                st.push(i);
            else{
                while(!st.empty() && heights[st.top()]>heights[i]){
                    temp=st.top();
                    st.pop();
                    if(!st.empty())
                        mx=max(mx,(i-st.top()-1)*heights[temp]);
                    else
                        mx=max(mx,i*heights[temp]);
                }//end of while. 
                st.push(i);
            }//end of else. 
        }//end of for. 
        while(!st.empty()){
            temp=st.top();
            st.pop();
            if(!st.empty())
                mx=max(mx,(i-st.top()-1)*heights[temp]);
            else
                mx=max(mx,i*heights[temp]);           
        }
        return mx;
    }
};
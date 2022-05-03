//#define DBG
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        int lb=INT_MAX,ub=INT_MIN;
        //
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                lb=min(lb,st.top());
                st.pop();
            }
            st.push(i);
        }//end of for.
        if(lb==INT_MAX)return 0;
#ifdef DBG
        printf("Lower Bound[%d].\n",lb);
#endif 
        while(!st.empty())st.pop();
        //
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                ub=max(ub,st.top());
                st.pop();
            }
            st.push(i);
        }//end of for.
#ifdef DBG
        printf("Upper Bound[%d].\n",ub);
#endif
        return (ub-lb+1);
    }
};
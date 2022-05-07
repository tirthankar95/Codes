typedef vector<int> vi;
class Solution {
    bool check(int a1,int a3,int a2){
        return (a3>a1 && a3>a2 && a2>a1);
    }
public:
    bool find132pattern(vi& nums) {
        int n=nums.size();
        if(n<3)return false;
        vi l_to_r(n);
        l_to_r[0]=nums[0];
        for(int i=1;i<n;i++)
            l_to_r[i]=min(nums[i],l_to_r[i-1]);
        stack<int> st;
        st.push(nums[n-1]);
        for(int i=n-2;i>0;i--)
        {
            if(nums[i]>st.top() && nums[i]>l_to_r[i-1])
            {
                while(!st.empty() && st.top()<=l_to_r[i-1])st.pop();
                if(!st.empty() && check(l_to_r[i-1],nums[i],st.top()))return true;
                st.push(nums[i]);
            }
            else if(nums[i]<l_to_r[i-1]){
                while(!st.empty() && st.top()<=l_to_r[i-1])st.pop();
                if(st.empty() || nums[i]<st.top())
                    st.push(nums[i]);
            }
            else if(nums[i]<st.top())st.push(nums[i]);
        }
        return false;
    }
};
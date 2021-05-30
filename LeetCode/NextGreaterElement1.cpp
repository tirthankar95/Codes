typedef vector<int> vi;

class Solution {
public:
    vi nextGreaterElement(vi& nums1, vi& nums2) {
        int n=nums2.size();
        stack<int> st;
        unordered_map<int,int> hashMap;
        for(int i=0;i<n;i++)
        {
            if(st.empty() || nums2[i]<=nums2[st.top()])
                st.push(i);
            else 
            {
                while(!st.empty() && nums2[i]>nums2[st.top()])
                {
                    hashMap[nums2[st.top()]]=nums2[i];
                    st.pop();
                }
                st.push(i);
            }
        }//end of for. 
        while(!st.empty())
        {
            hashMap[nums2[st.top()]]=-1;
            st.pop();
        }
        int m=nums1.size();
        vi sol(m);
        for(int i=0;i<m;i++)
            sol[i]=hashMap[nums1[i]];
        return sol;
    }
};
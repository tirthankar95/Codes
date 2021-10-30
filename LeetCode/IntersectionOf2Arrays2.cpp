const int mxSize=1e3+1;
int hashMap[mxSize];

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        memset(hashMap,0,sizeof(hashMap));
        for(int i=0;i<n1;i++)
            hashMap[nums1[i]]++;
        vector<int> sol;
        for(int i=0;i<n2;i++)
        {
            if(hashMap[nums2[i]]>0)
            {
                sol.push_back(nums2[i]);
                hashMap[nums2[i]]--;
            }
        }
        return sol;
    }
};
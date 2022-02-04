class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n3=nums3.size();
        int n4=nums4.size();
        unordered_map<int,int> hashMap;
        for(int i=0;i<n3;i++)
            for(int j=0;j<n4;j++)
                hashMap[nums3[i]+nums4[j]]+=1;
        int cnt=0;
        for(int i=0;i<n1;i++)
            for(int j=0;j<n2;j++)
                cnt+=hashMap[-(nums1[i]+nums2[j])];
        return cnt;
    }
};
/* 2nd attempt */
typedef vector<int> vi;
typedef pair<int,int> ii;
class Solution {
public:
    int fourSumCount(vi& nums1,vi& nums2,vi& nums3,vi& nums4) {
        unordered_map<int,int> hashMap;
        int ans=0,n=nums1.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                hashMap[(nums1[i]+nums2[j])]++;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ans+=hashMap[-(nums3[i]+nums4[j])];
        return ans;
    }
};
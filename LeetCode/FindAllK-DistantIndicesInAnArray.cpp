class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int> savArr;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==key)
                savArr.push_back(i);
        }//end of for.
        vector<int> sol;
        int mxIndex=-1;
        for(int i=0;i<savArr.size();i++){
            int lb=savArr[i]-k;
            for(int j=max(0,lb);j<=min(n-1,savArr[i]+k);j++){
                if(mxIndex<j){
                    mxIndex=j;
                    sol.push_back(j);
                }
            }//end of inner-for.
        }//end of outer-for.
        return sol;
    }
};
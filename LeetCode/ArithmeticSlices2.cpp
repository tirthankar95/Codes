typedef long long ll;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        unordered_map<ll,int>* hMap=new unordered_map<ll,int>[n];
        int ans=0; ll diff;
        for(int i=1;i<n;i++) // i - is the last element of the AP.
        {
            for(int j=0;j<i;j++)
            {
                diff=(ll)nums[i]-(ll)nums[j];
                if(hMap[j].find(diff)==hMap[j].end())
                     hMap[i][diff]++;
                else
                {
                    hMap[i][diff]+=hMap[j][diff]+1;
                    ans+=hMap[j][diff]; // only add those whose sequences whose length are greater than equal to 3. 
                }
            }//end of for-j. 
        }//end of for-i.
        return ans;
    }
};

/*
// Another solution.
typedef long long ll;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& NN) {
        int n=NN.size();
        vector<ll> nums(n);
        for(int i=0;i<n;i++)nums[i]=NN[i];
        unordered_map<ll,int>* hMap=new unordered_map<ll,int>[n];
        int ans=0; ll diff;
        for(int i=1;i<n;i++) // i - is the last element of the AP.
        {
            for(int j=0;j<i;j++)
            {
                diff=nums[i]-nums[j];
                ans-=1; // always subtract a one. (1)
                if(hMap[j].find(diff)==hMap[j].end()) // one subtracted for sequences whose length is less than 3. 
                    hMap[i][diff]++;
                else
                    hMap[i][diff]+=hMap[j][diff]+1; // one subtracted for adding only hMap[j][diff] to ans.
            }//end of for-j. 
            for( unordered_map<ll,int>::iterator it=hMap[i].begin();it!=hMap[i].end();it++)
            {
                ans+=(it->second);
            }
        }//end of for-i.
        return ans;
    }
};
*/
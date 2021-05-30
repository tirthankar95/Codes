class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n=timeSeries.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=duration;
            if(i-1>=0 && timeSeries[i-1]+duration>timeSeries[i])
                ans-=(timeSeries[i-1]+duration-timeSeries[i]);
        }
        return ans;
    }
};
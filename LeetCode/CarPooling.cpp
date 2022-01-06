const int mxSize=1e3+1;
int freq[mxSize];

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        memset(freq,0,sizeof(freq));
        int n=trips.size();
        for(int i=0;i<n;i++){
            for(int j=trips[i][1];j<trips[i][2];j++)
                freq[j]+=trips[i][0];
        }
        for(int i=0;i<mxSize;i++)
            if(capacity<freq[i])
                return false;
        return true;
    }
};
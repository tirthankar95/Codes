typedef long long ll;
const int MODULO=1e9+7;
const int mxSize=301;
ll freq[mxSize];

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        memset(freq,0,mxSize*sizeof(int));
        int n=arr.size();
        for(int i=0;i<n;i++)
            freq[arr[i]]++;
        int temp;ll count=0;
        for(int i=0;i<mxSize;i++){
            if(3*i==target)
                count=count+(freq[i]*(freq[i]-1)*(freq[i]-2))/6;
            else if(target>=2*i && freq[(target-2*i)])
                count=count+freq[(target-2*i)]*( (freq[i]*(freq[i]-1))/2 );
            count=count%MODULO;
            for(int j=i+1;j<mxSize;j++){
                temp=(target-i-j);
                if(temp>0 && temp>j && freq[temp])
                {
                    count=count+(freq[i]*freq[j]*freq[temp]);
                    count=count%MODULO;
                }
            }//end of inner-for.
        }//end of outer-for. 
        return count;
    }
};
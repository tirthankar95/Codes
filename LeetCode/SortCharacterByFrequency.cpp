typedef pair<int,int> ii;
const int mxSize=256;
int hashMap[mxSize];

class Solution {
public:
    string frequencySort(string s) {
        memset(hashMap,0,mxSize*sizeof(int));
        int n=s.length();
        for(int i=0;i<n;i++)
            hashMap[s[i]]++;
        vector<ii> arr;
        for(int i=0;i<n;i++)
        {
            if(hashMap[s[i]])
            {
                arr.push_back(ii(hashMap[s[i]],i));
                hashMap[s[i]]=0;
            }
        }//end of for.
        sort(arr.rbegin(),arr.rend());
        int m=arr.size();
        string ans="";
        for(int i=0;i<m;i++)
            for(int j=0;j<arr[i].first;j++)
                ans+=(char)(s[arr[i].second]);
        return ans;
    }
};
typedef pair<int,int> ii;
class Solution {
public:
    int minSetSize(vector<int>& A) {
        int n=A.size(),cnt=0;
        unordered_map<int,int> hMap;
        vector<int> arr;
        for(int i=0;i<n;i++){
            if(hMap.find(A[i])==hMap.end()){
                arr.push_back(1);
                hMap[A[i]]=cnt++;
            }//
            else 
                arr[hMap[A[i]]]++;
        }//end of for. 
        sort(arr.rbegin(),arr.rend());
        int res=0;
        int nOrig=n;
        for(int i=0;i<cnt;i++){
            n-=arr[i];
            res++;
            if(nOrig>=2*n)
                return res;
        }
        return res;
    }
};
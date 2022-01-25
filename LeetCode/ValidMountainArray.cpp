class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size(),mx=INT_MIN,index;
        if(n<=2)return false;
        for(int i=0;i<n;i++){
            if(mx<arr[i]){
                mx=arr[i];
                index=i;
            }
        }
        int iter=0;
        while(iter<index){
            if(arr[iter]>=arr[iter+1])
                return false;
            iter++;
        }
        if(index==0 || index==n-1)return false;
        iter=n-1;
        while(iter>index){
            if(arr[iter]>=arr[iter-1])
                return false;
            iter--;
        }
        return true;
    }
};
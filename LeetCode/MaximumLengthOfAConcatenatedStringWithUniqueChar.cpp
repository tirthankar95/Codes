const int mxSize=26;
int hashMap[mxSize];

class Solution {
    int N,ans;
    bool duplicateChar(string str)
    {
        int n=str.length();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                if(str[i]==str[j])return true;
        }
        return false;
    }
    void fn(vector<string>& arr,int index,int cnt){
        if(index>=N)
        {
            ans=max(ans,cnt);
            return;
        }
        int i=0;
        string str=arr[index];
        fn(arr,index+1,cnt);
        for(;i<str.length();i++)
        {
            if(!hashMap[(int)(str[i]-'a')])
                hashMap[(int)(str[i]-'a')]=true;
            else 
                break;
        }
        if(i==str.length())
            fn(arr,index+1,cnt+i);
        for(int j=0;j<i;j++)
            hashMap[(int)(str[j]-'a')]=false;
    }
public:
    int maxLength(vector<string>& arr) {
        int lb=0,ub=0;
        int n=arr.size();
        while(ub<n)
        {
            if(duplicateChar(arr[ub]))
                ub++;
            else
                swap(arr[lb++],arr[ub++]);
        }//end of while.
        memset(hashMap,false,sizeof(hashMap));
        N=lb;ans=0;
        fn(arr,0,0);
        return ans;
    }
};
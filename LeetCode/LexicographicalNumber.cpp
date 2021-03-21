// This method is not much faster 440ms. 
typedef vector<int> vi;
class Solution {
    string toString(int a)
    {
        string str="";
        while(a)
        {
            int m=a%10;
            str=(char)('0'+m)+str;
            a/=10;
        }
        return str;
    }
    bool isFirstParamSamller(int a,int b)
    {
        string s_a=toString(a);
        string s_b=toString(b);
        if(s_a>=s_b)return false;
        else return true;
    }
    void merge(vi& arr,int lb,int mid,int ub)
    {
        int lb1=lb,ub1=mid;
        int lb2=mid+1,ub2=ub;
        vi tmp(ub-lb+1);int iter=0;
        while(lb1<=ub1 && lb2<=ub2)
        {
            if(isFirstParamSamller(arr[lb1],arr[lb2]))
                tmp[iter++]=arr[lb1++];
            else tmp[iter++]=arr[lb2++];
        }
        while(lb1<=ub1)tmp[iter++]=arr[lb1++];
        while(lb2<=ub2)tmp[iter++]=arr[lb2++];
        for(int i=0;i<ub-lb+1;i++)arr[lb+i]=tmp[i];
    }
    void mSort(vi& arr,int lb,int ub)
    {
        if(lb>=ub)return;
        int mid=(lb+ub)/2;
        mSort(arr,lb,mid);
        mSort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
public:
    vector<int> lexicalOrder(int n) {
        vi sol(n);
        for(int i=0;i<n;i++)sol[i]=i+1;
        mSort(sol,0,n-1);
        return sol;
    }
};


// This method is much much faster 4ms. 
class Solution {
    public:
    void dfs(int num,vector<int> &answer,const int &n){
        num*=10;
        if(num>n) return;
        for(int i=0;i<=9;i++){
            num+=i;
            if(num>n) return;
            answer.push_back(num);
            dfs(num,answer,n);
            num-=i;
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> answer;
        for(int i=1;i<=9;i++){
            if(i>n) break;
            answer.push_back(i);
            dfs(i,answer,n);
        }
        return answer;
    }
};
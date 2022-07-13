//TLE.
typedef vector<int> vi;
class Solution {
    int n;
    int side;
    bool fn(vi& arr,int s1,int s2,int s3,int lb){
        if(s1==side && s2==side && s3==side)return true;
        if(s1>side || s2>side || s3>side || lb>=n)return false;   
        if(fn(arr,s1+arr[lb],s2,s3,lb+1))return true;
        if(fn(arr,s1,s2+arr[lb],s3,lb+1))return true;
        if(fn(arr,s1,s2,s3+arr[lb],lb+1))return true;
        if(fn(arr,s1,s2,s3,lb+1))return true;
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        n=matchsticks.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=matchsticks[i];
        if(sum%4)return false;
        side=sum/4;
        return fn(matchsticks,0,0,0,0);
    }
};

//Will work.
typedef vector<int> vi;
class Solution {
    int n;
    int side;
    vi sol;
    void fn(vi& arr,int s1,int flag,int lb){
        if(s1==side)
        {
            sol.push_back(flag);
            return;
        }
        if(s1>side || lb>=n)return;   
        fn(arr,s1+arr[lb],(flag|(1<<lb)),lb+1);
        fn(arr,s1,flag,lb+1);
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        n=matchsticks.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=matchsticks[i];
        if(sum%4)return false;
        side=sum/4;
        sol.clear();
        fn(matchsticks,0,0,0);
        int m=sol.size();
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                if(sol[i]&sol[j])continue;
                for(int k=j+1;k<m;k++){
                    if(sol[i]&sol[k] || sol[j]&sol[k])continue;
                    return true;
                }//k
            }//j
        }//i
        return false;
    }
};
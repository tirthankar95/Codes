/* METHOD 1*/
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
    vvi sol;
    int K;int N;
    void fn(vi elements_,int start,int rSum,int eCnt){
        if(start>9)return;
        if(rSum+start<=N && eCnt<=K){
            elements_.push_back(start);
            if(rSum+start==N && eCnt+1==K)
                sol.push_back(elements_);
            else 
            {
                fn(elements_,start+1,rSum+start,eCnt+1);
                elements_.pop_back();
                fn(elements_,start+1,rSum,eCnt);
            }
        }
    }
public:
    vvi combinationSum3(int k, int n) {
        sol.clear();
        vi elements_;N=n;K=k;
        fn(elements_,1,0,0);
        return sol;
    }
};

/* METHOD 2 */
typedef vector<int> vi;
class Solution {
    vector<vi> sol;
    int N;
    void fn(int strt,int k,int rSum,vi subSol)
    {
        if(k==0 && rSum==N)sol.push_back(subSol);
        else if(k==0)return;
        for(int i=strt;i<=9;i++)
        {
            if(rSum+i>N)
                break;
            subSol.push_back(i);
            fn(i+1,k-1,rSum+i,subSol);
            subSol.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        sol.clear();
        N=n;
        vi subSol;
        fn(1,k,0,subSol);
        return sol;
    }
};

/*
Method 2 is faster than Method 1 because the number of recursive function calls are reduced using for loops.
*/

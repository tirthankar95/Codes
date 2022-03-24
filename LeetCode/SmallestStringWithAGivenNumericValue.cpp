/********* DYNAMIC PROGRAMMING SOLUTION(TLE) **********/
/*
typedef pair<int,int> ii;
const int mxWt=26;
map<ii,pair<bool,string>> dp;
inline int getWeight(char ch){
    return ((int)(ch-'a')+1);
}

class Solution {
    pair<bool,string> fn(int n,int k){
        if(n==0 && k==0){
            return dp[ii(n,k)]=pair<bool,string>(true,"");
        }
        if(n<=0 || k<=0){
            return dp[ii(n,k)]=pair<bool,string>(false,"");
        }
        if(dp.find(ii(n,k))!=dp.end())
            return dp[ii(n,k)];
        string str="",res="";
        pair<bool,string> temp;
        for(char ch='a';ch<='z';ch++){
            if(k>=getWeight(ch)){
                temp=fn(n-1,k-getWeight(ch));
                if(temp.first){
                    str=temp.second+ch;
                    if(res=="" || str<res)
                        res=str;
                }
            }
            else 
                break;
        }//end of for. 
        if(res!="")
            return dp[ii(n,k)]=pair<bool,string>(true,res);
        else 
            return dp[ii(n,k)]=pair<bool,string>(false,res);
    }
public:
    string getSmallestString(int n, int k) {
        dp.clear();
        return fn(n,k).second;
    }
};
*/
/******************************************************/

class Solution {
public:
    string getSmallestString(int n, int k) {
        string initialAns="";
        int weight=0;
        for(int i=0;i<n;i++){
            initialAns+='a';
            weight++;
        }//end of for.
        int index=n-1;
        char ch;
        while(k>weight){
            ch=(k-weight>=26)?'z':(char)('a'+(k-weight));
            weight+=(int)(ch-'a');
            initialAns[index--]=ch;
        }
        return initialAns;
    }
};
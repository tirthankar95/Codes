
class Solution {
    // int N;
    // int sol;
    // void dfs(string s,string res,int ptr)
    // {
    //     if(ptr==N)
    //     {
    //         //cout<<res<<endl;
    //         sol++;
    //         return;
    //     }
    //     int f=(s[ptr]-'0')-1;
    //     if(f==-1)return;
    //     dfs(s,res+(char)('A'+f),ptr+1);
    //     f++;
    //     if(ptr+1<N && 10*f+(s[ptr+1]-'0')<=26 )
    //     {
    //         int tmp=10*f+(s[ptr+1]-'0')-1;
    //         dfs(s,res+(char)('A'+tmp),ptr+2);
    //     }
    // }
public:
    int numDecodings(string s) {
        int N=s.length();
        // sol=0;
        // string res="";
        // dfs(s,res,0);
        // return sol;
        vector<int> dp(N+1,0);
        dp[N]=1;
        for(int i=N-1;i>=0;i--)
        {
            if(s[i]=='0')continue;
            dp[i]+=dp[i+1];
            if(i+1<N)
            {
                int ft=10*(int)(s[i]-'0')+(int)(s[i+1]-'0')-1;
                if(ft<26)dp[i]+=dp[i+2];
            }
        }//end of for.
        return dp[0];
    }
};
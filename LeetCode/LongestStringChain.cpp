//#define DBG
bool cmp(string a,string b){
    return (a.length()<b.length());
}
class Solution {
    bool isParent(string par,string child){
        int n=par.length(),i=0;
        int nc=child.length(),ic=0;
        while(i<n && ic<nc){
            if(par[i]!=child[ic])ic++;
            else{
                i++;
                ic++;
            }
        }//end of while.
        return (i==n);
    }
#ifdef DBG
    void print(vector<string>& words){
        int n=words.size();
        for(int i=0;i<n;i++)
            cout<<words[i]<<" ";
        cout<<endl;
    }
#endif
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),cmp);
#ifdef DBG
        print(words);
#endif
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(words[j].length()==words[i].length()-1){
                    if(isParent(words[j],words[i]))
                        dp[i]=max(dp[i],1+dp[j]);
                }
                else if(words[j].length()<words[i].length()-1)
                    break;
            }
        }//end of outer for
        int mx=1;
        for(int i=0;i<n;i++)mx=max(mx,dp[i]);
        return mx;
    }
};
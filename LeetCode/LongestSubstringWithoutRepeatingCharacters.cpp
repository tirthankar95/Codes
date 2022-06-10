const int mxSize=128;
char hMap[mxSize];

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        memset(hMap,0,sizeof(hMap));
        int fptr=0,sptr=0;
        int n=s.length();
        if(!n)return 0;
        int mx=1;
        while(sptr<n){
            if(!hMap[s[sptr]]){
                mx=max(mx,sptr-fptr+1);
                hMap[s[sptr]]=true;
            }
            else{
                while(hMap[s[sptr]])
                    hMap[s[fptr++]]=false;
                mx=max(mx,sptr-fptr+1);
                hMap[s[sptr]]=true;
            }
            sptr++;
        }//end of while.
        return mx;
    }
};
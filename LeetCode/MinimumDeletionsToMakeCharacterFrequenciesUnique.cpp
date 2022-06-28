const int mxSize=26;
int freq[mxSize];

class Solution {
public:
    int minDeletions(string s) {
        memset(freq,0,sizeof(freq));
        int n=s.length();
        for(int i=0;i<n;i++)
            freq[(int)(s[i]-'a')]++;
        int cnt=0;int i=0;
        while(i<mxSize){
            if(!freq[i]){
                i++;
                continue;
            }
            bool incr=true;
            for(int j=0;j<mxSize;j++){
                if(!freq[i]){
                    incr=true;
                    break;
                }
                if(i!=j && freq[i]==freq[j]){
                    freq[i]--;
                    incr=false;
                    cnt++;
                }
            }//
            if(incr)i++;
        }//
        return cnt;
    }
};
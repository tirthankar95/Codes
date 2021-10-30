const int OFFSET=256;
const int LIMIT=1e9+1;
typedef long long ll;
class Solution {
    string ans;
    bool compute(string s,int win)
    {
        int n=s.length();
        ll hash=0,q=1;       
        for(int i=0;i<win;i++)
        {
            hash=((hash<<5)+(s[i]-'a'+OFFSET))%LIMIT;
            if(i!=0)q=(q<<5)%LIMIT;
        }
        unordered_map<int,bool> hashMap;
        hashMap[hash]=true;
        for(int i=win;i<n;i++)
        {
            hash=(hash-(q*(s[i-win]-'a'+OFFSET))%LIMIT)%LIMIT;
            if(hash<0)hash+=LIMIT;
            hash=((hash<<5)+(s[i]-'a'+OFFSET))%LIMIT;
            if(hashMap[hash]){
                int second=i-win+1;
                for(int j=0;j<second;j++){
                    if(s[second]==s[j])
                    {
                        int first=j,k;
                        for(k=0;k<win;k++)
                        {
                            if(s[first+k]!=s[second+k])
                                break;
                        }//end of for-k.
                        if(k==win)
                        {
                            ans=s.substr(second,win);
                            return true;
                        }
                    }
                }//end of for-j.
            }
            hashMap[hash]=true;
        }//end of i.
        return false;
    }
public:
    void fn(string s,int lb,int ub)
    {
        if(lb>ub)return;
        int mid=(lb+ub)/2;
        if(compute(s,mid))//returns true if a solution exists.
            fn(s,mid+1,ub);
        else
            fn(s,lb,mid-1);
    }
    string longestDupSubstring(string s) {
        ans="";
        fn(s,1,s.length());
        return ans;
    }
};
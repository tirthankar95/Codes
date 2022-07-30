const int mxSize=26;
char store[mxSize];
bool used[mxSize];

class Solution {
    string pattern;
    bool match(string w){
        memset(store,-1,sizeof(store));
        memset(used,false,sizeof(used));
        int n;
        if((n=w.length())!=pattern.length())return false;
        for(int i=0;i<n;i++)
        {
            if(store[(int)(w[i]-'a')]==-1)
            {
                if(!used[(int)(pattern[i]-'a')])
                {
                    store[(int)(w[i]-'a')]=pattern[i];
                    used[(int)(pattern[i]-'a')]=true;
                }
                else return false;
            }
            else if(store[(int)(w[i]-'a')]!=pattern[i])
                return false;
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pat1) {
        pattern=pat1;
        int sz=words.size();
        vector<string> res;
        for(int i=0;i<sz;i++)
        {
            if(match(words[i]))
                res.push_back(words[i]);
        }
        return res;
    }
};
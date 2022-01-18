const int mxSize=26;
int hashMap[mxSize];

class Solution {
    vector<string> split(string s,char ch){
        vector<string> res;
        int n=s.length();
        string temp="";
        for(int i=0;i<n;i++){
            if(s[i]==ch)
            {
                res.push_back(temp);
                temp="";
            }
            else{
                temp=temp+s[i];
            }
        }
        res.push_back(temp);
        return res;
    }
public:
    bool wordPattern(string pattern, string s) {
        int np=pattern.length(),id;
        vector<string> splitArr=split(s,' ');
        if(np!=splitArr.size())return false;
        memset(hashMap,-1,sizeof(hashMap));
        map<string,bool> SBmap;
        for(int i=0;i<np;i++){
            if(hashMap[(int)(pattern[i]-'a')]==-1){
                hashMap[(int)(pattern[i]-'a')]=i;
                if(SBmap[splitArr[i]])
                    return false;
                SBmap[splitArr[i]]=true;
            }
            else{
                id=hashMap[(int)(pattern[i]-'a')];
                if(splitArr[id]!=splitArr[i])return false;
            }
        }
        return true;
    }
};
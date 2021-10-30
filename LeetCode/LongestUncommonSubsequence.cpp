typedef pair<int,int> ii;
class Solution {
    bool isSubseq(string par,string child){
        int cPtr=0;
        int n=par.length();
        for(int i=0;i<n;i++){
            if(child[cPtr]==par[i]){
                cPtr++;
                if(cPtr==child.length())
                    return true;
            }
        }
        return false;
    }
public:
    int findLUSlength(vector<string>& strs) {
        int n=strs.size();
        vector<ii> lenId(n);
        for(int i=0;i<n;i++)
            lenId[i]=ii(strs[i].length(),i);
        sort(lenId.rbegin(),lenId.rend());
        bool flag_=true;
        for(int i=0;i<n;i++)
        {
            flag_=true;
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                if(isSubseq(strs[lenId[j].second],strs[lenId[i].second]))
                {
                    flag_=false;
                    break;
                }
            }//end of for-j.
            if(flag_)return lenId[i].first;
        }//end of for-i.
        return -1;
    }
};
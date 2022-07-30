const int mxSize=26;
int gcMap[mxSize];
int cMap[mxSize];

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int sz2=words2.size();
        memset(gcMap,0,sizeof(gcMap));
        for(int i=0;i<sz2;i++){
            memset(cMap,0,sizeof(cMap));
            for(int j=0;j<words2[i].length();j++)
                cMap[(int)(words2[i][j]-'a')]++;
            for(int j=0;j<mxSize;j++)
                gcMap[j]=max(gcMap[j],cMap[j]);
        }
        int sz1=words1.size(),j;
        vector<string> res;
        for(int i=0;i<sz1;i++){
            memset(cMap,0,sizeof(cMap));
            for(int j=0;j<words1[i].length();j++)
                cMap[(int)(words1[i][j]-'a')]++;
            for(j=0;j<mxSize;j++)
                if(cMap[j]<gcMap[j])break;
            if(j==mxSize)res.push_back(words1[i]);
        }
        return res;
    }
};
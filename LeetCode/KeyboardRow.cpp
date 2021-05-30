string s[3]={"qwertyuiop","asdfghjkl","zxcvbnm"};
unordered_map<char,bool> hashMap[3];
bool calledInit=false;

void init(){
    calledInit=true;
    for(int i=0;i<3;i++)
    {
        int n=s[i].length();
        for(int j=0;j<n;j++)
            hashMap[i][s[i][j]]=true;
    }
}
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> sol;
        init();
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            int m=words[i].length();
            for(int j=0;j<3;j++)
            {
                bool found=true;
                for(int k=0;k<m;k++)
                {
                    char ch=words[i][k];
                    if(ch<='Z')ch=(char)(ch+('a'-'A'));
                    if(!hashMap[j][ch])
                    {
                        found=false;
                        break;
                    }
                }//end of k.
                if(found)
                {
                    sol.push_back(words[i]);
                    break;
                }
            }//end of j.
        }//end of i.
        return sol;
    }
};
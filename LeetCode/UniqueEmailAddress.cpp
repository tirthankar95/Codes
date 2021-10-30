class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n=emails.size();
        vector<string> EM;
        for(int i=0;i<n;i++)
        {
            int m=emails[i].length(),j=0;
            string str="";
            for(;j<m;j++)
            {
                if(emails[i][j]=='.')continue;
                else if(emails[i][j]=='+'){
                    while(emails[i][j]!='@')j++;
                    break;
                }
                if(emails[i][j]=='@')break;
                str+=emails[i][j];
            }//end of for.
            for(;j<m;j++)
                str+=emails[i][j];
            cout<<str<<" ";
            EM.push_back(str);
        }//end of for.
        map<string,bool> hMap;int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(hMap.find(EM[i])==hMap.end())
            {
                hMap[EM[i]]=true;
                cnt++;
            }
        }
        return cnt;
    }
};
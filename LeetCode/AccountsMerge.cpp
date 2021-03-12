typedef vector<int> vi;

class Solution {
    int parent(vi& _set,int indx)
    {
        int tmp;
        while(_set[indx]!=indx)
        {
            tmp=_set[_set[indx]];
            _set[indx]=tmp;
            indx=tmp;
        }
        return indx;
    }
    void unionT(vi& _set,int indx1,int indx2)
    {
        int r1=parent(_set,indx1);
        int r2=parent(_set,indx2);
        if(r1==r2)return;
        _set[r2]=r1;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        map<string,vi> hMap;
        unordered_map<int,int> indexInSol;
        int m;
        for(int i=0;i<n;i++)
        {
            m=accounts[i].size();
            for(int j=1;j<m;j++)
            {
                hMap[accounts[i][j]].push_back(i);
            }//end of inner-for.
        }//end of outer-for. 
        map<string,vi>:: iterator it=hMap.begin();
        vi tmp;vector<string> tmp1;
        vi _set(n);
        for(int i=0;i<n;i++)_set[i]=i;
        while(it!=hMap.end())
        {
            tmp=(*it).second;
            int len=tmp.size();
            for(int j=1;j<len;j++)
                unionT(_set,tmp[j-1],tmp[j]);
            it++;
        }//end of while. 
        vector<vector<string>> sol,sol1;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int r1=parent(_set,i);
            if(indexInSol.find(r1)==indexInSol.end())
            {    
                indexInSol[r1]=cnt++;
                sol.push_back(accounts[i]);
            }
            else 
            {
                for(int k=1;k<accounts[i].size();k++)
                    sol[indexInSol[r1]].push_back(accounts[i][k]);
            }
        }//end of for.
        for(int i=0;i<cnt;i++)
            sort(sol[i].begin()+1,sol[i].end());
        for(int i=0;i<cnt;i++)
        {
            vector<string> tmp1;
            tmp1.push_back(sol[i][0]);
            for(int j=1;j<sol[i].size();j++)
            {
                if(sol[i][j-1]==sol[i][j])continue;
                tmp1.push_back(sol[i][j]);
            }
            sol1.push_back(tmp1);
        }
        return sol1;
    }
};
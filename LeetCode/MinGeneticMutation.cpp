char gene[4]={'A','C','G','T'};

class Solution {
public:
    int minMutation(string start, string end_, vector<string>& bank) {
        map<string,int> hashMap;
        int n=bank.size(),index;
        vector<bool> vis(n+1,false);
        vector<int> parent(n+1,0);
        for(int i=0;i<n;i++)
            hashMap[bank[i]]=i;
        if(hashMap.find(end_)==hashMap.end())return -1;
        queue<string> Qu;
        Qu.push(start);
        // start's index will be n
        vis[n]=true;
        while(!Qu.empty())
        {
            string tmp=Qu.front();
            index=(tmp==start)?n:hashMap[tmp];
            Qu.pop();
            for(int i=0;i<8;i++)
            {
                char orig=tmp[i];
                for(int j=0;j<4;j++)
                {
                    tmp[i]=gene[j];
                    if(hashMap.find(tmp)!=hashMap.end() && !vis[hashMap[tmp]])
                    {
                        Qu.push(tmp);
                        parent[hashMap[tmp]]=parent[index]+1;
                        vis[hashMap[tmp]]=true;
                    }
                    if(tmp==end_)
                        return parent[hashMap[tmp]];
                    tmp[i]=orig;
                }//end of outer-j.
            }//end of outer-i.
        }//end of while-loop.
        return -1;
    }
};
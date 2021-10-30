// # -> -1.
typedef vector<int> vi;
vi split(string s)
{
    int n=s.length();
    vi sol;int no=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=',' && s[i]!='#')
            no=no*10+(int)(s[i]-'0');
        else if(s[i]=='#')
            no=-1;
        else if(s[i]==',')
        {
            sol.push_back(no);
            no=0;
        }
    }
    sol.push_back(no);
    return sol;
}
class Solution {
public:
    bool isValidSerialization(string preorder) {
        vi sol=split(preorder);
        int n=sol.size();
        stack<int> pre;
        int i=0,a,b,c;
        while(i<n)
        {
            pre.push(sol[i]);
            //check-part.
            while(!pre.empty())
            {
                a=pre.top();
                pre.pop();
                if(!pre.empty())b=pre.top();
                else{
                    pre.push(a);
                    break;
                }
                pre.pop();
                if(a==-1 && b==-1)
                {
                    if(pre.empty())return false;
                    c=pre.top();
                    pre.pop();
                    pre.push(-1);
                }
                else
                {
                    pre.push(b);
                    pre.push(a);
                    break;
                }
            }//end of while-loop.
            i++;
        }
        if(pre.size()==1 && pre.top()==-1)return true;
        return false;
    }
};
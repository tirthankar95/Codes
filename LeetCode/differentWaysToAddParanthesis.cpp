typedef vector<int> vi;
typedef enum{
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
}SYMBOLS;
struct node{
    vi operands;
    vector<char> operators;
};

class Solution {
    int n;
    node extract(string input)
    {
        node sol;
        int tmp=0;int i=0,sign=0;
        if(input[0]=='-'){sign=2,i++;}
        while(i<n)
        {
            if(input[i]!='+' && input[i]!='-' && input[i]!='*')
            {
                while(i<n && input[i]!='+' && input[i]!='-' && input[i]!='*')
                {
                    tmp=tmp*10+(int)(input[i]-'0');
                    i++;
                }
                if(sign==2){tmp*=-1;sign=1;}
                sol.operands.push_back(tmp);
                tmp=0;
            }
            else
            {
                if(input[i]=='+')sol.operators.push_back(ADDITION);
                else if(input[i]=='-')sol.operators.push_back(SUBTRACTION);
                else sol.operators.push_back(MULTIPLICATION);
                i++;
            }
        }
        return sol;
    }
public:
    vector<int> diffWaysToCompute(string input) {
        n=input.length();
        node sol=extract(input);
        int m=sol.operands.size();
        vector<vector<vi>> dp(m,vector<vi>(m));
        for(int j=0;j<m;j++)
            dp[j][j].push_back(sol.operands[j]);   
        for(int d=1;d<m;d++)
        {
            for(int j=0;j<m-d;j++)
            {
                for(int k=j;k<j+d;k++)
                {
                    int n1=dp[j][k].size();
                    int n2=dp[k+1][j+d].size();
                    for(int iter1=0;iter1<n1;iter1++)
                    {
                        for(int iter2=0;iter2<n2;iter2++)
                        {              
                            if(sol.operators[k]==ADDITION)
                                dp[j][j+d].push_back(dp[j][k][iter1]+dp[k+1][j+d][iter2]);
                            else if(sol.operators[k]==SUBTRACTION)
                                dp[j][j+d].push_back(dp[j][k][iter1]-dp[k+1][j+d][iter2]);
                            else 
                                dp[j][j+d].push_back(dp[j][k][iter1]*dp[k+1][j+d][iter2]);
                        }//end of iter2.
                    }//end of iter1.
                }//end dof k.
            }//end of j.
        }//end of d. 
        vi result=dp[0][m-1];
        sort(result.begin(),result.end());
        return result;
    }
};
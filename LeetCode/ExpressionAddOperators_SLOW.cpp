typedef long long ll;
typedef vector<ll> vll;
vector<char> op({'+','-','*'});
#define ENABLE

class Solution {
    int N,T;
    vector<string> sol;
    string num;
    int eval(string expr)
    {
#ifdef ENABLE
        int n=expr.length();
        vll operand_;vector<char> operator_;
        int no=0;
        for(int i=0;i<n;i++)
        {
            if(expr[i]=='+' || expr[i]=='-' || expr[i]=='*')
            {
                operand_.push_back(no);
                operator_.push_back(expr[i]);
                no=0;
            }
            else
                no=no*10+(int)(expr[i]-'0');
        }
        operand_.push_back(no);
        n=operator_.size(); 
        if(n==0) return operand_[0];
        int i=0;
        while(i<operator_.size())
        {
            if(operator_[i]=='*')
            {
                operator_.erase(operator_.begin()+i);
                ll a=operand_[i],b=operand_[i+1];
                operand_.erase(operand_.begin()+i);
                operand_.erase(operand_.begin()+i);
                operand_.insert(operand_.begin()+i,a*b);
                i--;
            }
            i++;
        }
        n=operator_.size();
        ll tmp=operand_[0];
        for(int i=0;i<n;i++)
            tmp=(operator_[i]=='-')?(tmp-operand_[i+1]):(tmp+operand_[i+1]);
        return tmp;
#else
        return T+1; // for checking the speed.
#endif  
    }
    void fn(string expr,int ptr)
    {
        if(ptr>=N){
            if(eval(expr)==T)
                sol.push_back(expr);
            return;
        }
        expr+=num[ptr];
        if(ptr!=N-1){
            for(auto operator_:op){
                string tmp=expr;
                tmp+=operator_;
                fn(tmp,ptr+1);
            }
        }
        int id=expr.length()-3;
        if(id==-1 && expr[id+1]=='0')return;
        if(id>=0 && (expr[id]=='+' || expr[id]=='-' || expr[id]=='*') && expr[id+1]=='0')return;
        fn(expr,ptr+1);
    }
public:
    vector<string> addOperators(string num_, int target){
        N=num_.length();
        T=target;
        sol.clear();
        string expr="";
        num=num_;
        fn(expr,0);
        return sol;
    }
};
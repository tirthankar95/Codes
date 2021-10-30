typedef long long ll;
typedef vector<ll> vll;
vector<char> op({'*','+','-'});

class Solution {
    int N,T;
    vector<string> sol;
    string num;
    void fn(string expr,ll rRes,ll pa,ll a,char llOp,char lOp,int ptr)
    {
        if(ptr>=N){
            ll rRestmp=0;
            if(lOp=='+' || lOp=='-')
                rRestmp=(lOp=='+')?(rRes+a):(rRes-a);
            else if(lOp=='*')
            {
                if(llOp!=0)rRestmp=(llOp=='+')?(rRes-pa+pa*a):(rRes+pa-pa*a);
                else rRestmp=rRes*a;
            }
            if(rRestmp==T)
                sol.push_back(expr);
            return;
        }
        expr+=num[ptr];
        a=a*10+(num[ptr]-'0');
        if(ptr!=N-1)
        {
            ll rRestmp=0;
            if(lOp=='+' || lOp=='-')
                rRestmp=(lOp=='+')?(rRes+a):(rRes-a);
            else if(lOp=='*')
            {
                if(llOp!=0)rRestmp=(llOp=='+')?(rRes-pa+pa*a):(rRes+pa-pa*a);
                else rRestmp=rRes*a;
            }
            for(auto operator_:op){
                string tmp=expr+operator_;
                char llOp_=llOp;ll pa_=pa;
                if(operator_=='*')
                {
                    llOp_=(llOp_==0 && (lOp=='+' || lOp=='-'))?lOp:llOp_;
                    if(llOp_!=0)pa_=(pa_==0)?a:pa_*a;
                }
                else{
                    llOp_=0;
                    pa_=0;
                }
                fn(tmp,rRestmp,pa_,0,llOp_,operator_,ptr+1);
            }
        }//end of putting if-operators.
        int id=expr.length()-1;
        if(ptr+1<N && id-1>=0 && (expr[id-1]=='+' || expr[id-1]=='-' || expr[id-1]=='*') && expr[id]=='0')return;
        fn(expr,rRes,pa,a,llOp,lOp,ptr+1);
    }
public:
    vector<string> addOperators(string num_, int target){
        N=num_.length();sol.clear();
        T=target;num=num_;
        string expr="";ll no=0;
        ////////////////////////////////
        for(int i=0;i<N;i++)
        {
            expr+=num_[i];
            no=no*10+(num_[i]-'0');
            if(i!=N-1){
                for(auto operator_:op){
                    string tmp=expr;
                    tmp+=operator_;
                    fn(tmp,no,0,0,0,operator_,i+1);
                }
            }
            if(num_[0]=='0')break;
        }
        if(no==T && expr[0]!='0')sol.push_back(num);
        ////////////////////////////////
        return sol;
    }
};
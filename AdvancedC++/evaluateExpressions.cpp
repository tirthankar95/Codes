#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;


int eval(string expr)
{
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
}

int main(){
	cout<<eval("1*2*3")<<endl;
	cout<<eval("1*2+3")<<endl;
	cout<<eval("1+2+3")<<endl;
	return 0;
}
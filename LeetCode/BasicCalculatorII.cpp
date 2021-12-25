//Correct Solution
#if 0
#define DBG
typedef vector<double> vi;
static char allOperators[]={'+','-','*','/'};

class Solution {
#ifdef DBG
    void print(vi& operand_,vector<char>& operator_){
        int sz=operator_.size();
        for(int i=0;i<sz;i++)
            cout<<operand_[i]<<operator_[i]<<operand_[i+1]<<":";
        cout<<endl;
    }
#endif
    string removeSpaces(string s){
        int n=s.length();
        string res="";
        for(int i=0;i<n;i++)
            if(s[i]!=' ')res+=s[i];
        return res;
    }
public:
    int calculate(string s1) {
        string s=removeSpaces(s1);
        int n=s.length();
        int no=0;
        vi operand_;
        vector<char> operator_;
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9')
                no=no*10+(int)(s[i]-'0');
            else if( s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' ){
                operand_.push_back(no);
                operator_.push_back(s[i]);
                no=0;
            }   
        }//end of for-loop.
        operand_.push_back(no);
        int sz=operator_.size(),lb;
        double temp;
        for(int i=3;i>=0;i--){
            lb=0;
#ifdef DBG
            print(operand_,operator_);
#endif
            while(lb<sz){
                if(operator_[lb]==allOperators[i]){
                    switch(i){
                        case 3:
                            temp=operand_[lb]/operand_[lb+1];
                            break;
                        case 2:
                            temp=operand_[lb]*operand_[lb+1];
                            break;
                        case 1:
                            temp=operand_[lb]-operand_[lb+1];
                            break;
                        case 0:
                            temp=operand_[lb]+operand_[lb+1];
                            break;
                    }//end of switch.
                    operator_.erase(operator_.begin()+lb);
                    operand_.erase(operand_.begin()+lb);
                    operand_[lb]=temp;
                    sz--;
                }
                else lb++;
            }//end of while.
        }
        return round(operand_[0]);
    }
};
#endif
//Solution they want. [ In C++ precedence of '/' & '*' are same so is the precedence of '+' & '-' ]
class Solution {
public:
    int calculate(string s) {
        int n = (int) s.size();
        
        // Treat each number as the second operand.
        // op is the type of operation in which the number is being used
        
        stack<int> stack;
        int num = 0;
        char op = '+'; // last seen operation (assume + initially since we want to add first num to stack)
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); 
            }
            if ((!isdigit(c) && !isspace(c)) || i == n - 1) {
                if (op == '+') {
                    stack.push(num);
                } else if (op == '-') {
                    stack.push(-num);
                } else {
                    int top = stack.top();
                    stack.pop();
                    if (op == '*') {
                        stack.push(top * num);
                    } else {
                        stack.push(top / num);
                    }
                }
                op = c;
                num = 0;
            }
        }
        
        int result = 0;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        
        return result;
    }
};
/* My modified solution unoptimized TLE */
//#define DBG
typedef vector<int> vi;
static char allOperators[]={'+','-','*','/'};

class Solution {
#ifdef DBG
    void print(vi& operand_,vector<char>& operator_){
        int sz=operator_.size();
        for(int i=0;i<sz;i++)
            cout<<operand_[i]<<operator_[i]<<operand_[i+1]<<":";
        cout<<endl;
    }
#endif
    string removeSpaces(string s){
        int n=s.length();
        string res="";
        for(int i=0;i<n;i++)
            if(s[i]!=' ')res+=s[i];
        return res;
    }
public:
    int calculate(string s1) {
        string s=removeSpaces(s1);
        int n=s.length();
        int no=0;
        vi operand_;
        vector<char> operator_;
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9')
                no=no*10+(int)(s[i]-'0');
            else if( s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' ){
                operand_.push_back(no);
                operator_.push_back(s[i]);
                no=0;
            }   
        }//end of for-loop.
        operand_.push_back(no);
        int sz=operator_.size(),lb,temp;
        for(int i=2;i>=0;i-=2){
            lb=0;
#ifdef DBG
            print(operand_,operator_);
#endif
            while(lb<sz){
                if(operator_[lb]==allOperators[i] || operator_[lb]==allOperators[i+1]){
                    switch(operator_[lb]){
                        case '/':
                            temp=operand_[lb]/operand_[lb+1];
                            break;
                        case '*':
                            temp=operand_[lb]*operand_[lb+1];
                            break;
                        case '-':
                            temp=operand_[lb]-operand_[lb+1];
                            break;
                        case '+':
                            temp=operand_[lb]+operand_[lb+1];
                            break;
                    }//end of switch.
                    operator_.erase(operator_.begin()+lb);
                    operand_.erase(operand_.begin()+lb);
                    operand_[lb]=temp;
                    sz--;
                }
                else lb++;
            }//end of while.
        }
        return operand_[0];
    }
};

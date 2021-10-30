//Time is halved with #define.
#define SPC
class Solution {
    int n,index;
    enum{
        ADD,
        SUB
    };
    string removeSpaces(string s)
    {
        string ans="";int i=-1;
        while(s[++i]){
            if(s[i]!=' ')ans+=s[i];
        }
        return ans;
    }
    int expr(string s)
    {
        int no1=0,no2,sign=1;
        if(s[index]=='(')
            index++,no1=expr(s);
        else
        {
#ifdef SPC
            while(index<n && s[index]==' ')index++; //SPC
#endif
            if(s[index]=='-'){sign=-1;index++;} // if the first number is negative. 
#ifdef SPC
            while(index<n && s[index]==' ')index++; //SPC
#endif
            while(index<n && s[index]>='0' && s[index]<='9')
                no1=no1*10+(int)(s[index++]-'0');
            no1*=sign;
        }
        do{
            if(index>=n || s[index]==')'){
                index++;
                break;
            }
#ifdef SPC
            if(s[index]==' '){index++;continue;} //SPC
#endif
            int op=(s[index++]=='+')?ADD:SUB;
#ifdef SPC
            while(index<n && s[index]==' ')index++; //SPC
#endif
            no2=0;
            if(s[index]=='(')
                index++,no2=expr(s);
            else{
#ifdef SPC
                while(index<n && s[index]==' ')index++; //SPC
#endif
                while(index<n && s[index]>='0' && s[index]<='9')
                    no2=no2*10+(int)(s[index++]-'0');
            }
            if(op==ADD) no1+=no2;
            else no1-=no2;
        }while(index<n);
        return no1;
    }
public:
    int calculate(string s) {
#ifndef SPC
        s=removeSpaces(s);
#endif
        index=0,n=s.length();
        int sign=1;
#ifdef SPC
        while(index<n && s[index]==' ')index++; //SPC
#endif
        if(s[index]=='-'){
            int i=index+1;
#ifdef SPC
            while(i<n && s[i]==' ')i++; //SPC
#endif
            if(s[i]=='('){
                index=i;
                sign=-1;
            }
        }
        return sign*expr(s);
    }
};
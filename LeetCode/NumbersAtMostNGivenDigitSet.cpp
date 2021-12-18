typedef vector<int> vi;
typedef pair<int,bool> ib;
vi digit(10);//contains the digits of the limiting number.
class Solution {
    int L,n;
    // returns number of elements less than 'elem'
    ib bin(vector<string>& digit_array,int elem){
        char elemC=(char)('0'+elem);
        int lb=0,ub=L-1,mid;
        while(lb<=ub){
            mid=(lb+ub)/2;
            if(digit_array[mid][0]==elemC)
                return ib(mid,true);
            else if(digit_array[mid][0]<elemC)lb=mid+1;
            else ub=mid-1;
        }
        return ib(lb,false);
    }
    int fn(int n,vector<string>& digit_array){
        if(n==1)
        {
            ib tmp=bin(digit_array,digit[0]);
            return tmp.first+tmp.second;
        }
        int b=pow(L,n-1);
        int a=(L==1)?n-1:(L*(b-1)/(L-1));
        ib r=bin(digit_array,digit[n-1]);
        if(r.first==0 && !r.second)
            return a;
        else if(!r.second)//element not found in digit_array
            return r.first*b+a;
        else
            return (r.first+1)*b+fn(n-1,digit_array);
    }
public:
    int atMostNGivenDigitSet(vector<string>& digit_array, int no) {
        L=digit_array.size();
        n=0;
        while(no){
            digit[n++]=no%10;
            no/=10;
        }
        return fn(n,digit_array);
    }
};
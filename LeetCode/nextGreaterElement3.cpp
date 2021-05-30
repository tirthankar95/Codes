//LSB .... MSB.
typedef vector<int> vi;
typedef long long ll;
const ll limit=((ll)1<<31)-1;
class Solution {
    void split(int n,vi& digits)
    {
        if(!n){
            digits.push_back(0);
            return;
        }
        while(n)
        {
            int m=n%10;
            digits.push_back(m);
            n/=10;
        }
    }
    int construct(vi& digits)
    {
        int n=digits.size();
        ll val=0;
        for(int i=n-1;i>=0;i--)
            val=val*(ll)10+(ll)digits[i];
        if(limit<val)return -1;
        return (int)val;
    }
public:
    int nextGreaterElement(int n) {
        vi digits;
        split(n,digits);
        bool noSol=true;
        for(int i=0;i<digits.size()-1;i++)
        {
            if(digits[i]>digits[i+1])
            {
                noSol=false;
                int mi=INT_MAX;int miIndx=-1;
                for(int j=i;j>=0;j--)
                {
                    if(digits[j]>digits[i+1] && mi>digits[j])
                    {
                        mi=digits[j];
                        miIndx=j;
                    }
                }
                swap(digits[miIndx],digits[i+1]);
                sort(digits.begin(),digits.begin()+i+1);
                reverse(digits.begin(),digits.begin()+i+1);
                break;
            }
        }//end of for-loop.
        if(noSol)return -1;
        return construct(digits);
    }
};
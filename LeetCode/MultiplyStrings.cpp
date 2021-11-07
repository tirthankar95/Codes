const int mxSize=501;
int prodArr[mxSize][2];
class Solution {
public:
    string multiply(string num1, string num2) {
        int d1,d2,c,prod,offset=0,j,iter,tmp;
        int n1=num1.length()-1;
        int n2=num2.length()-1;
        memset(prodArr,0,sizeof(prodArr));
        for(int i=n2;i>=0;i--)
        {
            d1=(int)(num2[i]-'0');
            c=0,iter=offset;
            for(j=n1;j>=0;j--)
            {
                d2=(int)(num1[j]-'0');
                prod=(d1*d2+c)%10;
                c=(d1*d2+c)/10;
                prodArr[iter++][1]=prod;
            }
            while(c){
                prodArr[iter++][1]=c%10;
                c/=10;
                j++;
            }
            for(j=offset;j<iter;j++)
            {
                tmp=prodArr[j][0]+prodArr[j][1]+c;
                prodArr[j][0]=tmp%10;
                c=tmp/10;
            }
            while(c){
                tmp=prodArr[j][0]+c;
                prodArr[j][0]=tmp%10;
                c=tmp/10;
                j++;
            }
            offset++;
        }//end of for-i.
        string res="";
        for(j=mxSize-1;j>=0;j--)
        {
            if(prodArr[j][0])
                break;
        }
        if(j<0)return "0";
        for(int i=j;i>=0;i--)
            res=res+(char)('0'+prodArr[i][0]);
        return res;
    }
};
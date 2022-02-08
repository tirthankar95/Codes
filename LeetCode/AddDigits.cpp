class Solution {
public:
    int addDigits(int num) {
        if((num/10)==0)return num;
        int sum=0;
        while(num){
            sum=sum+num%10;
            num/=10;
        }
        return addDigits(sum);
    }
};

/* Best Solution
class Solution {
public:
    int addDigits(int num) {
        if(num==0)return 0;
        int ans=num%9;
        if(!ans)return 9;
        return ans;
    }
};
*/
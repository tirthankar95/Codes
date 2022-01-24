typedef long long ll;
typedef vector<int> vi;
static int arr[10]={1,2,3,4,5,6,7,8,9,0};

class Solution {
public:
    vi sequentialDigits(int low, int high) {
        int temp=low;
        int swin=0,bwin=0;
        while(temp){
            temp/=10;
            swin++;
        }//end of while.
        temp=high;
        while(temp){
            temp/=10;
            bwin++;
        }//end of while. 
        ll no=0,iter=0,hash=1;
        while(iter<swin){
            no=no*10+arr[iter++];
            hash*=10;
        }
        hash/=10;
        ll win=swin,noSav=no;
        vi sol;
        while(win<=bwin){
            while(iter<10){
                if(low<=no && no<=high)
                    sol.push_back(no);
                if(no>high)
                    return sol;
                no=(no-hash*arr[iter-win])*10+arr[iter++];
            }//end of inner-while.
            if(win==9)break;
            noSav=noSav*10+arr[win++];
            hash*=10,no=noSav,iter=win;
        }//end of outer-while. 
        return sol;
    }
};
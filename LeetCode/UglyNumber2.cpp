class Solution {
public:
    int nthUglyNumber(int n) {
        int ptr2=0,ptr3=0,ptr5=0;
        int cnt=0,elem;
        vector<int> arr(n);
        arr[0]=1;
        while(cnt+1<n)
        {
            elem=min(arr[ptr2]*2,min(arr[ptr3]*3,arr[ptr5]*5));
            if(elem==arr[ptr2]*2)ptr2++;
            if(elem==arr[ptr3]*3)ptr3++;
            if(elem==arr[ptr5]*5)ptr5++;
            arr[++cnt]=elem;
        }
        return arr[n-1];
    }
};
//#define DBG

class priority_queue_{
    int* arr;
    int sz;
    const int mxSize=1001;
    public:
    priority_queue_(){
        arr=new int[mxSize];
        sz=0;
    }
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}
    int parent(int i){return (i-1)/2;}
#ifdef DBG
    void printpQ()
    {
        for(int i=0;i<sz;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
#endif
    void push(int elem);
    void pop();
    int top(){return arr[0];}
    bool empty(){return (sz<=0);}
};
void priority_queue_::push(int elem){
    int iter=sz;
    arr[sz++]=elem;
    while(iter!=0 && arr[iter]>arr[parent(iter)]){
        swap(arr[iter],arr[parent(iter)]);
        iter=parent(iter);
    }
}
void priority_queue_::pop(){
    swap(arr[0],arr[sz-1]);
    sz--;
    int iter=0,bigIndex;
    while(iter<sz)
    {
        bigIndex=iter;
        if(left(iter)<sz && arr[left(iter)]>arr[bigIndex])
            bigIndex=left(iter);
        if(right(iter)<sz && arr[right(iter)]>arr[bigIndex])
            bigIndex=right(iter);
        if(iter==bigIndex)break;
        swap(arr[iter],arr[bigIndex]);
        iter=bigIndex;
    }
}
#ifdef DBG
    void test(){
        priority_queue_ pQ;
        for(int i=0;i<10;i++)
            pQ.push(i);
        pQ.printpQ();
        while(!pQ.empty()){
            cout<<pQ.top()<<" ";
            pQ.pop();
        }
        cout<<"\n\n";
    }
#endif
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue_ pQ;
        int n=stones.size();
#ifdef DBG
        test();
#endif
        for(int i=0;i<n;i++)
            pQ.push(stones[i]);
        int e1,e2;
        while(!pQ.empty()){
            e1=pQ.top();
            pQ.pop();
            if(pQ.empty())return e1;
            e2=pQ.top();
            pQ.pop();
            pQ.push(e1-e2);
        }//end of while. 
        return 0;
    }
};
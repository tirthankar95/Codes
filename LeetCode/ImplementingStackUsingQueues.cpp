class MyStack {
    int mxSize=1e2+1;
    int* arr;
    int ptr;
public:
    MyStack() {
        arr=new int[mxSize];
        ptr=0;
    }
    void push(int x) {
        if(ptr==mxSize){
            mxSize*=5;
            int* arr_=new int[mxSize];
            for(int i=0;i<mxSize;i++)
                arr_[i]=arr[i];
            arr=arr_;
        }
        arr[ptr++]=x;
    }
    int pop() {
        if(!empty())
            return arr[--ptr];
        else return -1;//error.
    }
    int top() {
        if(!empty())
            return arr[ptr-1];
        else return -1;//error.
    }
    bool empty() {
        return (ptr==0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
const int mxSize=1e4+1;
int st[mxSize];
int minSt[mxSize];
class MinStack {
    int front;
public:
    MinStack() {
        front=0;
    }
    void push(int val) {
        minSt[front]=(front==0)?val:min(val,minSt[front-1]);
        st[front++]=val;
    }
    void pop() {
        front--;
    }
    int top() {
        return st[front-1];
    }
    int getMin() {
        return minSt[front-1];
    }
};

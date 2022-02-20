//#define DBG
typedef vector<int> vi;

void merge(vector<vi>& intervals,int lb,int mid,int ub){
    int f=lb,s=mid+1;
    vector<vi> temp(ub-lb+1);
    int iter=0;
    while(f<=mid && s<=ub){
        if(intervals[f][1]<=intervals[s][1]){
            if(intervals[f][1]==intervals[s][1]){
                if(intervals[f][0]<=intervals[s][0])
                    temp[iter++]=intervals[s++];
                else 
                    temp[iter++]=intervals[f++];
            }
            else
                temp[iter++]=intervals[f++];
        }//
        else 
            temp[iter++]=intervals[s++];
    }//eow
    while(f<=mid){
        temp[iter++]=intervals[f++];
    }
    while(s<=ub){
        temp[iter++]=intervals[s++];
    }
    for(int i=lb;i<=ub;i++)
        intervals[i]=temp[i-lb];
}
void msort(vector<vi>& intervals,int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        msort(intervals,lb,mid);
        msort(intervals,mid+1,ub);
        merge(intervals,lb,mid,ub);
    }
}
class Solution {
#ifdef DBG
    void print(vector<vi>& intervals){
        int n=intervals.size();
        for(int i=0;i<n;i++)
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        cout<<endl;
    }
#endif
public:
    int removeCoveredIntervals(vector<vi>& intervals) {
        int n=intervals.size();
        msort(intervals,0,n-1);
#ifdef DBG
        print(intervals);
#endif
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty() || intervals[i][0]<=intervals[st.top()][0])
            {
                while(!st.empty() && intervals[i][0]<=intervals[st.top()][0])
                    st.pop();
                st.push(i);
            }
            else if(intervals[st.top()][1]<=intervals[i][1])
                st.push(i);
        }
        int cnt=0;
        while(!st.empty()){
            cnt++;
            st.pop();
        }
        return cnt;
    }
};
class MyCalendar {
    vector<pair<int,int>> intervals;
public:
    MyCalendar() {
        intervals.clear();
    }
    
    bool book(int start, int end) {
        int n=intervals.size();
        for(int i=0;i<n;i++){
            if((intervals[i].first<=start && start<intervals[i].second)||(intervals[i].first<end && end<=intervals[i].second)||(start<=intervals[i].first && intervals[i].second<=end))
                return false;
        }
        intervals.push_back(pair<int,int>(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
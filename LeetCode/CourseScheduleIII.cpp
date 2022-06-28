typedef vector<int> vi;

class Solution {
public:
    int scheduleCourse(vector<vi>& courses) {
        vector<vi> c_;
        int n=courses.size();
        for(int i=0;i<n;i++){
            if(courses[i][0]>courses[i][1])continue;
            c_.push_back({courses[i][1],courses[i][0]});// <end,duration>
        }//
        sort(c_.begin(),c_.end());
        n=c_.size();
        if(!n)return 0;
        int cnt=0,current=0;
        for(int i=0;i<n;i++){
            if(current+c_[i][1]<=c_[i][0]){
                current+=c_[i][1];
                c_[cnt++]=c_[i];
            }
            else{
                int mx=i;
                for(int j=0;j<cnt;j++){
                    if(c_[j][1]>c_[mx][1]){
                        mx=j;
                    }
                }//
                current-=(c_[mx][1]-c_[i][1]);
                swap(c_[i][1],c_[mx][1]);
            }
        }//for-i
        return cnt;
    }
};
//#define DBG
typedef vector<int> vi;
typedef vector<vi> vvi;

static bool comp(vi& a,vi& b){
    if(a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]))return true;
    else return false;
}
class Solution {
public:
    vvi reconstructQueue(vvi& people) {
        sort(people.begin(),people.end(),comp);
#ifdef DBG 
        for(int i=0;i<people.size();i++)
            cout<<people[i][0]<<" "<<people[i][1]<<endl;
        cout<<endl;
#endif 
        int n=people.size(),blank;
        vvi res(n,vi({-1,-1}));
        for(int i=0;i<n;i++){
            blank=0;
            for(int j=0;j<n;j++){
                if(res[j][0]==-1){
                    blank++;
                    if(blank>people[i][1]){
                        res[j]=people[i];
                        break;
                    }
                }//o-if
            }//i-for
        }//o-for.
        return res;
    }
};
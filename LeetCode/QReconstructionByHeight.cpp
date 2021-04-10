This “comparator” function returns a value; convertible to bool, which basically tells us whether the passed “first” argument should be placed before the passed “second” argument or not. For eg: In the code below, suppose intervals {6,8} and {1,9} are passed as arguments in the “compareInterval” function(comparator function). Now as i1.first (=6) > i2.first (=1), so our function returns “false”, which tells us that “first” argument should not be placed before “second” argument and so sorting will be done in order like {1,9} first and then {6,8} as next. 

The N^2 approach given in solution is less optimal (beats around 50% solutions) probably due to the shifting -

class Solution{
public:
    static bool sortPeople(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
        else return a[0] > b[0];
    }
        
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people){
        sort(people.begin(), people.end(), sortPeople);
        vector<vector<int>> q;
        
        for(vector<int> p : people){
            q.insert(q.begin()+p[1],p);
        }
        
        return q;
    }
};

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
    void print(vvi& ans)
    {
        int n=ans.size();
        for(int i=0;i<n;i++)
            cout<<"["<<ans[i][0]<<" "<<ans[i][1]<<"] ";
        cout<<endl;
    }
public:
    vvi reconstructQueue(vvi& people) {
        sort(people.begin(),people.end());
        int n=people.size();
        vvi ans(n,vi(2,-1));
        for(int i=0;i<n;i++)
        {
            int noOfPeople=people[i][1],j;
            for(j=0;j<n;j++)
            {
                if(noOfPeople==0 && ans[j][0]==-1)break;
                if(ans[j][0]==-1 || ans[j][0]==people[i][0])noOfPeople--;
            }
            ans[j]=people[i];
        }//end of for.
        return ans;
    }
};

/* DP solution - It won't work since there is no recurring subproblems 
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
    int mi;
    int n2,n;
    map<pair<vi,int>,bool> dp;
    bool fn(vvi& costs,int i,int costA,int A,int costB,int B,vi& elemB){
        if(A>n || B>n)
            return dp[pair<vi,int>{elemB,i}]=false;
        if(A==n && B==n){
            mi=min(mi,costA+costB);
            return dp[pair<vi,int>{elemB,i}]=true;
        }
        if(dp.find(pair<vi,int>{elemB,i})!=dp.end())
        {
            cout<<"Hit\n";
            return dp[pair<vi,int>{elemB,i}];
        }
        bool r1=fn(costs,i+1,costA+costs[i][0],A+1,costB,B,elemB);
        elemB.push_back(i);
        r1|=fn(costs,i+1,costA,A,costB+costs[i][1],B+1,elemB);
        elemB.pop_back();
        return dp[pair<vi,int>{elemB,i}]=r1;
    }
public:
    int twoCitySchedCost(vvi& costs) {
        mi=INT_MAX;dp.clear();
        n2=costs.size();
        n=n2/2;
        vi elemB;
        fn(costs,0,0,0,0,0,elemB);
        return mi;
    }
};
*/

/* I have to find a greedy solution to this problem */
typedef vector<int> vi;
typedef pair<int,int> ii;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vi a,b;
        int ac=0,bc=0;
        int costa=0,costb=0;
        int n=costs.size();
        int index;
        for(int i=0;i<n;i++){
            if(costs[i][0]<costs[i][1])
            {
                ac++;
                costa+=costs[i][0];
                a.push_back(i);
            }
            else
            {
                bc++;
                costb+=costs[i][1];
                b.push_back(i);
            }
        }//end of for-i.
        if(ac>bc){
            int m=a.size();
            vector<ii> temp(m);
            for(int i=0;i<m;i++)
            {
                index=a[i];
                temp[i]=ii(abs(costs[index][0]-costs[index][1]),index);
            }
            sort(temp.begin(),temp.end());
            int iter=0;
            while(ac>bc){
                costa-=costs[temp[iter].second][0];
                costb+=costs[temp[iter].second][1];
                ac--;bc++;
                iter++;
            }
        }//end of if.
        else if(bc>ac){
            int m=b.size();
            vector<ii> temp(m);
            for(int i=0;i<m;i++)
            {
                index=b[i];
                temp[i]=ii(abs(costs[index][0]-costs[index][1]),index);
            }
            sort(temp.begin(),temp.end());
            int iter=0;
            while(bc>ac){
                costb-=costs[temp[iter].second][1];
                costa+=costs[temp[iter].second][0];
                bc--;ac++;
                iter++;
            }
        }//end of else-if.
        return costa+costb;
    }
};
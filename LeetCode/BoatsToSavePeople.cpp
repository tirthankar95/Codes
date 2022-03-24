class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int lb=0;int ub=people.size()-1;
        int count=0;
        while(lb<=ub){
            if(lb!=ub && limit>=people[lb]+people[ub])
                lb++;
            ub--;
            count++;
        }//end of while.
        return count;
    }
};
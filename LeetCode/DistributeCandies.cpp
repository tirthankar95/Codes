class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        n/=2;
        unordered_map<int,bool> isPresent;
        int uniq=0;
        for(int i=0;i<2*n;i++)
        {
            if(isPresent.find(candyType[i])==isPresent.end())
            {
                isPresent[candyType[i]]=true;
                uniq++;
            }
        }
        return min(uniq,n);
    }
};
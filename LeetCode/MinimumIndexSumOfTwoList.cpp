class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> hashMap;
        int n=list1.size();
        for(int i=0;i<n;i++)hashMap[list1[i]]=i;
        int mi=INT_MAX;
        n=list2.size();
        for(int i=0;i<n;i++)
        {
            if(hashMap.find(list2[i])!=hashMap.end())
                mi=min(mi,i+hashMap[list2[i]]);
        }
        vector<string> soln;
        for(int i=0;i<n;i++)
        {
            if(hashMap.find(list2[i])!=hashMap.end() && (i+hashMap[list2[i]])==mi)
                soln.push_back(list2[i]);
        }
        return soln;
    }
};
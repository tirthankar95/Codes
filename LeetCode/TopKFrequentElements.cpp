#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hMap;
        int n=nums.size();
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,nums[i]);
            hMap[nums[i]]++;
        }//end of for.
        vector<ii> arr(n);int sz=0;
        unordered_map<int,int>:: iterator it=hMap.begin();
        for(;it!=hMap.end();it++)
            arr[sz++]=ii(it->second,it->first);
        arr.resize(sz);
        sort(arr.rbegin(),arr.rend());
        vector<int> sol(k);
        for(int i=0;i<k;i++)
            sol[i]=arr[i].second;
        return sol;        
    }
};

void print(vector<int>& vArr){
    for(int i=0;i<vArr.size();i++)
        cout<<vArr[i]<<" ";
    cout<<endl;
}
int main(){
    Solution obj;
    //TC 1
    vector<int> temp({1,1,1,2,2,3});
    vector<int> vArr=obj.topKFrequent(temp,2);
    print(vArr);
    //TC 2
    vector<int> temp1({1});
    vector<int> vArr1=obj.topKFrequent(temp1,1);
    print(vArr1);
    //TC 3
    vector<int> temp2({-1,-1});
    vector<int> vArr2=obj.topKFrequent(temp2,1);
    print(vArr2);
    return 0;
}

/*
Check "Solution" part of https://leetcode.com/problems/top-k-frequent-elements/solution/
Approach 2: Quickselect (Hoare's selection algorithm)
*/
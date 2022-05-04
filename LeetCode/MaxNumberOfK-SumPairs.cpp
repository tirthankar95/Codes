#define TYPEI
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freqMap;
        for(int i=0;i<n;i++)
            freqMap[nums[i]]++;
        int res=0;
#ifdef TYPEI
        unordered_map<int,int>:: iterator it=freqMap.begin();
        for(;it!=freqMap.end();it++){
            if(2*it->first!=k && freqMap.find(k-it->first)!=freqMap.end())
            {
                //checking freqMap[k-it->first]!=0 actually inserts the element in the unordered_map
                // and messes other elements.
                res+= min(it->second,freqMap[k-it->first]);
                freqMap[k-it->first]=0;
            }
            else if(2*it->first==k)
                res+=it->second/2;
            freqMap[it->first]=0;
        }
        return res;
#endif 
#ifdef TYPEII
        for(int i=0;i<n;i++){
            if(freqMap[nums[i]]>0 && freqMap[k-nums[i]]>0)
            {
                if(2*nums[i]==k && freqMap[nums[i]]>=2){
                    res++;
                    freqMap[nums[i]]-=2;
                }
                else if(2*nums[i]!=k){
                    res++;
                    freqMap[nums[i]]--;
                    freqMap[k-nums[i]]--; 
                }
            }//
        }//end of for. 
        return res;
#endif
    }
};
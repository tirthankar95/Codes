const int mxSize=1e4+1;
int arr[mxSize];

class RandomizedSet {
    unordered_map<int,int> isPresent;
    int cnt;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        cnt=0;
        srand(time(0));
    }
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(isPresent.find(val)!=isPresent.end())return false;
        isPresent[val]=cnt;
        arr[cnt++]=val;
        return true;   
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(isPresent.find(val)==isPresent.end())return false;
        swap(arr[isPresent[val]],arr[cnt-1]);
        swap(isPresent[val],isPresent[arr[isPresent[val]]]);
        isPresent.erase(val);
        cnt--;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int id=rand()%cnt;
        return arr[id];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
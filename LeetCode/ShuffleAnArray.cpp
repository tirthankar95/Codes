// Here shuffle means that every permutation of array element should equally likely.
// Check the proof in geeks for geeks. 
typedef vector<int> vi;

class Solution {
public:
    vi original;
    vi random;
    int N;
    Solution(vector<int>& nums) {
        srand (time(NULL));  
        original=nums;
        random=nums;
        N=nums.size();
    }
    /** Resets the array to its original configuration and return it. */
    vi reset() {
        for(int i=0;i<N;i++)random[i]=original[i];
        return random;
    }
    /** Returns a random shuffling of the array. */
    vi shuffle() {
        for(int i=1;i<N;i++)
        {
            int j=rand()%(i+1);//rand()%i;
            swap(random[i],random[j]);
        }
        return random;
    }
};
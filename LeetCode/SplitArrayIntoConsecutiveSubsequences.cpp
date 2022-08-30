class Solution {
public:
    bool isPossible(vector<int>& nums) {
        /***
		Observations
        1. Array is in ASC order with duplicate elements
        2. Array needs to be split into one or more subsequences
            such that a) each sequence should be of length >= 3
                      b) each sequence is increasing one i.e. each integer is exactly one more than the previous integer

        
        Q. How to determine if split is even possible Or not ?
        A.  Base case - If len(arr) < 3
        
        Q. How to split the array ? 
        A. Can we use frequencies of the element to figure it out ?
            -> Yes, but frequency array will only tells us how many times an elment has occurred in the sequence
            
        Greedy approach 
        -> Form sequence of length 3 greedily 
        -> How to handle left out numbers ? 
            e.g arr = [1, 2, 3, 4, 5]
                Here first sequence of length 3 = [1, 2, 3]
                Left out numbers are = [4, 5] which collectively forms sequence of length 2
            Here we'll use a hypothetical map (aka Vacancy map) which we'll store the next available element for already formed sequences of length  >= 3
                i.e. Take above example
                    We've formed a sequence of length  = 3 => [1, 2, 3]
                    Now we'll create a vacancy for next element of this sequence in vacancy map = { 4 : 1v, ...}
                    When we reach 4 in the array
                    we check if (vacancy for 4 is available) {
                        fill the vacancy
                        create new vacancy for next element i.e. 5
                    }
                

        ***/
        const int LEAST_SPLIT = 3;
        const int n = nums.size();
        //base case
        if (n < 3) return false;
        // Array is sorted in increasing order
        unordered_map<int, int> freq;
        
        // Contains the elements which are available to be filled up in existing sequence
        unordered_map<int, int> vacancy;
        
        // calculate the frequencies
        for(int v : nums) {
            ++freq[v];
        }
        
        
        for(int v : nums) {
            if (!freq[v]) continue;
            //if number 'v' can be joined to already formed sequence ending with v - 1, then do this else continue to next block
            // Note - This will be filled up by 
            if (vacancy[v]) {
                //decrease the frequency
                --freq[v];
                //fill up the vacany
                --vacancy[v];
                //create vacany for next element in the sequence
                ++vacancy[v+1];
            } else {
                int len = 0;
                for (int e = v; freq[e]!= 0;++e) {
                    ++len;
                    --freq[e];
                    if (len == 3) {
                        //create a vacany to fill up
                        ++vacancy[e + 1];
                        break;
                    }
                }
                if (len < 3) return false;
            }
        }
        
        return true;
    }
};
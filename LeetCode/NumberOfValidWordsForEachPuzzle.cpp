//Actual Solution.
class Solution {
public:
    
    // function to convert given string (word/puzzle) into a mask
    int mask_string(string s)
    {
        int mask = 0 ;
        
        for(int i=0;i<s.size();i++)
        {
            char c = s[i] ;
            mask = mask | (1<<(c-'a')) ; // every time the bit corresponding to the char s[i] will be made 1
        }
        
        return mask ;
    }
    
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
    {
        unordered_map<int,int> mask_freq ; // map to store the frequency of masks
        // let ab and ababbbb are two words. mask of both of them are same (i.e. 3)
        //  so freq of 3 will be 2 .i.e. mask_freq[3] = 2
        //  mask_freq[mask] = number of words with that mask
        
        for(int i=0;i<words.size();i++)
        {
            string curr_word = words[i] ;
            int curr_mask = mask_string(curr_word) ;
            
            mask_freq[curr_mask] ++ ; // increasing the frequency of mask of current ord by 1 as mentioned above
        }
        
        
        vector<int> ans ; // to store the result/answer vector
        
        for(int i=0;i<puzzles.size();i++)
        {
            string curr_puzzle = puzzles[i] ;
            
            int mask = mask_string(curr_puzzle) ; // mask of current puzzle
            int submask = mask ;
            int first = 1<<(curr_puzzle[0]-'a') ; // it corresponds to mask of first character of current puzzle
            int count = 0 ;
            
            // before entering the while loop condition 2(in question) is already satisfied because submask = mask
            while(submask)
            {
                if(submask&first) // checking for the first condition given in question
                {
                    count += mask_freq[submask] ;
                }
                
                submask = submask - 1 ; // this makes the last(from right) set bit 0 and all zero bits to the right of it becomes 1
                
                //if we use this submask in next iteration of loop, then second condition may not be satisfied
                // so we unset the bits that are set in submask but not in mask (simply by performing and operation)
                submask = submask & mask ;
                
                // this ensures that 2nd condtions is always satisfied while checking for first condition (i.e. by using the above if condition)
            }
            
            ans.push_back(count) ;
            
        }
        
        return ans ;
        
        
    }
};
//My solution.
const int mxSize=26;
typedef vector<int> vi;
class Solution {
    unordered_map<int,vi> hMap;
    void getAllSubsets(int no,int index,int iter)
    {
        if(iter>=mxSize){
            hMap[no].push_back(index);
            return;
        }
        while(iter<mxSize && ((no>>iter)&1)==0)iter++;
        no=no&(~(1<<iter));
        getAllSubsets(no,index,iter+1);
        no=no|(1<<iter);
        getAllSubsets(no,index,iter+1);
    }
public:
    vi findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n=puzzles.size(),tmp;
        vi sol(n,0);
        hMap.clear();  
        for(int i=0;i<n;i++)
        {
            tmp=0;
            for(int j=0;j<puzzles[i].length();j++)
                tmp=tmp|(1<<(int)(puzzles[i][j]-'a'));
            getAllSubsets(tmp,i,0);
        }//end of outer for. 
        n=words.size();
        int index,mask;
        for(int i=0;i<n;i++)
        {
            tmp=0,mask=0;
            for(int j=0;j<words[i].length();j++)
                tmp=tmp|(1<<(int)(words[i][j]-'a'));
            for(int j=0;j<hMap[tmp].size();j++)
            {
                index=hMap[tmp][j];
                mask=(1<<(int)(puzzles[index][0]-'a'));
                if(tmp&mask)
                    sol[index]++;
            }
        }//end of outer for. 
        return sol;
    }
};
//My solution slightly faster.
const int mxSize=26;
typedef vector<int> vi;
class Solution {
    unordered_map<int,vi> hMap;
    void getAllSubsets(int no,int index,int first)
    {
        int mask=no;
        while(no){
            if(no&first)
                hMap[no].push_back(index);
            no=no-1;
            no=no&mask;
        }
    }
public:
    vi findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n=puzzles.size(),tmp;
        vi sol(n,0);
        hMap.clear();  
        for(int i=0;i<n;i++)
        {
            tmp=0;
            for(int j=0;j<puzzles[i].length();j++)
                tmp=tmp|(1<<(int)(puzzles[i][j]-'a'));
            getAllSubsets(tmp,i,1<<(int)(puzzles[i][0]-'a'));
        }//end of outer for. 
        n=words.size();
        for(int i=0;i<n;i++)
        {
            tmp=0;
            for(int j=0;j<words[i].length();j++)
                tmp=tmp|(1<<(int)(words[i][j]-'a'));
            for(int j=0;j<hMap[tmp].size();j++)
                    sol[hMap[tmp][j]]++;
        }//end of outer for. 
        return sol;
    }
};
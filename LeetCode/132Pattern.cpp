class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int mini[n];
        mini[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            mini[i]=min(mini[i-1],nums[i]);
        }
        stack<int> s;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>mini[i])
            {
                while(s.empty()==false && s.top()<=mini[i])
                {
                    s.pop();
                }
                if(s.empty()==false && s.top()<nums[i])
                {
                    return 1;
                }
            }
            s.push(nums[i]);
        }
        return 0;
        
    }
};
////////////////////////////////////////////////////////////
typedef vector<int> vi;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int a=0,b,c,i;
        for(i=1;i<n;i++)
            if(nums[i-1]>nums[i])break;
        if(i==n)return false;
        while(a<n)
        {
            while(a+1<n && nums[a]>=nums[a+1])a++;
            b=a+1;
            while(b+1<n && nums[b]<=nums[b+1])b++;
            c=b+1;
            while(c<n)
            {
                if(c<n && nums[a]<nums[c] && nums[b]>nums[c])
                    return true;
                c++;
            }
            a=b+1;
        }//end of while. 
        return false;
    }
};
/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/discuss/2128501/Two-Pointers-or-Visual-Explanation-JAVA

public int[] twoSum(int[] nums, int target) {
	int l = 0, r = nums.length - 1;

	while (l < r) {
		int sum = nums[l] + nums[r];
		if (sum == target) return new int[] {l+1, r+1};
		else if (sum < target) l++;
		else r--;
	}

	return new int[2];
}
*/
class Solution {
    int binSearch(vector<int>& numbers,int element){
        int lb=0;int ub=numbers.size()-1;
        int mid;
        while(lb<=ub){
            mid=(lb+ub)/2;
            if(numbers[mid]==element)return mid;
            if(numbers[mid]<element)lb=mid+1;
            else ub=mid-1;
        }
        return -1;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size(),j;
        for(int i=0;i<n;i++){
            if((j=binSearch(numbers,target-numbers[i]))!=-1 && i!=j)
            {
                vector<int> sol({min(i+1,j+1),max(i+1,j+1)});
                return sol;
            }
        }
        vector<int> sol;
        return sol;
    }
};
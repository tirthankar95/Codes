typedef vector<int> vi;
class Solution {
public:
    vector<vi> intervalIntersection(vector<vi>& firstList, vector<vi>& secondList) {
        int n1=firstList.size();
        int n2=secondList.size();
        vector<vi> sol(n1+n2,vi(2));
        int lb1=0,lb2=0,cnt=0;
        while(lb1<n1 && lb2<n2){
            if(firstList[lb1][0]<secondList[lb2][0])
                sol[cnt++]=firstList[lb1++];
            else 
                sol[cnt++]=secondList[lb2++];
        }
        while(lb1<n1)
            sol[cnt++]=firstList[lb1++];
        while(lb2<n2)
            sol[cnt++]=secondList[lb2++];
        vector<vi> ans;
        int lb=0,i=1;
        while(i<cnt)
        {
            if(sol[lb][1]>=sol[i][0])
            {
                if(sol[lb][1]<=sol[i][1])
                {
                    ans.push_back(vi({sol[i][0],sol[lb][1]}));
                    lb=i;
                }
                else
                    ans.push_back(vi({sol[i][0],sol[i][1]}));
            }//end of if.
            else lb=i;
            i++;
        }
        return ans;
    }
};
/*
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while(i < size(A) && j < size(B)) {
            // intersection condition
            if((A[i][1] >= B[j][0] && A[i][0] <= B[j][1]) || (B[j][1] >= A[i][0] && B[j][0] <= A[i][1])) 
                ans.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
            A[i][1] < B[j][1] ? i++ : j++;    // increment pointer of list whose interval ended first
        }
        return ans;
    }
};
*/
typedef vector<int> vi;
class Solution {
public:
    int maxDistToClosest(vi& seats) {
        int n=seats.size();
        int lb=-1,dist=0,da,db;
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                if(lb==-1)db=i;
                dist=max(dist,i-(lb+1));
                lb=i;
            }
        }//end of for. 
        da=ceil((float)dist/(float)2);
        db=max(db,n-1-lb);
        return max(da,db);
    }
};
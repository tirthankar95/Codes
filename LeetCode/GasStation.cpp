typedef vector<int> vi;
class Solution {
public:
    int canCompleteCircuit(vi& gas, vi& cost) {
        int n=gas.size();
        for(int i=0;i<n;i++)
            gas[i]-=cost[i];
        if(n==1)
            return (gas[0]>=0)?0:-1;
        int lb=0,ub=0,pos=0,neg=0;
        if(gas[0]>=0)pos+=gas[0];
        else neg+=gas[0];
        do{
            if(pos>=abs(neg)){
                ub=(ub+1)%n;
                if(gas[ub]>=0)pos+=gas[ub];
                else neg+=gas[ub];
            }
            else{
                lb=(lb<1)?n+(lb-1)%n:(lb-1)%n;
                if(gas[lb]>=0)pos+=gas[lb];
                else neg+=gas[lb];
            }
        }while(lb!=ub);
        if(pos>=abs(neg))
            return lb;
        else 
            return -1;
    }
};
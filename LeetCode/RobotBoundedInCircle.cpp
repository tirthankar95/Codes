#define REPEAT (4)
enum{
    F=0,
    L=1,
    B=2,
    R=3,
    MX=4
};

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int curr[2]={0,0};
        int o=F;
        int n=instructions.size();
        for(int i=0;i<REPEAT;i++){
            for(int j=0;j<n;j++){
                if(instructions[j]=='G'){
                    switch(o){
                        case F:
                            curr[0]+=1;
                            break;
                        case L:
                            curr[1]-=1;
                            break;
                        case R:
                            curr[1]+=1;
                            break;
                        case B:
                            curr[0]-=1;
                            break;
                        default:
                            break;
                    }
                }//end of if.
                else if(instructions[j]=='L')
                    o=(o+1)%MX;
                else{
                    o=(o-1)%MX;
                    if(o<0)o+=MX;
                }
            }//end of for-j.
            if(curr[0]==0 && curr[1]==0)return true;
        }//end of for-i.
        return false;
    }
};
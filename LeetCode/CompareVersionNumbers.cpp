typedef vector<int> vi;
class Solution {
    vi split(string str){
        vi res;
        int n=str.length();
        int temp=0;
        bool isleading=true;
        for(int i=0;i<n;i++){
            if(isleading && str[i]=='0')continue;
            else if(str[i]!='.'){ 
                isleading=false;
                temp=temp*10+(int)(str[i]-'0');
            }
            else{
                res.push_back(temp);
                isleading=true;
                temp=0;
            }
        }//end of for. 
        res.push_back(temp);
        return res;
    }
public:
    int compareVersion(string version1, string version2) {
        vi vA1=split(version1);
        vi vA2=split(version2);
        int nA1=vA1.size(),nA2=vA2.size();
        int p1=0,p2=0;
        while(p1<nA1 && p2<nA2){
            if(vA1[p1]<vA2[p2])return -1;
            else if(vA1[p1]>vA2[p2])return 1;
            p1++,p2++;
        }
        if(p1<nA1){
            while(p1<nA1){
                if(vA1[p1++]!=0)
                    return 1;
            }        
            return 0;
        }
        if(p2<nA2){
             while(p2<nA2){
                if(vA2[p2++]!=0)
                    return -1;
            }        
            return 0;       
        }
        return 0;
    }
};
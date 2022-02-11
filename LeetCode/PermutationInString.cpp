class BitMap{
    int bit[(int)('z'-'a')+1];
    int mxSize;
public:
    BitMap(){
        mxSize=(int)('z'-'a')+1;
        memset(bit,0,sizeof(bit));
    }
    void set(char ch){bit[(int)(ch-'a')]++;}
    void reset(char ch){bit[(int)(ch-'a')]--;}
    bool operator==(BitMap obj){
        for(int i=0;i<mxSize;i++)
            if(this->bit[i]!=obj.bit[i])
                return false;
        return true;
    }  
};
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        if(n1>n2)return false;
        BitMap ob1,ob2;
        for(int i=0;i<n1;i++)
            ob1.set(s1[i]),ob2.set(s2[i]);
        for(int i=n1;i<n2;i++)
        {
            if(ob1==ob2)
                return true;
            ob2.reset(s2[i-n1]);
            ob2.set(s2[i]);
        }
        return (ob1==ob2);
    }
};
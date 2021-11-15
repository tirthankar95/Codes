vector<string> res;
class CombinationIterator {
    int resLen,iter;
    string par;
    void fn(string tmp,int start,int len){
        if(start+len>par.length())return;
        if(len==0){
            res.push_back(tmp);
            return;
        }
        fn(tmp+par[start],start+1,len-1);
        fn(tmp,start+1,len);
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        this->par=characters;
        res.clear();
        fn("",0,combinationLength);
        this->resLen=res.size();
        this->iter=0;
    }
    string next() {
        return res[(this->iter)++];
    }
    bool hasNext() {
        return (this->iter<this->resLen);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
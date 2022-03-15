class Solution {
public:
    string simplifyPath(string path) {
        int n=path.length();
        stack<string> st;
        string word="";
        for(int i=0;i<n;i++){
            if((path[i]>='A' && path[i]<='Z')||(path[i]>='a' && path[i]<='z')||
               path[i]=='_'|| (path[i]>='0' && path[i]<='9'))
                word+=path[i];
            if(path[i]=='/' && word!=""){
                st.push(word);
                word="";
            }
            if((i-1>=0 && path[i-1]=='/') && path[i]=='.'){
                int j=i;
                while(j<n && path[j]=='.')j++;
                if(j-i==1 && (j>=n || path[j]=='/'));
                else if(j-i==2 && !st.empty() && (j>=n || path[j]=='/'))
                    st.pop();
                else if((j-i>2) || path[j]!='/')
                    word+=path.substr(i,j-i);
                i=j-1;
            }
            else if(path[i]=='.')
                word+=path[i];
        }//end of for.
        if(word!="" && word!="..")
            st.push(word);
        string res="";
        while(!st.empty())
        {
            res="/"+st.top()+res;
            st.pop();
        }
        if(res=="")res="/";
        return res;
    }
};
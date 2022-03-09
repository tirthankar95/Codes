/*
    DFS doesn't work because you are traversing 2^i nodes at depth i.
    The solution becomes exponential. 
    BFS will work because we add the node in the queue once and update it several times.
    So the solution is not exponential because at depth i we don't have 2^i nodes in the queue.
    Repeated nodes are not inserted in the Queue.
*/
const int mxSize=1e2;
double cup[mxSize][2*mxSize];
//#define DBG

class Solution {
#ifdef DBG
    void print(){
        int row=0,col=100;
        for(int i=0;i<mxSize;i++){
            for(int j=mxSize-i;j<=mxSize+i;j++)
                cout<<cup[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
#endif
    void fill(double poured,int row,int col){
        if(row>=mxSize)return;
        if(poured>0){
            if((1-cup[row][col])<=poured){
                poured-=(1-cup[row][col]);
                cup[row][col]=1;
                fill(poured/2,row+1,col-1);
                fill(poured/2,row+1,col+1);
            }//end of if. 
            else 
                cup[row][col]+=poured;
        }
        return;
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        memset(cup,0,sizeof(cup));
        fill(poured,0,mxSize);
#ifdef DBG
        print();
#endif
        int s_id=(mxSize-query_row)+2*query_glass;
        return cup[query_row][s_id];
    }
};

/*
    MY BFS solution that works.
*/
const int mxSize=1e2;
double cup[mxSize][2*mxSize];
typedef pair<int,int> ii;
//#define DBG

class Solution {
#ifdef DBG
    void print(){
        int row=0,col=100;
        for(int i=0;i<mxSize;i++){
            for(int j=mxSize-i;j<=mxSize+i;j++)
                cout<<cup[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
#endif
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        memset(cup,0,sizeof(cup));
        int temp=0;
        queue<ii> Q;Q.push(ii(0,mxSize));
        unordered_map<int,bool> vis;
        temp=mxSize,vis[temp]=true;
        cup[0][mxSize]=poured;
        while(!Q.empty()){
            ii src=Q.front();
            if(src.first==99)break;
            Q.pop();
            // Child 1.
            ii c1=ii(src.first+1,src.second-1);
            if(cup[src.first][src.second]>1)
            {
                cup[c1.first][c1.second]+=(cup[src.first][src.second]-1)/2;
                temp=c1.first*(2*mxSize)+c1.second;
                if(!vis[temp]){
                    Q.push(c1);
                    vis[temp]=true;
                }
            }
            //Child 2.
            ii c2=ii(src.first+1,src.second+1);
            if(cup[src.first][src.second]>1)
            {
                cup[c2.first][c2.second]+=(cup[src.first][src.second]-1)/2;
                temp=c2.first*(2*mxSize)+c2.second;
                if(!vis[temp]){
                    Q.push(c2);
                    vis[temp]=true;
                }
            }            
        }//end of BFS.
#ifdef DBG
        print();
#endif
        int s_id=(mxSize-query_row)+2*query_glass;
        return ((cup[query_row][s_id]>1)?1:cup[query_row][s_id]);
    }
};


/*
    Editorial Solution https://leetcode.com/problems/champagne-tower/solution/
*/
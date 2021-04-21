struct node{
	int key;
	int value;
	int cnt;		
};
const int mx=1e4+1;
node pool[mx];
int poolPtr=0;
node* create(int key,int value){
    node* tmp=&pool[poolPtr];
    poolPtr=(poolPtr+1)%mx;
    tmp->value=value;
    tmp->key=key;
    tmp->cnt=1;
    return tmp;
}
//////////////////////////////////////////////////////////////
class PQ{
	int sz;
	node** arr;
	int left(int i){return 2*i+1;}
	int right(int i){return 2*i+2;}
	int parent(int i){return (i-1)/2;}
	int curr;
	void heapify(int indx){
		int sindx=indx;
		if(left(indx)<this->curr && arr[sindx]->cnt>=arr[left(indx)]->cnt)
			sindx=left(indx);
		if(right(indx)<this->curr && arr[sindx]->cnt>=arr[right(indx)]->cnt)
			sindx=right(indx);
		if(sindx!=indx)
		{
			swap(arr[indx],arr[sindx]);
			heapify(sindx);
		}
	}
public:
	PQ(int capacity)
	{
		this->curr=0;
		this->sz=capacity;
		arr=new node*[this->sz];
	}
	node* top(){return arr[0];}
	bool empty(){return this->curr<=0;}
	void push(node* element)
	{
		arr[this->curr++]=element;
		int indx=this->curr-1;
		while(parent(indx)!=indx && arr[parent(indx)]->cnt>arr[indx]->cnt)
		{
			swap(arr[parent(indx)],arr[indx]);
			indx=parent(indx);
		}
	}
	void pop(){
		if(this->curr==0)return;
		this->curr-=1;
		swap(arr[0],arr[this->curr]);
		heapify(0);
	}
	void scan(node* element){
		int i;
		for(i=0;i<this->curr;i+=1)
			if(element->key==arr[i]->key)
				break;
		heapify(i);
	}
	void print(){
		for(int i=0;i<this->curr;i+=1)
		{
			printf(" [ K[%d] V[%d] F[%d] ], ", arr[i]->key,arr[i]->value,arr[i]->cnt);
		}
		printf("\n\n");
	}
};
//////////////////////////////////////////////////////////////
class LFUCache {
    unordered_map<int,node*> hashMap;// key and address.
    PQ* pQ;
    int curr;
    int capacity;
public:
    LFUCache(int capacity) {
        this->capacity=capacity;
    	pQ=new PQ(this->capacity);
        curr=0;
    }
    int get(int key) {
        if(hashMap.find(key)==hashMap.end())return -1;
        int ans=(hashMap[key])->value;
        (hashMap[key])->cnt+=1;
        pQ->scan(hashMap[key]);
        return ans;
    }
    void put(int key, int value) {
        if(curr==capacity)
        {
            node* tmp=pQ->top();
            pQ->pop();
            hashMap.erase(tmp->key);
            curr--;
        }
        curr++;
        node* tmpNew=create(key,value);
        pQ->push(tmpNew);
        hashMap[key]=tmpNew;
    }
};
//////////////////////////////////////////////////////////////
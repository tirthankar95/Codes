#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class BIT{
	vi tree;
	int N;
	int read(int indx)
	{
		int sum=0;
		while(indx>0)
		{
			sum+=tree[indx];
			indx-=(-indx&indx);
		}
		return sum;
	}
public:
	BIT(vi& arr){
		N=arr.size();
		tree.resize(N+1);
		for(int i=0;i<N;i++)
			update(i+1,arr[i]);
	}
	int find(int lb,int ub)// inclusive.
	{
		lb+=1;
		ub+=1;
		return read(ub)-read(lb-1);
	}
	void update(int indx,int element)
	{
		indx+=1;
		while(indx<N)
		{
			tree[indx]+=element;
			indx+=(-indx&indx);
		}
	}
};
int main(){
	int N=10,Q=10;
	vi arr(N,0),cumul(N,0);
	for(int i=0;i<N;i++)
		arr[i]=rand()%100;
	cumul[0]=arr[0];
	for(int i=1;i<N;i++)
		cumul[i]=cumul[i-1]+arr[i];
	for(int i=0;i<N;i++)
		printf("%d | ",arr[i]);
	printf("\n");
	BIT obj(arr);
	int iter=1,a,b,c,tmp,tmp1;
	while(Q--)
	{
		a=rand()%N;b=rand()%N;
		c=max(a,b);
		a=min(a,b);
		b=c;
		tmp1=(a-2>=0)?(cumul[b-1]-cumul[a-2]):cumul[b-1];
		tmp=obj.find(a,b);
		assert(tmp1==tmp);
		printf("%d. (%d,%d) -> %d\n",iter,a,b,tmp);
		iter+=1;
	}
	return 0;
}
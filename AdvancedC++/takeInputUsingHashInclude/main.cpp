#include<iostream> 
using namespace std;
const int mxSize=2;
typedef char uint8; 
#define MAX_CELL (12)
struct node{
	int count;
	int arr[mxSize];	
};


void getDump(){
	node mem;
	//initialization.
	{
		mem.count=2;
		mem.arr[0]=1;mem.arr[1]=0; 
	}
	FILE* file=fopen("input.dat","w");
	for(int _i=0;_i<MAX_CELL;_i++)
	{
		uint8* temp=(uint8*)&mem;
		fprintf(file,"{");
		for(int i=0;i<sizeof(node)/4;i++){
			fprintf(file,"%d, %d, %d, %d, ",i,*temp,*(temp+1),*(temp+2),*(temp+3));
			temp+=4;
		}
		fprintf(file,"},");
	}
	fclose(file);
}
int main(){
	getDump();
	uint8 gArr[MAX_CELL][sizeof(node)]={
	#include "input.dat"
	};
	for(int _i=0;_i<MAX_CELL;_i++)
	{
		for(int i=0;i<sizeof(node);i++)
			cout<<(int)gArr[_i][i]<<" ";
		cout<<endl;
	}
	return 0;
}
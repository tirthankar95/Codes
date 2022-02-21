#include<iostream>
using namespace std;

template<class X>
void merge(X* arr,int lb,int mid,int ub){
	X* temp=new X[ub-lb+1];int iter=0;
	int fs=lb,fe=mid;
	int ss=mid+1,se=ub;
	while(fs<=fe && ss<=se){
		if(arr[fs]<=arr[ss])
			temp[iter++]=arr[fs++];
		else 
			temp[iter++]=arr[ss++];
	}
	while(fs<=fe)
		temp[iter++]=arr[fs++];
	while(ss<=se)
		temp[iter++]=arr[ss++];
	for(int i=lb;i<=ub;i++)
		arr[i]=temp[i-lb];
}
template<class X> 
void mergeSort(X* arr,int lb,int ub){
	if(lb<ub){
		int mid=(lb+ub)/2;
		mergeSort(arr,lb,mid);
		mergeSort(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
	}
}
template<class X>
void printArr(X* arr,int n){
	for(int i=0;i<n;i++)
		cout<<arr[i]<<", ";
	cout<<endl;
}
//Driver Function.
int main(){
	double dArr[]={19.2,-0.42,422.99,-100,27.31};
	int n=sizeof(dArr)/sizeof(dArr[0]);
	cout<<"Unsorted Double Array\n";
	printArr(dArr,n);
	cout<<"Sorted Array\n";
	mergeSort(dArr,0,n-1);
	printArr(dArr,n);
	return 0;
}
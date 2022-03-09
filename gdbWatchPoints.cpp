#include<iostream>
using namespace std;

void incr(int* arr){
	for(int i=0;i<100;i++)
		arr[i]=i+1;
	for(int i=0;i<100;i++)
		cout<<arr[i]<<",";
	cout<<endl;
}
int main(){
	int arr[100];
	for(int i=0;i<100;i++)
		arr[i]=0;
	incr(arr);
	return 0;
}
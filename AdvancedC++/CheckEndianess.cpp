#include<iostream>
using namespace std;

int main(){
	int n=1;
	if((*(char*)&n)==1)cout<<"Little Endian\n";
	else cout<<"Big Endian\n";
	return 0;
}
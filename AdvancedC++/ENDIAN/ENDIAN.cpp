#include<iostream>
using namespace std;

int main(){
	int n=1;
	if((*(char*)&n)==1)cout<<"Little Endian\n";
	else cout<<"Big Endian\n";
	// The values are stored in increasing address.
	char num[2];
	num[0]='a';num[1]='b';
	printf("addr1[%p] val[%c]\n",(char*)num,(*(char*)num));
	printf("addr2[%p] val[%c]\n",(char*)(num+1),(*(char*)(num+1)));
	// Writing into file.
	FILE* file=fopen("ENDIAN.txt","w");
	fwrite(num,1,2*sizeof(char),file);
	fclose(file);
	// Since character is single byte there is no concept of endianess. 
	char cString[20]="Tirthankar Mittra";
	file=fopen("ENDIAN1.txt","w");
	fwrite(cString,1,20*sizeof(char),file);
	fclose(file);
	// Long (You find the difference here)
	unsigned long long element=8421234751234;
	file=fopen("ENDIAN2.txt","w");
	fwrite((char*)&element,1,sizeof(unsigned long long),file);
	fclose(file);	
	return 0;
}
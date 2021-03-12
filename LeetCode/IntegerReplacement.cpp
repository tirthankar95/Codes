#include<bits/stdc++.h>
using namespace std;

class Solution {
    int fn(long long n)
    {
        if(n==1)return 0;
        if(n%2==0)return 1+fn(n/2);
        else return 1+min(fn(n-1),fn(n+1));        
    }
public:
    int integerReplacement(int n) {
        return fn((long long)(n));
    }
};

int main()
{
	FILE* file=fopen("op.txt","w");
	Solution obj;
	for(int i=1;i<=100;i++)
		fprintf(file,"%d ~ %d\n",i,obj.integerReplacement(i));
	fclose(file);
	return 0;
}
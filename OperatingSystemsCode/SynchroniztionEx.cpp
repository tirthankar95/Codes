#include<bits/stdc++.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
#define N 10

int test_and_set(int* L)
{
	int prev=*L;
	*L=1;
	return prev;
}

void fn()
{
	FILE* file=fopen("op.txt","a");
	fprintf(file,"Parent[%d] -> Child[%d]\n",getppid(),getpid());
	//fflush(stdout);
}
int main(){
	int pid;
	/*
	printf("Starting|[Parent[%d]-Child[%d]]\n",getppid(),getpid());
    fflush(stdout);// it is important to flush the output buffer otherwise this print will come ten times.
    */
	for(int i=0;i<N;i++)
	{
		pid=fork();
		if(pid==-1)
		{
			printf("Error\n");
			fflush(stdout);
			exit(1);
		}
		else if(pid==0)
		{
			fn();
			exit(0);
		}
	}
	int childCnt=0;
	while(childCnt<N)
	{
		//printf("rChild[%d]\n",wait(NULL));
		wait(NULL);
		childCnt++;
	}
	return 0;
}

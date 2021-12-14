#ifndef _SRC_
#define _SRC_ 

#include <bits/stdc++.h>
using namespace std;
struct nodeOfT{
	int uid;
	char name[100];
};
extern nodeOfT* getNode();
extern void setNode(void* addr);

#endif
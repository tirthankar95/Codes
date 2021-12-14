#include "Source.h"
static nodeOfT* gNode;

nodeOfT* getNode(){
	return gNode;
}
void setNode(void* addr){
	gNode=(nodeOfT*)addr;
	memset(gNode,0,sizeof(nodeOfT));
}
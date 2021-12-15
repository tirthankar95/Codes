
#include "Def_Phy_SOC.h"

static tPhycFuncList gpPhycFuncList[MAX_JOB_CNT];
tPhycFuncList* GetPhycFunc(int uCcId){
	return &gpPhycFuncList[uCcId];
}
static char* FuncName[MAX_FUNC_LIST+1]={
	FUNCNAME(MAIN),
	FUNCNAME(DUMMY),

	FUNCNAME(MAX_ENUM_FUNC_ID)
};
char* getFuncName(int uVal){
	return FuncName[uVal];
}
void display(){
	for(int i=0;i<MAX_JOB_CNT;i++){
		printf("cellID[%d]\n",i);
		for(int j=0;j<MAX_FUNC_LIST;j++){
			printf("\tFuncName[%s] LineNo[%d]\n",GetPhycFunc(i)->FuncDetail[j].funcName,GetPhycFunc(i)->FuncDetail[j].lineNo);
		}
	}
}
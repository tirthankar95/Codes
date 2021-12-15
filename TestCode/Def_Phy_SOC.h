#include<stdio.h>
#define MAX_JOB_CNT 12
/**************************************************/
#define FUNCNAME(x) [x] = #x
enum{
	MAIN, 
	DUMMY,

	MAX_ENUM_FUNC_ID
};
#define MAX_FUNC_LIST MAX_ENUM_FUNC_ID
extern char* getFuncName(int uVal);
/**************************************************/
typedef struct{
	int lineNo;
	char*  funcName;
}tFuncDetail;
typedef struct{
	int uAirTime;
	tFuncDetail FuncDetail[MAX_FUNC_LIST];
}tPhycFuncList;
extern tPhycFuncList* GetPhycFunc(int uCcId);
#define FUNC_LOGGING_SHM(a,b,c)\
{\
	tPhycFuncList* pLocal=GetPhycFunc(a);\
	pLocal->uAirTime=100;\
	pLocal->FuncDetail[b].lineNo=c;\
	pLocal->FuncDetail[b].funcName=getFuncName(b);\
}
extern void display();
/**************************************************/
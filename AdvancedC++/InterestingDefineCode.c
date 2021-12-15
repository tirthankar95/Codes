#include<stdio.h>
#define FUNCNAME(x) [x] = #x
enum{
	TIRTHANKAR,
	MITTRA,

	MAX_ENUM_FUNC_ID
};
static char* FuncName[MAX_ENUM_FUNC_ID+1]=
{
	FUNCNAME(TIRTHANKAR),
	FUNCNAME(MITTRA),

	FUNCNAME(MAX_ENUM_FUNC_ID)
};
char* GetFuncName(int uVal)
{
	return FuncName[uVal];
}

int main(){
	printf("%s %s\n",GetFuncName(0),GetFuncName(1));
	return 0;
}

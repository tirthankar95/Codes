#include<iostream>
using namespace std;
#define FUNCNAME(x) [x] = #x
enum{
	TIRTHANKAR,
	MITTRA,

	MAX_ENUM_FUNC_ID
};
static string FuncName[MAX_ENUM_FUNC_ID+1]=
{
	[TIRTHANKAR]="TIRTHANKAR",
	[MITTRA]="MITTRA",

	[MAX_ENUM_FUNC_ID]="MAX_ENUM_FUNC_ID"
};
string GetFuncName(int uVal)
{
	return FuncName[uVal];
}

int main(){
	cout<<GetFuncName(0)<<" "<<GetFuncName(1)<<endl;
	return 0;
}

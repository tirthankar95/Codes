#include <iostream>
#include <strstream>
using namespace std;

int main()
{
	const char *p = "this is a test\1\2\3\4\5\6\7";
	istrstream ins(p);
	char ch;int temp;
	// read and display binary info
	while (!ins.eof()) {
		ins.get(ch);
		temp=(int) ch;
		cout << hex << temp << "-";
		cout << temp <<"    ";
	}
	return 0;
}
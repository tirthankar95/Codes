/* This program shows how to read the contents of any array that contains text. */
#include <iostream>
#include <strstream>
using namespace std;

int main()
{
	char s[] = "10.23 this is a test <<>><<?!\n";
	istrstream ins(s);
	char ch;
	/* This will read and display the contents of any text array. */
	ins.unsetf(ios::skipws); // don't skip spaces
	while (ins) { // false when end of array is reached
		ins >> ch;
		cout << ch;
	}
	return 0;
}
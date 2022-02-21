// Demonstrate default template arguments.
#include <iostream>
#include <cstdlib>
using namespace std;
// Here, AType defaults to int and size defaults to 10.
template <class AType=int, int size=10> class atype {
	AType a[size]; // size of array is passed in size
public:
	atype() {
		register int i;
		for(i=0; i<size; i++) a[i] = i;
	}
	AType &operator[](int i);
};
// Provide range checking for atype.
template <class AType, int size>
AType &atype<AType, size>::operator[](int i)
{
	if(i<0 || i> size-1) {
		cout << "\nIndex value of ";
		cout << i << " is out-of-bounds.\n";
		exit(1);
	}
	return a[i];
}
int main()
{
	atype<int, 100> intarray; // integer array, size 100
	atype<double> doublearray; // double array, default size
	atype<> defarray; // default to int array of size 10
	int i;
	cout << "int array: ";
	for(i=0; i<100; i++) intarray[i] = i;
	for(i=0; i<100; i++) cout << intarray[i] << " ";
	cout << '\n';
	cout << "double array: ";
	for(i=0; i<10; i++) doublearray[i] = (double) i/3;
	for(i=0; i<10; i++) cout << doublearray[i] << " ";
	cout << '\n';
	cout << "defarray array: ";
	for(i=0; i<10; i++) defarray[i] = i;
	for(i=0; i<10; i++) cout << defarray[i] << " ";
	cout << '\n';
	return 0;
}
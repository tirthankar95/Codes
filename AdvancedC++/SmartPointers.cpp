// https://www.geeksforgeeks.org/smart-pointers-cpp/
/* So in C++ 11, it introduces smart pointers that automatically manage memory and they will deallocate the object 
when they are not in use when the pointer is going out of scope automatically it’ll deallocate the memory. */

#include <iostream>
using namespace std;
 
// A generic smart pointer class
template <class T>
class SmartPtr {
    T* ptr; // Actual pointer
public:
    // Constructor
    explicit SmartPtr(T* p = NULL) { ptr = p; }
 
    // Destructor
    ~SmartPtr() { delete (ptr); }
 
    // Overloading dereferncing operator
    T& operator*() { return *ptr; }
 
    // Overloading arrow operator so that
    // members of T can be accessed
    // like a pointer (useful if T represents
    // a class or struct or union type)
    T* operator->() { return ptr; }
};
 
int main()
{
    SmartPtr<int> ptr(new int());
    *ptr = 20;
    cout << *ptr;
    return 0;
}
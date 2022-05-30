#include <iostream>
using namespace std;

class BaseClass {
public:
   virtual void disp(){
      cout<<"Function of Parent Class\n";
   }
};
class DerivedClass: public BaseClass{
public:
// Throws Error void disp(int x) override{
void disp() override{
      cout<<"Function of Child Class\n";
   }
};
int main() {
   /* Reference of base class pointing to
    * the object of child class.
    */
   DerivedClass d1;
   BaseClass* obj = &d1; 
   obj->disp();
   return 0;
}
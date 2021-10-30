#include<iostream>
using namespace std;

//LATE BINDING OR, Dynamic Binding.
class Base{
	public:
		virtual void show(){ // remove the virtual keyword and see what will happen.
			cout<<"Base Class\n";
		}
};
class D1: public Base{
	public:
		void show(){
			cout<<"D1 Class\n";
		}	
};
class D2: public Base{
	public:
		void show(){
			cout<<"D2 Class\n";
		}	
};
//Diver Function.
int main(){
	D1 d1;
	D2 d2;
	Base* ptr;
	ptr=&d1;
	ptr->show();
	ptr=&d2;
	ptr->show();
	return 0;
}

//When we will never want to instantiate objects of a base class, we call it an abstract class. virtual void show()=0;(Pure virtual function)
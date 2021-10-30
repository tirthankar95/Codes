/*
Google Search: const at the end of function c++
https://stackoverflow.com/questions/5347744/why-put-a-const-at-the-end#:~:text=%22const%22%20at%20the%20end%20of%20any%20c%2B%2B%20declaration,have%20a%20const%20reference%20to%20the%20relevant%20object.
https://stackoverflow.com/questions/3141087/what-is-meant-with-const-at-end-of-function-declaration
*/

#include<iostream>
using namespace std;

class Counter{
	private:
		int count;
	public:
		Counter(): count(0) {}
		Counter(int c): count(c) {}
		int get_count(){return count;}
		Counter operator ++ (){
			++count;
			 return Counter(count);
		}
};
//Driver Funciton.
int main(){
	Counter c1,c2; 
	cout<<"c1="<<c1.get_count();
	cout<<"\nc2="<<c2.get_count();
	++c1;
	c2=++c1;
	cout<<"\nc1="<<c1.get_count();
	cout<<"\nc2="<<c2.get_count();	
	cout<<endl;
	return 0;
}
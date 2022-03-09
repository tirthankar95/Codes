#include<iostream>
#include<list>
using namespace std; 

int main(){
	list<int> l1,l2; 
	for(int i=0;i<10;i++)
		l1.push_back(rand()%100),l2.push_front(rand()%100);
	cout<<"Original lists\n";
	for(list<int>::iterator i=l1.begin();i!=l1.end();i++)
		cout<<*i<<" "; 
	cout<<endl;
	for(list<int>::iterator i=l2.begin();i!=l2.end();i++)
		cout<<*i<<" "; 
	cout<<endl;
	l1.merge(l2);
	l1.sort(); 
	cout<<endl<<"Final List\n";
	for(list<int>::iterator i=l1.begin();i!=l1.end();i++)
		cout<<*i<<" ";
	cout<<endl;
	return 0;
}
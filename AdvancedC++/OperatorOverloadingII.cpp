#include<iostream>
using namespace std;

class coordinate{
	int x,y;
public:
	coordinate(){}
	coordinate(int x,int y){
		this->x=x; this->y=y;
	}
	/*
	coordinate operator+(int no); //only this is possible.
	*/
	friend coordinate operator+(coordinate o1,int no);
	friend coordinate operator+(int no,coordinate o1);
	void show(){
		printf("[x[%d] y[%d]]\n",x,y);
	}
};

coordinate operator+(coordinate o1,int no){
	coordinate temp;
	temp.x=o1.x+no;
	temp.y=o1.y+no;
	return temp;
}
coordinate operator+(int no,coordinate o1){
	coordinate temp;
	temp.x=o1.x+no;
	temp.y=o1.y+no;
	return temp;
}
// Driver Function.
int main(){
	coordinate c1(10,10);
	coordinate c2=c1+10;
	coordinate c3=10+c1;
	// c2 print.
	c2.show();
	// c3 print.
	c3.show();
	return 0;
}
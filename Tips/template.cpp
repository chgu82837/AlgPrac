#include <stdio.h>
#include <iostream>
using namespace std;

//template: 模板，編譯時才決定其變數型態
template<class T>
void swap(T*a,T*b){
	T temp=*a;
	*a=*b;
	*b=temp;
}


//typedef: 把既有型態取別名
typedef unsigned long long ULINT;
typedef struct{
	int x,y;
} point;


int main(){

	//對 template 進行測試
	int a=10,b=15;
	printf("a=%d,b=%d\n",a,b);
	swap(a,b);
	printf("a=%d,b=%d\n",a,b);

	string c="David",
		d="Amy";

	cout << "c=" << c << ",d=" << d << endl;
	swap(c,d);
	cout << "c=" << c << ",d=" << d << endl;


	ULINT e=123;
	printf("e=%llu\n",e);

	return 0;
}

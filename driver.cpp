#include <iostream>
using namespace std;
#include <fstream>
#include "matrices.h"
int main()
{
	
	matrix m1(2,3);
	cout<<endl;
	m1.print(m1);
	/*m1.transpose();*/
	matrix m2(2,3);
	cout<<endl;
	m2.print(m2);
	matrix m3=m1+m2;
	cout<<endl;
	m3.print(m3);
	cout<<endl;
	/*m1=m3+m2;*/
	cout<<endl;
	m1.print(m1);
	m1=m1+m2;
	cout<<endl;
	m1.print(m1);
	m1*=3;
	cout<<endl;
	m1.print(m1);
	m1+=10;
	cout<<endl;
	m1.print(m1);
	cout<<endl;
	cout<<endl;
	matrix m6(4,4);
	m6.print(m6);
	cout<<endl;
	m6-=m6;
	m6.print(m6);
	fstream fin("mat1.txt");
	matrix m4(fin);
	fstream fin1("mat2.txt");
	matrix m5(fin1);
	m4.print(m4);
	cout<<endl;
	m5.print(m5);
	if (m4==m5)
	{
		cout<<"They are equal";
	}
	system("pause");
	return 0;
}
#include <iostream>
using namespace std;


class matrix{
	int **p;
	int rows;
	int colms;
public:
	matrix()
	{
		rows=0;
		colms=0;
		p=nullptr;
	}
	matrix(fstream &fin);
	matrix(int row,int colm);
	matrix operator=(const matrix &obj);
	matrix  operator+(const matrix &obj);
	matrix operator-(const matrix &obj);
	int ** transpose();
	matrix operator*(const matrix &obj);
	matrix operator*=(int n);
	matrix operator+=(int k);
	void print(matrix m);
	matrix operator-=(const matrix &obj);
	bool operator==(const matrix &obj);

};
#include <iostream>
#include "matrices.h"
#include <fstream>

matrix :: matrix(fstream &fin)
{
	int n,k,i,l,j,c;
	char frd[50];
	char t[3];
	fin.getline(frd,50);
	rows=n=atoi(frd);
	fin.getline(frd,50);
	colms=c=atoi(frd);
	p= new int*[n];
	int num[10];
	int q=0;
	while(fin.good())
	{
		fin.getline(frd,50);
		l=strlen(frd);
		k=0;
		p[q] = new int[l];
		for(i=0;i<l;i++)
		{
			if(frd[i]>='0'&&frd[i]<='9')
			{
				t[0]=frd[i];
				t[1]='\0';
				p[q][k]=atoi(t);
				k++;
			}
		}
		p[q][k]=-1;
		if(q<n)
			q++;
	}
	/*for(i=0;i<n;i++)
		{for(j=0;p[i][j]!=-1;j++)
			cout<<p[i][j]<<" ";
	cout<<endl;*/
	}
matrix :: matrix(int row,int colm)
{
	rows=row;
	colms=colm;
	p=new int*[rows];
	for (int i=0;i<rows;i++)
	{
		p[i]=new int[colm];
		for (int j=0;j<colms;j++)
		{
			
			p[i][j]=rand()%10;
		}
	}
	
}
int ** matrix :: transpose()
{
	
	int** arr=new int*[colms];
	for (int i=0;i<colms;i++)
	{
		arr[i]=new int[rows];
		for (int j=0;j<rows;j++)
		{
			
			arr[i][j]=p[j][i];
		}
	}
	for (int c=0;c<colms;c++)
	{
		for (int g=0;g<rows;g++)
		{
			cout<<arr[c][g]<<" ";
		}
		cout<<endl;
	}
	return arr;
}
void matrix :: print(matrix m)
{
	for (int c=0;c<rows;c++)
	{
		for (int g=0;g<colms;g++)
		{
			cout<<m.p[c][g]<<" ";
		}
		cout<<endl;
	}


}
matrix matrix:: operator=(const matrix &obj)
{
	rows=obj.rows;
		colms=obj.colms;
		p=new int*[rows];
		for (int i=0;i<rows;i++)
		{
			p[i]=new int[colms];
			{
				for (int j=0;j<colms;j++)
				{
					p[i][j]=obj.p[i][j];
				}
			}
		}
		return *this;

}
matrix matrix:: operator+(const matrix &obj)
{
	matrix m(rows,colms);
		
		if (rows!=obj.rows || colms!=obj.colms)
		{
			cout<<"they cant be added";
		}
		for (int i=0;i<rows;i++)
		{
			
			for (int j=0;j<colms;j++)
			{
				m.p[i][j]=p[i][j]+obj.p[i][j];

			}
			
		}
	

	return m;


}
matrix matrix:: operator-(const matrix &obj)
{
	matrix m(rows,colms);
		
		if (rows!=obj.rows || colms!=obj.colms)
		{
			cout<<"they cant be added";
		}
		for (int i=0;i<rows;i++)
		{
			
			for (int j=0;j<colms;j++)
			{
				m.p[i][j]=p[i][j]-obj.p[i][j];

			}
			
		}
	

	return m;
}
matrix matrix:: operator*=(int n)
{
	for (int i=0;i<rows;i++)
			for (int j=0;j<colms;j++)
				p[i][j]=p[i][j]*n;
		return *this;
}
matrix matrix :: operator+=(int k)
{
	for (int i=0;i<rows;i++)
			for (int j=0;j<colms;j++)
				p[i][j]=p[i][j]+k;
		return *this;
}
matrix matrix:: operator-=(const matrix &obj)
{
	for (int i=0;i<rows;i++)
			for(int j=0;j<colms;j++)
				p[i][j]=obj.p[i][j]*-1;
		return *this;
}
bool matrix :: operator==(const matrix &obj)
{
	if (rows!=obj.rows || colms!=obj.colms)
	{
		return false;
	}
	for (int i=0;i<rows;i++)
	{
		for (int j=0;j<colms;j++)
		{
			if (p[i][j]!=obj.p[i][j])
			{
				return false;
			}

		}
	}
	return true;
}
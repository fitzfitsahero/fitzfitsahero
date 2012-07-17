// Crypto Miller-Rabin.cpp : Defines the entry point for the console application.
//
//
// for these numbers, a can be 2 or 3

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>


using namespace std;

int findM(int n);
int mod(int a, int b);

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 997;
	double a2 = 2, a3 = 3;

	//cout << "n: " << n << endl;
	//cout << findM(n) << endl;
	int m = findM(n);

	double b = pow((double)a2,m);
	b = mod((int)b,n);

	if( mod(b,n) == 1)
		cout << "prime" << endl;

	cout << b << endl;

	system("PAUSE");
	
	return 0;
}

int findM(int n)
{
	int nminus = n -1;
	while(1)
	{
		nminus /= 2;
		//cout << nminus << endl;
		if(nminus % 2 != 0)
			return nminus;
	}
}

int mod(int a, int b)
{
	int temp = a % b;
	if(temp < 0)
		return b + temp;
	return temp;
}
// Crypto HW2 Q6-8-17.cpp : Simple single letter RSA encryption with small numbers
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int e = 13;
	int n = 8881;
	double temp = 0;
	double r = 0;

	for(int i = 1; i < 27; i++)
	{
		temp = pow((double)i,e);
		cout << setw(3) << i << " : " << (char)(i + 'a' -1) << " : ";
		cout << setw(12) << temp;
		r = temp - n*floor(temp/n);
		cout << " : " << r << endl;
	}

	system("PAUSE");
	return 0;
}

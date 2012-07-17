// GCD Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <math.h>

//#define _PRINT

using namespace std;

void affineKeys(int num);
int lGCD(int a, int b);

int _tmain(int argc, _TCHAR* argv[])
{	
	int count = 0;
	int num = 1024;

	affineKeys(26);
	affineKeys(29);
	affineKeys(99);
	affineKeys(1024);

	system("PAUSE");
	
	return 0;
}

void affineKeys(int num)
{
	int count = 0;
	for(int i = 0; i < num; i++)
	{
		if(lGCD(i, num) == 1)
		{
#ifdef _DEBUG
			cout << i << endl;
#endif
			count++;
		}
	}
	cout << "Count: " << count << endl;
	cout << "Keys = Count * Number: " << count << " * " << num << ": " << count * num << endl;
}

int lGCD(int a, int b)
{
	int temp = 0;
	while(b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
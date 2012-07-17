// ExtendedEA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int extended(int a, int b);

int _tmain(int argc,_TCHAR* argv[])
{
	cout << extended(1007,26) << endl;

	system("PAUSE");

	return 0;
}
/*
int extended(int a, int b)
{

int q = 0;
	int r0 = a;
	int r1 = b;
	int s0 = 1, s1 = 0;
	int t0 = 0, t1 = 1;
	int temp;

	while(r0 != 0)
	{
		q = r0 / r1;
		temp = r0 - q * r1;
		r0 = r1;
		r1 = temp;

		temp = t0 - q * t1;
		t0 = t1;
		t1 = temp;

		temp = s0 - q * s1;
		s0 = s1;
		s1 = temp;
	}
	
	return s0;
}
*/

int extended(int a, int b)
{
	vector<int>r;
	vector<int>s;
	vector<int>t;
	vector<int>q;
	int m = 1;

	r.push_back(a);
	r.push_back(b);

	s.push_back(1);
	s.push_back(0);

	t.push_back(0);
	t.push_back(1);

	q.push_back(0);

	while(r[m] != 0)
	{
		q.push_back(r[m-1]/r[m]);
		r.push_back(r[m-1] - q[m] * r[m]);
		t.push_back(t[m-1] - q[m] * t[m]);
		s.push_back(s[m-1] - q[m] * s[m]);
		m++;
	}
	m--;
	return s[m];
}

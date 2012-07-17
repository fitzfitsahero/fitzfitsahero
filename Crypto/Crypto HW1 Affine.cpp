// Crypto HW1 Affine.cpp : Defines the entry point for the console application.
//
// HGXAGXHKKXDWZZKXHLCGCAJTGHGTCPCGTGXRTKKEHWWTWXGCXHCEZKKEZKXHEKKXTCBGXWXHGXAJKKTCBZGVWVQZCgTGXKZSDWEGVZQCYGXKKXHGGCXHGTSRKKX
// DENKENDAANHOLLANDZIEIKBREDERIVIERENTRAAGDOORONEINDIGLAAGLANDGAANRIJENONDENKBAARIJLEPOPULIYRENALSHOGEPLUIMENAANDEEINDERSTAAN
// Thinking see of Holland I broad rivers slowly through infinite lowland go rows inconceivably rarefied poplars as high plumes at the einder stand

// http://www.deltawerken.com/Denkend-aan-Holland.../257.html

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int gcd(int a, int b);
int extended(int a, int b);
int mod(int a, int b);

int _tmain(int argc, _TCHAR* argv[])
{
	string s = "HGXAGXHKKXDWZZKXHLCGCAJTGHGTCPCGTGXRTKKEHWWTWXGCXHCEZKKEZKXHEKKXTCBGXWXHGXAJKKTCBZGVWVQZCgTGXKZSDWEGVZQCYGXKKXHGGCXHGTSRKKX";
	int length = 123;//s.length();
	int cipher[123];//int cipher[length];
	int plaintext[123];

	ofstream outfile;
	outfile.open("Dutch", ios::out);


#ifdef _DEBUG
	cout << 'H' - 'A' << endl;
#endif

	int beta = 1;			////////

	int alpha[12];
	int ialpha[12];
	int index = 0;

	for(int i = 0; i < 26; i++)
	{
		if(gcd(i,26) == 1)
			alpha[index++] = i;
	}
	for(int i = 0; i < 12; i++)
	{
		ialpha[i] = extended(alpha[i],26);
		if(ialpha[i] < 0)
			ialpha[i] += 26;
#ifdef _DEBUG
		cout << ialpha[i] << endl;
#endif
		//cout << " alpha: " << alpha[i] << endl;
		//cout << "ialpha: " << ialpha[i] << endl << endl;
	}

	ialpha[1] = 9;
	ialpha[3] = 21;
	ialpha[4] = 3;
	ialpha[5] = 19;
	ialpha[6] = 7;
	ialpha[7] = 23;
	ialpha[8] = 11;
	ialpha[9] = 5;
	ialpha[10] = 17;
	ialpha[11] = 25;

#ifdef _DEBUG
	for(int i = 0; i < 12; i++)
		cout << alpha[i] << endl;
#endif

	for(int i = 0; i < length; i++)
	{
		cipher[i] = s[i] - 'A';
#ifdef _DEBUG
		cout << cipher[i] << " ";
#endif
	}
#ifdef _DEBUG
	for(int i = 0; i < length; i++)
	{
		plaintext[i] = ialpha[1] * (cipher[i] - beta);
		plaintext[i] = mod(plaintext[i], 26);
#ifdef _DEBUG
		cout << plaintext[i] << " ";
#endif
		cout << char(plaintext[i] + 'A');
	}
#endif

	for(int x = 0; x < 12; x++)
	{
		for(int b = 0; b < 26; b++)
		{
			outfile << "Alpha : " << alpha[x] << " Beta: " << b << "   ";
			for(int i = 0; i < length; i++)
			{
				plaintext[i] = ialpha[x] * (cipher[i] - b);
				plaintext[i] = mod(plaintext[i], 26);
				outfile << char(plaintext[i] + 'A');
			}
			outfile << endl;
		}
	}


#ifdef _DEBUG	
	cout << endl;
	cout << -8 % 3 << endl;
	cout << mod(-8,3) << endl;
#endif

	cout << extended(3,26) << endl;

	system("PAUSE");
	return 0;
}
int gcd(int a, int b)
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
/*
int extended(int a, int b)
{
	int q = 0;
	int r = 0;
	int x = 1;
	int y = 0;
	int x1 = 1;
	int x2 = 1;
	int y1 = 1;
	int y2 = 0;
	
	while(b > 0)
	{
		q = a / b;
		r = a - q * b;
		x = x2 - q * x1;
		y = y2 - q * y1;

		a = b;
		b = r;

		x2 = x1;
		x1 = x;
		y2 = y1;
		y1 = y;
	}
	return x;
}
*/

int extended(int a, int b)
{
	int q = 0;
	int r0 = a;
	int r1 = b;
	int s0 = 1, s1 = 0;
	int t0 = 0, t1 = 1;
	int temp;

	while(b != 0)
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

int mod(int a, int b)
{
	int temp = a % b;
	if(temp < 0)
		return b + temp;
	return temp;
}
// Gracjan Zeniuk.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
//start 0.0
//end punkt x
//klikniecie  (x+ 1, y + 1)
// brak reakcji  (x+ 1, y - 1)
// przeszkody n
// opis przeszkody (xi=wspolrzedna x, ai=koniec przeszkody od dolu, bi= koniec przeszkody od gory), y(mniejsze, rowne)<a i y(wieksze, rowne)>b (naleza do zabronionych)
int x = 0, y = 0, i = 1, n = 1, licznik = 0, z = 1;
long int X;
int * ai = new int[500000];
int * bi = new int[500000];
int * xi = new int[500000];
//int ai[50000];
//int bi[50000];
//int xi[50000];
int klikniecie()
{
	x++;
	y++;
	licznik++;
	return x, y,licznik;
}
int brak_reakcji()
{
	x++;
	y--;

	return x, y;
}
void wyjscie_dobre()
{
	cout << licznik<< endl;
	getchar();
}

void wyjscie_zle()
{
	cout << "NIE" << endl;
	getchar();
}
int main()
{
//wejscie
	cout << "WEJSCIE" << endl;
	do
	{
		cout << "podaj n "<<endl;//liczba przeszkod
		cin >> n;
		cout << "podaj X "<<endl;//cel 
		cin >> X;
	} 
	while (n > X || 0 > n > 500000 || 1 > X > 1000000000);
	for (i = 1; i <= n; i++)
	{
		xi[i] = 1000 - i;
		ai[i] = -1;
		bi[i] = 2;
		/*cout << "podaj xi ";
		cin >> xi[i];
		cout << "podaj ai ";
		cin >> ai[i];
		cout << "podaj bi ";
		cin >> bi[i];
		getchar();*/
	}
	for (int k = 1; k <= n; k++)
	{
		while (x < xi[k])
		{
			if (y <= ai[k] && y < bi[k])
			{
				klikniecie();
				//cout << "y1 " << y << endl;
				//cout << "x1 " << x << endl;
				//cout << "licznik " << licznik << endl;

			}

			else if (y > ai[k] )
			{

				int z = y - ai[k];
				if (z == 1)
				{
					klikniecie();
					//cout << "y3 " << y << endl;
					//cout << "x3 " << x << endl;
					//cout << "licznik " << licznik << endl;
				}
				else
				{
					brak_reakcji();
					//cout << "y2 " << y << endl;
					//cout << "x2 " << x << endl;
					//cout << "licznik2 " << licznik2 << endl;
				}		
			}
		}
		}
	while (x<X)
	{
		brak_reakcji();
		//cout << "y2 " << y << endl;
		//cout << "x2 " << x << endl;
		//cout << "licznik " << licznik << endl;
	}

	/*cout << "Wejscie:\n" << n << " " << X << endl;
	for (int j = 1; j <= n; j++)
	{
		cout << "  " << xi[j];
		cout << "  " << ai[j];
		cout << "  " << bi[j] << endl;
		
	}*/
//wyjscie	
	cout << "WYJSCIE" << endl;
	if (y==ai[i]||y==bi[i])
	{
		wyjscie_zle();
	}
	else
	{
		wyjscie_dobre();
	}
	getchar();
    return 0;
}


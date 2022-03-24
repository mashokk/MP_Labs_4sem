// 3.cpp: ���������� ����� ����� ��� ����������� ����������.
//


#include "stdafx.h"
#include <iostream>
#include <iomanip> 
#include "Salesman.h"
#define N 5

using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	int d[N][N] = { //0    1    2    3     4        
					{ INF,  4,   23,  INF,   2 },    //  0
					{ 2,   INF,  17,  66,   82 },    //  1
					{ 4,    6,  INF,  86,   51 },    //  2 
					{ 19,  56,   8,   INF,   6 },    //  3
					{ 91,  68,   52,  15,  INF } };   //  4  
	int r[N];   /// ��������� 
	int s = salesman(
		N,          /// [in]  ���-�� ������� 
		(int*)d,    /// [in]  ������ [n*n] ���������� 
		r           /// [out] ������ [n] ������� 0 x x x x  

	);
	cout << "\n-- ������ ������������ -- ";
	cout << "\n-- ����������  �������: " << N;
	cout << "\n-- ������� ���������� : ";

	for (int i = 0; i < N; i++)
	{
		cout << "\n";
		for (int j = 0; j < N; j++)

			if (d[i][j] != INF) cout << setw(3) << d[i][j] << " ";

			else cout << setw(3) << "INF" << " ";
	}

	cout << "\n-- ����������� �������: ";
	for (int i = 0; i < N; i++)
		cout << r[i] + 1 << "-->";

	cout << 1;
	cout << "\n-- ����� ��������     : " << s << "\n";
	system("pause");
	return 0;

}
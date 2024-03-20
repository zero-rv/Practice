#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void b9();

int main()
{
back:
	cout << "Switch: ";
	int x;
	cin >> x;
	switch (x)
	{
	case 9:
		b9();
		goto back;
	case 10:
		
		goto back;
	case 11:
		
		goto back;
	case 12:
		
		goto back;
	case 0:
		break;
	default:
		goto back;
	}
	return 0;
}

void input(string s, int& n)
{
	cout << s;
	cin >> n;
}

bool isPrime(int n)
{
	if (n < 2)
		return false;

	for (int i = 2; i < n/2; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int cal_prime_value(int** arr, int& r, int& c, bool(*condition)(int))
{
	int sum = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (condition((arr[i][j])))
				sum += arr[i][j];
		}
		cout << endl;
	}
	return sum;
}

void b9()
{
	srand(time(NULL));
	int r, c;
	input("Nhap so hang: ", r);
	input("Nhap so cot: ", c);
	int** arr = new int* [r];
	for (int i = 0; i < r; i++)
	{
		arr[i] = new int[c];
	}
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			arr[i][j] = rand() % 100 + 1;
		}
		cout << endl;
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << arr[i][j];
			if (j < c - 1)
				cout << ", ";
		}
		cout << endl;
	}

	int sum = cal_prime_value(arr, r, c, isPrime);

	cout << "Tong cac so nguyen to trong mang: " << sum << endl;
	delete[] arr;
}
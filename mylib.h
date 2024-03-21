#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void input(string s, int& n)
{
	cout << s;
	cin >> n;
}

void printArr(int *arr, int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

void swap(int &a, int&b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void reverseArr(int *arr, int &n)
{
	for (int i = 0; i < n / 2; i++)
	{
		swap(arr[i], arr[n - i - 1]);
	}
}

int* findIndexValue(int *arr, int &n, int x, int index = -1)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			index = i;
			return &index;
		}
	}
	return &index;
}

bool isPrime(int n)
{
	if (n < 2)
		return false;

	for (int i = 2; i < n / 2; i++)
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
	}
	return sum;
}

void pushBackArr(int *&a, int&n, int x)
{
	int new_size = n + 1;
	int* new_array = new int[new_size];

	for (int i = 0; i < n; i++)
	{
		new_array[i] = a[i];
	}

	new_array[new_size - 1] = x;

	delete[] a;
	a = new_array;
	n = new_size;
}

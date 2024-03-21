#include "mylib.h"

void b6();
void b7();
void b9();
void bonus();


int main()
{
back:
	cout << "Switch: ";
	int x;
	cin >> x;
	switch (x)
	{
	case 6:
		b6();
		goto back;
	case 7:
		b7();
		goto back;
	case 9:
		b9();
		goto back;
	case 10:

		goto back;
	case 11:

		goto back;
	case 12:

		goto back;
	case 100:
		bonus();
		goto back;
	case 0:
		break;
	default:
		goto back;
	}
	return 0;
}

void b6()
{
	int n;
	do
	{
		input("Nhap so phan tu cua mang (n>0): ", n);
	} while (n <= 0);

	int *arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	printArr(arr, n);
	cout << endl;
	reverseArr(arr, n);
	cout << "Mang sau khi dao nguoc: ";
	printArr(arr, n);
	cout << endl;
}

void b7()
{
	srand(time(NULL));
	int n, x;
	do
	{
		input("Nhap so phan tu cua mang (n>0): ", n);
	} while (n <= 0);

	int *arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	printArr(arr, n);
	cout << endl;
	input("Nhap gia tri can tim: ", x);
	if (findIndexValue(arr, n, x) != new int(-1))
		cout << "Tim thay tai phan tu arr[" << *findIndexValue(arr, n, x) << "]" << endl;
	else
		cout << "Khong tim thay gia tri can tim!" << endl;

	delete[] arr;
}

void b9()
{
	srand(time(NULL));
	int r, c;
	input("Nhap so hang: ", r);
	input("Nhap so cot: ", c);
	int** arr = new int*[r];
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

void bonus()
{
	srand(time(NULL));

	int n, x;
	do
	{
		input("Nhap so phan tu cua mang (n>0): ", n);
	} while (n <= 0);

	int *arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100 + 1;
	}

	cout << "Mang ban dau: ";
	printArr(arr, n);
	cout << endl;
	input("Nhap gia tri muon them: ", x);
	pushBackArr(arr, n, x);
	cout << "Mang sau khi them: ";
	printArr(arr, n);
	cout << endl;

	delete[] arr;
}